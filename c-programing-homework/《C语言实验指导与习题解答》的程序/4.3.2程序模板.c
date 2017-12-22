#include<stdio.h>
int main()
{
	int DA,MO,GU;
	float ZJG;
	printf("请输入购买打印纸、墨盒、光盘的数量：");
	scanf("%d%d%d",&DA,&MO,&GU);
	ZJG=18*DA+132*MO+4.5*GU;
	if(ZJG>500)
	{
	    ZJG=ZJG*0.9;
	 	printf("应付货款：%.2f",ZJG);
	}
	else if(ZJG>400)
	{
	    ZJG=ZJG*0.92;
	    printf("应付货款：%.2",ZJG);
	}
	else if(ZJG>300)
	{
	    ZJG=ZJG*0.93;
  	    printf("应付货款：%.2f",ZJG);
	}
	else if(ZJG>200)
	{
	    ZJG=ZJG*0.94;
	 	printf("应付货款：%.2f",ZJG);
	}
	else if(ZJG>100)
	{
	    ZJG=ZJG*0.95;
	 	printf("应付货款：%.2f",ZJG);
	}
	else
	{
		printf("购买数量： 打印纸：%d 墨盒：%d 光盘：%d\n应付货款：%f",DA,MO,GU,ZJG);
	}
}
