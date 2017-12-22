#include<stdio.h>
int main()
{
	int x,n,y;
	float sume=0.0;
	printf("请选择：1.日用品      2.文具         3.食品\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			printf("请选择：1.牙刷（3.5元/支）  2.牙膏（6.2元/支）\n");
			printf("        3.肥皂（2元/块）    4.毛巾（8.6元/条）\n");
			scanf("%d",&y);
			printf("数量？"); 
			scanf("%d",&n);
			switch(y)
			{
				case 1: sume=n*3.5; break;
				case 2: sume=n*6.2; break;
				case 3: sume=n*2;   break;
				case 4: sume=n*8.6;	break;
			 } 
			 break;
		case 2:
			printf("请选择：1.笔（3元/支）         2.笔记本（1.2元/个）\n");
			printf("        3.文件夹（12元/个）    4.文具盒（8.6元/个）\n");
			scanf("%d",&y);
			printf("数量？");
			scanf("%d",&n);
			switch(y)
			{
				case 1: sume=n*3;   break;
				case 2: sume=n*1.2; break;
				case 3: sume=n*12;  break;
				case 4:	sume=n*8.6; break;
			 } 
			 break;
 	    case 3:
			printf("请选择：1.白糖（3.6元/包）  2.盐（1元/包）\n");
			printf("        3.饼（2元/个）      4.方便面（3.6元/条）\n");
			scanf("%d",&y);
			printf("数量？");
			scanf("%d",&n);
			switch(y)
			{
				case 1: sume=n*3.6; break;
				case 2: sume=n*1;   break;
				case 3: sume=n*2;   break;
				case 4: sume=n*3.6; break;
			 } 
			 break;
	} 
	printf("总计：%.2f 元\n",sume);
	return 0; 
 } 
 
