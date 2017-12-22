#include<stdio.h>
main()
{
	int h, f, x, y;
	printf("鸡兔的总数，鸡兔脚总数:");
	scanf_s("%d%d", &h, &f);
	if (h> 0 && f> 0)
	{
		x = (4 * h - f) / 2;
		y = (f - 2 * h) / 2;
		printf("鸡:%d   兔:%d", x, y);
	}
	else
		printf("输入错误!\n");
}
 
