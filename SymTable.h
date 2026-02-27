#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

struct GenericValue {
    string type;        
    double nVal;
    bool bVal;
    string sVal;

    GenericValue() : type("void"), nVal(0), bVal(false), sVal("") {}
    GenericValue(int v) : type("int"), nVal(v), bVal(false), sVal("") {}
    GenericValue(float v) : type("float"), nVal(v), bVal(false), sVal("") {}
    GenericValue(double v) : type("float"), nVal(v), bVal(false), sVal("") {}
    GenericValue(bool v) : type("bool"), nVal(0), bVal(v), sVal("") {}
    GenericValue(string v) : type("string"), nVal(0), bVal(false), sVal(v) {}
};

struct IdInfo {
    string name;
    string type;          
   GenericValue value;


    bool isFunction;
    string returnType;
    vector<pair<string, string>> params; 

    IdInfo() : isFunction(false), value(GenericValue()) {}

    IdInfo(string n, string t, GenericValue v = GenericValue())
    : name(n), type(t), value(v), isFunction(false) {}

    IdInfo(string n, string retT, vector<pair<string, string>> p) 
        : name(n), returnType(retT), params(p), isFunction(true) {}
};

class SymTable {
public:
    string tableName;
    SymTable* parent;
    map<string, IdInfo> ids;
    map<string, SymTable*> classScopes; 
    map<string, SymTable*> functionScopes;
    
    SymTable(string name, SymTable* p = nullptr);
    ~SymTable();

    void addVariable(string type, string name, GenericValue value = GenericValue());

    void addFunc(string returnType, string name, vector<pair<string, string>> params);
    void addClass(string name, SymTable* classScope);

    GenericValue getValue(string id);
    void setValue(string id, GenericValue val);
    
    bool existsLocal(string name);
    bool exists(string name);
    bool functionExists(string name);
    bool classExists(string name);

    SymTable* getClassScope(string className);
    string getType(string name);               
    string getFunctionReturnType(string name); 
    vector<pair<string, string>> getFunctionParams(string name); 
    string getFieldType(string className, string fieldName);

    bool classHasField(string className, string fieldName);

    void printTable(ostream& out);
    string getMethodReturnType(string className, string methodName); 
    vector<pair<string, string>> getMethodParams(string className, string methodName);
};

#endif