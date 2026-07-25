%{
#include "parser1.tab.h"
#include <string.h>

char str[100];
%}

%%

[a-zA-Z]+ {
    strcpy(str, yytext);
    return STRING;
}

[ \t] ;

\n ;

. ;

%%

int yywrap()
{
    return 1;
}