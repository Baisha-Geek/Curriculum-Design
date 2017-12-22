#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
void sort1(int s[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{   
			if(s[k]>s[j])
				k=j;
 		}
 		if(k!=i)
		{ 
			t=s[k];
			s[k]=s[i];
			s[i]=t;
		} 
	} 
		s[i]=t; 
}

int main()
{
	int a[10],i;
	srand(time(NULL));
	printf("随机产生10个整数：\n");
	for(i=0;i<10;i++)
	{
		a[i]=rand()%100;
		printf("%d ",a[i]);
	}
	printf("\n");
	sort1(a,10);
	printf("排序后的结果：\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	
}
