//6.[DAY 7] ��n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m������
#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=n-m;i<n;i++)
	printf("%d ",a[i]);
	for(int i=0;i<n-m;i++)
	printf("%d ",a[i]);
	return 0;
}
