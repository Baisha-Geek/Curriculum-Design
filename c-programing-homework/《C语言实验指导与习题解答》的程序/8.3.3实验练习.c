#include"stdio.h"
char *reverse(char *str);
char *link(char *str1,char *str2);
int main()
{
    char str[30],str1[30],*str2;
    printf("Input Reversing Character String:");
    gets(str);
    str2=reverse(str);
    printf("\nOutput Reversed Character String:");
    puts(str2);
    printf("Input String1:");
    gets(str);
    printf("\nInput String2:");
    gets(str1);
    str2=link(str,str1);
    printf("\nLink String1 and String2: ");
    puts(str2);
}
char *reverse(char *str)
{

    char *p,*q,temp;
    p=str,q=str;
    while (*p!='\0')
        p++;
    p--;
    while(q<p)
    {
        temp=*p;
        *p=*q;
        *q=temp;
        q++,p--;
    }
    return str;
}
char *link(char *str1,char *str2)
{
    char *p=str1,*q=str2;
    while(*p!='\0')
        p++;
    while(*q!='\0')
    {
    	//*p++=*q++;
    	*p=*q;
		p++;
		q++; 
        
    }
    *p='\0';
    return str1;
}

