//#include<stdio.h>
//int max(int x,int y)
//{
//	return x>y?x:y;
// } 
// int main()
// {
// 	int num1;
// 	printf("please input the first number:");
// 	scanf("%d",&num1);
// 	int num2;
// 	printf("please input the second number:");
// 	scanf("%d",&num2);
// 	printf("max=%d\n",max(num1, num2));
// 	return 0;
// }
 
 
#include<stdio.h> 
int main ( )
{
int max(int x,int y,int z);
int a,b,c,e;
scanf("%d%d%d",&a,&b,&c);
e=max(a,b,c);
printf("max=%d\n",e);
}
int max(int x,int y,int z)
{
int m;
if (x>y) m=x;
else m=y;
if (z>m) m=z;
else 
return(m);
}



