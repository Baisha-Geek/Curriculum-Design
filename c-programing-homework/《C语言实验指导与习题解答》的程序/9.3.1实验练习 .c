#include<stdio.h>
int main()
{  
	struct date{
   		int year;
   		int month;
   		int day;
  	};
  	struct date a;
  	int i, days=0;
  	printf("输入年，月，日：");
  	scanf("%d%d%d", &a.year, &a.month, &a.day);
  	for(i=1; i<a.month; i++){  
	  	if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10)
  			days+=31;
     	else if(i==4 || i==6 || i==9 || i==11)
	 		days+=30;
     	else if((a.year%4==0 && a.year%100!=0) || a.year%400==0)
	 		days+=29;
     	else 
	 		days+=28;
  	} 
  	days+=a.day;
  	printf("%d年%d月%d日是该年的第%d天", a.year, a.month, a.day, days);
  	return 0;
 } 
