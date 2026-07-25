%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

input:
      input line
    |
    ;

line:
      '\n'
    | expr '\n' { printf("Result = %d\n", $1); }
    ;

expr:
      expr '+' expr   { $$ = $1 + $3; }
    | expr '-' expr   { $$ = $1 - $3; }
    | expr '*' expr   { $$ = $1 * $3; }
    | expr '/' expr
      {
          if($3 == 0)
          {
              printf("Division by zero not allowed\n");
              $$ = 0;
          }
          else
              $$ = $1 / $3;
      }
    | '(' expr ')'    { $$ = $2; }
    | NUMBER          { $$ = $1; }
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid Expression\n");
}

int main()
{
    printf("Simple Calculator\n");
    printf("Enter expression:\n");
    yyparse();
    return 0;
}