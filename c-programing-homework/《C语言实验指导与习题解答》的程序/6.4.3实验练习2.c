#include<stdio.h>
int age(int n)
{
    int c;
    if(n==1)
        c=10;
    else
    	c=age(n-1)+2;
    return c;
}
int main()
{
    int a,n=5;
    a=age(n);
    printf("第5位学生的年龄是%d",a);
    return 0;
}

