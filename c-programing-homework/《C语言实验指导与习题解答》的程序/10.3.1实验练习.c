#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char string[81];
    if (argc != 2 || (fp = fopen(argv[1], "r")) == NULL)
    {
        printf("can't open file");
        exit(0);
    }
    while (fgets(string, 81, fp) != NULL)
    {
        puts(string);
        fclose(fp);
    }
    return 0;
}
