#include <stdio.h>
int main()
{
int num;
int i,j;
printf("�������������ɵ������θ߶ȣ� ");
scanf("%d",&num);
for(i=1; i<=num; i++)         //���ѭ���������Ʋ��� 
 {

    for(j=1; j<2*num; j++)    //2*num - 1����ײ㣬Ҳ���ǿռ���Ҫ����һ���ַ��������������ѭ����ʼֵ��1������2*num����-1��   
    {
       if(j>num-i&&j<num+i)   //����������Ե�һ�е�*Ϊ�������ģ�num - i �� num + i�����᷶Χ��ÿ�����*�ķ�Χ����������ո�        
         printf("%c",'*');
       else
         printf(" ");
    }
    printf("\n");
 }
return 0;
}
