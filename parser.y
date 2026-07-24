%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
      expr '\n'      { printf("Valid Expression\n"); }
    ;

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | '-' expr %prec UMINUS
    | NUMBER
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid Expression\n");
}

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}