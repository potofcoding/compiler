#pragma once
#include<fstream>
#include<ostream>
#include <iostream>
using namespace std;


class filem{
public:
    ofstream filer;
    void load_file_into_variable(char* file,string &s);
    void write_to_file(string s,void (*ptr)());
};