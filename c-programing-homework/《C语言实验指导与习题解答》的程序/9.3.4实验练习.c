#include<stdio.h>
#define N 10
struct child
{
	int no;
	int next;
};
struct child link[N];
int main()
{
	int i,n,m,s,count,h;
	printf("输入围圈人数，出圈报数，开始报数位置：");
	scanf("%d %d %d", &n, &m, &s);
	for (i=1; i<=n; i++)
	{
		if (i == n)
		   link[i].next=1;
		else
		   link[i].next=i+1;
		link[i].no = i;      
	}
	count = 0;
	if(s == 1)
	   h = n;
	else
	   h = s-1;
	printf("出圈顺序为：");
	while(m < n - 1)
	{
		i = 0;
		while(i !=m )
		{
			h=link[h].next;
			if(link[h].no)
			   i++;
		}
		printf("%d, ", link[h].no);
		link[h].no = 0;
		count++;
	}
	for(i=1; i<=n; i++)
	if(link[i].no != 0)
	   printf("%d", count);   
	return 0;
}

