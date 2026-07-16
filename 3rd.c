#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50], word[100], datatype[20];
    int size;
    int local = 0;
    char *p;

    printf("Enter source file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("\n-------------------------------------------------\n");
    printf("Identifier\tData Type\tSize\tScope\n");
    printf("-------------------------------------------------\n");

    while (fscanf(fp, "%s", word) != EOF)
    {
        if (strcmp(word, "main()") == 0 || strcmp(word, "main") == 0)
        {
            local = 1;
            continue;
        }

        if (strcmp(word, "int") == 0 ||
            strcmp(word, "char") == 0 ||
            strcmp(word, "float") == 0 ||
            strcmp(word, "double") == 0)
        {
            strcpy(datatype, word);

            if (strcmp(datatype, "int") == 0)
                size = 4;
            else if (strcmp(datatype, "char") == 0)
                size = 1;
            else if (strcmp(datatype, "float") == 0)
                size = 4;
            else
                size = 8;

            fscanf(fp, "%s", word);

            if (strchr(word, '('))
                continue;

            p = strchr(word, ';');
            if (p) *p = '\0';

            p = strchr(word, ',');
            if (p) *p = '\0';

            p = strchr(word, '[');
            if (p) *p = '\0';

            p = strchr(word, '=');
            if (p) *p = '\0';

            printf("%-15s %-10s\t%d\t%s\n",
                   word,
                   datatype,
                   size,
                   local ? "Local" : "Global");
        }
    }

    fclose(fp);

    return 0;
}
