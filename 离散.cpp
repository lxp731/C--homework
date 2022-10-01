#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
const int maxn=1e3+10;
int a[maxn][maxn];
int vis[maxn][maxn];
int v[maxn][maxn];
int num,s_ize;
int res;
void relation1()//判断自反，反自反，非自反
{
	int flag=0;
	for(int i=1;i<=num;i++)
	{
		if(a[i][i])
			flag++;
	}
	if(flag==num)
		printf("满足自反性\n");
	else if(flag!=num&&flag!=0)
		printf("满足非自反性\n");
	else if(!flag)
		printf("满足反自反性\n");
}
void relation2()//判断对称
{
	int flag=0;
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=num;j++)
		{
			if(a[i][j]==a[j][i]&&vis[i][j])
			{
				flag++;
				vis[i][j]=0;
			}
		}
	}
	if(flag==s_ize)
	{
		printf("满足对称性\n");
		res++;
	}
}
void relation3()//反对称,非对称 
{
	int flag=0;
	for(int i=1;i<num;i++)
	{
		for(int j=i+1;j<=num;j++)
		{
			if(a[i][j]&&a[j][i]&&i!=j)
			{
				flag++;
				break;
			}
		}
	}
	if(flag==0)
	{
		res++;
		printf("满足反对称性\n");
	}
	if(!res)
		printf("满足非对称性\n");
}
void relation4()//传递性
{
	int flag=1;
	int num1,num2;
	for(int i=1;i<s_ize;i++)
	{
		for(int j=2;j<=s_ize;j++)
		{
			if(v[i][2]==v[j][1])
			{
				num1=v[i][1],num2=v[j][2];
				if(vis[num1][num2]!=1)
				{
					flag=0;
					break;
				}
			}
		}
		if(!flag)
			break;
	}
	if(!flag)
		printf("不满足传递性\n");
	else
		printf("满足传递性\n");
}
int main(int argc, char const *argv[])
{
	printf("---------开始进行二元关系的判断---------\n");
	printf("请输入需要执行的次数\n");
	int t;
	scanf("%d",&t);
	int T=0;
	while(t--)
	{
		printf("定义矩阵的大小后继续。\n") ;
		printf("******Case%d:请输入 ******\n",++T);
		scanf("%d",&num);
		if(num<=0)
			break;
		printf("请输入集合中的关系个数：\n");
		scanf("%d",&s_ize);
		printf("请输入集合中的关系元素，一共有 %d 对关系 %d 个元素(请以整数形式输入) \n",s_ize,2*s_ize);
		int x,y;
		res=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int k=1;k<=s_ize;k++)
		{
			scanf("%d%d",&x,&y);
			v[k][1]=x;
			v[k][2]=y;
			a[x][y]=1;
			vis[x][y]=1;
		}
		int i,j;
		printf("**********输出关系矩阵**********\n");
		for(i=1;i<=num;i++)
		{
			for(j=1;j<=num;j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		relation1();
		relation2();
		relation3();
		relation4();
		printf("\n");
	}
	printf("********************感谢使用********************\n");
	return 0;
}
