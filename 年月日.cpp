#include<stdio.h>
int main( )
{
	int n,y,r,x;
	printf("����������֪���������գ��ÿո�ֿ����ɣ�\n");
	scanf("%d %d %d",&n,&y,&r);
	switch(y)
	{
		case 12 : x+=30;
		case 11 : x+=31;
		case 10 : x+=30;
		case 9  : x+=31;
		case 8  : x+=30;
		case 7  : x+=31;
		case 6  : x+=30;
		case 5  : x+=31;
		case 4  : x+=30;
		case 3  : x+=28;
		case 2  : x+=30;
		case 1  : x+= r;
	}
	if(y>2&&n/400==0)
	    x++;
		printf("��һ������һ��ĵ�%d��\n",x); 
	return 0;
}
