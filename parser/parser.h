#pragma once
#include<../lexical/lexical.h>
#include "tree.hh"
class parser{
    int start=0;
    int end=0;
    tree<string> tr;
public:
    vector<token> lexem;
    /*bool primary_expression(int p);
    bool constant(int p);
    bool enumeration_constant(int p);
    bool String(int p);
    bool generic_selection(int p);
    bool generic_assoc_list(int p);
    bool generic_association(int p);
    bool postfix_expression(int p);*/
    // bool argument_expression_list(int p);
    // bool unary_expression(int p);
    // bool unary_operator(int p);
    // bool cast_expression(int p);
    // bool multiplicative_expression(int p);
    // bool additive_expression(int p);
    // bool shift_expression(int p);
    // bool relational_expression(int p);
    // bool equality_expression(int p);
    // bool and_expression(int p);
    // bool exclusive_or_expression(int p);
    // bool inclusive_or_expression(int p);
    // bool logical_and_expression(int p);
    // bool logical_or_expression(int p);
    // bool conditional_expression(int p);
    // bool assignment_expression(int p);
    // bool assignment_operator(int p);
    
    // bool constant_expression(int p);
    // bool declaration(int p);
    // bool declaration_specifiers(int p);
    // bool init_declarator_list(int p);
    // bool init_declarator(int p);
    // bool storage_class_specifier(int p);
    // bool type_specifier(int p);
    // bool struct_or_union_specifier(int p);
    // bool struct_or_union(int p);
    // bool struct_declaration_list(int p);
    // bool struct_declaration(int p);
    // bool specifier_qualifier_list(int p);
    // bool struct_declarator_list(int p);
    // bool struct_declarator(int p);
    // bool enum_specifier(int p);
    // bool enumerator_list(int p);
    // bool enumerator(int p);
    // bool atomic_type_specifier(int p);
    // bool type_qualifier(int p);
    // bool function_specifier(int p);
    // bool alignment_specifier(int p);
    // bool declarator(int p);
    // bool direct_declarator(int p);
    // bool pointer(int p);
    // bool type_qualifier_list(int p);
    // bool parameter_type_list(int p);
    // bool parameter_list(int p);
    // bool parameter_declaration(int p);
    // bool identifier_list(int p);
    // bool type_name(int p);
    // bool abstract_declarator(int p);
    // bool direct_abstract_declarator(int p);
    // bool initializer(int p);
    // bool initializer_list(int p);
    // bool designation(int p);
    // bool designator_list(int p);
    // bool designator(int p);
    // bool static_assert_declaration(int p);
    
    // bool labeled_statement(int p);
    
    // bool block_item_list(int p);
    // bool block_item(int p);
    // bool expression_statement(int p);
    
    // bool iteration_statement(int p);
    // bool jump_statement(int p);
    // bool translation_unit(int p);
    // bool external_declaration(int p);
    // bool function_definition(int p);
    // bool declaration_list(int p);
    bool compound_statement(int p);
    bool statement(int p);
    bool expression(int p);
    bool selection_statement(int p);
    void run();
};