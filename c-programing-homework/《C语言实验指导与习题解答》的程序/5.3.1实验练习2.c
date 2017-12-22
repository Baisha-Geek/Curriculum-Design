#include<stdio.h>
main()
{
        int n,i,j,sign=1;
        float fac,sum;
        printf("please input value of n:");
        scanf("%d",&n);
        sum=0.0;
        for(i=1;i<=n;i++)
        {
                fac=1.0;
                for(j=1;j<=2*i-1;j++)
                {
                        fac=fac*j;
                }

                fac=fac*sign;
                sum=sum+fac;
                sign=-sign;
        }
        printf("sum=%.0f\n",sum);
}
                        
