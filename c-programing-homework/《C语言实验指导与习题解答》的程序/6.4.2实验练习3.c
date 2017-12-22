#include<stdio.h>
int Ack(int n,int x,int y)
{
    int a;
    if(n==0)
    {
        a=x+1;
    }
    else if((n==1)&&(y==0))
    {
        a=x;
    }
    else if((n==2)&&(y==0))
    {
        a=0;
    }
    else if((n==3)&&(y==0))
    {
        a=1;
    }
    else if((n>=4)&&(y==0))
    {
        a=2;
    }
    else if((n!=0)&&(y!=0))
    {
       a=Ack(n-1,Ack(n,x,y-1),x);    
    }
    return a; 
}
main()
{
    int n,x,y,result;
    printf("please input n,x,y:");
    scanf("%d%d%d",&n,&x,&y);
    if((n<0)||(x<0)||(y<0))
    {
        printf("请重新输入有效值");
    }
    result=Ack(n,x,y);
    printf("Ack(%d %d %d)=%d\n",n,x,y,result);
}

