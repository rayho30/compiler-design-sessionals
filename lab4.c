#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int i, found = 0;

    char keywords[][20] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; i < 32; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
        printf("%s is a Keyword.\n", str);
    else
        printf("%s is Not a Keyword.\n", str);

    return 0;
}
