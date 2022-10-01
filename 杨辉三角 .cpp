//杨辉三角 
#include <stdio.h>
int main()
{
    int s = 1, h;               
    int i, j;      
    printf("输入行数:");
    scanf("%d",&h);      
    printf("1\n");           
    for (i = 2; i <= h; s = 1, i++)        
    {
        printf("1 ");                

        for (j = 1; j <= i - 2; j++) 
            
            printf("%d ", (s = (i - j) * s / j));

        printf("1\n");               
    }                   
    return 0;
}
