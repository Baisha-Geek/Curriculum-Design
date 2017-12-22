#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char str[100];
    int i;
    if ((fp = fopen("test.dat", "w")) == NULL)
    {
        printf("Cannot open the file.\n");
        exit(0);
    }
    printf("Input a string:");
    gets(str);
    for(i = 0; str[i] && i<100; i++)
    {
        if (str[i]>96 && str[i]<123)
            str[i] -= 32;
        fputc(str[i], fp);
    }
    fclose(fp);
    fp = fopen("text.dat", "r");
    fgets(str, 100, fp);
    printf("%s\n", str);
    fclose(fp);
    return 0;
}
