#include<stdio.h>
int main()
{
        float v,sum=0.0;
        int n=0;
        printf("input value:");
        scanf("%f",&v);
        do
        {
                ++n;
                sum+=1.0/n;
        }
        while(sum<=v);
        printf("n=%d",n);
        return 0;
}
                           
