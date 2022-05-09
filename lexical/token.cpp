#include "token.h"

void token::print(){
    if (t==NO){
        cout<< "<"<<s<<">\n";
    }
    else{
        cout<< "<"<<s<<','<<t<<">\n";
    }
}

token::token(string s,types t){
    this->s=s;
    this->t=t;
}
token::token(string s){
    this->s=s;
}