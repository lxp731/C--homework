#include<stdio.h>
int main()
{
	int n;
    int yx,tg,bjg;
    yx=tg=bjg=0;
	while(scanf("%d",&n),n>0)
    {
    if(n>=85)
	yx++;
	else if(n>60&&n<84)
	tg++;
	else if(n<60)
	bjg++;	
	}
	printf(">=85:%d\n",yx);
	printf("60-84:%d\n",tg);
	printf("<60:%d\n",bjg);
	return 0;
}
