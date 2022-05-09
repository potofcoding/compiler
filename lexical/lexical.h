#pragma once
#include <iostream>
#include <vector>
#include "token.h"

using namespace std;
class lexical{
    int start=0;
    int end=0;
    string buffer;
    vector<token> lexem;
public:
    void run(string buffer);
};