%{
#include<stdio.h>

FILE *yyin;
FILE *yyout;
%}

%%

"//".*                  ;

"/*"([^*]|\*+[^*/])*\*+"/"     ;

^[ \t]*\n              ;

.|\n                   { fputc(yytext[0],yyout); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin=fopen("input.c","r");

    if(yyin==NULL)
    {
        printf("Input file not found\n");
        return 1;
    }

    yyout=fopen("output.c","w");

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("Comments removed successfully.\n");

    return 0;
}