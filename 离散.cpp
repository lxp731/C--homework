#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
const int maxn=1e3+10;
int a[maxn][maxn];
int vis[maxn][maxn];
int v[maxn][maxn];
int num,s_ize;
int res;
void relation1()//�ж��Է������Է������Է�
{
	int flag=0;
	for(int i=1;i<=num;i++)
	{
		if(a[i][i])
			flag++;
	}
	if(flag==num)
		printf("�����Է���\n");
	else if(flag!=num&&flag!=0)
		printf("������Է���\n");
	else if(!flag)
		printf("���㷴�Է���\n");
}
void relation2()//�ж϶Գ�
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
		printf("����Գ���\n");
		res++;
	}
}
void relation3()//���Գ�,�ǶԳ� 
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
		printf("���㷴�Գ���\n");
	}
	if(!res)
		printf("����ǶԳ���\n");
}
void relation4()//������
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
		printf("�����㴫����\n");
	else
		printf("���㴫����\n");
}
int main(int argc, char const *argv[])
{
	printf("---------��ʼ���ж�Ԫ��ϵ���ж�---------\n");
	printf("��������Ҫִ�еĴ���\n");
	int t;
	scanf("%d",&t);
	int T=0;
	while(t--)
	{
		printf("�������Ĵ�С�������\n") ;
		printf("******Case%d:������ ******\n",++T);
		scanf("%d",&num);
		if(num<=0)
			break;
		printf("�����뼯���еĹ�ϵ������\n");
		scanf("%d",&s_ize);
		printf("�����뼯���еĹ�ϵԪ�أ�һ���� %d �Թ�ϵ %d ��Ԫ��(����������ʽ����) \n",s_ize,2*s_ize);
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
		printf("**********�����ϵ����**********\n");
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
	printf("********************��лʹ��********************\n");
	return 0;
}
