#include<stdio.h>
int main()
{
	char s[100],a[100];
	int i,j;
	gets(s);
	gets(a);
	for(i=0;s[i]!='\0';i++)
		for(j=0;a[j]!='\0';j++)
		if(s[i]==a[j])
			s[i]=s[i+1];	
	puts(s); 
	return 0;
 } 
