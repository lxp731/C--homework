#include<stdio.h>
int main()
{
	int a,b,c,d,e,num,t=0;

	for(num=22222;num<=88888;num++)
	{
	    e=num/10000;
        d=(int)(num-e*10000)/1000;
        c=(int)(num-e*10000-d*1000)/100;
        b=(int)(num-e*10000-d*1000-c*100)/10;
        a=(int)(num-e*10000-d*1000-c*100-b*10);
	    if(num==a*10000+b*1000+c*100+d*10+e)
	    t++;
	}
	printf("%d",t);
	return 0;
}
