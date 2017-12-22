#include<math.h>
#include<stdio.h>
float area(float a,float b,float c)
{
	float s,p,area;
	s=(a+b+c)/2;
	p=s*(s-a)*(s-b)*(s-c);
	area=sqrt(p);
	return (area);
}
int main()
{
	float x,y,z,ts;
	scanf("%f%f%f",&x,&y,&z);
	if(x+y>z && x+z>y && y+z>x)
	{
		ts=area(x,y,z);
		printf("area=%f\n",ts);
	}
	else 
		printf("data error!");
	return 0;
}
