#include<stdio.h>
#include<string.h>
#define N 40
void main()
{
	char str[N],ch='Y';
	int i,len;
	printf("请输入一个字符串：");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-1-i])
		{
			ch='N';
			break;
	 	} 
 	} 
 	if(ch=='Y')
 		printf("%s 是回文\n",str);
 	else
 		printf("%s 不是回文\n",str);
}
