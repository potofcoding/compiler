#include "filem.h"

void filem::load_file_into_variable(char* file,string &s){
    FILE* fp = fopen(file, "r");
    unsigned char character = 0;
    while(!feof(fp)){
        character = fgetc(fp);
        s += character;
    }
}

void filem::write_to_file(string s){
    ofstream myfile;
    myfile.open ("../example.txt");
    myfile.close();
}