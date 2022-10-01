#include<stdio.h>
int main()
{
	char a[100],b[100];
	gets(a);
	int i,j=0;
	for(i=0;a[i]!='\0';i++)
	if(a[i]>='0'&&a[i]<='9')
	b[j++]=a[i];
	for(i=0;i<j;i++)
	{
		b[i]-=48;//b[i]-='0';¶¼¿ÉÒÔ¡£ 
		printf("%d",b[i]);
	}
	printf("\n");
	return 0; 
}











