#include "SymTable.h"
#include "AST.h" 
#include <iomanip>

SymTable::SymTable(string name, SymTable* p) {
    tableName = name;
    parent = p;
}

SymTable::~SymTable() {
    for (auto& pair : classScopes) {
        delete pair.second;
    }
    for (auto& pair : functionScopes) {  
        delete pair.second;
    }
}

void SymTable::addVariable(string type, string name, GenericValue value) {
    ids[name] = IdInfo(name, type, value);
}


void SymTable::addFunc(string returnType, string name, vector<pair<string, string>> params) {
    ids[name] = IdInfo(name, returnType, params);
}

void SymTable::addClass(string name, SymTable* classScope) {
    ids[name] = IdInfo(name, "class");
    classScopes[name] = classScope;
}

bool SymTable::existsLocal(string name) {
    return ids.find(name) != ids.end();
}

bool SymTable::exists(string name) {
    auto it = ids.find(name);
    if (it != ids.end() && !it->second.isFunction)
        return true;
    if (existsLocal(name)) return true;
    if (parent)
        return parent->exists(name);
    return false;
}

bool SymTable::functionExists(string name) {
    auto it = ids.find(name);
    if (it != ids.end() && it->second.isFunction)
        return true;
    if (parent)
        return parent->functionExists(name);
    return false;
}

bool SymTable::classExists(string name) {
    auto it = ids.find(name);
    if (it != ids.end() && it->second.type == "class")
        return true;
    if (parent)
        return parent->classExists(name);
    return false;
}

string SymTable::getType(string name) {
    auto it = ids.find(name);
    if (it != ids.end())
        return it->second.type;
    if (parent)
        return parent->getType(name);
    return "undefined_type";
}

string SymTable::getFunctionReturnType(string name) {
    auto it = ids.find(name);
    if (it != ids.end() && it->second.isFunction)
        return it->second.returnType;
    if (parent)
        return parent->getFunctionReturnType(name);
    return "undefined_ret_type";
}

vector<pair<string, string>> SymTable::getFunctionParams(string name) {
    auto it = ids.find(name);
    if (it != ids.end() && it->second.isFunction)
        return it->second.params;
    if (parent)
        return parent->getFunctionParams(name);
    return {};
}

bool SymTable::classHasField(string className, string fieldName) {
    if (classScopes.count(className)) {
        return classScopes[className]->ids.count(fieldName);
    }
    if (parent)
        return parent->classHasField(className, fieldName);
    return false;
}

SymTable* SymTable::getClassScope(string className) {
    if (classScopes.count(className))
        return classScopes[className];
    if (parent)
        return parent->getClassScope(className);
    return nullptr;
}

string SymTable::getFieldType(string className, string fieldName) {
    if (classScopes.count(className)) {
        auto scope = classScopes[className];
        auto it = scope->ids.find(fieldName);
        if (it != scope->ids.end())
            return it->second.type;
    }
    if (parent)
        return parent->getFieldType(className, fieldName);
    return "undefined_field";
}

string SymTable::getMethodReturnType(string className, string methodName) {
    if (classScopes.count(className)) {
        auto scope = classScopes[className];
        auto it = scope->ids.find(methodName);
        if (it != scope->ids.end() && it->second.isFunction)
            return it->second.returnType;
    }
    if (parent)
        return parent->getMethodReturnType(className, methodName);
    return "undefined_method";
}

vector<pair<string, string>> SymTable::getMethodParams(string className, string methodName) {
    if (classScopes.count(className)) {
        auto scope = classScopes[className];
        auto it = scope->ids.find(methodName);
        if (it != scope->ids.end() && it->second.isFunction)
            return it->second.params;
    }
    if (parent)
        return parent->getMethodParams(className, methodName);
    return {};
}

GenericValue SymTable::getValue(string id) {
    if (ids.count(id))
        return ids[id].value;
    if (parent)
        return parent->getValue(id);
    return GenericValue();
}

        

void SymTable::setValue(string id, GenericValue val) {
    if(ids.find(id) != ids.end()) {
        ids[id].value = val;
        return;
    }
    if(parent) {
        parent->setValue(id, val);
        return;
    }
    cerr << "[ERROR] Variable '" << id << "' not declared in any accessible scope\n";
}

void SymTable::printTable(ostream& out) {
    out << "\n========================================\n";
    out << "Symbol Table: " << tableName << "\n";
    out << "Parent Scope: " << (parent ? parent->tableName : "None (Global)") << "\n";
    out << "========================================\n";

    if (!ids.empty()) {
        out << "\nIdentifiers:\n";
        out << left << setw(20) << "Name"
            << setw(15) << "Category"
            << setw(15) << "Type/Return"
            << "Details\n";
        out << string(70, '-') << "\n";

        for (auto& pair : ids) {
            IdInfo& info = pair.second;
            out << left << setw(20) << info.name;

            if (info.isFunction) {
                out << setw(15) << "Function"
                    << setw(15) << info.returnType
                    << "Parameters: ";
                if (info.params.empty()) {
                    out << "none";
                } else {
                    for (size_t i = 0; i < info.params.size(); i++) {
                        out << info.params[i].first << " " << info.params[i].second;
                        if (i + 1 < info.params.size())
                            out << ", ";
                    }
                }
            } else if (info.type == "class") {
                out << setw(15) << "Class"
                    << setw(15) << "class"
                    << "Definition";
            }else {
                out << setw(15) << "Variable"
                    << setw(15) << info.type
                    << "Value: ";
                    if (info.value.type != "void" && info.value.type != "int" && 
                        info.value.type != "float" && info.value.type != "bool" && 
                        info.value.type != "string" && info.value.type != "class") {
                        out << "Object of class " << info.value.type;
                    }
                if (info.value.type == "void") {
                    out << "undefined";
                }
                else if (info.value.type == "string" && info.value.sVal.empty()) {
                    out << "undefined";
                }
                else if (info.value.type == "int")
                    out << (int)info.value.nVal;
                else if (info.value.type == "float")
                    out << info.value.nVal;
                else if (info.value.type == "bool")
                    out << (info.value.bVal ? "true" : "false");
                else if (info.value.type == "string")
                    out << "\"" << info.value.sVal << "\"";
                else
                    out << "undefined";
            }
            
            out << "\n";
        }
    } else {
        out << "\nNo identifiers in this scope.\n";
    }

    for (auto& pair : classScopes) {
        pair.second->printTable(out);
    }
    for (auto& pair : functionScopes) {
        pair.second->printTable(out);
    }
}