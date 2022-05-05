#include<iostream>
#include<fstream>
#include<ostream>
#include<string>
#include<bits/stdc++.h>
#include <vector>
#include "token/token.h"
#include "filem/filem.h"

using namespace std;

int main(int argc, char* argv[]){
    filem fm;
    token t;
    string buffer;
    
    if (argc>=2){
        fm.load_file_into_variable(argv[1],buffer);
    }
    cout<<buffer;
} 