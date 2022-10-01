//6.[DAY 1]输入一个不超过3位的整数，从左到右将该数的各位
//数值所对应的英文输出在屏幕上，
//英文之间用空格分隔。例如，输入104，输出one zero four
//#include<stdio.h>
//int main()
//{
//	int a[3],i;
//	printf("input three numbers(空格间隔):\n");
//	for(i=0;i<3;i++)
//	scanf("%d",&a[i]);
//	for(i=0;i<3;i++)
//	{
//		switch(a[i])
//		{
//			case 0 : printf("zero ");break;
//			case 1 : printf("one ");break;
//			case 2 : printf("tow ");break;
//			case 3 : printf("three ");break;
//			case 4 : printf("four ");break;
//			case 5 : printf("five ");break;
//			case 6 : printf("six ");break;
//			case 7 : printf("seven ");break;
//			case 8 : printf("eight ");break;
//			case 9 : printf("nine ");break;
//		}
//	}
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//char m,n,q;
//int m1,n1,q1;
//char a[11]={'1','2','3','4','5','6','7','8','9','0'};
//char *b[11]={"one","two","three","four","five","six","seven","eight","nine","zero"};
//scanf("%c%c%c",&n,&m,&q);
//for(int i=0;i<10;i++)
//{
//if(a[i]==n)
//{
//n1=i;
//}
//if(a[i]==m)
//{
//m1=i;
//}
//if(a[i]==q)
//{
//q1=i;
//}
//}
//printf("%s %s %s",b[n1],b[m1],b[q1]);
//return 0;
//}



#include<stdio.h>
int main()
{
	int a,b,s,g;
	printf("输入一个不超过3位的整数:\n");
	scanf("%d",&a); 
	b=a/100;
	s=a/10-b*10;
	g=a%10;
	int c[3];
	c[0]=b;
	c[1]=s;
	c[2]=g;
	for(int i=0;i<3;i++)
	{
		switch(c[i])
		{
			case 0 : printf("zero ");break;
			case 1 : printf("one ");break;
			case 2 : printf("tow ");break;
			case 3 : printf("three ");break;
			case 4 : printf("four ");break;
			case 5 : printf("five ");break;
			case 6 : printf("six ");break;
			case 7 : printf("seven ");break;
			case 8 : printf("eight ");break;
			case 9 : printf("nine ");break;
		}
	}
	return 0;
}
