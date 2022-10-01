//#include<stdio.h>
//int main()
//{
//	printf("本程序只能计算同一年内的短期情况\n\n\n");
//	int sm=0, sd=0 ,em=0, ed=0, day=0,year;
//	printf("请输入年份\n");
//	scanf("%d",&year);
//	printf("请输入开始日期（例如：8 7）\n");
//	scanf("%d %d",&sm,&sd);
//	printf("请输入结束日期（例如：8 7）\n");
//	scanf("%d %d", &em, &ed);
//	if (sm == em)
//	{
//		day = ed - sd + 1;
//	}
//	else
//	{
//		switch (sm)
//		case 1
//	}
//	printf("一共经过了%d天\n",day);
//	return 0;
//}




#include<stdio.h>
int main( )
{
	int gz;
	int sn,sy,sr,x1;
	int en,ey,er,x2;
	printf("请输入一天的工资是多少钱\n");
	scanf("%d",&gz);
	printf("请输入起始的年月日，用空格分开即可：\n");
	scanf("%d %d %d",&sn,&sy,&sr);
	printf("请输入结束的年月日，用空格分开即可：\n");
	scanf("%d %d %d",&en,&ey,&er);
	switch(sy)
	{
		case 12 : x1+=30;
		case 11 : x1+=31;
		case 10 : x1+=30;
		case 9  : x1+=31;
		case 8  : x1+=30;
		case 7  : x1+=31;
		case 6  : x1+=30;
		case 5  : x1+=31;
		case 4  : x1+=30;
		case 3  : x1+=28;
		case 2  : x1+=30;
		case 1  : x1+= sr;
	}
	if(sy>2&&sn/400==0)
	    x1++;
	switch(ey)
	{
		case 12 : x2+=30;
		case 11 : x2+=31;
		case 10 : x2+=30;
		case 9  : x2+=31;
		case 8  : x2+=30;
		case 7  : x2+=31;
		case 6  : x2+=30;
		case 5  : x2+=31;
		case 4  : x2+=30;
		case 3  : x2+=28;
		case 2  : x2+=30;
		case 1  : x2+=er;
	}
	if(sy>2&&en/400==0)
	    x2++;
		printf("一共经过了%d天\n",x2-x1);
		printf("应付的工资是%d元",(x2-x1)*gz);
	return 0;
}
