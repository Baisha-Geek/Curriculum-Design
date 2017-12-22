#include<stdio.h>
int main()
{
    int m,n,k;
    int sum=0;
    printf("各种驮法如下：\n");
    for(m=1;m<=100;m++)
    {
        for(n=1;n<=100-m;n++)
        {
          k=100-m-n;
          if((k%2==0)&&(3*m+2*n+0.5*k==100))
          {
            printf("大马%d匹; 中马%d匹; 小马%d匹.\n",m,n,k);
            sum++;
          }
        }
    }
    printf("共有%d种驮法.\n",sum);
}

