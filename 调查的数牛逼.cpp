//����������ۺϿ��������forѭ���� 

#include<stdio.h>
int main()
{
	int n;
	printf("������鼸����\n");
	scanf("%d",&n);
	printf("\n");
	int a[n+1],i,count=0; 
	printf("��������Ҫ�������\n"); 
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	if(a[i]%2) 
	count++;
	printf("\n");
	printf("������������ %d ������",count);
	return 0;
 } 
