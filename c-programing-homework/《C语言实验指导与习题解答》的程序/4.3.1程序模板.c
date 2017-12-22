#include<stdio.h>
int main()
{
	int l, w, h;
	printf("请输入箱子的长、宽、高：\n");
	scanf("%d%d%d", &l, &w, &h);
	if (l == w && w==h && l==h)
		printf("该箱子是正方形\n");
	else 
	    printf("该箱子是长方形\n");
	return 0;
}
