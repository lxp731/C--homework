#include<stdio.h>
int main()
{
	int n;
	printf("你喜欢我吗？\n");
	printf("\n");
    printf("1.喜欢  2.不喜欢  3.\n");
    printf("\n");
	scanf("%d",&n);
	printf("\n");
	switch(n)
{
	case 1 :
	printf("太棒了，我也喜欢你！\n");
	break;
	case 2 :
	printf("我喜欢你，与你无关。\n");
	break;
	case 3 :
	printf("我3选项都没写内容你就敢输，在下敬你是条汉子。有着超越前人的思维，是个可塑之才。\n");
}
	return 0;
 } 
