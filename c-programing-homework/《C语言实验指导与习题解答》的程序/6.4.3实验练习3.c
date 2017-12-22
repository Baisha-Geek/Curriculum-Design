#include<stdio.h>
int Acm(int m,int n)
{
    if(m==0)
        return (n+1);
    else if(n==0)
        return (Acm(m-1,1));
    else if(m>0 && n>0)
        return (Acm(m-1,Acm(m,n-1)));
}

int main()
{
    int m,n,a;
    printf("please enter m¡¢n:");
    scanf("%d%d",&m,&n);
	a=Acm(m,n);
    printf("Acm(%d,%d)=%d",m,n,a);
    return 0;
}
                      
