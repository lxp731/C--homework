#include<stdio.h>
#include<math.h>
int main ()
{
	printf("������������\n"); 
	printf("�ҵ�ѧ���ǣ�18001030108\n");
	double a,b,c,s,p;
    printf("�������������������εıߣ�");
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c)); 
	printf("%lf\n",s);
	return 0;
}

