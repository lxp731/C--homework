#include<stdio.h>
int main()
{
	int n,count=0,sum=0;
	double pjz;
	printf("������һ�������ո�������0������\n"); 
	while(scanf("%d",&n),n>0)
	{
		if(n%2)
		{
		count++;
		sum+=n;
	    }
	}
	pjz=(double)sum/count;
	printf("����ż����ƽ��ֵ�ǣ�%.10lf\n",pjz);
	return 0;
 } 
