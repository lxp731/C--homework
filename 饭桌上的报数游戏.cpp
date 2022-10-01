 #include<stdio.h>
#include "stdlib.h"
int primeList[] = {2, 3, 5, 7, 11, 13, 17};
int primeCounter[] = {0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6, 7, 7};
int main()
{
int m, n, i, j, num, acc, t;
int counter[20][2] = {0};
printf("please input n: ");
scanf("%d", &n);
if (n<=3 || n>=20)
{
printf("error n, game over\n");
return 0;
}
num = primeCounter[n-1];
acc = 1;
t = rand();
m = primeList[t%num];
primeList[t%num] = 0;
printf("m = %d\n", m);
printf("please input begin number: ");
scanf("%d", &j);
if (j<1 || j>n)
{
printf("error number, game over\n");
return 0;
}
j--;
i = 1;
do
{
if (counter[j][1] == 0)
{
i++;
if (i%m == 0)
{
counter[j][0]++;
if (counter[j][0] == 5)
{
break;
}
if (counter[j][0] == 3)
{
acc++;
if (acc > num)
{
printf("not available m, game over\n");
return 0;
}
do
{
t = rand();
i = primeList[t%num];
}
while (i == 0);
primeList[t%num] = 0;
m = i;
printf("m = %d\n", m);
i = 1;
}
counter[j][1] = 1;
}
}
else
{
counter[j][1] = 0;
}
j = (j+1)%n;
}
while (1);
printf("number %d drink 5 glasses\n"); 
}

