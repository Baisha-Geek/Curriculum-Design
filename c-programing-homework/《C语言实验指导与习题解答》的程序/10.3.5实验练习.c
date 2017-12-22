#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char encypt(char f, char c)
{
    return f^c;
}
int main()
{
    FILE *fp, *fp1;
    char fn[40], *p = fn,
         ps[10], *s = ps;
    char ch;
    char *tm = "temp.tmp";
    printf("Input the path and filename:");
    gets(p);
    if ((fp = fopen(p, "rb")) == NULL || (fp1 = fopen(tm, "wb")) == NULL)
    {
        printf("Cannot open file strike any key exit!");
        exit(0);
    }
    printf("Input the password:");
    gets(s);
    ch = fgetc(fp);
    while (!feof(fp))
    {
        s = ps; 
        while (*s != '\0')
        {
			ch = encypt(ch, *s++);
            fputc(ch, fp1);
            ch = fgetc(fp);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove(p);
    rename(tm, p);
    return 0;
}
