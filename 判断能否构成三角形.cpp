//7.	[DAY 1]是否构成三角形。输入三个数值，
//判断它们是否构成三角形。输出1表示能构成三角形，输出0表示不能构成三角形。

#include<stdio.h>
int main()
{
	float a,b,c;
	printf("input three numbers(空格间隔):\n");
	scanf("%f%f%f",&a,&b,&c);
	if(a+b>=c&&b+c>=a&&a+c>=b)
	printf("1\n");
	else
	printf("0\n");
	return 0;
}

