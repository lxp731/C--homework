//1468: �ж�һ�����ǲ���ˮ�ɻ���  OJ
#include<stdio.h>
int main()
{
	int a,g,s,b;
	printf("input a number(ע��153��ˮ�ɻ���):\n");
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
