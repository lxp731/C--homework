//��������ֵm��...�ҿ������1+2+3+4+...���ǵĺ�С��m�� 
//������ӵ��ڼ���� ���һ���Ƕ��١� 

#include<stdio.h>
int main(void)
{
	int s=0,m,i;
	scanf("%d",&m);
	for(i=1;;++i)
	{
		s+=i;
		if(s>m) break;
	}
	//printf("s=%d \n",i);
	printf("n=%d,s=%d\n",i-1,s-i);
	return 0;
}
