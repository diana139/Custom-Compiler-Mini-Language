#ifndef AST_H
#define AST_H

#include <string>
#include <iostream>
#include "SymTable.h"

using namespace std;

class ASTNode {
public:
    string content;         
    string nodeCategory;    
    string expressionType;  

    ASTNode *left;
    ASTNode *right;

    ASTNode(string c, string cat,
            ASTNode* l = nullptr,
            ASTNode* r = nullptr);

    ASTNode() : content(""), nodeCategory(""), expressionType("void"), left(nullptr), right(nullptr) {}

    GenericValue evaluate(SymTable* currentScope);
};

#endif