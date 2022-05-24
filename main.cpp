#include <iostream>
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
        fm.filer.open ("../lexical.sad");
        fm.filer<< "Writing this e.\n";
        fm.filer.close();
    }
} 