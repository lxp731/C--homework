//求s=a+aa+aaa+aaaa+aa...a的值，a是一位数。
//例如2+22+222+2222+22222(此时共有5个数相加)
#include<stdio.h>
int main( )
{
	int a,n,p=0,sum=0;
	scanf("%d%d",&a,&n);
	for(int i=1;i<=n;i++)
	{
		p=10*p+a;
		sum+=p;
	 } 
    printf("%d",sum);
    return 0;
}

