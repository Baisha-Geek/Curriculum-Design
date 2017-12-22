#include<stdio.h>
int main()
{
	int *p,a,c=3;
	float *q,b;
	p=&a;
	q=&b;
	printf("Please Input the Value of a,b: ");
	scanf("%d%f",p,q);
	printf("Result: \n");
	printf("       %d, %f\n",a,b);
	printf("       %d, %f\n",*p,*q);
	printf("The Address of a,b: %p,%p\n",&a,&b);
	printf("The Address of a,b: %p,%p\n",p,q);
	p=&c;
	printf("c=%d\n",*p);
	printf("The Address of c: %x,%x\n",p,&c);
	return 0;
	
}
