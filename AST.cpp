#include "AST.h"
#include "SymTable.h"
#include <cstdlib>
#include <iostream>

ASTNode::ASTNode(std::string c, std::string cat, ASTNode* l, ASTNode* r) {
    content = c;
    nodeCategory = cat;
    left = l;
    right = r;
    expressionType = "void";
}

GenericValue ASTNode::evaluate(SymTable* currentScope) {
    if (!currentScope) return GenericValue();

    if (!left && !right) {
        if (nodeCategory == "LITERAL") {
            if (expressionType == "int") return GenericValue(std::stoi(content));
            if (expressionType == "float") return GenericValue((float)std::atof(content.c_str()));
            if (expressionType == "bool") return GenericValue(content == "true");
            if (expressionType == "string") {
                std::string cleaned = content;
                if (cleaned.size() >= 2 && cleaned.front() == '"' && cleaned.back() == '"')
                    cleaned = cleaned.substr(1, cleaned.size() - 2);
                return GenericValue(cleaned);
            }
        }

        if (nodeCategory == "ID") {
            SymTable* scope = currentScope;
            while(scope) {
                if(scope->existsLocal(content)) 
                    return scope->getValue(content);
                scope = scope->parent;
            }
            std::cerr << "[ERROR] Undefined variable: " << content << std::endl;
            return GenericValue();
        }

if (nodeCategory == "OTHER") {
    if (content.find("new ") == 0) {
        std::string className = content.substr(4); 
        
        GenericValue objValue;
        objValue.type = className;
        objValue.sVal = className + "_instance";
        return objValue;
    }
    
    if (expressionType == "int") return GenericValue(0);
    if (expressionType == "float") return GenericValue(0.0f);
    if (expressionType == "bool") return GenericValue(false);
    if (expressionType == "string") return GenericValue("");
}
        return GenericValue();
    }

if (content == "<-") {
    GenericValue val = right->evaluate(currentScope);
    
    if (val.type == "int") std::cout << (int)val.nVal;
    else if (val.type == "float") std::cout << val.nVal;
    else if (val.type == "bool") std::cout << (val.bVal ? "true" : "false");
    else if (val.type == "string") std::cout << val.sVal;
    else std::cout << val.type;
    std::cout << std::endl;
    
    SymTable* scope = currentScope;
    while(scope) {
        if(scope->existsLocal(left->content)) {
            scope->setValue(left->content, val);
            return val;
        }
        scope = scope->parent;
    }
    std::cerr << "[ERROR] Cannot assign to undefined variable: " << left->content << std::endl;
    return val;
}

    if (content == "Print") {
        GenericValue val = left->evaluate(currentScope);
        std::cout << "[PRINT]: ";
        if (val.type == "void" || val.type.empty()) std::cout << "undefined";
        else if (val.type == "int") std::cout << (int)val.nVal;
        else if (val.type == "float") std::cout << val.nVal;
        else if (val.type == "bool") std::cout << (val.bVal ? "true" : "false");
        else if (val.type == "string") std::cout << val.sVal;
        std::cout << std::endl;
        return val;
    }

    GenericValue L = left ? left->evaluate(currentScope) : GenericValue();
    GenericValue R = right ? right->evaluate(currentScope) : GenericValue();

    if (content == "+") return (L.type == "string") ? GenericValue(L.sVal + R.sVal) :
                               (L.type == "int") ? GenericValue((int)L.nVal + (int)R.nVal) :
                               GenericValue(L.nVal + R.nVal);
    if (content == "-") return GenericValue(L.nVal - R.nVal);
    if (content == "*") return GenericValue(L.nVal * R.nVal);
    if (content == "/") return GenericValue(R.nVal != 0 ? (L.nVal / R.nVal) : 0.0f);
    if (content == "%") return GenericValue((int)L.nVal % (int)R.nVal);

    if (content == ">" ) return GenericValue(L.nVal > R.nVal);
    if (content == "<" ) return GenericValue(L.nVal < R.nVal);
    if (content == "==") return GenericValue(L.nVal == R.nVal);
    if (content == "!=") return GenericValue(L.nVal != R.nVal);
    if (content == ">=") return GenericValue(L.nVal >= R.nVal);
    if (content == "<=") return GenericValue(L.nVal <= R.nVal);

    if (content == "&&" || content == "AND") return GenericValue(L.bVal && R.bVal);
    if (content == "||" || content == "OR") return GenericValue(L.bVal || R.bVal);
    if (content == "!" || content == "NOT") return GenericValue(!L.bVal);

    return GenericValue();
}