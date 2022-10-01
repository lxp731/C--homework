#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 30  
#define NULLKEY "\0"


typedef struct
{
    char name[20];
	char num[20];
	char add[30];
}Record;
Record Inf[M];
Record H[M];

int menu_select()

{
    int c;
	do
	{
	    system("cls");
		printf("**************************\n");
		printf("**********哈希表**********\n");
		printf("******1.创建哈希表********\n");
		printf("******2.按姓名散列********\n");
		printf("******3.按学号散列********\n");
		printf("******0.结束程序**********\n");
		printf("**************************\n");
		printf("\n");
		printf("请选择您要运行的选项按(0-3):");
		scanf("%d",&c);
		getchar();
	}
	while(c<0||c>3);
	return(c);
}


int Create(Record H[M])  //创建辅助数组
{
    int i;
	for(i=0;i<30;i++)
	{
	    strcpy( H[i].add,"\0");
		strcpy( H[i].num,"\0");
		strcpy( H[i].name,"\0");
	}
	i=0;
	char sign;
	while(sign!='n'&&sign!='N')
	{
	    printf("请输入名字\n");
		scanf("%s",Inf[i].name);
		printf("请输入学号\n");
		scanf("%s",Inf[i].num);
		printf("请输入地址\n");
		scanf("%s",Inf[i].add);
		printf("\t\t\t还需要继续输入吗?(Y/N)");
		scanf("\t\t\t%c",&sign);
		i++;
	}
	return i;
}


int Hash_name(char name[20])     //以姓名为关键字的哈希函数
{
    int i=0;
	int a=0;
	while(name[i]!='\0')
	{
	    a=a+name[i];
		i++;
	}
	a=a%29;
	return(a);
}


void input_name(Record Inf[M],int m,Record H[M])   //以姓名为关键字创建哈希表
{
    int j,key=0;
	for(j=0;j<m;j++)
	{
	    key=Hash_name(Inf[j].name);
		while(1)
		{
		    if(strcmp(H[key].name,NULLKEY)==0)
			{
			    strcpy(H[key].name,Inf[j].name);
				strcpy(H[key].num,Inf[j].num);
				strcpy(H[key].add,Inf[j].add);
				break;
			}
			else
			    key++;
			}
	}
}


int Hash_num(char num[20])    //以姓名为关键字的哈希函数
{ 
    int i=0;
	int b=0;
	while(num[i]!='\0')
	{ 
	    b=b+num[i];
		i++;
	}
	b=b%29;
	return(b);
}


void input_num(Record Inf[M],int m,Record H[M])    //以学号为关键字创建哈希表
{
    int j,key=0;
	for(j=0;j<m;j++)
	{
	    key=Hash_num(Inf[j].num);
		while(1)
		{
            if(strcmp(H[key].num,NULLKEY)==0)
			{
			    strcpy(H[key].name,Inf[j].name);
				strcpy(H[key].num,Inf[j].num);
				strcpy(H[key].add,Inf[j].add);
				break;
			}
			else
			key++;
		}
	}
}



int Search_name(Record H[],char name[20])   //以姓名为关键字的哈希表的查找函数
{    
    int key=0;
	key=Hash_name(name);
	while(strcmp(H[key].name,name)!=0)
	{ 
	    key++;
		if(strcmp(H[key].name,NULLKEY)==0)
		{
		    printf("查找名字不存在!\n");
			return(-1);
			break;
		}
	}
	return(key);
}




int Search_num(Record H[],char num[20])   //以学号为关键字的哈希表的查找函数
{
    int key=0;
	key=Hash_num(num);
	while(strcmp(num,H[key].num)!=0)
	{
	    key++;
		if(strcmp(H[key].num,NULLKEY)==0)
		{
            printf("查找学号不存在\n");
			return(-1);
			break;
		}
	}
	return(key);
}



void Insert_name(Record H[M],char name[20],char num[20],char add[30])  //以姓名为关键字哈希表的插入函数
{
    int key;
	key=Hash_name(name);
    while(1)
	{
	    if(strcmp(H[key].name,NULLKEY)==0)
        {
		    strcpy(H[key].name,name);
            strcpy(H[key].num,num);
			strcpy(H[key].add,add);
			break;
		}
        else
		    key++;
	}
}




void Insert_num(Record H[M],char name[20],char num[20],char add[30])
{                                               //以学号为关键字的哈希表插入函数
    int key;
	key=Hash_num(num);
    while(1)
	{
	    if(strcmp(H[key].num,NULLKEY)==0)
        {
		    strcpy(H[key].name,name);
            strcpy(H[key].num,num);
			strcpy(H[key].add,add);
			break;
		}
        else
		key++;
    }
}	



void Print_name(Record H[M])       //以姓名为关键字的哈希表的输出函数
{
    int i;
	printf("\t哈希地址\t姓名\t\t学号\t\t地址\n");
    for(i=0;i<30;i++)
	{
	    if(strcmp(H[i].name,"\0")!=0)
        {
		    printf("\t%d\t\t%s\t\t%s\t\t%s\n",i,H[i].name,H[i].num,H[i].add);
		}
	}
}	


void Print_num(Record H[M])   //以学号为关键字的哈希表的输出函数
{
    int i;
	printf("\t哈希地址\t姓名\t\t学号\t\t地址\n");
    for(i=0;i<30;i++)
	{
	    if(strcmp(H[i].num,"\0")!=0)
        {
		    printf("\t%d\t\t%s\t\t%s\t\t%s\n",i,H[i].name,H[i].num,H[i].add);
		}
	}
}



void Del_name(Record H[M],char name[20])  //以姓名为关键字的哈希表的删除函数
{
    int key,t=0;
	int i,k;
    key=Hash_name(name);
	i=key;
	while(1)
    {
	    if(strcmp(H[key].name,name)==0)
        {
		    t=1;
			strcpy(H[key].name,"\0");
            strcpy(H[key].num,"\0");
			strcpy(H[key].add,"\0");
            k=key;
			while(key<30)
			{
			    key++;
                if(Hash_name(H[key].name)==i)
                {
				    strcpy(H[k].name,H[key].name);
					strcpy(H[k].num,H[key].num);
                    strcpy(H[k].add,H[key].add);
					k=key;
					strcpy(H[key].name,"\0");
                    strcpy(H[key].num,"\0");
					strcpy(H[key].add,"\0");
				}
			}
        break;
		}
		key++;
	}
    if(t==0)
	printf("该姓名不存在!");
}


void Del_num(Record H[M],char num[20])   //以学号为关键字的哈希表的删除函数
{
    int key=0,t=0;
    key=Hash_num(num);
	int i,k;
	i=key;
	while(1)
    {
	    if(strcmp(H[key].num,num)==0)
        {
		    t=1;
			strcpy(H[key].name,"\0");
			strcpy(H[key].num,"\0");
            strcpy(H[key].add,"\0");
			k=key;
			while(key<30)
			{
                key++;
				if(Hash_num(H[key].num)==i)
				{
				    strcpy(H[k].name,H[key].name);
                    strcpy(H[k].num,H[key].num);
				    strcpy(H[k].add,H[key].add);
                    k=key;
					strcpy(H[key].name,"\0");
					strcpy(H[key].num,"\0");
                    strcpy(H[key].add,"\0");
				}
			}
			    break;
		}
            else
			    key++;
	}
        if(t==0)
		printf("该学号不存在!\n");
}	


int  main()
{
    char name[20],num[20];
	char a0[20],b0[20],c0[30];
    char a1[20],b1[20],c1[20];
	int m,i,g;
	int w,k;
	int flag=0;
    while(1)
	{
	    switch(menu_select())
		{
		    case 1 : m=Create(H);     break;
			case 2 : input_name(Inf,m,H);
			         Print_name(H);
					 while(1)
					 {
					    flag=0;
                        printf("\n");
						printf("1:查找\n");
                        printf("2:插入\n");
						printf("3:删除\n");
						printf("0:返回\n");
                        printf("输入（0-3）:\n");
						scanf("%d",&g);
                        switch(g)
						{
						    case 1 : 
							    printf("\n请输入要查找的名字：\n");
								scanf("%s",name);
								    k=Search_name(H,name);
								printf("查找该人的信息是：\n");
                                printf("该人的姓名是:%s\n",H[k].name);
                                printf("该人的学号是:%s\n",H[k].num);
                                printf("该人的地址是:%s\n",H[k].add);
								break;
                            case 2 :
							    printf("\n请输入要插入的信息：\n");
                                printf("插入的姓名是:");
								scanf("%s",a0);
                                printf("插入的电话是:");
								scanf("%s",b0);
                                    printf("插入的地址是:");
								scanf("%s",c0);
                                    Insert_name(H,a0,b0,c0);
								printf("插入后的结果:\n");
                                Print_name(H);
								break;
							case 3 :
                                printf("请输入要删除的名字:\n");
								scanf("%s",name);
                                    Del_name(H,name);
								printf("删除后的信息:\n");
                                Print_name(H);
								break;
							case 0 :
							    flag=1;
							    break;
                        } 
                        if(flag==1)
						    break;
					}
	                for(i=0;i<30;i++)
					{
	                    strcpy( H[i].add,"\0");
						strcpy(H[i].num,"\0");
                        strcpy( H[i].name,"\0");
					}
					break;
					printf("\n");
            case 3 :
			    input_num(Inf,m,H);
                Print_num(H);
				while(1)
				{
				    flag=0;
                    printf("\n");
					printf("1:查找\n");
                    printf("2:插入\n");
					printf("3:删除\n");
					printf("0:返回");
                    printf("输入（0-3）:\n");
					scanf("%d",&g);
                    switch(g)
					{
					    case 1 :
						    printf("请输入要查找的学号：\n");
                            scanf("%s",num);
							w=Search_num(H,num);
                            printf("查找该人的信息是：\n");
                            printf("该人的姓名是：%s\n",H[w].name);
                            printf("该人的学号是:%s\n",H[w].num);
                            printf("该人的地址是:%s\n",H[w].add);
                            break;
						case 2 :
                            printf("\n请输入要插入的信息：\n");
                            printf("插入的姓名是:");
							scanf("%s",a1);
                            printf("插入的电话是:");
							scanf("%s",b1);
                            printf("插入的地址是:");
							scanf("%s",c1);
                                Insert_num(H,a1,b1,c1);
							printf("插入后的结果:\n");
                                Print_num(H);
							break;
                        case 3 :
						    printf("请输入要删除的学号：");
                          	scanf("%s",num);
							    Del_num(H,num);
                            printf("删除后的信息：\n");
							    Print_num(H);
                            break;
						case 0 :
						flag=1;
						break;
					}
	                if(flag==1)
					    break;
				}
				for(i=0;i<30;i++)
                {
				    strcpy( H[i].add,"\0");
					strcpy( H[i].num,"\0");
                    strcpy( H[i].name,"\0");
				}
				break;
			case 0 :
			printf("欢迎使用！");
            exit(0);
			break;
		}
		system("pause");
	}
}




