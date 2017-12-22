#include<stdio.h>
main()
{
	float x,y;
	printf("请输入x的值：");
	scanf("%f", &x);
	if (x < 1)
		printf("y的值为%.2f", x);
	else if (x >= 10)
	{
		printf("y的值为%.2f",3*x-1);
	}
	else 
	{
		printf("y的值为%.2f",2*x-1);
	}
}
