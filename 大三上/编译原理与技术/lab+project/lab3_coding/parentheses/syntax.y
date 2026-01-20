%{
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"

int result = 1;

void yyerror(const char *s) {
    // 遇到任何语法错误，都判定为无效
    result = 0;
}
extern int yylex_destroy(void);

%}

// Bison 声明区
%token LP RP LB RB LC RC

// 定义起始符号
%start ValidSequence

%%
// 一个完整的、有效的、正确嵌套的括号序列
ValidSequence:
    %empty
|   Group ValidSequence
;

// 一个自包含的、被匹配括号包裹起来的有效序列
Group:
    LP ValidSequence RP
|   LB ValidSequence RB
|   LC ValidSequence RC
;
%%

int validParentheses(char *expr) {
    result = 1;
    yy_scan_string(expr);
    yyparse();
    yylex_destroy(); 
    
    return result;
}
