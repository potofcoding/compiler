#pragma once
#include <iostream>
#include <vector>
#include "token.h"
#include <string>
#include <unordered_map>
using namespace std;

class lexical{
    int start=0;
    int end=0;
    int line=1;
    string buffer;
public:
    vector<token> lexem;
    unordered_map<string,int> id_table;
    void run(string buffer ,ofstream& f);
};