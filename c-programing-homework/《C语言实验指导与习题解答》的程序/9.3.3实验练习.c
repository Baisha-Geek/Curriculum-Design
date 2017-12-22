#include "stdio.h"
#include "stdlib.h"
struct
{
	int number;
	char name[10];
	char job;
	union
	{
		int classes;
		char position[10];
	}category;
}person[2];

int main()
{
	int i;
	printf("输入某人的编号、姓名、职业：\n");
	for(i=0; i<2; i++)
	{
		scanf("%d  %s  %c", &person[i].number, &person[i].name, &person[i].job);
		if(person[i].job == 's')
		   scanf("%d", &person[i].category.classes);
		else if(person[i].job == 't')
		   scanf("%s", &person[i].category.position);
		else
			printf("input error!");    
	}
	printf("\n");
	printf("编号   姓名   职业  班级/职务\n");
	for(i=0; i<2; i++)
	{
	   if(person[i].job == 's')
	      printf("%d  %s  %c  %d \n", person[i].number, person[i].name,
		  							  person[i].job, person[i].category.classes);
	   else
	      printf("%d  %s  %c  %s",person[i].number, person[i].name,
		  						  person[i].job, person[i].category.position);
    }
    return 0;
}


