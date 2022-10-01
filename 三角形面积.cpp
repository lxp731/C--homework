#include<stdio.h>
#include<math.h>
int main ()
{
	printf("我是刘晓鹏。\n"); 
	printf("我的学号是：18001030108\n");
	double a,b,c,s,p;
    printf("请输入三个满足三角形的边：");
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c)); 
	printf("%lf\n",s);
	return 0;
}

