//斐波那契问题  
//求前n项和。 

#include <stdio.h>
int main()
{
	int n,i,sum=0;
	printf("你想求前几项和？ "); 
	scanf("%d",&n);
	int a[n+1]={0,1};
	for(i=2;i<=n;i++)
	   a[i]=a[i-1]+a[i-2];
	for(i=1;i<=n;i++)
	sum+=a[i];
	printf("前 %d 项和是 %d\n",n,sum);
	return 0;
 } 


 //求前n项的值。 
// #include <stdio.h>
//int main()
//{
//	int n,i;
//	printf("你想知道前几项？\n");
//	scanf("%d",&n);
//	int a[n+1]={0,1};
//	for(i=2;i<=n;i++)
//	a[i]=a[i-1]+a[i-2];
//	for(i=1;i<=n;i++)
//	printf("%d ",a[i]);
//	return 0;
//}





