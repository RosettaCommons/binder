#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

int skip(const std::string& s1)
{
    if (s1.length()==0) return 1;
    if (s1.length()>2) if (s1.substr(2)=="//") return 2;
    if (s1.find("Source list file")!=std::string::npos) return 3;
    if (s1.find("Modules list file")!=std::string::npos) return 4;
    if (s1.find("pybind11::handle cl_type = cl;")!=std::string::npos) return 5;
    if (s1.find("File:")!=std::string::npos) return 6;
    return 0;
}
int COMPARE_ASCII_FILES(const std::string& f1,const std::string& f2)
{
    std::fstream file1(f1.c_str()), file2(f2.c_str());
    std::string string1, string2;
    int j1,j2;
    j1 = 0;
    j2 = 0;
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

        //printf("%s %s\n", string1.c_str(),string2.c_str());
        if(string1.compare(string2) != 0)
        {
            std::cout << j1<<"/"<<j2 << "-th strings are not equal" << f1<<f2<<"\n";
            std::cout << "   ->" << string1 << "<-\n";
            std::cout << "   ->" << string2 << "<-\n";
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
int main(int argc, char** argv)
{
    if (argc!=3) {
        std::cout<<"Wrong number of arguments"<<std::endl;
        return EXIT_FAILURE;
    }
    return COMPARE_ASCII_FILES(argv[1],argv[2]);
}








