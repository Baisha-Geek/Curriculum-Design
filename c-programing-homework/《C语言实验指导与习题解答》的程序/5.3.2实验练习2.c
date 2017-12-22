#include<stdio.h>
int main()
{
        int x,y,z,k=100;
        while(k<999)
        {
                x=k/100;
                y=(k/10)%10;
                z=k%10;
                if(k==x*x*x+y*y*y+z*z*z)
                        printf("%d\n",k);
                k++;
        }
}

