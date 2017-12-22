#include<stdio.h>
int main ()
{
	float x,j,c,hj,fk,zh,cw,g,f;
	printf("输入西药费，检查费，材料费，床位费，观察费，护理费：\n");
	scanf("%f%f%f%f%f%f",&x,&j,&c,&cw,&g,&f);
	hj=x+j+c+cw+g+f;
	printf("应付款（元）：%.2f ",hj);
	printf("病人付款（元）："); 
	scanf("%f",&fk);
	zh=fk-hj;
	printf("计算结果：\n");
	printf("病人付款 = %6.2f元\n应收款 = %6.2f元 应找回 = %6.2f元\n",fk,hj,zh);
	return 0; 
}
 
