#include<stdio.h>
main()
{
	int x,y,z,sum=0;
	for(x=1;x<29;x++)
	{
		for(y=1;y<30-x;y++)
		{
			z=30-x-y;
			if(3*x+2*y+z==50)
			{
				printf("大学生%3d\t中学生%3d\t小学生%3d\n",x,y,z);   //如果不在%d的d的前面加个3的话，会导致输出的字符不整齐； 
				sum+=1;
			}
			else
			    continue;
		}
	}
	printf("sum = %d\n",sum); 
}

/*书上所采用的算法； 
#include<stdio.h> 
main()
{
	int x,y,z,sum=0;
	for(x=1;x<30;x++)
	{
		for(y=1;y<30;y++)
		{
			z=30-x-y;
			if(z!=0 && 3*x+2*y+z==50)
			{
				printf("大学生%3d\t中学生%3d\t小学生%3d\n",x,y,z);   
				sum+=1;
			}
			else
			    continue;
		}
	}
	printf("sum = %d\n",sum); 
}
*/ 
