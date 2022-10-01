#include<stdio.h>
int main()
{
	#define SIZE 9
	int i,j;
	for(i=1;i<=SIZE;i++)
	{
		for(j=1;j<=i;j++)
		printf("%d*%d=%2d ",j,i,i*j);
		printf("\n");
    }
	return 0;
}



