%{
    #include <stdlib.h>
    #include <stdio.h> // for snprintf
    #include <string.h> // for snprintf (safer)
    #include "syntax.tab.h"
    #include "parse_tree.h"
    #define BUFLEN (4096)
    size_t line = 1;
    char buffer[BUFLEN];
    char *parse_int(char *raw);
    #define TOKEN_NODE(TYPE) { yylval.node = new_node(#TYPE, line, NULL, NULL, NULL); return TYPE; }
    #define TYPE_NODE(TYPE)  { yylval.node = new_node("TYPE", line, yytext, NULL, NULL); return TYPE; }
    #define STRUCT_NODE(TYPE)  { yylval.node = new_node("STRUCT", line, NULL, NULL, NULL); return STRUCT; }
%}
%option noyywrap
literal_int     [0-9]+|0x[0-9a-fA-F]+
literal_float   [0-9]+"."[0-9]+
identifier      [a-zA-Z_][a-zA-Z0-9_]*
literal_char    \'.\'|\'\\x[0-9a-fA-F]{2}\'
%%

"//".*$         { /* ignore comments */ }
"/*"([^*]|[*][^/]|[*][*]+[^*/])*"*/"    { for (size_t i = 0; i < strlen(yytext); i++) if (yytext[i] == '\n') line++; }
[ \t\r]+        { /* ignore whitespace */ }
"\n"            { line++; }
"int"           TYPE_NODE(TYPE)
"float"         TYPE_NODE(TYPE)
"char"          TYPE_NODE(TYPE)
"struct"        STRUCT_NODE(STRUCT)
"if"            TOKEN_NODE(IF)
"else"          TOKEN_NODE(ELSE)
"while"         TOKEN_NODE(WHILE)
"return"        TOKEN_NODE(RETURN)
"."             TOKEN_NODE(DOT)
";"             TOKEN_NODE(SEMI)
","             TOKEN_NODE(COMMA)
"="             TOKEN_NODE(ASSIGN)
"<"             TOKEN_NODE(LT)
">"             TOKEN_NODE(GT)
"<="            TOKEN_NODE(LE)
">="            TOKEN_NODE(GE)
"!="            TOKEN_NODE(NE)
"=="            TOKEN_NODE(EQ)
"+"             TOKEN_NODE(PLUS)
"-"             TOKEN_NODE(MINUS)
"*"             TOKEN_NODE(MUL)
"/"             TOKEN_NODE(DIV)
"&&"            TOKEN_NODE(AND)
"||"            TOKEN_NODE(OR)
"!"             TOKEN_NODE(NOT)
"("             TOKEN_NODE(LP)
")"             TOKEN_NODE(RP)
"["             TOKEN_NODE(LB)
"]"             TOKEN_NODE(RB)
"{"             TOKEN_NODE(LC)
"}"             TOKEN_NODE(RC)
{identifier}    { yylval.node = new_node("ID", line, yytext, NULL, NULL); return ID; }
{literal_char}  { yylval.node = new_node("CHAR", line, yytext, NULL, NULL); return CHAR; }
{literal_int}   { yylval.node = new_node("INT", line, parse_int(yytext), NULL, NULL); return INT;}
{literal_float} { yylval.node = new_node("FLOAT", line, yytext, NULL, NULL); return FLOAT; }

'\\x.*'         { snprintf(buffer, BUFLEN, "illegal char %s", yytext); yylval.node = new_node("ILLEGAL", line, buffer, NULL, NULL); return ILLEGAL; }
0x([0-9a-fA-F]|[g-zG-Z])+       { snprintf(buffer, BUFLEN, "illegal hex %s", yytext); yylval.node = new_node("ILLEGAL", line, buffer, NULL, NULL); return ILLEGAL; }
[0-9]{identifier}    { snprintf(buffer, BUFLEN, "illegal identifier %s", yytext); yylval.node = new_node("ILLEGAL", line, buffer, NULL, NULL); return ILLEGAL; }
.               { snprintf(buffer, BUFLEN, "illegal symbol %s", yytext); yylval.node = new_node("ILLEGAL", line, buffer, NULL, NULL); return ILLEGAL; }
%%

char *parse_int(char *raw) {
    if (raw[1] == 'x') {
        int val = 0;
        char *ptr;
        for (ptr = raw + 2; *ptr; ptr++) {
            val *= 16;
            if (*ptr <= '9') {
                val += *ptr - '0';
            }
            else if (*ptr <= 'Z') {
                val += *ptr - 'A' + 10;
            }
            else {
                val += *ptr - 'a' + 10;
            }
        }
        buffer[BUFLEN - 1] = 0;
        for (ptr = buffer + BUFLEN - 2; val; ptr--) {
            *ptr = val % 10 + '0';
            val /= 10;
        }
        return ++ptr;
    }
    else {
        return raw;
    }
}