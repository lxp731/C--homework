//2.	[DAY 1]����һ���ַ�����Ȼ������Ļ����ʾ"Hello, "����
//�ٽ�����ղ�������Ǹ��ַ��������磺����David   �����Hello, David
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10]="Hello ��",b[100];
	gets(b); 
	printf("%s\n",strcat(a,b));
	return 0;
}

