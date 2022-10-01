#include<stdio.h>
int main( )
{
	//#define N (10)
	int a[10];//={75,63,99,87,57,84,92,27,90,28};
	int i,max;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	max=a[0];
	for(i=1;i<10;i++)
	if (max<a[i])
	max=a[i];
	printf("max=%d\n",max);
	return 0;
 } 
 
 
//#include<stdio.h>
//int main()
//{
//	#define N (10)
//	int a[N]={1,1,2,1,3,1,5,8,1,9};
//	j=0;
//	for(i=0;i<N;i++)
//	if(a[i]!=x)
//	a[j++]=a[i];
//	for(i=0;i<j;i++)//这一行看不懂！！！！！ 
//	printf("%d ",a[i]);
//	return 0;
// } 
 
 
 
 
 
 
 
 
