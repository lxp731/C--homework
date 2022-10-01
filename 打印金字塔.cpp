#include <stdio.h>
int main()
{
int num;
int i,j;
printf("请输入您想生成的三角形高度： ");
scanf("%d",&num);
for(i=1; i<=num; i++)         //这个循环用来控制层数 
 {

    for(j=1; j<2*num; j++)    //2*num - 1是最底层，也就是空间需要最大的一层字符数量，这个控制循环初始值是1，所以2*num不用-1。   
    {
       if(j>num-i&&j<num+i)   //这个部分是以第一行的*为数轴中心，num - i 到 num + i的数轴范围是每层输出*的范围，其他输出空格        
         printf("%c",'*');
       else
         printf(" ");
    }
    printf("\n");
 }
return 0;
}
