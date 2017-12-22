#include<stdio.h>
int facsum(int m)
{
    int sum=1,f=2;
    while(f<=(m/2))
    {
        if(m%f==0)
        {
            sum+=f;
        }
        f++;
    }
    return sum;
}
int main()
{
    int m=3,n,k;
    while(m<=500)
    {
        n=facsum(m);
        k=facsum(n);
        if((m==k)&&(m<=n))
           {
               printf("%d , %d\n",m,n);
           }
        m++;
    }
    return 0;
}

