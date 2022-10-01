#include<stdio.h>
int main()
{
	int n;
	   printf("你喜欢我吗？\n");
	   printf("\n");
       printf("1.喜欢  2.不喜欢  3.\n");
       printf("\n");
	while(scanf("%d",&n),n>1)
	{
		if(n==2)
		{
			printf("\n");
			printf("你真的不喜欢我吗？\n");
		    printf("\n");
	   	    printf("再给你一次机会选择。\n");
		    printf("\n");
		}
		if(n==3)
		{
			printf("\n");
			printf("亲，这个选项无意义哦。\n");
			printf("\n");
			printf("再给你一次机会选择。\n");
			printf("\n");
		}
	    printf("你喜欢我吗？\n");
	    printf("\n");
        printf("1.喜欢  2.不喜欢  3.\n");
        printf("\n");
	}
	printf("哈哈，我也喜欢我自己！\n");
	return 0;
}
