//2.	[DAY 1]输入一个字符串，然后在屏幕上显示"Hello, "串后，
//再接上你刚才输入的那个字符串。例如：输入David   输出：Hello, David
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10]="Hello ，",b[100];
	gets(b); 
	printf("%s\n",strcat(a,b));
	return 0;
}

