//쳲���������  
//��ǰn��͡� 

#include <stdio.h>
int main()
{
	int n,i,sum=0;
	printf("������ǰ����ͣ� "); 
	scanf("%d",&n);
	int a[n+1]={0,1};
	for(i=2;i<=n;i++)
	   a[i]=a[i-1]+a[i-2];
	for(i=1;i<=n;i++)
	sum+=a[i];
	printf("ǰ %d ����� %d\n",n,sum);
	return 0;
 } 


 //��ǰn���ֵ�� 
// #include <stdio.h>
//int main()
//{
//	int n,i;
//	printf("����֪��ǰ���\n");
//	scanf("%d",&n);
//	int a[n+1]={0,1};
//	for(i=2;i<=n;i++)
//	a[i]=a[i-1]+a[i-2];
//	for(i=1;i<=n;i++)
//	printf("%d ",a[i]);
//	return 0;
//}





