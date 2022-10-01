#include<stdio.h>
int main()
{
	int a;

	printf("1.添加会员信息\n");
	printf("2.查询会员信息\n");
	printf("3.删除会员信息\n");
	printf("4.会员统计\n");
	printf("5.修改会员信息\n");
	printf("\n");
	printf("你想进行的操作"); 
	scanf("%d",&a); 
	struct VIP
	{
		int num;
		char name[20],type;
	};	
	struct VIP lq;
	switch(a)
	{
		case 1:	
			const char* filename "E:\VIP\李倩.txt";
			FILE* xp = fopen(filename,"wb");
		if(xp==NULL)
		{
			printf("failed to open file!\n");
			return -1;
		}
		char x[];
		scanf("%s",&x);
		fwrite(x,1,25,xp);
		
		fclose(xp);
		break;
		case 2:  ;//这儿填填 （查找文件信息） 
		break;
		case 3:  ;//不会 （删除相应的文件）
		break;
		case 4:  ;// 用for循环遍历 
		break;
		case 5:  ;//问别人吧 （没学过） 
		break;    
	}
	return 0;
}

