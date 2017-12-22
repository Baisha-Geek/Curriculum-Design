#include<stdio.h>
int day_tab[2][13]={
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
}; 
int day_year(int y,int m,int d)
{
	int i=0,j,s=0;
	if((y%4==0 && y%100!=0) || y%400==0)
		i=1;
	for(j=1;j<m;j++)
		s+=day_tab[i][j];	
	return s+d;
}

int main()
{
	int y,m,d;
	printf("Input year_month_day: \n");
	scanf("%d%d%d",&y,&m,&d);
	printf("是这年的第%d天\n",day_year(y,m,d));
}
