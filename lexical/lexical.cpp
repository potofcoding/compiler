#include "lexical.h"

void lexical::run(string buffer,ofstream& f){
    this->buffer = buffer;
    while(end !=  (int) buffer.size()){
        switch(buffer[end]){
            case ';':
                lexem.push_back(token(";",SEMICOLON,start,line));
                end++;
                start = end;
            break;
            case ',':
                lexem.push_back(token(",",COMMA,start,line));
                end++;
                start = end;
            break;
            case ':':
                switch(buffer[end+1]){
                    case '>':
                        end++;
                        lexem.push_back(token("]",AND_OP,end,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token(":",COLLON,start,line));
                        end++;
                        start = end;
                }//handle ::
            break;
            case '=':
                if (buffer[end+1]=='='){
                    end++;
                    lexem.push_back(token("==",EQ_OP,start,end - start,line)); 
                    end++;
                    start = end;
                }
                else{
                    lexem.push_back(token("=",ASSIMENT,start,line));
                    end++;
                    start = end;
                }
            break;
            case '.':
                if (buffer[end+1]=='.'&&buffer[end+2]=='.'){
                    end+=2;
                    lexem.push_back(token("...",ELLIPSIS,end-start,line));
                    end++;
                    start = end;
                }else{
                    lexem.push_back(token(".",DOT,start,line));
                    end++;
                    start = end;
                }
            break;
            case '&':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("&=",AND_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    case '&':
                        end++;
                        lexem.push_back(token("&&",AND_OP,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("&",AND,start,line));
                        end++;
                        start = end;
                }
            break;
            case '!':
                if (buffer[end+1]=='='){
                    end++;
                    lexem.push_back(token("!=",NE_OP,start,end-start,line));
                    end++;
                }else{
                    lexem.push_back(token("!",EXCLIMATION,start,line));
                    end++;
                    start = end;
                }
            break;
            case '~':
                lexem.push_back(token("~",TELDA,start,line));
                end++;
                start = end;
            break;
            case '-':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("-=",SUB_ASSIGN,end,end - start,line));
                        end++;
                        start = end;
                    break;
                    case '-':
                        end++;
                        lexem.push_back(token("--",DEC_OP,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    case '>':
                        end++;
                        lexem.push_back(token("->",PTR_OP,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("-",MINUS,start,line));
                        end++;
                        start = end;
                }
            break;
            case '+':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("+=",ADD_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    case '+':
                        end++;
                        lexem.push_back(token("++",INC_OP,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("+",PLUS,start,line));
                        end++;
                        start = end;
                }
            break;
            case '*':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("*=",MUL_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("*",ASTRICS,start,line));
                        end++;
                        start = end;
                }
            break;
            case '/':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("/=",DIV_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    case '*':
                        end+=2;
                        while(buffer[end] != '*' && buffer[end+1] != '/'){
                            if (buffer[end]=='\n'){
                                line++;
                            }
                            end++;
                        }
                        if (buffer[end]=='\n'){
                            line++;
                        }
                        end+=2;
                        cout<<"long comment\n";
                        start = end;
                    break;
                    case '/':
                        while(buffer[end]!='\n'){
                            end++;
                        }
                        cout<<"line comment\n";
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("/",FORWARD_SLASH,start,line));
                        end++;
                        start = end;
                }
            break;
            case '%':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("%=",MOD_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    case '>':
                        end++;
                        lexem.push_back(token("}",LEFT_CURLY_BRACKET,start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("%",PERCENT,start,line));
                        end++;
                        start = end;
                }
            break;
            case '>':
                if ( buffer[end+1] == '>' && buffer[end+2] == '='){
                    end+=2;
                    lexem.push_back(token(">>=",RIGHT_ASSIGN,start,end-start,line));
                    end++;
                    start = end;
                }
                else if(buffer[end+1]=='='){
                    end++;
                    lexem.push_back(token(">=",GE_OP,start,end-start,line));
                    end++;
                    start = end;
                }else if(buffer[end+1]=='>'){
                    end++;
                    lexem.push_back(token(">>",RIGHT_OP,start,end-start,line));
                    end++;
                    start = end;
                }else{
                    lexem.push_back(token(">",GREATER_THAN,end,line));
                    end++;
                    start = end;
                }
            break;
            case '<':
                if ( buffer[end+1] == '<' && buffer[end+2] == '='){
                    end+=2;
                    lexem.push_back(token("<<=",LEFT_ASSIGN,start,end-start,line));
                    end++;
                    start = end;
                }
                else if(buffer[end+1]=='='){
                    end++;
                    lexem.push_back(token("<=",LE_OP,start,end-start,line));
                    end++;
                    start = end;
                }else if(buffer[end+1]=='>'){
                    end++;
                    lexem.push_back(token("<<",LEFT_OP,start,end-start,line));
                    end++;
                    start = end;
                }else if(buffer[end+1]==':'){
                    end++;
                    lexem.push_back(token("[",LEFT_SQUARE_BRACKET,end,line));
                    end++;
                    start = end;
                }else if(buffer[end+1]=='%'){
                    end++;
                    lexem.push_back(token("{",LEFT_CURLY_BRACKET,end,line));
                    end++;
                    start = end;
                }else{
                    lexem.push_back(token("<",LESS_THAN,end,line));
                    end++;
                    start = end;
                }
            break;
            case '^':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("^=",XOR_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("^",POWER,end,line));
                        end++;
                        start = end;
                }
            break;
            case '|':
                switch(buffer[end+1]){
                    case '=':
                        end++;
                        lexem.push_back(token("|=",OR_ASSIGN,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    case '|':
                        end++;
                        lexem.push_back(token("||",OR_OP,start,end-start,line));
                        end++;
                        start = end;
                    break;
                    default:
                        lexem.push_back(token("|",STICK,start,line));
                        end++;
                        start = end;
                }
            break;
            case '?':
                lexem.push_back(token("?",QUISTION_MARK,start,line));
                end++;
                start = end;
            break;
            case '(':
                lexem.push_back(token("(",LEFT_BRACKET,start,line));
                end++;
                start = end;
            break;
            case ')':
                lexem.push_back(token(")",RIGHT_BRACKET,start,line));
                end++;
                start = end;
            break;
            case '[':
                lexem.push_back(token("[",LEFT_SQUARE_BRACKET,start,line));
                end++;
                start = end;
            break;
            case ']':
                lexem.push_back(token("]",RIGHT_SQUARE_BRACKET,start,line));
                end++;
                start = end;
            break;
            case '{':
                lexem.push_back(token("{",LEFT_CURLY_BRACKET,start,line));
                end++;
                start = end;
            break;
            case '}':
                lexem.push_back(token("}",RIGHT_CURLY_BRACKET,start,line));
                end++;
                start = end;
            break;
            case '\n':
                end++;
                start = end;
                line++;
            break;
            case '"':
                end++;
                while (buffer[end]!='"')
                {
                    end++;
                }
                end++;
                lexem.push_back(token(buffer.substr(start,end-start),STRING_LITERAL,start,end-start,line));
                start = end;
            break;
            case ' ':
                end++;
                start = end;
            break;
            default:
                if ((buffer[end]>='A' && buffer[end]<='Z' )|| (buffer[end]>='a' && buffer[end]<='z')) {
                    end++;
                    while((buffer[end]>='A' && buffer[end]<='Z') || (buffer[end]>='a' && buffer[end]<='z')||(buffer[end] >= '0' and buffer[end] <= '9') || buffer[end] == '_'){
                        end++;
                    }
                    token t = token(buffer.substr(start,end-start),AUTO,start,end-start,line);
                    t.see_its_type();
                    lexem.push_back(t);
                    start = end;
                }else if (buffer[end] >= '0' and buffer[end] <= '9'){
                    while((buffer[end] >= '0' and buffer[end] <= '9')){
                        end++;
                    }
                    lexem.push_back(token(buffer.substr(start,end-start),I_CONSTANT,start,end-start,line));
                    start = end;
                }else{
                    end++;
                }
        }
    }
    for (token i :lexem){
        i.print(f);
    }
    
}