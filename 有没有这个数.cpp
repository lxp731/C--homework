#include<stdio.h>
#include<string.h>
int main()
{
	int a[10];
	int i,n,find=0;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	scanf("%d",&n);
	for(i=0;i<10;i++)
	if(a[i]==n)
	{
		find=1;
		break;
	}
	if(find)
	printf("%d\n",i);
	else
	printf("no this number\n");
	return 0;
 } 
