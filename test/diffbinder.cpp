//
// Copyright (c) 2020 Andrii Verbytskyi <andrii.verbytskyi@mpp.mpg.de> for the binder project
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string.h>

int skip(std::string const & s1)
{
    if (s1.length()==0) return 1;
    if (s1.length()>1) 
    {
        size_t comment=s1.find_first_of("//");
        if (comment==s1.find_first_not_of(" \t")&&comment!=std::string::npos) return 2; //The comments should be ignored
    }
    if (s1.find("Source list file")!=std::string::npos) return 3;       //Same as the list of source files
    if (s1.find("Modules list file")!=std::string::npos) return 4;      //Same as the list of modules
    if (s1.find("File:")!=std::string::npos) return 5;                  //Same as the full file paths.
    if (s1.find("pybind11::handle cl_type = cl;")!=std::string::npos) return 6;  //This could be optimized in binder
    if (s1.find("__cxx11")!=std::string::npos) return 7;                         //This looks like implementation dependent
    if (s1.find("assign")!=std::string::npos) return 8;                          // The assing is binded differently for some reasons
    if (s1.find("#include")!=std::string::npos) return 9;                        // Includes could differ
    return 0;
}
std::string strip(std::string const & s1)
{
    if (s1.length()==0) return s1;
    size_t comment=s1.find_first_of("//");
    return s1.substr(0,comment);
}
int compare_text_files(std::string const & f1,const std::string & f2)
{
    std::fstream file1(f1), file2(f2);
    std::string string1, string2;
    int j1,j2;
    j1 = 0;
    j2 = 0;
    if (!file1 || !file2 ) 
    {
            std::cout << "Cannot open one of files " << f1<<" or "<<f2<<"\n";
            return EXIT_FAILURE;
    }
    std::cout <<"Run comparison"<< "\n";
    while((!file1.eof())&&(!file2.eof()))
    {
        for (;;) {
            j1++;
            if (!std::getline(file1,string1)) break;
            if (skip(string1)==0) break;
        }
        for (;;) {
            j2++;
            if (!std::getline(file2,string2)) break;
            if (skip(string2)==0) break;
        }
        if(strip(string1).compare(strip(string2)) != 0)
        {
            std::cout << j1<<"/"<<j2 << "-th strings are not equal" << f1<<" "<<f2<<"\n";
            std::cout << "   ->" << string1 << "<-\n";
            std::cout << "   ->" << string2 << "<-\n";
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
int main(int argc, char** argv)
{
    if (argc!=3&&argc!=4) {
        std::cout<<"Wrong number of arguments"<<std::endl;
        return EXIT_FAILURE;
    }
    int status=compare_text_files(argv[1],argv[2]);
    if (argc==4)  { if (strcmp(argv[3],"--always-success")==0)  return EXIT_SUCCESS; }
    return status;
}
