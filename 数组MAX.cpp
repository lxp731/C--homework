#include<stdio.h>
int main ( )
{
    #define N (5)
    int a[N]={23,45,66,45,76};    
	int i,max;
	max=a[0];
	for(i=1;i<N;i++)
	if(max<a[i])
	max=a[i];
	printf("max=%d\n",max);
	return 0;
 } 
