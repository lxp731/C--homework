//1468: 判断一个数是不是水仙花数  OJ
#include<stdio.h>
int main()
{
	int a,g,s,b;
	printf("input a number(注：153是水仙花数):\n");
	scanf("%d",&a);
	b=a/100;
	s=a/10-b*10;
	g=a%10;
	if(a==b*b*b+s*s*s+g*g*g)
	printf("this number is\n");
	else
	printf("this number is not\n");
	return 0;
}
