//����������������Ȼ��������ֵ�� 

#include<stdio.h>
int main ()
{
	int a[3];
	int i,max;
	printf("��Ӽ���������������\n");
	for(i=0;i<3;i++)
	scanf("%d",&a[i]);
	max=a[0];
	for(i=1;i<3;i++)
	if (max<a[i])
	max=a[i];
	printf("max=%d\n",max);
	return 0;
}
