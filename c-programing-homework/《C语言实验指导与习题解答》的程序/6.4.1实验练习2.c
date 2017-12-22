#include<stdio.h>
int N=6;
long function(int i)
{   
    /*
    static long f=1;
    f=f*i;
    return f;  */
    
    int n,sum=1;
    for(n=1;n<=i;n++)
    {
    	sum*=n;
	}
	return sum;
}
int main()
{
    int i;
    long product;
    for (i=1;i<N;i++)
    {
        product=function(i);
        printf("%d的阶乘是：%ld\n",i,product);
    }
    
}
  
/* 这个题目巧妙的使用了static静态变量来保存上一次求得的f的值，
   而我刚开始在编写是只想到了用for循环去求阶乘；  */ 
 
