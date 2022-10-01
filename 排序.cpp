#include<stdio.h>
int main()
{
	int a[10];
	int i,ctn,j;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]); 
	for(j=9;j>0;j--)
	{
		for(i=0;i<j;i++)
		if(a[i]<a[i+1])
		{
			ctn=a[i];
			a[i]=a[i+1];
			a[i+1]=ctn;
		}
	}
	for(i=0;i<10;i++) 
	printf("%d ",a[i]);
	return 0;
 }
