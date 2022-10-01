#include<stdio.h>
int main()
{
	int year,leap;
	scanf("%d",&year);
	if(year%4)
	leap=0;
	else leap=1;
	if(leap)
	printf("%d is",year);
	else printf("%d is not",year);
	printf(" a leap year.\n");
	return 0;
}
