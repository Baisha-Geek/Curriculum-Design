#include "stdio.h"
#include<string.h>
struct person
{
	char name[20];
	int count;
}a[6]={"zhang", 0, "li", 0, "wang", 0, "zhao", 0, "liu", 0, "zhu", 0};

int main()
{
	int i, j; 
	char abc[20];
	for(i=1; i<=10; i++){
		printf("输入候选人名字：");
		scanf("%s", abc);
		for(j=0; j<6; j++){
			if(strcmp(a[j].name, abc) == 0)
				a[j].count++;
		}			
	}
	for(j=0; j<6; j++)
		printf("%-5s:%d \n", a[j].name, a[j].count);
	return 0;
}
 
