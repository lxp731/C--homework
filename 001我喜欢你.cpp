#include<stdio.h>
int main ()
{
	int n;
	printf("你喜欢我吗？\n");
	printf("\n");
    printf("1.喜欢  2.不喜欢  3.\n");
    printf("\n");
    scanf("%d",&n);
	printf("\n");
	if(n==1)
	printf("太棒了，我也喜欢你！\n",n);
	else if(n==2)
	printf("我喜欢你，与你无关。你就让我喜欢着就好了。\n",n);
	else if(n>2)
	printf("你妹的瞎输什么呢，有这个选项吗?\n",n);
	return 0;
 } 


