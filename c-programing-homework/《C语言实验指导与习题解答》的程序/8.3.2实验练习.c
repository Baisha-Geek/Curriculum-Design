#include<stdio.h>
void swap1(int x,int y);
void swap2(int *x,int *y);
int main()
{
	int a,b;
	printf("Please Input a=: ");
	scanf("%d",&a);
	printf("\n             b=: ");
	scanf("%d",&b);
	swap1(a,b);
	printf("\nAfter Call swap1: a=%d  b=%d\n",a,b);
	swap2(&a,&b);
	printf("\nAfter Call swap1: a=%d  b=%d\n",a,b);
	return 0;
 } 
 
 void swap1(int x,int y)
 {
 	int temp;
 	temp=x;
 	x=y;
 	y=temp;
 }
 
 void swap2(int *x,int *y)
 {
 	int temp;
 	temp=*x;
 	*x=*y;
 	*y=temp; 
 	
 }
