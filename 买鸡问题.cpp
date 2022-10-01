#include <iostream>
int main()
{
    int  g,m,x;
    for(g=0;g<=19;g++)
    {
    	for(m=0;m<=100-g;m++)
    	{
    		x=100-g-m;
    		if(5*g+3*m+x/3==100)
    		printf("%d, %d, %d\n",g,m,x);
		}
	}
//	return 0;
}
//#include<stdio.h>
//int main()
//{
//	int a,b,c;
//	a=0;
//	while(a<=19)
//	{
//		b=0;
//		while(b<=100-a)
//		{
//			c=100-a-b;
//			if(5*a+3*b+c/3==100)
//			  printf("%d,%d,%d\n",a,b,c);
//			 b++; 
//		}
//		a++;
//	}
//	return 0;
//}

