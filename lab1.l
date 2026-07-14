%{
#include<stdio.h>
%}

%%

"//".*          { printf("Single Line Comment\n"); }

"/*".*"*/"      { printf("Multi Line Comment\n"); }

.*              { printf("Not a Comment\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a line: ");
    yylex();
    return 0;
}