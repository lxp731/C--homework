#include<stdio.h>
int main()
{
	int x,y=0;
	printf("请输入一组数，空格间隔，以0结束。\n"); 
	while(scanf("%d",&x),x>0)
	{
	if(x%2==0)
	y+=x*x;
    }
	printf("其中偶数的平方和是：%d\n",y);
	return 0;
}
