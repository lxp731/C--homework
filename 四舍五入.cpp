//【if语句】编写程序，大连出租车的运价规定为：白天（6点至22点，不含22点）：三公里内起步价为10.0
// 元三公里以外每公里的运价为2.0元。晚上（22点至6点）：三公里内起步价为12.0元，三公里以外每公里的
// 运价为2.4元。编写程序，从键盘上输入乘车时间及乘车里程数，计算出车费（车费以元为单位，四舍五入）
// ，并输出在屏幕上。（注：不考虑临界点跳表的情况）
//例如：输入：4 4
//      输出：14
//      输入：21 4
//      输出：12
//【测试数据有多组，每组输出结果后必须换行】
#include<stdio.h>
int main()
{
	double tm,km,money;
	printf("请分别输入你坐车时间和乘车里程数。\n");
	scanf("%lf %lf",&tm,&km);
	if(tm>=6&&tm<=22)
	{
		if(km<=3)
		money=10;
		else
		money=10+2*(km-3);
	}
	else
	{
		if(km<=3)
		money=12;
		else
		money=12+2.4*(km-3);
	}
	if(money-(int)money<0.5)
	printf("%d\n",(int)money);
	else
	printf("%d\n",(int)money+1);
	return 0;
 } 
