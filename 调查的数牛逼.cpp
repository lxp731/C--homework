//调查的数，综合考察数组和for循环。 

#include<stdio.h>
int main()
{
	int n;
	printf("你想调查几个数\n");
	scanf("%d",&n);
	printf("\n");
	int a[n+1],i,count=0; 
	printf("请输入你要调查的数\n"); 
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	if(a[i]%2) 
	count++;
	printf("\n");
	printf("你调查的数中有 %d 个奇数",count);
	return 0;
 } 
