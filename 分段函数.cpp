#include <stdio.h>
int main()
{ 
    int x;
    printf("姓名：刘晓鹏\n");
    printf("学号是：18001030108");
    printf("请输入一个数x\n");
    scanf("%d",&x);
    if(x<1)
    printf("%d\n",x);
    else if(x>=1&&x<=10)
    printf("%d\n",2*x-1);
    else if(x>=10)
    printf("%d\n",3*x-11);
	
	return 0;
  
}
