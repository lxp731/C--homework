#include<stdio.h>
int main()
{
	int x,y=0;
	printf("������һ�������ո�������0������\n"); 
	while(scanf("%d",&x),x>0)
	{
	if(x%2==0)
	y+=x*x;
    }
	printf("����ż����ƽ�����ǣ�%d\n",y);
	return 0;
}
