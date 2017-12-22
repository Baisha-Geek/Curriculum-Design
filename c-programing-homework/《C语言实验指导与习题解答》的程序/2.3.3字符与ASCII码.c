#include<stdio.h>
main()
{
	char a;
	printf("请输入一个大写字母:\n");
	scanf("%c",&a);
	printf("小写字母为： ");
	printf("%c,%c,%c\n",a+31,a+32,a+33);
	printf("ASCII码值为： ");
    printf("%d,%d,%d",a+31,a+32,a+33);
 } 
