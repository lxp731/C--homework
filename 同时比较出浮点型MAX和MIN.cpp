#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	double a[n];
	for(i=0;i<n;i++)
	scanf("%lf",&a[i]);
	int min,max;
	min=a[0];
	for(i=1;i<n;i++)
		if(min>a[i])
		min=a[i];
	max=a[n-1];
	for(i=n-1;i>=0;i--)
	    if(max<a[i])
	    max=a[i];
	printf("%.2lf %.2lf",1.0*max,1.0*min);
	return 0;
}
