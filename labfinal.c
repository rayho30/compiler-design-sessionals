#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKENS 200

char *keywords[] = {
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union","unsigned","void",
    "volatile","while"
};

int keywordCount = 32;

struct Token
{
    char token[50];
    char category[20];
    int frequency;
};

struct Token table[MAXTOKENS];
int total = 0;

int isKeyword(char word[])
{
    int i;

    for(i = 0; i < keywordCount; i++)
    {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

void addToken(char word[], char category[])
{
    int i;

    for(i = 0; i < total; i++)
    {
        if(strcmp(table[i].token, word) == 0)
        {
            table[i].frequency++;
            return;
        }
    }

    strcpy(table[total].token, word);
    strcpy(table[total].category, category);
    table[total].frequency = 1;
    total++;
}

int main()
{
    FILE *fp;
    char filename[100];
    char ch;
    char word[100];

    int i;
    int keywordTotal = 0;
    int identifierTotal = 0;

    printf("Enter C source file name: ");
    scanf("%99s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch) || ch == '_')
        {
            i = 0;
            word[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isalnum(ch) || ch == '_'))
            {
                word[i++] = ch;
            }

            word[i] = '\0';

            if(isKeyword(word))
            {
                keywordTotal++;
                addToken(word, "Keyword");
            }
            else
            {
                identifierTotal++;
                addToken(word, "Identifier");
            }
        }
    }

    fclose(fp);

    printf("\n-----------------------------------------------\n");
    printf("%-20s %-15s %-10s\n","TOKEN","CATEGORY","FREQUENCY");
    printf("-----------------------------------------------\n");

    for(i = 0; i < total; i++)
    {
        printf("%-20s %-15s %-10d\n",
               table[i].token,
               table[i].category,
               table[i].frequency);
    }

    printf("-----------------------------------------------\n");
    printf("Total Keywords    : %d\n", keywordTotal);
    printf("Total Identifiers : %d\n", identifierTotal);

    return 0;
}
