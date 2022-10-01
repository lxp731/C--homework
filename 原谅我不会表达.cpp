//求你输入值m的...我靠就这个1+2+3+4+...他们的和小于m。 
//输出最多加到第几项和 最后一项是多少。 

#include<stdio.h>
int main(void)
{
	int s=0,m,i;
	scanf("%d",&m);
	for(i=1;;++i)
	{
		s+=i;
		if(s>m) break;
	}
	//printf("s=%d \n",i);
	printf("n=%d,s=%d\n",i-1,s-i);
	return 0;
}
