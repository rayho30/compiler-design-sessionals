%{
#include <stdio.h>

int line = 1;
%}

LETTER      [A-Za-z_]
DIGIT       [0-9]
ID          {LETTER}({LETTER}|{DIGIT})*
NUM         {DIGIT}+
KEYWORD     int|float|char|double|if|else|while|for|return|void|break|continue

%%

{KEYWORD}      { printf("%-15s %-15s %d\n", yytext, "Keyword", line); }

{ID}           { printf("%-15s %-15s %d\n", yytext, "Identifier", line); }

{NUM}          { printf("%-15s %-15s %d\n", yytext, "Constant", line); }

"=="|"!="|">="|"<="|"="|">"|"<"|"+"|"-"|"*"|"/"|"%"
               { printf("%-15s %-15s %d\n", yytext, "Operator", line); }

";"|","|"("|")"|"{"|"}"|"["|"]"
               { printf("%-15s %-15s %d\n", yytext, "Delimiter", line); }

[ \t]+         ;

\n             { line++; }

.              ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("\n-------------------------------------------\n");
    printf("%-15s %-15s %s\n","TOKEN","TYPE","LINE");
    printf("-------------------------------------------\n");

    yylex();

    printf("-------------------------------------------\n");

    return 0;
}