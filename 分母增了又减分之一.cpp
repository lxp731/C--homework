//��������������m��n��m<=n������ S=1/m+1/(m+1)+1/(m+2)+��+1/(n-1)+1/n���������10λС����
//#include<stdio.h>
//int main()
//{
//	int m,n,x,y;
//	double S=0;
//	printf("��������������ǰ��С�ڻ���ں��ߡ�\n");
//	scanf("%d %d",&m,&n);
//	for(x=m;x<99999;x++)
//	for(y=n;y<99999;y++)
//	S=1/x+1/y;
//	printf("����Ϊ��%.10lf\n"); 
//	return 0;
//}
//����һ��������n������1+1/3+1/5+����ǰn��֮�͡��������10λС��
//����1-1/4+1/7-1/10+1/13-1/16+����ǰn��֮�͡�
//����1-2/3+3/5-4/7+5/9-6/11+����ǰn��֮�͡�

//#include<stdio.h>
//int main()
//{
//	int l=1,i=1,n;
//	double sum=0.0; 
//	printf("������һ����������",n);
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
//	printf("������һ����������",n);
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

//������S=1+2+3+4+��+n<mʱn�����ֵ��S��ֵ��
//#include<stdio.h>
//int main()
//{
//	int S=0,m,n=1;
//	printf("������һ����������");
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

//�ù�ʽ ��/4 = 1 - 1/3 + 1/5 - 1/7 + �� ,��еĽ���ֵ

//#include<stdio.h>
//int main()
//{
//	double e,i=1,sum=0;
//	printf("������һ���㹻С������");
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




















