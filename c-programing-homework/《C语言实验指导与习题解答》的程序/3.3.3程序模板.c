#include<stdio.h>
main()
{
	int h = 10;
	float x1 = 2, y1 = 2, x2 = -2, y2 = 2, x3 = -2, y3 = -2, x4 = 2, y4 = -2, x, y, d1, d2, d3, d4;
	printf("请输入一个点（x,y):");
	scanf_s("%f%f", &x, &y);
	d1 = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
	d2 = sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2));
	d3 = sqrt((x - x3)*(x - x3) + (y - y3)*(y - y3));
	d4 = sqrt((x - x4)*(x - x4) + (y - y4)*(y - y4));
	if (d1 > 1 && d2 > 1 && d3 > 1 && d4 > 1)
		h = 0;
	printf("该点高度为%d", h);
	
}
