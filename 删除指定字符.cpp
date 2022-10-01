#include<stdio.h>
int main()
{
	char a[255],x;
	gets(a);
	scanf("%c",&x);
	int i,j;
	for(i=0;a[i]!='\0';i++)
	{
		if (a[i]==x)
		{
			j=i--;
			while(a[j]!='\0')
			{
				a[j++]=a[j];
			}
		}
	}
	printf("%s\n",a);
} 
