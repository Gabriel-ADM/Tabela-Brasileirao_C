#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // char mode = "w+";
    char string[] = "This is a string bitch";
    int i;
    FILE *fp;
    fp = fopen(argv[1], "w+");
    fprintf(fp, "%s", string);
    printf("%c", string[i]);

    for (i = 0; i < strlen(string); i++)
    {
    printf("%c", string[i]);
    }
    fclose(fp);
    // char text[] = "So much sex and text";

    // for (int i = 0; i < argc; i++)
    // {
    //     printf("argv[%d] = %s\n", i, argv[i]);
    // }

    // int count = 0;
    // while (text[count] != EOF)
    // {
    //     fprintf(file, "%c", text[count]);
    // }

    // fclose(file);
    return 0;
}
