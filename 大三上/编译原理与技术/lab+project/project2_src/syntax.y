%{
#include <stdio.h>
#include "tree.h"
#include "semantic.h"

extern int yylineno;
extern char* yytext;
void yyerror(const char *s);
int yylex();

Node* root = NULL;
%}

%union {
    Node* node;
}

%token <node> INT FLOAT ID SEMI COMMA ASSIGN RELOP PLUS MINUS STAR DIV AND OR DOT NOT TYPE LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE

%type <node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN
%nonassoc LOWER_THAN_ELSE 
%nonassoc ELSE
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT 
%left DOT LB RB LP RP

%%

/* Program: 入口规则，生成根节点并保存到全局变量 */
Program : ExtDefList { 
    $$ = new_node("Program", @$.first_line); 
    $$->child = $1; 
    root = $$; 
}
;

ExtDefList : ExtDef ExtDefList { 
    $$ = new_node("ExtDefList", @$.first_line); 
    $$->child = $1; 
    $1->next = $2; 
}
| { $$ = NULL; }
;

ExtDef : Specifier ExtDecList SEMI { 
    $$ = new_node("ExtDef", @$.first_line); 
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
}
| Specifier SEMI {
    $$ = new_node("ExtDef", @$.first_line);
    $$->child = $1;
    $1->next = $2;
}
| Specifier FunDec CompSt {
    $$ = new_node("ExtDef", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
}
;

/* Specifier: 类型说明 */
Specifier : TYPE {
    $$ = new_node("Specifier", @$.first_line);
    $$->child = $1;
}
| StructSpecifier {
    $$ = new_node("Specifier", @$.first_line);
    $$->child = $1;
}
;

/* StructSpecifier: 结构体定义或结构体引用 */
StructSpecifier : STRUCT OptTag LC DefList RC {
    $$ = new_node("StructSpecifier", @$.first_line);
    $$->child = $1;
    
    Node* p = $1;
    if ($2) { p->next = $2; p = $2; }
    
    p->next = $3; p = $3;
    
    if ($4) { p->next = $4; p = $4; }
    
    p->next = $5;
}
| STRUCT Tag {
    $$ = new_node("StructSpecifier", @$.first_line);
    $$->child = $1;
    $1->next = $2;
}
;

/* OptTag / Tag: 可选/必需的结构体标签 */
OptTag : ID { 
    $$ = new_node("OptTag", @$.first_line); 
    $$->child = $1; 
}
| { $$ = NULL; }
;

Tag : ID {
    $$ = new_node("Tag", @$.first_line);
    $$->child = $1;
}
;

/* VarDec / FunDec / VarList / ParamDec: 变量和函数声明相关规则 */
VarDec : ID {
    $$ = new_node("VarDec", @$.first_line);
    $$->child = $1;
}
| VarDec LB INT RB {
    $$ = new_node("VarDec", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
    $3->next = $4;
}
;

FunDec : ID LP VarList RP {
    $$ = new_node("FunDec", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
    $3->next = $4;
}
| ID LP RP {
    $$ = new_node("FunDec", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
;

VarList : ParamDec COMMA VarList {
    $$ = new_node("VarList", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
| ParamDec {
    $$ = new_node("VarList", @$.first_line);
    $$->child = $1;
}
;

ParamDec : Specifier VarDec {
    $$ = new_node("ParamDec", @$.first_line);
    $$->child = $1; 
    $1->next = $2;
}
;

/* CompSt / StmtList / Stmt: 复合语句与普通语句 */
CompSt : LC DefList StmtList RC {
    $$ = new_node("CompSt", @$.first_line);
    $$->child = $1; // LC
    
    Node* p = $1;
    if ($2) { p->next = $2; p = $2; } // DefList (可能为空)
    if ($3) { p->next = $3; p = $3; } // StmtList (可能为空)
    
    p->next = $4; // RC
}
;

StmtList : Stmt StmtList {
    $$ = new_node("StmtList", @$.first_line);
    $$->child = $1; 
    $1->next = $2;
}
| { $$ = NULL; }
;

Stmt : Exp SEMI {
    $$ = new_node("Stmt", @$.first_line);
    $$->child = $1; 
    $1->next = $2;
}
| CompSt {
    $$ = new_node("Stmt", @$.first_line);
    $$->child = $1;
}
| RETURN Exp SEMI {
    $$ = new_node("Stmt", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
| IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
    $$ = new_node("Stmt", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
    $3->next = $4; 
    $4->next = $5;
}
| IF LP Exp RP Stmt ELSE Stmt {
    $$ = new_node("Stmt", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
    $3->next = $4; 
    $4->next = $5; 
    $5->next = $6; 
    $6->next = $7;
}
| WHILE LP Exp RP Stmt {
    $$ = new_node("Stmt", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3; 
    $3->next = $4; 
    $4->next = $5;
}
;

/* DefList / Def / DecList / Dec / ExtDecList: 局部与外部定义（变量、数组、初始化等） */
DefList : Def DefList {
    $$ = new_node("DefList", @$.first_line);
    $$->child = $1; 
    $1->next = $2;
}
| { $$ = NULL; }
;

Def : Specifier DecList SEMI {
    $$ = new_node("Def", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
;

DecList : Dec {
    $$ = new_node("DecList", @$.first_line);
    $$->child = $1;
}
| Dec COMMA DecList {
    $$ = new_node("DecList", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
;

Dec : VarDec {
    $$ = new_node("Dec", @$.first_line);
    $$->child = $1;
}
| VarDec ASSIGN Exp {
    $$ = new_node("Dec", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
;

ExtDecList : VarDec {
    $$ = new_node("ExtDecList", @$.first_line);
    $$->child = $1;
}
| VarDec COMMA ExtDecList {
    $$ = new_node("ExtDecList", @$.first_line);
    $$->child = $1; 
    $1->next = $2; 
    $2->next = $3;
}
;

/* Exp / Args: 表达式规则（算术、逻辑、函数调用、数组与结构体访问等） */
Exp : Exp ASSIGN Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp AND Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp OR Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp RELOP Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp PLUS Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp MINUS Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp STAR Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp DIV Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| LP Exp RP {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| MINUS Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2;
}
| NOT Exp {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2;
}
| ID LP Args RP {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3; $3->next = $4;
}
| ID LP RP {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp LB Exp RB {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3; $3->next = $4;
}
| Exp DOT ID {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| ID {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1;
}
| INT {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1;
}
| FLOAT {
    $$ = new_node("Exp", @$.first_line);
    $$->child = $1;
}
;

Args : Exp COMMA Args {
    $$ = new_node("Args", @$.first_line);
    $$->child = $1; $1->next = $2; $2->next = $3;
}
| Exp {
    $$ = new_node("Args", @$.first_line);
    $$->child = $1;
}
;

%%

void yyerror(const char *s) {
    printf("Error type B at Line %d: %s\n", yylineno, s);
}

int main(int argc, char** argv) {
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    
    if (root != NULL) {
        semantic_analysis(root);
    }
    
    return 0;
}