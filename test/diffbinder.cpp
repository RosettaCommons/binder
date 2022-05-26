//
// Copyright (c) 2020 Andrii Verbytskyi <andrii.verbytskyi@mpp.mpg.de> for the binder project
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.
/// This is a simple and portable implementation of diff utility for the binder CI
/// that should ignore certain patters.
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

/// Function that checks if the line should be skipped in the comparison.
/// It is indicated with a non-zero return code.
/// The function checks the presence of variable or semantically unimportant strings in the line.
/// These can be comments, the absolute paths of the sources and some codes that rely on the implementation of the STL.
int skip(std::string const &s1)
{
	if( s1.length() == 0 ) return 1;
	if( s1.length() > 1 ) {
		size_t comment = s1.find_first_of("//");
		if( comment == s1.find_first_not_of(" \t") && comment != std::string::npos ) return 2; // The comments should be ignored
	}
	if( s1.find("Source list file") != std::string::npos ) return 3; // Same as the list of source files
	if( s1.find("Modules list file") != std::string::npos ) return 4; // Same as the list of modules
	if( s1.find("File:") != std::string::npos ) return 5; // Same as the full file paths.
	if( s1.find("pybind11::handle cl_type = cl;") != std::string::npos ) return 6; // This could be optimized in binder
	if( s1.find("__cxx11") != std::string::npos ) return 7; // This looks like implementation dependent
	if( s1.find("assign") != std::string::npos ) return 8; // The assing is binded differently for some reasons
	if( s1.find("#include") != std::string::npos ) return 9; // Includes could differ
	if( s1.find("pybind11::gil_scoped_acquire gil;") != std::string::npos ) return 10; // This could be optimized in binder
	return 0;
}
/// This function strips the one-line C++ comments from the input and return the result.
std::string strip_comment_and_whitespace(std::string const &s1)
{
	if( s1.empty() ) return s1;
	size_t comment = s1.find_first_of("//");
	std::string temp = s1.substr(0, comment);
	temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c) { return (c == ' ' || c == '\t'); }), temp.end());
	return temp;
}
/// This function compares the content of two files f1 and f2 using the
int compare_text_files(std::string const &f1, const std::string &f2)
{
	std::fstream file1(f1), file2(f2);
	std::string string1, string2;
	int j1 = 0, j2 = 0;
	if( !file1 || !file2 ) {
		std::cout << "Cannot open one of files " << f1 << " or " << f2 << "\n";
		return EXIT_FAILURE;
	}
	std::cout << "Run comparison"
			  << "\n";
	while( (!file1.eof()) && (!file2.eof()) ) {
		for( ;; ) {
			j1++;
			if( !std::getline(file1, string1) ) break;
			if( skip(string1) == 0 ) break;
		}
		for( ;; ) {
			j2++;
			if( !std::getline(file2, string2) ) break;
			if( skip(string2) == 0 ) break;
		}
		if( strip_comment_and_whitespace(string1) != strip_comment_and_whitespace(string2) ) {
			std::cout << j1 << "/" << j2 << "-th strings are not equal " << f1 << " " << f2 << "\n";
			std::cout << "   ->" << string1 << "<-\n";
			std::cout << "   ->" << string2 << "<-\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
int main(int argc, char **argv)
{
	if( argc != 3 && argc != 4 ) {
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage:        " << argv[0] << " <first file to compare> <second file to compare> [options]" << std::endl;
		std::cout << "Options:      --always-success     Optional. Perform comparison, but return 0 exit code regardless of the comparison result." << std::endl;
		return EXIT_FAILURE;
	}
	if( argc == 4 ) {
		if( strcmp(argv[3], "--always-success") != 0 ) {
			std::cout << "Wrong option: " << argv[3] << std::endl;
			std::cout << "Usage:        " << argv[0] << " <first file to compare> <second file to compare> [options]" << std::endl;
			std::cout << "Options:      --always-success     Optional. Perform comparison, but return 0 exit code regardless of the comparison result." << std::endl;
			return EXIT_FAILURE;
		}
	}
	int status = compare_text_files(argv[1], argv[2]);
	if( argc == 4 ) {
		if( strcmp(argv[3], "--always-success") == 0 ) return EXIT_SUCCESS;
	}
	return status;
}
