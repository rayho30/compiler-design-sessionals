%{
#include <stdio.h>

int words = 0;
%}

%%

[ \t\n]+      ;

[^ \t\n]+     { words++; }

%%

int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    yyin = fp;
    yylex();

    printf("Total number of words = %d\n", words);

    fclose(fp);
    return 0;
}