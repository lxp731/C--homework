#include<stdio.h>
int main()
{
int gy(int a,int b);
int gb(int a,int b);
int m,n,gys,gbs;
scanf("%d %d",&m,&n);
gys=gy(m,n);
gbs=gb(m,n);
printf("%d %d",gys,gbs);
return 0; 
}
int gy(int a, int b)
{ 
int z;
    for (z=a%b; z!=0;a=b,b=z,z=a%b);
    return b;
}
int gb(int a, int b)
{
int t;
t=(a*b)/gy(a,b);
    return t;
}
