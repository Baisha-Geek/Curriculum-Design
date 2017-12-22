#include<stdio.h>
# define N 10
void arrsort(int a[],int n);
int main() 
{
	int a[N],i;
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	arrsort(a,N);
	for(i=0;i<N;i++)
		printf("%d ",a[i]);
}

void arrsort(int a[],int n)
{
	int *p,*q,temp;
	p=a;
	q=a+n-1;
	while(p<q)
	{
		while(*p%2!=0)
			p++;
		while(*q%2==0)
			q--;
		if(p>q)
			break;
		temp=*p;
		*p=*q;
		*q=temp;
		p++;//刚开始在编写时后面两行代码没写，程序也通过了；后来思考了一下， 
		q--;//虽然不写，程序也是对的，但是它没有写上的效率高；
	}
}
