#include<stdio.h>
int main()
{
	int n,count=0,sum=0;
	double pjz;
	printf("请输入一组数，空格间隔，以0结束。\n"); 
	while(scanf("%d",&n),n>0)
	{
		if(n%2)
		{
		count++;
		sum+=n;
	    }
	}
	pjz=(double)sum/count;
	printf("其中偶数的平均值是：%.10lf\n",pjz);
	return 0;
 } 
