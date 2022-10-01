//键入数组求有几个奇数。 

#include <stdio.h>
int main()
{
	#define N (10)
	int a[N];
	int i,count=0;
    printf("请输入10个整数：\n");
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    for(i=0;i<N;i++)
    	if(a[i]%2)
           count++;
	printf("%d",count); 
	return 0;
}
