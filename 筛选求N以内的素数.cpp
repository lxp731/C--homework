#include<stdio.h>
int main ()
{
int n,i,j,k,t,a ,b,s[100];
 printf("ĞÕÃû£ºÁõÏşÅô\n");
    printf("Ñ§ºÅÊÇ£º18001030108\n");
printf("please input a number:");
while (scanf ("%d",&n)!=EOF) 
{
t=0;
if (n==2)
printf ("2\n");
else
{
for (j=2;j<n;j++)
{
b = 0; 
for (i=2;i<j;i++)
{
a=j%i;
if (a==0)
{
b=1;
break;
}
}
if (b!=1)
{
s[t]=j;
t++;
}
}
for (k=0;k<t;k++) 
{
printf ("%d\n",s[k]); 
}
printf("please input another number:");
}
}
return 0;
}
