#include <stdio.h>
int main()
{
    int i,j,k,n=0; 
    for(i=1;i<5;i++)
        for(j=1;j<5;j++)
            for(k=1;k<5;k++)
                if(i!=j&&i!=k&&j!=k)
                    {
                        n++;
                        printf("%d%d%d ",i,j,k);
                        if(n%6==0)
                        printf("\n");
                    }
    printf("\nÒ»¹²:%d\n",n);
    return 0;
}
