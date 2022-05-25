#include "parser.h"
bool parser::primary_expression(int p){

}

/*
constant
	: I_CONSTANT		
	| F_CONSTANT
	| ENUMERATION_CONSTANT
	;
*/
bool parser::constant (int p){
    switch(lexem[p].give_type()){
        case I_CONSTANT:
            p++;
            start = p; 
            return true; 
            break;
        default:return false;
    }
}
/*
string
	: STRING_LITERAL
	| FUNC_NAME
	;
*/
bool parser::String(int p){
    switch(lexem[p].give_type()){
        p++;
        start = p;
        case STRING_LITERAL :return true;break;
        case FUNC_NAME:return true;break;
        default:return false;
    }
}
/*
enumeration_constant
	: IDENTIFIER
	;
*/
bool parser::enumeration_constant(int p){
    switch (lexem[p].give_type())
    {
    case IDENTIFIER:return true;break;
    default:return false;
    }
}
/*
generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	;
*/
bool parser::generic_selection(int p){
    if (   lexem[p].give_type() == GENERIC 
        && lexem[p+1].give_type() == LEFT_BRACKET 
        && assignment_expression(p+2) 
        && lexem[p+3].give_type() == COMMA
        && generic_assoc_list(p+4)
        && lexem[p+5].give_type() == RIGHT_BRACKET
    )
    {
        return true;
    }
    return false;
}
/*
generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;
*/
bool parser::generic_assoc_list(int p){
    if (generic_association(p)){
        return true;
    }else if(generic_assoc_list(p)
        && lexem[p+1].give_type() == COMMA
        && generic_association(p+2)
    ){
        return true;
    }
    return false;

}
/*
generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;
*/
bool parser::generic_association(int p){                
    if (type_name(p) && lexem[p+1].give_type()== COLLON && assignment_expression(p+2)){
        return true;
    }else if (lexem[p].give_type()==DEFAULT && lexem[p+1].give_type()==COLLON && assignment_expression(p+2)){
        return true;
    }
    return false;
}
/*
postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
*/
/*
bool parser::postfix_expression(int p){
    if (primary_expression(p)){
        return true;
    }else if (
        postfix_expression(p) 
        && lexem[p+1].give_type()==LEFT_SQUARE_BRACKET
        && argument_expression_list(p+2)
        && lexem[p+3].give_type()==RIGHT_SQUARE_BRACKET
    ){
        return true;
    }else if (
        postfix_expression(p) 
        && lexem[p+1].give_type()==LEFT_BRACKET
        && lexem[p+2].give_type()==RIGHT_BRACKET
    ){
        return true;
    }else if (
        postfix_expression(p) 
        && lexem[p+1].give_type()==LEFT_BRACKET
        && argument_expression_list(p+2)
        && lexem[p+3].give_type()==RIGHT_BRACKET
    ){
        return true;
    }else if (
        postfix_expression(p)
        && lexem[p+1].give_type()==DOT
        && lexem[p+2].give_type()==IDENTIFIER
    ){
        return true;
    }else if (
        postfix_expression(p)
        && lexem[p+1].give_type()==PTR_OP
        && lexem[p+2].give_type()==IDENTIFIER
    ){
        return true;
    }else if (
        postfix_expression(p)
        && lexem[p+1].give_type()==INC_OP
    ){
        return true;
    }else if (
        postfix_expression(p)
        && lexem[p+1].give_type()==DEC_OP
    ){
        return true;
    }else if (
        
    ){
        return true;
    }else if (

    ){
        return true;
    }
    return false;
    
}
*/
/*
argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;
*/
bool parser::argument_expression_list(int p){
    if (assignment_expression(p)){
        return true;
    }else if (
        argument_expression_list(p)
        &&lexem[p+1].give_type()==COMMA
        &&assignment_expression(p+2)
    ){
        return true;
    }
    return false;
}
/*
unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	| ALIGNOF '(' type_name ')'
	;
*/
/*
bool parser::unary_expression(int p){
    if (postfix_expression(p)){
        return true;
    }else if (
        lexem[p].give_type()==INC_OP
        && unary_expression(p+1)
    ){
        return true;
    }else if (
        lexem[p].give_type()==DEC_OP
        && unary_expression(p+1)
    ){
        return true;
    }else if (
        unary_operator(p)
        && cast_expression(p)
    ){
        
    }else if (

    ){
        
    }else if (

    ){
        
    }else if (

    ){
        
    }
    return false;
}
*/
/*
direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' ')'
	| direct_declarator '(' identifier_list ')'
	;
*/
/*
compound_statement
	: '{' '}'
	| '{'  block_item_list '}'
	;
*/
bool parser::compound_statement(int p){
    if (lexem[p].give_type()==LEFT_CURLY_BRACKET
        &&lexem[p+1].give_type()==RIGHT_CURLY_BRACKET
        ){
            cout<<"compoun";
            end += 2;
            return true;
        }
    return false;
}

/*
selection_statement
	: IF '(' expression ')' statement ELSE statement
	| IF '(' expression ')' statement
	| SWITCH '(' expression ')' statement
	;
*/
bool parser::statement(int p){
    if (compound_statement(p)
    ){
        cout<<"statment";
        end = p;
        return true;
    }
}



bool parser::selection_statement(int p){
    if (lexem[p].give_type() == IF
        && lexem[p+1].give_type() == LEFT_BRACKET
        && expression(p+2)
        && lexem[p+3].give_type() == RIGHT_BRACKET
        && statement(p+4)
        ){
            cout<<"selective";
            end += 4;
            return true;
        }
    return false;
}

/*
statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;
*/




void parser::run(){
    while(end != lexem.size()){
        compound_statement(end);
    }
}