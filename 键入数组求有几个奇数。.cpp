//�����������м��������� 

#include <stdio.h>
int main()
{
	#define N (10)
	int a[N];
	int i,count=0;
    printf("������10��������\n");
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    for(i=0;i<N;i++)
    	if(a[i]%2)
           count++;
	printf("%d",count); 
	return 0;
}
