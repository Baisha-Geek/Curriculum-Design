#include<stdio.h>
double f(double x); 
double sab(double a, double b,int n)
{
	double h,result,x1,x2,x3=0,t;
	int k;
	h=(b-a)/n;
	x1=f(a);
	x2=f(b);
	for(k=1;k<=n-1;k++)
	{
		t=a+k*h;
		x3+=f(t);
	}
	result=h*(x1+x2)/2+h*x3;
	return result;
}

/* 
//////2-1.cpp////////
#include<stdio.h>
#include<math.h>
//#include"sab.h"
double f(double x)
{
	return  x*x*exp(x);
}
int main()
{
	double a,b,result;
	int n;
	printf("please enter double a,b and integer n:");
	scanf("%lf%lf%d",&a,&b,&n);
	result=sab(a,b,n);
	printf("sab(%lf,%lf,%d)=%lf",a,b,n,result);
	return 0;
}
*/ 
//////2-1.cpp////////
#include<stdio.h>
#include<math.h>
//#include"sab.h"
double f(double x)
{
	return  1/(25+x*x);
}
int main()
{
	double a,b,result;
	int n;
	printf("please enter double a,b and integer n:");
	scanf("%lf%lf%d",&a,&b,&n);
	result=sab(a,b,n);
	printf("sab(%lf,%lf,%d)=%lf",a,b,n,result);
	return 0;
}

