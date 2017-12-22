#include<stdio.h>
main()
{
	char c;
	int k, data=0;
	for(k=0; k<4; k++)
	{
		while(1)
		{   
		 	c=getchar();
			if(c>='0'&&c<='9')
				break;
		}
		if(k==0)
			data+=(c-'0')*1000;
	    if(k==1)
			data+=(c-'0')*100;
	    if(k==2)
			data+=(c-'0')*10;
		if(k==3)
			data+=(c-'0');
	}
	printf("Data=%d",data);
}


