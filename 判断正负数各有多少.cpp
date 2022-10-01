#include<stdio.h>
int main()
{
	int z=0,f=0,n;
    while(scanf("%d",&n),n!=0) 
    {	
    if(n>0)
        z+=1;
    else
        f+=1;	
	}
    printf("%d\n",z);
    printf("%d",f);
	return 0; 
}
