%{
#include "tree.h"
#include "syntax.tab.h"
#include "string.h"

int yycolumn = 1;

/* 维护行号和列号，用于报错 */
#define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_line = yylineno; \
    yylloc.last_column = yycolumn + yyleng; \
    yycolumn += yyleng;

/* 创建终结符节点 */
Node* create_token_node(char* name, int lineno) {
    Node* p = new_node(name, lineno);
    p->val.text = strdup(yytext);
    return p;
}
%}

%option yylineno

/* 正则定义 */
ws      [ \t\r]+
digit   [0-9]
letter  [_a-zA-Z]
INT     0|[1-9]{digit}*
FLOAT   {digit}+\.{digit}+
ID      {letter}({letter}|{digit})*

%%

{ws}        { }
"\n"        { yycolumn = 1; }

"int"       { yylval.node = create_token_node("TYPE", yylineno); return TYPE; }
"float"     { yylval.node = create_token_node("TYPE", yylineno); return TYPE; }
"char"      { yylval.node = create_token_node("TYPE", yylineno); return TYPE; }
"struct"    { yylval.node = create_token_node("STRUCT", yylineno); return STRUCT; }
"return"    { yylval.node = create_token_node("RETURN", yylineno); return RETURN; }
"if"        { yylval.node = create_token_node("IF", yylineno); return IF; }
"else"      { yylval.node = create_token_node("ELSE", yylineno); return ELSE; }
"while"     { yylval.node = create_token_node("WHILE", yylineno); return WHILE; }

{INT}       { 
              yylval.node = create_token_node("INT", yylineno); 
              yylval.node->val.int_val = atoi(yytext);
              return INT; 
            }
{FLOAT}     { 
              yylval.node = create_token_node("FLOAT", yylineno); 
              yylval.node->val.float_val = atof(yytext);
              return FLOAT; 
            }
{ID}        { yylval.node = create_token_node("ID", yylineno); return ID; }

";"         { yylval.node = create_token_node("SEMI", yylineno); return SEMI; }
","         { yylval.node = create_token_node("COMMA", yylineno); return COMMA; }
"="         { yylval.node = create_token_node("ASSIGN", yylineno); return ASSIGN; }
"<"         { yylval.node = create_token_node("RELOP", yylineno); return RELOP; }
">"         { yylval.node = create_token_node("RELOP", yylineno); return RELOP; }
"<="        { yylval.node = create_token_node("RELOP", yylineno); return RELOP; }
">="        { yylval.node = create_token_node("RELOP", yylineno); return RELOP; }
"=="        { yylval.node = create_token_node("RELOP", yylineno); return RELOP; }
"!="        { yylval.node = create_token_node("RELOP", yylineno); return RELOP; }
"+"         { yylval.node = create_token_node("PLUS", yylineno); return PLUS; }
"-"         { yylval.node = create_token_node("MINUS", yylineno); return MINUS; }
"*"         { yylval.node = create_token_node("STAR", yylineno); return STAR; }
"/"         { yylval.node = create_token_node("DIV", yylineno); return DIV; }
"&&"        { yylval.node = create_token_node("AND", yylineno); return AND; }
"||"        { yylval.node = create_token_node("OR", yylineno); return OR; }
"."         { yylval.node = create_token_node("DOT", yylineno); return DOT; }
"!"         { yylval.node = create_token_node("NOT", yylineno); return NOT; }
"("         { yylval.node = create_token_node("LP", yylineno); return LP; }
")"         { yylval.node = create_token_node("RP", yylineno); return RP; }
"["         { yylval.node = create_token_node("LB", yylineno); return LB; }
"]"         { yylval.node = create_token_node("RB", yylineno); return RB; }
"{"         { yylval.node = create_token_node("LC", yylineno); return LC; }
"}"         { yylval.node = create_token_node("RC", yylineno); return RC; }

.           { printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); }

%%

int yywrap() { return 1; }