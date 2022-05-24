#pragma once
#include <iostream>
#include <vector>
#include "token.h"
#include <string>
using namespace std;

class lexical{
    int start=0;
    int end=0;
    int line=1;
    string buffer;
    vector<token> lexem;
public:
    void run(string buffer);
};