#include<stdio.h>
long  getpower(int x, int y)
{
    if(y==1)
    {
     	return x;
    }
    else
    {
       return x*getpower(x,y-1);
    }
}
main()
{
    int x,y;
    long answer;
    printf("输入一个数:");
    scanf("%d",&x);
    printf("输入幂次房:");
    scanf("%d",&y);
    answer=getpower(x , y);
    printf("结果是:%ld\n",answer);
}

