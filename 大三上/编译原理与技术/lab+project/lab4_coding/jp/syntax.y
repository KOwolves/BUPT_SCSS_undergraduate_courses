%{
    #include"lex.yy.c"
    int i=0;
    void yyerror();
%}


%token LC RC LB RB COLON COMMA
%token STRING NUMBER
%token TRUE FALSE VNULL
%%

Json:
      Value
    | LB Values RB COMMA error { puts("Comma after the close, recovered"); }
    | LB Values RB RB error { puts("Extra close, recovered"); }
    | LC Members RC Values error { puts("Extra value after close, recovered"); }
    ;

Value:
      Object
    | Array
    | STRING
    | NUMBER {if($1==0) {yyerror();i++;puts("Numbers cannot have leading zeroes, recovered");}}
    | TRUE
    | FALSE
    | VNULL
    ;

Object:
      LC RC
    | LC Members RC
    ;

Members:
      Member
    | Member COMMA RC error { puts("Extra comma, recovered"); }
    | Member COMMA Members
    ;

Member:
      STRING COLON Value
    | STRING Value error { puts("Missing colon, recovered"); }
    | STRING COLON COLON Value error { puts("Double colon, recovered"); }
    | STRING COMMA Values error { puts("Comma instead of colon, recovered"); }
    | error { if(i==0){puts("Comma instead if closing brace, recovered");i++; }}
    ;

Array:
      LB RB
    | LB Values RB
    | LB Values error { puts("Unclosed array, recovered"); }
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    | COMMA Values error { puts("<-- missing value, recovered"); }
    ;

Values:
      Value
    | Value COMMA Values
    | Value COLON Values error{ puts("Colon instead of comma, recovered"); }
    | COMMA error { puts("double extra comma, recovered"); }
    | Value COMMA error { puts("extra comma, recovered"); }
    ;
%%


void yyerror(){
    if(i==0)
        printf("syntax error: ");
}

int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
