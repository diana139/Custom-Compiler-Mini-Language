%{
#include <stdio.h>
#include "AST.h"
#include "limbaj.tab.h"
#include <string>
#include <iostream>
using namespace std;
%}

%option noyywrap
%option yylineno

digit       [0-9]
id          [a-zA-Z_][a-zA-Z0-9_]*
ws          [ \t]+

%%

"int"               { yylval.Id = new std::string(yytext); return TYPE; }
"float"             { yylval.Id = new std::string(yytext); return TYPE; }
"string"            { yylval.Id = new std::string(yytext); return TYPE; }
"bool"              { yylval.Id = new std::string(yytext); return TYPE; }
"void"              { yylval.Id = new std::string(yytext); return TYPE; }

"class"             { return CLASS; }
"public"            { return PUBLIC; }
"private"           { return PRIVATE; }
"protected"         { return PROTECTED; }
"function"          { return FUNCTION; }
"return"            { return RETURN; }
"verify"            { return IF; }
"doesn't_verify"    { return ELSE; }
"loop"              { return WHILE; }
"counted_steps"     { return FOR; }
"Print"             { return PRINT; }
"new"               { return NEW; }
"begin"             { return BGIN; }
"end"               { return END; }

"true"              { return TRUE; }
"false"             { return FALSE; }

"<-"        { return ASSIGN; }
"=="        { return EQ; }
"!="        { return NEQ; }
">="        { return GE; }
"<="       { return LE; }
">"         { return GT; }
"<"         { return LT; }
"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
"."         { return '.'; }
","         { return ','; }
";"         { return ';'; }
"("         { return '('; }
")"         { return ')'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"%"         {return '%';}

\"[^\"]*\"            { yylval.Str = strdup(yytext); return STRING_VAL; }
{digit}+\.{digit}+ { yylval.Float = atof(yytext); return NR_FLOAT; }
{digit}+           { yylval.Int = atoi(yytext); return NR_INT; }



{id}                  { yylval.Id = new std::string(yytext); return ID; }

{ws}        ;
\n          ;
.           { printf("Eroare Lex: caracter necunoscut %s\n", yytext); return yytext[0]; }

%%