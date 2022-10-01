//这个程序可以转换单个的字母,加等变小写，减等变大写。 

#include<stdio.h>
int main()
{
	char str[255];
	char ch;
	int i;
	gets(str);
	scanf("%c",&ch);
	for(i=0;str[i]!='\0';i++)
	{
	if(str[i]==ch)
	str[i]+=32;
	}
	puts(str);
	return 0;
}


/*这个程序可以转换一组字母*/ 

//#include<stdio.h>
//int main()
//{
//	char a[66],b[66];
//	int i,j;
//	gets(a);
//	gets(b);
//	for(i=0;a[i]!='\0';i++)
//	{
//		for(j=0;b[j]!='\0';j++)
//		if(a[i]==b[j])
//		a[i]-=32;
//	}
//	puts(a);
//	return 0;
//}






