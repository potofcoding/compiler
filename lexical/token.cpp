#include "token.h"

void token::print(ofstream& f){
    if (t==NO){
        f<< "<"<<s<< "|" <<start <<"|"<<len<<"|"<<line<<">\n";
    }
    else if (t==IDENTIFIER){
        f<< "<"<<s<<'|'<<t<< "|" <<start<<"|"<<len<<"|"<<line<<">\n";
    }else{
        f<< "<"<<s<<'|'<<typenames[(int) t]<< "|" <<start<<"|"<<len<<"|"<<line<<">\n";
    }
}

token::token(string s,types t,int start,int len,int line){
    this->s=s;
    this->t=t;
    this->start=start;
    this->len=len;
    this->line = line;

}
token::token(string s,int start,int line){
    this->s=s;
    this->t=NO;
    this->start=start;
    this->line = line;
}

void token::see_its_type(){
    for (int i =0 ; i<keys.size();i++){
        if(keys[i] == this->s){
            this->t = (types) i;
            break;
        }
        else{
            this->t = IDENTIFIER;
        }
    }
}