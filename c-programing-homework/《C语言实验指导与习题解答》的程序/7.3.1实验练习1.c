#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
void sort1(int s[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(s[j]>s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		} 
	}
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
