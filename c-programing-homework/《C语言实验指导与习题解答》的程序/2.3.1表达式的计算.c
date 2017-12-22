#include<stdio.h>
#include<math.h>
main()
{
	float a, b;
	float x;
	printf("Please enter a,b£º\n");
	scanf("%f£¬%f", &a,&b);
	x = (b + sqrt(b*b + 2 * a)) / (a - b);
	printf("x=%.2f", x);
}
