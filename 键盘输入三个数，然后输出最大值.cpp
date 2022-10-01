//键盘输入三个数，然后输出最大值。 

#include<stdio.h>
int main ()
{
	int a[3];
	int i,max;
	printf("请从键盘输入三个数：\n");
	for(i=0;i<3;i++)
	scanf("%d",&a[i]);
	max=a[0];
	for(i=1;i<3;i++)
	if (max<a[i])
	max=a[i];
	printf("max=%d\n",max);
	return 0;
}
