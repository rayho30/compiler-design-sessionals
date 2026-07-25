%{
#include <stdio.h>
#include <string.h>

extern char str[100];

int yylex();
void yyerror(const char *s);
%}

%token STRING

%%

start:
    STRING
    {
        int i, len = strlen(str), flag = 1;

        for(i = 0; i < len/2; i++)
        {
            if(str[i] != str[len-i-1])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("Palindrome\n");
        else
            printf("Not Palindrome\n");
    }
;

%%

void yyerror(const char *s)
{
    printf("Invalid Input\n");
}

int main()
{
    printf("Enter a string: ");
    yyparse();
    return 0;
}