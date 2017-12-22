#include<stdio.h>
void trangle(int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n-1;j++)
		{
			printf(" ");
		}
		for(k=1;k<=i*2+1;k++)
		{
			printf("*");
		}	
		putchar('\n');
	}
} 
main()
{
	int n;
	printf("please enter n:");
	scanf("%d",&n);
	printf("\n");
	trangle(n);
}
