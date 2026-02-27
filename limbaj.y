%code requires {
 
    #include <string>
    #include <vector>
#include "SymTable.h"
    extern SymTable* globalTable;
    extern SymTable* currentClassTable;
    extern SymTable* currentScope;
    extern int errorCount;
}

%{
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include "AST.h"  

#include "SymTable.h"



using namespace std;
vector<ASTNode*> mainBlockASTs;
vector<ASTNode*> globalInitASTs; 

SymTable* globalTable = nullptr;
SymTable* currentClassTable = nullptr;
SymTable* currentScope = nullptr;
string currentExpectedReturnType = "";
int errorCount = 0;

extern FILE* yyin;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
%}


%union {
    int Int;
    float Float;
    char* Str;
    bool BoolVal;
    const char* TypeName;
    std::string* Id;
    struct {
        std::vector<std::string>* list;
    } StrList;
    struct {
        std::vector<std::pair<std::string, std::string>>* params;
    } ParamList;
    struct {
        SymTable* table;
    } Scope;
    struct {
        std::vector<ASTNode*>* nodes;  
    } AstList;
    ASTNode* astNode;
}
%token NEW
%token <Int> NR_INT
%token <Float> NR_FLOAT
%token <Str> STRING_VAL
%token <Id> ID TYPE
%token <BoolVal> BOOL_VAL

%token CLASS FUNCTION RETURN IF WHILE PRINT BGIN END
%token PUBLIC PRIVATE PROTECTED FOR ELSE
%token ASSIGN
%token TRUE FALSE
%token EQ NEQ LT GT LE GE OR AND NOT

%type <astNode> ast_expr ast_simple_stmt
%type <TypeName> expr expr_bool simple_stmt
%type <TypeName> func_item id_start_item func_block
%type <AstList> call_list_ast


%type <StrList> vars call_list
%type <ParamList> list_param param_list param
%type <Id>  func_name

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left '+' '-'
%left '*' '/' '%'
%left NOT
%left '.'
%right UMINUS

%start progr


%%


progr
    : { 
        globalTable = new SymTable("Global", nullptr);
        currentScope = globalTable;
        globalInitASTs.clear();  // <-- ADAUGĂ
      }
      global_definitions 
      {
        cout << "\n========== INITIALIZING GLOBALS ==========\n";
        for(auto ast : globalInitASTs) {
            if(ast) ast->evaluate(globalTable);
        }
        cout << "========== END INITIALIZATION ==========\n\n";
      }
      main_block  
      {
        if (errorCount == 0) {
            cout << "Program corect sintactic si semantic!" << endl;
        }
        
        ofstream outFile("tables.txt");
        if(outFile.is_open()) {
            globalTable->printTable(outFile);
            outFile.close();
            cout << "Symbol tables written to tables.txt (post-execution)" << endl;
        }
      }
    ;
global_definitions
    : /* empty */
    | global_definitions global_decl_var
    | global_definitions class_def
    | global_definitions func_def
    ;

global_decl_var
    : TYPE vars ';' {
        for(auto& id : *$2.list) {
            if(globalTable->existsLocal(id)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Variable '%s' already declared in this scope", id.c_str());
                yyerror(errMsg);
            } else {
                globalTable->addVariable(*$1, id, GenericValue());  
            }
        }
        delete $2.list;
        delete $1;
    }
    | ID ID ';' {
        if(!globalTable->classExists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Type '%s' not declared", $1->c_str());
            yyerror(errMsg);
        }
        if(globalTable->existsLocal(*$2)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' already declared", $2->c_str());
            yyerror(errMsg);
        } else {
            globalTable->addVariable(*$1, *$2, GenericValue());  
        }
        delete $1;
        delete $2;
    }
    | TYPE ID ASSIGN NR_INT ';' {  
        if(!globalTable->existsLocal(*$2)) {
            globalTable->addVariable(*$1, *$2, GenericValue());
        }
        
        ASTNode* idNode = new ASTNode(*$2, "ID");
        idNode->expressionType = *$1;
        
        ASTNode* valNode = new ASTNode(to_string($4), "LITERAL");
        valNode->expressionType = "int";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        assignNode->expressionType = "void";
        
        globalInitASTs.push_back(assignNode);
        
        delete $1;
        delete $2;
    }
    | TYPE ID ASSIGN NR_FLOAT ';' {
        if(!globalTable->existsLocal(*$2)) {
            globalTable->addVariable(*$1, *$2, GenericValue());
        }
        
        ASTNode* idNode = new ASTNode(*$2, "ID");
        idNode->expressionType = *$1;
        
        ASTNode* valNode = new ASTNode(to_string($4), "LITERAL");
        valNode->expressionType = "float";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        globalInitASTs.push_back(assignNode);
        
        delete $1;
        delete $2;
    }
    | TYPE ID ASSIGN STRING_VAL ';' {
        if(!globalTable->existsLocal(*$2)) {
            string strVal = string($4);
            if(strVal.length() >= 2 && strVal[0] == '"' && 
               strVal[strVal.length()-1] == '"') {
                strVal = strVal.substr(1, strVal.length()-2);
            }
            
            GenericValue val(strVal);
            val.type = *$1;
            
            globalTable->addVariable(*$1, *$2, val);
            
            ASTNode* idNode = new ASTNode(*$2, "ID");
            idNode->expressionType = *$1;
            
            ASTNode* valNode = new ASTNode(strVal, "LITERAL");
            valNode->expressionType = "string";
            
            ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
            assignNode->expressionType = "void";
            
            globalInitASTs.push_back(assignNode);
        }
        delete $1;
        delete $2;
        free($4);
    }
    | TYPE ID ASSIGN TRUE ';' {
    if(!globalTable->existsLocal(*$2)) {
        GenericValue val(true);
        val.type = *$1;
        globalTable->addVariable(*$1, *$2, val);
             cout<< "' = true" << endl;
        
        ASTNode* idNode = new ASTNode(*$2, "ID");
        idNode->expressionType = *$1;
        
        ASTNode* valNode = new ASTNode("true", "LITERAL");
        valNode->expressionType = "bool";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        assignNode->expressionType = "void";
        
        globalInitASTs.push_back(assignNode);
    }
    delete $1;
    delete $2;
}
| TYPE ID ASSIGN FALSE ';' {
    if(!globalTable->existsLocal(*$2)) {
        GenericValue val(false);
        val.type = *$1;
        globalTable->addVariable(*$1, *$2, val);
             cout<< "' = false" << endl;
        
        ASTNode* idNode = new ASTNode(*$2, "ID");
        idNode->expressionType = *$1;
        
        ASTNode* valNode = new ASTNode("false", "LITERAL");
        valNode->expressionType = "bool";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        assignNode->expressionType = "void";
        
        globalInitASTs.push_back(assignNode);
    }
    delete $1;
    delete $2;
};


    ;
vars
    : ID {
        $$.list = new vector<string>();
        $$.list->push_back(*$1);
        delete $1;
    }
    | vars ',' ID {
        $1.list->push_back(*$3);
        $$ = $1;
        delete $3;
    }
    ;

class_def
    : CLASS ID
      {
          currentClassTable = new SymTable("Class_" + *$2, globalTable);
          currentScope = currentClassTable; 
      }
      BGIN class_body END
      {
          globalTable->addClass(*$2, currentClassTable);
          currentClassTable = nullptr;
          currentScope = globalTable; 
          delete $2;
      }
    ;

class_body
    : /* empty */
    | class_body access_modifier class_members
    ;

access_modifier
    : PUBLIC | PRIVATE | PROTECTED
    ;

class_members
    : class_member_list
    ;

class_member_list
    : /* empty */
    | class_member_list class_member
    ;

class_member
    : class_field
    | class_method
    | constructor_def
    ;
constructor_def
    : FUNCTION ID '(' ')' BGIN func_block END
    ;
class_field
    : TYPE vars ';' {
        if(currentClassTable == nullptr) {
            yyerror("Internal Error: No active class scope");
        } else {
            for(auto& id : *$2.list) {
                if(currentClassTable->existsLocal(id)) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Field '%s' already declared in class", id.c_str());
                    yyerror(errMsg);
                } else {
                    currentClassTable->addVariable(*$1, id, GenericValue()); // adaugă membru
                }
            }
        }
        delete $2.list;
        delete $1;
    }
    | ID ID ';' {
        if(currentClassTable == nullptr) {
            yyerror("Internal Error: No active class scope");
        } else {
            if(!globalTable->classExists(*$1)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Type '%s' not declared", $1->c_str());
                yyerror(errMsg);
            }
            if(currentClassTable->existsLocal(*$2)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field '%s' already declared", $2->c_str());
                yyerror(errMsg);
            } else {
                currentClassTable->addVariable(*$1, *$2, GenericValue());  
            }
        }
        delete $1;
        delete $2;
    }
    ;

class_method
    : FUNCTION TYPE func_name '(' list_param ')' 
      {
        if (currentClassTable == nullptr) {
            yyerror("Internal Error: currentClassTable is null");
        } else {
            currentClassTable->addFunc(*$2, *$3, *$5.params);
            
            currentExpectedReturnType = *$2;

            SymTable* mScope = new SymTable("Method_" + *$3, currentClassTable);
            for(auto p : *$5.params) {
                mScope->addVariable(p.first, p.second, GenericValue());
            }
            currentClassTable->functionScopes[*$3] = mScope;
            currentScope = mScope;
        }
      }
      BGIN func_block END 
      {
        currentScope = currentClassTable;
        currentExpectedReturnType = "";
        delete $2; delete $3; 
      }
    ;

func_def
    : FUNCTION TYPE func_name '(' list_param ')' 
      {
        currentExpectedReturnType = *$2; 
        SymTable* funcScope = new SymTable("Func_" + *$3, globalTable);
        for(auto p : *$5.params) funcScope->addVariable(p.first, p.second, GenericValue());
        globalTable->functionScopes[*$3] = funcScope; 
        currentScope = funcScope; 
      }
      BGIN func_block END 
      {
        globalTable->addFunc(*$2, *$3, *$5.params);
        currentScope = globalTable; 
        currentExpectedReturnType = ""; 
      }
    
    | FUNCTION ID func_name '(' list_param ')' 
      {
        SymTable* funcScope = new SymTable("Func_" + *$3, globalTable);
        for(auto p : *$5.params) funcScope->addVariable(p.first, p.second,GenericValue());
        
        currentScope = funcScope;
      }
      BGIN func_block END 
      {
        globalTable->addFunc(*$2, *$3, *$5.params);
        currentScope = globalTable; 
      }
    ;

func_name
    : ID { $$ = $1; }
    ;


func_block
    : /* empty */ { $$ = "void"; }
    | func_block func_item { $$ = "void"; }
    ;

func_item
    : TYPE ID ';' {
        if(currentScope->existsLocal(*$2)) {
            yyerror(("Semantic Error: Variable '"+*$2+"' already declared").c_str());
        } else {
            currentScope->addVariable(*$1, *$2, GenericValue()); 
        }
        $$ = strdup("void");     
        delete $1; delete $2;
    }
    | TYPE ID ASSIGN ast_expr ';' {
    if(currentScope->existsLocal(*$2)) {
        yyerror(("Semantic Error: Variable '"+*$2+"' already declared").c_str());
    } else {
        currentScope->addVariable(*$1, *$2, GenericValue());
        
        if(string(*$1) != $4->expressionType) {  
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Type mismatch in initialization of '%s' (expected %s, got %s)",
                    $2->c_str(), $1->c_str(), $4->expressionType.c_str());  
            yyerror(errMsg);
        }
        
        GenericValue initVal = $4->evaluate(currentScope);
        currentScope->setValue(*$2, initVal);
    }
    $$ = strdup("void");  
    delete $1; delete $2;
    delete $4;  
}
    | control_stmt {$$ = strdup("void");   }
    | id_start_item ';' { $$ = $1; }
    | RETURN expr ';'  { 
        if (currentExpectedReturnType != "" && currentExpectedReturnType != string($2)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Return type mismatch. Expected %s, got %s", 
                    currentExpectedReturnType.c_str(), $2);
            yyerror(errMsg);
        }
        $$ = $2; 
    }
    | RETURN expr_bool ';'  {if (currentExpectedReturnType != "" && currentExpectedReturnType != "bool") {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Return type mismatch. Expected %s, got bool", 
                currentExpectedReturnType.c_str());
        yyerror(errMsg);
    }
    $$ = strdup("bool");
    }
    

id_start_item
    : ID ID {
        if(currentScope->existsLocal(*$2)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' already declared", $2->c_str());
            yyerror(errMsg);
        } else {
            currentScope->addVariable(*$1, *$2, GenericValue());
        }
        $$ = strdup($1->c_str());
        delete $1; delete $2;
    }
    | ID ID ASSIGN expr_bool {
        if(currentScope->existsLocal(*$2)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' already declared", $2->c_str());
            yyerror(errMsg);
        } else {
            if(string(*$1) != string($4)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Type mismatch in initialization of '%s' (expected %s, got %s)",
                        $2->c_str(), $1->c_str(), $4);
                yyerror(errMsg);
            }
            currentScope->addVariable(*$1, *$2, "");
        }
        $$ = strdup($4);
        delete $1; delete $2;
    }
    | ID ASSIGN expr_bool {
    if(!currentScope->exists(*$1)) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
        yyerror(errMsg);
    }
    else if(currentScope->getType(*$1) != $3) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s' (expected %s, got %s)",
                $1->c_str(), currentScope->getType(*$1).c_str(), $3);
        yyerror(errMsg);
    }

    $$ = $3;        
    delete $1;
    }
    | ID ASSIGN NEW ID '(' ')' {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
            yyerror(errMsg);
        }
        if(!globalTable->classExists(*$4)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Class '%s' not declared", $4->c_str());
            yyerror(errMsg);
        }
        currentScope->addVariable(*$1, *$4,GenericValue()); 
        $$ = strdup($4->c_str());
        delete $1; delete $4;
    }
    | ID '.' ID ASSIGN expr_bool {
        string classType = currentScope->getType(*$1);
        if(!globalTable->classHasField(classType, *$3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Field '%s' does not exist in class '%s'", $3->c_str(), classType.c_str());
            yyerror(errMsg);
        } else {
            if(globalTable->getFieldType(classType, *$3) != string($5)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field type mismatch for '%s.%s' (expected %s, got %s)",
                        $1->c_str(), $3->c_str(), globalTable->getFieldType(classType, *$3).c_str(), $5);
                yyerror(errMsg);
            }
        }
        $$ = strdup("void");
        delete $1; delete $3;
    }
    | ID '(' call_list ')' {
    if(!globalTable->functionExists(*$1)) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Function '%s' not declared", $1->c_str());
        yyerror(errMsg);
        $$ = "error";
    } else {
        vector<pair<string,string>> expected = globalTable->getFunctionParams(*$1);

        if(expected.size() != $3.list->size()) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)",
                    $1->c_str(), expected.size(), $3.list->size());
            yyerror(errMsg);
        } else {
            for(size_t i = 0; i < expected.size(); i++) {
                if(expected[i].first != (*$3.list)[i]) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)",
                            i+1, $1->c_str(), expected[i].first.c_str(), (*$3.list)[i].c_str());
                    yyerror(errMsg);
                }
            }
        }
        $$ = strdup(globalTable->getFunctionReturnType(*$1).c_str());
    }
    delete $1;
    delete $3.list;
}
    | ID '.' ID '(' call_list ')' {
    string classType;
    if(!currentScope->exists(*$1)) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
        yyerror(errMsg);
        $$ = strdup("error");
    } else {
        classType = currentScope->getType(*$1);
        // Verificăm dacă clasa există
        if(!globalTable->classExists(classType)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Class '%s' not declared", classType.c_str());
            yyerror(errMsg);
            $$ = strdup("error");
        } 
        else {
            // Obținem lista de parametri a metodei
            vector<pair<string,string>> expected = globalTable->getMethodParams(classType, *$3);

            // Verificăm numărul de argumente
            if(expected.size() != $5.list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Wrong number of arguments for method '%s' (expected %lu, got %lu)",
                        $3->c_str(), expected.size(), $5.list->size());
                yyerror(errMsg);
            } 
            else {
                for(size_t i=0; i<expected.size(); i++) {
                    if(expected[i].first != (*$5.list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)",
                                i+1, $3->c_str(), expected[i].first.c_str(), (*$5.list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }

            $$ = strdup(globalTable->getMethodReturnType(classType, *$3).c_str());
        }
    }

    delete $1;
    delete $3;
    delete $5.list;
}

    | PRINT '(' expr ')' {$$ = strdup("void"); delete $3; }
    ;
  
list_param
    : /* empty */ { 
        $$.params = new vector<pair<string, string>>(); 
    }
    | param_list {
        $$ = $1;  
    }
    ;

param_list
    : param {
        $$ = $1;  
    }
    | param_list ',' param {
        $1.params->insert($1.params->end(), $3.params->begin(), $3.params->end());
        $$ = $1;
        delete $3.params;
    }
    ;

param
    : TYPE ID {
        $$.params = new vector<pair<string, string>>();
        $$.params->push_back(make_pair(*$1, *$2));
        delete $1;
        delete $2;
    }
    | ID ID {
        $$.params = new vector<pair<string, string>>();
        $$.params->push_back(make_pair(*$1, *$2));
        delete $1;
        delete $2;
    }
    ;

main_block
    : BGIN {
        mainBlockASTs.clear();
        currentScope = globalTable;
      }
      stmt_list_ast 
      END {
        cout << "\n========== EXECUTING MAIN BLOCK ==========\n";
        
        for(size_t i = 0; i < mainBlockASTs.size(); i++) {
            if(mainBlockASTs[i] == nullptr) {
            } else {

                mainBlockASTs[i]->evaluate(currentScope);
            }
        }
        cout << "========== END EXECUTION ==========\n\n";
      }
    ;


simple_stmt
    : ID ASSIGN expr_bool {
          if(!currentScope->exists(*$1)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Variable '%s' used before declaration", $1->c_str());
              yyerror(errMsg);
          } else if(currentScope->getType(*$1) != string($3)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s' (expected %s, got %s)", $1->c_str(), globalTable->getType(*$1).c_str(), $3);
              yyerror(errMsg);
          }
          $$ = "void";
          delete $1;
      }

    | ID ASSIGN NEW ID '(' ')' {
          if(!currentScope->exists(*$1)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
              yyerror(errMsg);
          }
          if(!globalTable->classExists(*$4)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Class '%s' not declared", $4->c_str());
              yyerror(errMsg);
          }
          // Only check type if variable exists
          else if(currentScope->exists(*$1) && currentScope->getType(*$1) != *$4) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Type mismatch in object creation (expected %s, got %s)", 
                      currentScope->getType(*$1).c_str(), $4->c_str());
              yyerror(errMsg);
          }
          $$ = "void";
          delete $1;
          delete $4;
      }
    | ID '.' ID ASSIGN expr {
          if(!currentScope->exists(*$1)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
              yyerror(errMsg);
          } else {
              string classType = currentScope->getType(*$1);
              if(!globalTable->classHasField(classType, *$3)) {
                  char errMsg[256];
                  sprintf(errMsg, "Semantic Error: Field '%s' does not exist in class '%s'", $3->c_str(), classType.c_str());
                  yyerror(errMsg);
              } else if(currentScope->getFieldType(classType, *$3) != string($5)) {
                  char errMsg[256];
                  sprintf(errMsg, "Semantic Error: Field type mismatch for '%s.%s' (expected %s, got %s)", $1->c_str(), $3->c_str(), globalTable->getFieldType(classType, *$3).c_str(), $5);
                  yyerror(errMsg);
              }
          }
          $$ = "void";
          delete $1;
          delete $3;
      }
    | RETURN expr { $$ = $2; }
    | RETURN expr_bool { $$ = "bool"; }
    | PRINT '(' expr ')' { $$ = "void"; }
     | ID '.' ID '(' call_list ')' { 
    if(!currentScope->exists(*$1)) {
        yyerror("Semantic Error: Variable not declared");
        $$ = strdup("error");
    } else {
        string classType = currentScope->getType(*$1);
        if(!globalTable->classExists(classType)) {
            yyerror("Semantic Error: Class not declared");
            $$ = strdup("error");
        } else {
            vector<pair<string,string>> expected = globalTable->getMethodParams(classType, *$3);
            if(expected.size() != $5.list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Method '%s' expected %lu args, got %lu", $3->c_str(), expected.size(), $5.list->size());
                yyerror(errMsg);
            } else {
                for(size_t i=0; i<expected.size(); i++) {
                    if(expected[i].first != (*$5.list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Arg %lu mismatch (expected %s, got %s)", i+1, expected[i].first.c_str(), (*$5.list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }
            $$ = strdup(globalTable->getMethodReturnType(classType, *$3).c_str());
        }
    }
    delete $1; delete $3; delete $5.list;
     }
    
    | ID '(' call_list ')' {
          if(!globalTable->functionExists(*$1)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Function '%s' not declared", $1->c_str());
              yyerror(errMsg);
          } else {
              vector<pair<string,string>> expected = globalTable->getFunctionParams(*$1);
              if(expected.size() != $3.list->size()) {
                  char errMsg[256];
                  sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)", $1->c_str(), expected.size(), $3.list->size());
                  yyerror(errMsg);
              } else {
                  for(size_t i = 0; i < expected.size(); i++) {
                      if(expected[i].first != (*$3.list)[i]) {
                          char errMsg[256];
                          sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)", i+1, $1->c_str(), expected[i].first.c_str(), (*$3.list)[i].c_str());
                          yyerror(errMsg);
                      }
                  }
              }
          }
          $$ = "void";
          delete $1;
          delete $3.list;
      }
    ;

control_stmt
    : IF '(' expr_bool ')' block_stmts %prec LOWER_THAN_ELSE 
    | IF '(' expr_bool ')' block_stmts ELSE block_stmts
    | WHILE '(' expr_bool ')' block_stmts
    | FOR '(' simple_stmt ';' expr_bool ';' simple_stmt ')' block_stmts
    ;

expr
    : '-' expr %prec UMINUS {
        // Verificăm tipul expresiei
        if(string($2) == "int") {
            $$ = strdup("int");
        } else if(string($2) == "float") {
            $$ = strdup("float");
        } else {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Unary '-' not allowed on type %s", $2);
            yyerror(errMsg);
            $$ = strdup("error");
        }
    }
    | expr '+' expr {
        if(string($1) != string($3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '+' (got %s and %s)", $1, $3);
            yyerror(errMsg);
        }
        $$ = $1;
    }
    | expr '-' expr {
        if(string($1) != string($3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '-' (got %s and %s)", $1, $3);
            yyerror(errMsg);
        }
        $$ = $1;
    }
    | expr '*' expr {
        if(string($1) != string($3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '*' (got %s and %s)", $1, $3);
            yyerror(errMsg);
        }
        $$ = $1;
    }
    | expr '/' expr {
        if(string($1) != string($3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '/' (got %s and %s)", $1, $3);
            yyerror(errMsg);
        }
        $$ = $1;
    }
    | expr '%' expr {
        if(string($1) != string($3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '%%' (got %s and %s)", $1, $3);
            yyerror(errMsg);
        }
        $$ = $1;
    }
    | '(' expr ')' { $$ = $2; }
    | NR_INT { $$ = "int"; }
    | NR_FLOAT { $$ = "float"; }
    | STRING_VAL { $$ = "string"; }
    | ID {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' undefined", $1->c_str());
            yyerror(errMsg);
            $$ = "error";
        } else {
            $$ = strdup(currentScope->getType(*$1).c_str());
        }
        delete $1;
    }
    | ID '.' ID {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
            yyerror(errMsg);
            $$ = "error";
        } else {
            string classType = globalTable->getType(*$1);
            if(!globalTable->classHasField(classType, *$3)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field '%s' not found in class '%s'", $3->c_str(), classType.c_str());
                yyerror(errMsg);
                $$ = "error";
            } else {
                $$ = strdup(globalTable->getFieldType(classType, *$3).c_str());
            }
        }
        delete $1;
        delete $3;
    }
    | ID '.' ID '(' call_list ')' { 
    if(!currentScope->exists(*$1)) {
        yyerror("Semantic Error: Variable not declared");
        $$ = strdup("error");
    } else {
        string classType = currentScope->getType(*$1);
        if(!globalTable->classExists(classType)) {
            yyerror("Semantic Error: Class not declared");
            $$ = strdup("error");
        } else {
            vector<pair<string,string>> expected = globalTable->getMethodParams(classType, *$3);
            if(expected.size() != $5.list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Method '%s' expected %lu args, got %lu", $3->c_str(), expected.size(), $5.list->size());
                yyerror(errMsg);
            } else {
                for(size_t i=0; i<expected.size(); i++) {
                    if(expected[i].first != (*$5.list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Arg %lu mismatch (expected %s, got %s)", i+1, expected[i].first.c_str(), (*$5.list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }
            $$ = strdup(globalTable->getMethodReturnType(classType, *$3).c_str());
        }
    }
    delete $1; delete $3; delete $5.list;

}
    | ID '(' call_list ')' {
        if(!globalTable->functionExists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Function '%s' not declared", $1->c_str());
            yyerror(errMsg);
            $$ = "error";
        } else {
            vector<pair<string,string>> expected = globalTable->getFunctionParams(*$1);
            if(expected.size() != $3.list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)", $1->c_str(), expected.size(), $3.list->size());
                yyerror(errMsg);
            } else {
                for(size_t i = 0; i < expected.size(); i++) {
                    if(expected[i].first != (*$3.list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)", i+1, $1->c_str(), expected[i].first.c_str(), (*$3.list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }
            $$ = strdup(globalTable->getFunctionReturnType(*$1).c_str());
        }
        delete $1;
        delete $3.list;
    }
    ;

expr_bool
    : TRUE { $$ = "bool"; }
    | FALSE { $$ = "bool"; }
    | expr comp expr {
        if(string($1) != string($3)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison operands must have the same type (got %s and %s)", $1, $3);
            yyerror(errMsg);
        }
        $$ = "bool";  
    }
    | expr_bool AND expr_bool { $$ = "bool"; }
    | expr_bool OR expr_bool { $$ = "bool"; }
    | NOT expr_bool { $$ = "bool"; }
    | '(' expr_bool ')' { $$ = $2; }
    ;
  
 stmt_list_ast
    : /* empty */
    | stmt_list_ast statement_ast
    ;


statement_ast
    : ast_simple_stmt ';' {
        mainBlockASTs.push_back($1);
    }
    | control_stmt {
        mainBlockASTs.push_back(nullptr);
    }
    | TYPE ID ASSIGN ast_expr ';' {
    
    if(!currentScope->existsLocal(*$2)) {
        currentScope->addVariable(*$1, *$2, GenericValue());
    }
    
    ASTNode* idNode = new ASTNode(*$2, "ID");
    idNode->expressionType = *$1;
    
    ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, $4);
    assignNode->expressionType = "void";
    
    mainBlockASTs.push_back(assignNode);
    delete $1;
    delete $2;
}
    | TYPE vars ';' {
        mainBlockASTs.push_back(nullptr);
        delete $1;
        delete $2.list;
    }
     
    ;

ast_simple_stmt
    :  ID ASSIGN NEW ID '(' ')' {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
            yyerror(errMsg);
        }
        if(!globalTable->classExists(*$4)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Class '%s' not declared", $4->c_str());
            yyerror(errMsg);
        }
        
        ASTNode* idNode = new ASTNode(*$1, "ID");
        ASTNode* classNode = new ASTNode("new " + *$4, "OTHER");
        classNode->expressionType = *$4;
        
        $$ = new ASTNode("<-", "STATEMENT", idNode, classNode);
        $$->expressionType = "void";
        delete $1;
        delete $4;
    }
    | ID ASSIGN ast_expr {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
            yyerror(errMsg);
        } else {
            string lhsType = currentScope->getType(*$1);
            string rhsType = $3->expressionType;

            if(lhsType != rhsType) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s' (expected %s, got %s)",
                        $1->c_str(), lhsType.c_str(), rhsType.c_str());
                yyerror(errMsg);
            }
        }

        ASTNode* idNode = new ASTNode(*$1, "ID");
        idNode->expressionType = currentScope->exists(*$1) ? 
            currentScope->getType(*$1) : "error";
        
        $$ = new ASTNode("<-", "STATEMENT", idNode, $3);
        $$->expressionType = "void";
        delete $1;
    }
    | ID '.' ID ASSIGN ast_expr {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
            yyerror(errMsg);
        } else {
            string classType = currentScope->getType(*$1);
            if(!globalTable->classHasField(classType, *$3)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field '%s' does not exist in class '%s'",
                        $3->c_str(), classType.c_str());
                yyerror(errMsg);
            } else {
                string lhsType = globalTable->getFieldType(classType, *$3);
                string rhsType = $5->expressionType;
                if(lhsType != rhsType) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s.%s' (expected %s, got %s)",
                            $1->c_str(), $3->c_str(), lhsType.c_str(), rhsType.c_str());
                    yyerror(errMsg);
                }
            }
        }

        ASTNode* objNode = new ASTNode(*$1, "ID");
        ASTNode* fieldNode = new ASTNode(*$3, "FIELD");
        ASTNode* lhs = new ASTNode(".", "ACCESS", objNode, fieldNode);

        $$ = new ASTNode("<-", "STATEMENT", lhs, $5);
        $$->expressionType = "void";

        delete $1;
        delete $3;
    }

    | PRINT '(' ast_expr ')' {
        $$ = new ASTNode("Print", "STATEMENT", $3, nullptr);
        $$->expressionType = "void";
    }
    |
    RETURN ast_expr {
        $$ = new ASTNode("Return", "STATEMENT", $2, nullptr);
        if($2) $$->expressionType = $2->expressionType;
        else $$->expressionType = "void";
    }
    
    ;
ast_expr
    : NR_INT { 
        $$ = new ASTNode(to_string($1), "LITERAL");
        $$->expressionType = "int";
    }
    | NR_FLOAT { 
        $$ = new ASTNode(to_string($1), "LITERAL");
        $$->expressionType = "float";
    }
    | STRING_VAL {  
        $$ = new ASTNode(string($1), "LITERAL");
        $$->expressionType = "string";
        free($1);
    }
    | TRUE {
        $$ = new ASTNode("true", "LITERAL");
        $$->expressionType = "bool";
    }
    | FALSE {
        $$ = new ASTNode("false", "LITERAL");
        $$->expressionType = "bool";
    }

    | ast_expr GT ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '>' requires same types (got %s and %s)", $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode(">", "OP", $1, $3);
        $$->expressionType = "bool";
    }
    | ast_expr LT ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '<' requires same types (got %s and %s)", $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("<", "OP", $1, $3);
        $$->expressionType = "bool";
    }
    | ast_expr EQ ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '==' requires same types (got %s and %s)", $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("==", "OP", $1, $3);
        $$->expressionType = "bool";
    }
    | ast_expr NEQ ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '!=' requires same types (got %s and %s)", $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("!=", "OP", $1, $3);
        $$->expressionType = "bool";
    }
    | ast_expr GE ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '>=' requires same types (got %s and %s)", $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode(">=", "OP", $1, $3);
        $$->expressionType = "bool";
    }
    | ast_expr LE ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '<=' requires same types (got %s and %s)", $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("<=", "OP", $1, $3);
        $$->expressionType = "bool";
    }
    | ID {
        $$ = new ASTNode(*$1, "ID");
        $$->expressionType = currentScope->exists(*$1) ? 
            currentScope->getType(*$1) : "error";
        delete $1;
    }
    | ID '.' ID '(' call_list_ast ')' {
        if(!currentScope->exists(*$1)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", $1->c_str());
            yyerror(errMsg);
        }
        string classType = currentScope->exists(*$1) ? 
            currentScope->getType(*$1) : "error";
        string returnType = "error";
        if(globalTable->classExists(classType)) {
            returnType = globalTable->getMethodReturnType(classType, *$3);
        }
        string methodCallInfo = *$1 + "." + *$3;
        ASTNode* methodCallNode = new ASTNode(methodCallInfo, "OTHER");
        methodCallNode->expressionType = returnType;
        if (!$5.nodes->empty()) methodCallNode->left = (*$5.nodes)[0];
        $$ = methodCallNode;
        delete $1;
        delete $3;
        delete $5.nodes;
    }
    | ID '(' call_list_ast ')' {  
    if(!globalTable->functionExists(*$1)) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Function '%s' not declared", $1->c_str());
        yyerror(errMsg);
        $$ = new ASTNode("error", "ERROR");
    } else {
        string returnType = globalTable->getFunctionReturnType(*$1);

        vector<pair<string,string>> expected = globalTable->getFunctionParams(*$1); // pereche (tip, nume)
        if(expected.size() != $3.nodes->size()) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)",
                    $1->c_str(), expected.size(), $3.nodes->size());
            yyerror(errMsg);
        } else {
            for(size_t i = 0; i < expected.size(); i++) {
                string argType = (*$3.nodes)[i]->expressionType;
                if(expected[i].first != argType) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)",
                            i+1, $1->c_str(), expected[i].first.c_str(), argType.c_str());
                    yyerror(errMsg);
                }
            }
        }

        ASTNode* funcCallNode = new ASTNode(*$1 + "()", "CALL");
        funcCallNode->expressionType = returnType;

        if (!$3.nodes->empty()) {
            funcCallNode->left = (*$3.nodes)[0];
            if ($3.nodes->size() > 1) funcCallNode->right = (*$3.nodes)[1];
        }

        $$ = funcCallNode;
    }

    delete $1;
    delete $3.nodes;
}
    | ID '.' ID {
        if(!currentScope->exists(*$1)) {
            yyerror("Semantic Error: Object not declared");
            $$ = new ASTNode("error", "ERROR");
        } else {
            string classType = currentScope->getType(*$1);
            if(!globalTable->classHasField(classType, *$3)) {
                yyerror("Semantic Error: Field not found");
                $$ = new ASTNode("error", "ERROR");
            } else {
                string fType = globalTable->getFieldType(classType, *$3);
                ASTNode* obj = new ASTNode(*$1, "ID");
                ASTNode* field = new ASTNode(*$3, "FIELD");
                $$ = new ASTNode(".", "ACCESS", obj, field);
                $$->expressionType = fType; // Foarte important pentru oba.x * oba.y
            }
        }
        delete $1; delete $3;
    }

    | ast_expr '+' ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '+' must have the same type (got %s and %s)",
                    $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("+", "OP", $1, $3);
        $$->expressionType = $1->expressionType;
    }
    | ast_expr '-' ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '-' must have the same type (got %s and %s)",
                    $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("-", "OP", $1, $3);
        $$->expressionType = $1->expressionType;
    }
    | ast_expr '*' ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '*' must have the same type (got %s and %s)",
                    $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("*", "OP", $1, $3);
        $$->expressionType = $1->expressionType;
    }
    | ast_expr '/' ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '/' must have the same type (got %s and %s)",
                    $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("/", "OP", $1, $3);
        $$->expressionType = $1->expressionType;
    }
    | ast_expr '%' ast_expr {
        if($1->expressionType != $3->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '%%' must have the same type (got %s and %s)",
                    $1->expressionType.c_str(), $3->expressionType.c_str());
            yyerror(errMsg);
        }
        $$ = new ASTNode("%", "OP", $1, $3);
        $$->expressionType = $1->expressionType;
    }
    | '(' ast_expr ')' { 
        $$ = $2; 
    }
    |ast_expr AND ast_expr {
        if ($1->expressionType != "bool" || $3->expressionType != "bool") {
            yyerror("Operands of 'AND' must be bool");
            $$ = new ASTNode("AND", "OP");
            $$->expressionType = "error";
        } else {
            $$ = new ASTNode("AND", "OP", $1, $3);
            $$->expressionType = "bool";
        }
    }
    | ast_expr OR ast_expr {
        if ($1->expressionType != "bool" || $3->expressionType != "bool") {
            yyerror("Operands of 'OR' must be bool");
            $$ = new ASTNode("OR", "OP");
            $$->expressionType = "error";
        } else {
            $$ = new ASTNode("OR", "OP", $1, $3);
            $$->expressionType = "bool";
        }
    }
    | NOT ast_expr {
        if ($2->expressionType != "bool") {
            yyerror("Operand of 'NOT' must be bool");
            $$ = new ASTNode("NOT", "OP");
            $$->expressionType = "error";
        } else {
            $$ = new ASTNode("NOT", "OP", $2, nullptr);
            $$->expressionType = "bool";
        }
    }
    
    ;

comp : EQ | LE | GE | GT | LT | NEQ ;

call_list
    : /* empty */ { 
        $$.list = new vector<string>(); 
    }
    | expr {
        $$.list = new vector<string>();
        $$.list->push_back($1);
    }
    | call_list ',' expr {
        $1.list->push_back($3);
        $$ = $1;
    }
    ;
call_list_ast
    : /* empty */ { 
        $$.nodes = new vector<ASTNode*>(); 
    }
    | ast_expr {
        $$.nodes = new vector<ASTNode*>();
        $$.nodes->push_back($1);
    }
    | call_list_ast ',' ast_expr {
        $1.nodes->push_back($3);
        $$ = $1;
    }
    ;
block_stmts 
    : BGIN stmt_list_ast END 
    ;


%%

void yyerror(const char * s){
    errorCount++;
    fprintf(stderr, "Error: %s at line: %d\n", s, yylineno);
}

int main(int argc, char** argv){
    if(argc < 2) {
        cout << "Usage: ./minilang file\n";
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if(!yyin) {
        perror("File opening failed");
        return 1;
    }
    yyparse();
    return 0;
}