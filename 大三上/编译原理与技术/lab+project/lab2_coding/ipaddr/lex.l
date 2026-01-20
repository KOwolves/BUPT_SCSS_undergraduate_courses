%{
    int indicator = 0;
    char *addr_type = NULL;
%}
%option noyywrap

de_number ([0-9])|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5])
hex_number [A-Fa-f0-9]
hex_in_v6 {hex_number}{1,4}
v4 ^(({de_number}\.){3}({de_number}))$
v6 ^(({hex_in_v6}:){7}({hex_in_v6}))$

%%
{v4} { indicator = 4; }
{v6} { indicator = 6; }
<<EOF>> {
    if(indicator == 4)
        addr_type = "IPv4";
    else if(indicator == 6)
        addr_type = "IPv6";
    else
        addr_type = "Neither";
    indicator = 0;
    return 0;
}
\n {}
. {}
%%
char *validIPAddress(char *IP){
    YY_BUFFER_STATE buf;
    buf = yy_scan_string(IP);
    yylex();
    yy_delete_buffer(buf);
    return addr_type;
}
