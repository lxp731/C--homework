//1 2 3 6 5 4 7 8 9 10
#include <stdio.h>
#define N 10 
int main()
{
	int j,i; 
    int a[N];
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    int temp = 0;
    for (j =N-1; j>0; j--)
    {
        for(i=0;i<j;i++)
            if (a[i]<a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i + 1] = temp;
            }
    }
    for (i = 0; i<N; i++)
        printf("%d ", a[i]);
}
