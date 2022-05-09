#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include "filem/filem.h"
#include "lexical/lexical.h"


using namespace std;

int main(int argc, char* argv[]){
    filem fm;
    string buffer;
    lexical l;
    if (argc>=2){
        fm.load_file_into_variable(argv[1],buffer);
        l.run(buffer);
    }
    cout<<buffer;
} 