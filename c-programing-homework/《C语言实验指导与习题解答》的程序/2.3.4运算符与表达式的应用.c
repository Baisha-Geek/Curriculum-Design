#include<stdio.h>
int main(void)
{
	int a,b,c,x,y;
	printf("请输入一个3位的正整数：\n");
	scanf("%d",&x);
	a=x/100;
	b=(x%100)/10;
	c=x%10;
	y=c*100+b*10+a;
	printf("%d: %d",x,y);
	return 0;
}


