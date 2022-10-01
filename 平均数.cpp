#include<stdio.h>
int  main( )
{
	int a,b;
	printf("姓名：刘晓鹏\n");
    printf("学号是：18001030108\n");
	printf("请输入两个数：");
	scanf("%d %d",&a,&b); 
	int average;
	average=(a+b)/2;
	printf("平均数为%d",average);
	return 0;
}
