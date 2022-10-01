//输入两个正整数m和n（m<=n），求 S=1/m+1/(m+1)+1/(m+2)+…+1/(n-1)+1/n。结果保留10位小数。
//#include<stdio.h>
//int main()
//{
//	int m,n,x,y;
//	double S=0;
//	printf("请输入两个数，前者小于或等于后者。\n");
//	scanf("%d %d",&m,&n);
//	for(x=m;x<99999;x++)
//	for(y=n;y<99999;y++)
//	S=1/x+1/y;
//	printf("得数为：%.10lf\n"); 
//	return 0;
//}
//输入一个正整数n，计算1+1/3+1/5+…的前n项之和。结果保留10位小数
//计算1-1/4+1/7-1/10+1/13-1/16+…的前n项之和。
//计算1-2/3+3/5-4/7+5/9-6/11+…的前n项之和。

//#include<stdio.h>
//int main()
//{
//	int l=1,i=1,n;
//	double sum=0.0; 
//	printf("请输入一个正整数：",n);
//	scanf("%d",&n);
//	while(i<=n)
//	{
//		if(i%2)
//		sum+=(double)l/(2*i-1);
//		else
//		sum-=(double)l/(2*i-1);
//	    i++;
//	    l++;
//	}
//	printf("%.10lf\n",sum);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i=1,n;
//	double sum=0.0; 
//	printf("请输入一个正整数：",n);
//	scanf("%d",&n);
//	while(i<=n)
//	{
//		if(i%2)
//		sum+=(double)1/(3*i-2);
//		else
//		sum-=(double)1/(3*i-2);
//	    i++;
//	}
//	printf("%.12lf\n",sum);
//	return 0;
//}

//求满足S=1+2+3+4+…+n<m时n的最大值及S的值。
//#include<stdio.h>
//int main()
//{
//	int S=0,m,n=1;
//	printf("请输入一个正整数：");
//
//	scanf("%d",&m);
//    while(S<m)
//	{
//		S+=n;
//	    n++;
//	}	
//	printf("%d %d\n",n-1,S-(n-1));
//	return 0;
//}

//用公式 π/4 = 1 - 1/3 + 1/5 - 1/7 + … ,求π的近似值

//#include<stdio.h>
//int main()
//{
//	double e,i=1,sum=0;
//	printf("请输入一个足够小的数：");
//	scanf("%lf",&e);
//	while(1/(2*i-1)<e)
//	{
//		if(i%2)
//		sum-=1/(2*i-1);
//		else
//		sum+=1/(2*i-1);
//		i++;
//	}
//	printf("pi=%.10lf\n",4*sum);
//	return 0;
//}




















