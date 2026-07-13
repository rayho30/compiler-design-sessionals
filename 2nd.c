#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], token[100];
    int count = 0;

    printf("Enter the source file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", token) != EOF) {
        count++;
    }

    fclose(fp);

    printf("Total number of tokens = %d\n", count);

    return 0;
}
