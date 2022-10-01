//1.[DAY 3]设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，
//且有：abc+bcc=532。求满足条件的所有a、b、c的值。
#include<stdio.h>
int main()
{
	int a,b,c,sum;
	for(a=0;a<=9;a++)
	{
		for(b=0;b<=9;b++)
		{
			for(c=0;c<=9;c++)
			if(a*100+b*10+c+b*100+c*10+c==532)
			printf("a=%d b=%d c=%d",a,b,c);
		}	
	}
	return 0;
}
