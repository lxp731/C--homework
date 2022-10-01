#include<stdio.h>
int main()
{
	int a,b,c;
	printf("请输入两个数a,b：");
	scanf("%d %d",&a,&b);
	if(a>=b)
	printf("%d\n",a+b);
	else
	printf("%d\n",a*b);
	return 0;
}
