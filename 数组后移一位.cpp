#include<stdio.h>
int main( )
{
	int a[10];
	int i,x;
	for(i=0;i<10;i++)
	    scanf("%d",&a[i]);
	x=a[0];
	for(i=0;i<10;i++)
	    a[i]=a[i+1];
	a[9]=x;
	for(i=0;i<10;i++)
	    printf("%d ",a[i]);
	printf("\n");
	return 0;
}
