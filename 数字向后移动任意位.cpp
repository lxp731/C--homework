//6.[DAY 7] 有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数。
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
