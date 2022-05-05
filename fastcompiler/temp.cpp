#include<iostream>
#include<fstream>
#include<ostream>
#include<string>
#include<bits/stdc++.h>
#include <vector>
#include<regex>

using namespace std;

int main(int argc, char* argv[]){
    vector<string> w;
    string word="";
    ofstream myfile;
    myfile.open ("../example.txt");
    myfile << '<';
    if (argc>=2){
        FILE* fp = fopen(argv[1], "r");
        unsigned char character = 0;
        while(!feof(fp)){
            character = fgetc(fp);
            switch(character){
                case '\n' :
                    w.push_back(word);
                    word = "";
                    break;
                case ' ' :
                    w.push_back(word);
                    word = "";
                    break;
                case '(' :
                    w.push_back(word);
                    w.push_back("(");
                    word = "";
                    break;
                case ')' :
                    w.push_back(word);
                    w.push_back(")");
                    word = "";
                    break;
                case '<<' :
                    w.push_back(word);
                    w.push_back("<<");
                    word = "";
                    break;
                case ';' :
                    w.push_back(word);
                    w.push_back(")");
                    word = "";
                    break;
                default:
                    word += character;
                    myfile << character;
            }
            cout << character<<endl;
        }
    }
    myfile.close();
    for (string i :w) {
        cout << i <<"\n";
    }
} 