#include "lexical.h"

void lexical::run(string buffer){
    this->buffer = buffer;
    while(end !=  (int) buffer.size()){
        switch(buffer[end]){
            case ';':
                lexem.push_back(token(";"));
                
            break;
            case ',':
                lexem.push_back(token(","));
            break;
            case ':':
                switch(buffer[end+1]){
                    case '>':
                        lexem.push_back(token("]",AND_OP));
                        end++;
                    break;
                    default:
                        lexem.push_back(token(":",NO));
                }//handle ::
            break;
            case '=':
                if (buffer[end+1]=='='){
                    lexem.push_back(token("==",EQ_OP));
                    end++;
                }
                else{
                    lexem.push_back(token("=",NO));
                }
            break;
            case '.':
                if (buffer[end+1]=='.'&&buffer[end+2]=='.'){
                    lexem.push_back(token("...",ELLIPSIS));
                    end+=2;
                }else{
                    lexem.push_back(token(".",NO));
                }
            break;
            case '&':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("&=",AND_ASSIGN));
                        end++;
                    break;
                    case '&':
                        lexem.push_back(token("&&",AND_OP));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("&",NO));
                }
            break;
            case '!':
                if (buffer[end+1]=='='){
                    lexem.push_back(token("!=",NE_OP));
                    end++;
                }else{
                    lexem.push_back(token("!",NO));
                }
            break;
            case '~':
                lexem.push_back(token("~",NO));
            break;
            case '-':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("-=",SUB_ASSIGN));
                        end++;
                    break;
                    case '-':
                        lexem.push_back(token("--",DEC_OP));
                        end++;
                    break;
                    case '>':
                        lexem.push_back(token("->",PTR_OP));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("-",NO));
                }
            break;
            case '+':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("+=",ADD_ASSIGN));
                        end++;
                    break;
                    case '+':
                        lexem.push_back(token("++",INC_OP));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("+",NO));
                }
            break;
            case '*':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("*=",MUL_ASSIGN));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("*",NO));
                }
            break;
            case '/':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("/=",DIV_ASSIGN));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("/",NO));
                }
            break;
            case '%':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("%=",MOD_ASSIGN));
                        end++;
                    break;
                    case '>':
                        lexem.push_back(token("}",NO));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("%",NO));
                }
            break;
            case '>':
                if ( buffer[end+1] == '>' && buffer[end+2] == '='){
                    lexem.push_back(token(">>=",RIGHT_ASSIGN));
                    end+=2;
                }
                else if(buffer[end+1]=='='){
                    lexem.push_back(token(">=",GE_OP));
                    end++;
                }else if(buffer[end+1]=='>'){
                    lexem.push_back(token(">>",RIGHT_OP));
                    end++;
                }else{
                    lexem.push_back(token(">",NO));
                }
            break;
            case '<':
                if ( buffer[end+1] == '<' && buffer[end+2] == '='){
                    lexem.push_back(token("<<=",LEFT_ASSIGN));
                    end+=2;
                }
                else if(buffer[end+1]=='='){
                    lexem.push_back(token("<=",LE_OP));
                    end++;
                }else if(buffer[end+1]=='>'){
                    lexem.push_back(token("<<",LEFT_OP));
                    end++;
                }else if(buffer[end+1]==':'){
                    lexem.push_back(token("[",NO));
                    end++;
                }else if(buffer[end+1]=='%'){
                    lexem.push_back(token("{",NO));
                    end++;
                }else{
                    lexem.push_back(token("<",NO));
                }
            break;
            case '^':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("^=",XOR_ASSIGN));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("^",NO));
                }
            break;
            case '|':
                switch(buffer[end+1]){
                    case '=':
                        lexem.push_back(token("|=",OR_ASSIGN));
                        end++;
                    break;
                    case '|':
                        lexem.push_back(token("||",OR_OP));
                        end++;
                    break;
                    default:
                        lexem.push_back(token("|",NO));
                }
            break;
            case '?':
                lexem.push_back(token("?",NO));
            break;
            case '(':
                lexem.push_back(token("(",NO));
            break;
            case ')':
                lexem.push_back(token(")",NO));
            break;
            case '[':
                lexem.push_back(token("[",NO));
            break;
            case ']':
                lexem.push_back(token("]",NO));
            break;
            case '{':
                lexem.push_back(token("{",NO));
            break;
            case '}':
                lexem.push_back(token("}",NO));
            break;
            default:
            break;
        }
        end++;
    }
}