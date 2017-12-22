#include<stdio.h> 
main()
{
	int i,k,s=0;
	printf("Enter a number:");
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		s=s+i;
		printf("%d ",s);

	}
}
