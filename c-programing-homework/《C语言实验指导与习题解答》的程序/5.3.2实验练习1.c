#include<stdio.h>
int main()
{
        float max,min,x;
        printf("please input score:");
        scanf("%f",&x);
        max=min=x;
        while(x>0){
                if(x>max)
                        max=x;
                if(x<min)
                        min=x;
                scanf("%f",&x);
        }
        printf("max=%f\nmin=%f",max,min);
}


