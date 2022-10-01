//键盘输入十个数，然后实现逆向输出。

 
#include<stdio.h>
int main()
{
    int a[10],i;
    printf("请输入十个数:\n");
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    for(i=9;i>=0;i--)
    printf("%d ",a[i]);
    return 0;
} 
