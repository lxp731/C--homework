#include<stdio.h>
#include<math.h>
int main()
{
long int num;
int a,b,c,d,e,place;
printf("please input a number(0--99999):\n");
scanf("%ld",&num);
if(num>=10000)
place=5;
else if(num>=1000)
place=4;
else if(num>=100)
place=3;
else if(num>=10)
place=2;
else
place=1;
printf("��������λ���ǣ�%d\n",place);
printf("ÿλ����Ϊ:");
e=num/10000;
d=(int)(num-e*10000)/1000;
c=(int)(num-e*10000-d*1000)/100;
b=(int)(num-e*10000-d*1000-c*100)/10;
a=(int)(num-e*10000-d*1000-c*100-b*10);
if(place == 5)
{
printf("%d,%d,%d,%d,%d",e,d,c,b,a);
printf("\n��������Ϊ:");
printf("%d,%d,%d,%d,%d\n",a,b,c,d,e);
}
if(place == 4)
{
printf("%d,%d,%d,%d",d,c,b,a);
printf("\n��������Ϊ:");
printf("%d,%d,%d,%d\n",a,b,c,d);
}
if(place == 3)
{
	printf("%d,%d,%d",c,b,a);
printf("\n��������Ϊ:");
printf("%d,%d,%d\n",a,b,c);
}
if(place == 2)
{
	printf("%d,%d",b,a);
printf("\n��������Ϊ:");
printf("%d,%d\n",a,b);

}
if(place == 1)
{
	printf("%d",a);
printf("\n��������Ϊ:");
printf("%d\n",a);

}

}
