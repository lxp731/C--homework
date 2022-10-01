#include<stdio.h>
int main()
{
    int i,j,k,n;
    printf("水仙花数有这些：\n",n); 
    for(n=100;n<1000;++n)	
    {
        i=n/100;
        j=n/10-i*10; //j=n/10%10
        k=n%10;
        if(n==i*i*i+j*j*j+k*k*k)
        printf("%d\n",n);
    }
    return 0;
 } 
 /*#include<stdio.h>
 int main()
 {
 	int n;
 	int a,b,c;
 	for(n=100;n<=999;n++)
 	{
 		a=n%10;
 		b=n%100/10;
 		c=n/100;
 		if(n==a*a*a+b*b*b+c*c*c)
 		printf("水仙花数有这些：%d\n",n);
 	//	printf("%d\n",n);
	 }
 	return 0;
 }*/
 
//判断水仙花数 
// #include<stdio.h>
//int main()
//{
//	int a[10],n,b,s,g;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	    scanf("%d",&a[i]);
//	for(int i=0;i<n;i++)
//	{
//		b=a[i]/100;
//		s=a[i]/10-b*10;
//		g=a[i]%10;
//		if(a[i]==b*b*b+s*s*s+g*g*g&&a[i]!=0)
//		printf("Y\n");
//		else
//		printf("N\n");
//	}
//    return 0;
//}
