#include<stdio.h>
int main()
{
	int i,j,k,n;
	n=100,k=0;
	for(i=0;i<=n/5;i++)
	for(j=0;j<=(n-5*i)/2;j++)
	{
		printf("5cent=%d\t2cent=%d\t1cent=%d\n",i,j,n-i*5-j*2);
		k++;
	}
	printf("total times=%d\n",k);
	return 0;
}
