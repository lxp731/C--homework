#include<stdio.h>
#include<string.h>
int main(){
	char t,str[255],str_copy[255];
	int i=0,len;
	while(scanf("%c",&t)&&(t!='\n')){
		str[i]=t;
		i++;
	}
	str[i] = '\0';
	str_copy[i] = '\0';
	i = 0;
	len = strlen(str);
	while(len--)
	{
		str_copy[len]=str[i];
		i++;
	}
	printf("%s\n",(!strcmp(str,str_copy))?"Yes":"No");
}
