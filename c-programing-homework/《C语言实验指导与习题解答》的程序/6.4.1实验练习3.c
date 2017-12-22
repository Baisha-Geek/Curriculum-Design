#include<stdio.h>
int gcd(int a,int b)
{
    int temp;
    int remainder;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    remainder=a%b;
    while(remainder!=0)
    {
        a=b;
		b=remainder;
        remainder=a%b;
    }
    return b;
}
main()
{
    int a,b;
    int fac;
    printf("please input two integers:");
    scanf("%d%d",&a,&b);
    fac=gcd(a,b);
    printf("The great common divisor is:%d",fac);
}

