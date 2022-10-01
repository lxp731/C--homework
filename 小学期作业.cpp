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
		printf("**********��ϣ��**********\n");
		printf("******1.������ϣ��********\n");
		printf("******2.������ɢ��********\n");
		printf("******3.��ѧ��ɢ��********\n");
		printf("******0.��������**********\n");
		printf("**************************\n");
		printf("\n");
		printf("��ѡ����Ҫ���е�ѡ�(0-3):");
		scanf("%d",&c);
		getchar();
	}
	while(c<0||c>3);
	return(c);
}


int Create(Record H[M])  //������������
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
	    printf("����������\n");
		scanf("%s",Inf[i].name);
		printf("������ѧ��\n");
		scanf("%s",Inf[i].num);
		printf("�������ַ\n");
		scanf("%s",Inf[i].add);
		printf("\t\t\t����Ҫ����������?(Y/N)");
		scanf("\t\t\t%c",&sign);
		i++;
	}
	return i;
}


int Hash_name(char name[20])     //������Ϊ�ؼ��ֵĹ�ϣ����
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


void input_name(Record Inf[M],int m,Record H[M])   //������Ϊ�ؼ��ִ�����ϣ��
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


int Hash_num(char num[20])    //������Ϊ�ؼ��ֵĹ�ϣ����
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


void input_num(Record Inf[M],int m,Record H[M])    //��ѧ��Ϊ�ؼ��ִ�����ϣ��
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



int Search_name(Record H[],char name[20])   //������Ϊ�ؼ��ֵĹ�ϣ��Ĳ��Һ���
{    
    int key=0;
	key=Hash_name(name);
	while(strcmp(H[key].name,name)!=0)
	{ 
	    key++;
		if(strcmp(H[key].name,NULLKEY)==0)
		{
		    printf("�������ֲ�����!\n");
			return(-1);
			break;
		}
	}
	return(key);
}




int Search_num(Record H[],char num[20])   //��ѧ��Ϊ�ؼ��ֵĹ�ϣ��Ĳ��Һ���
{
    int key=0;
	key=Hash_num(num);
	while(strcmp(num,H[key].num)!=0)
	{
	    key++;
		if(strcmp(H[key].num,NULLKEY)==0)
		{
            printf("����ѧ�Ų�����\n");
			return(-1);
			break;
		}
	}
	return(key);
}



void Insert_name(Record H[M],char name[20],char num[20],char add[30])  //������Ϊ�ؼ��ֹ�ϣ��Ĳ��뺯��
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
{                                               //��ѧ��Ϊ�ؼ��ֵĹ�ϣ����뺯��
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



void Print_name(Record H[M])       //������Ϊ�ؼ��ֵĹ�ϣ����������
{
    int i;
	printf("\t��ϣ��ַ\t����\t\tѧ��\t\t��ַ\n");
    for(i=0;i<30;i++)
	{
	    if(strcmp(H[i].name,"\0")!=0)
        {
		    printf("\t%d\t\t%s\t\t%s\t\t%s\n",i,H[i].name,H[i].num,H[i].add);
		}
	}
}	


void Print_num(Record H[M])   //��ѧ��Ϊ�ؼ��ֵĹ�ϣ����������
{
    int i;
	printf("\t��ϣ��ַ\t����\t\tѧ��\t\t��ַ\n");
    for(i=0;i<30;i++)
	{
	    if(strcmp(H[i].num,"\0")!=0)
        {
		    printf("\t%d\t\t%s\t\t%s\t\t%s\n",i,H[i].name,H[i].num,H[i].add);
		}
	}
}



void Del_name(Record H[M],char name[20])  //������Ϊ�ؼ��ֵĹ�ϣ���ɾ������
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
	printf("������������!");
}


void Del_num(Record H[M],char num[20])   //��ѧ��Ϊ�ؼ��ֵĹ�ϣ���ɾ������
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
		printf("��ѧ�Ų�����!\n");
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
						printf("1:����\n");
                        printf("2:����\n");
						printf("3:ɾ��\n");
						printf("0:����\n");
                        printf("���루0-3��:\n");
						scanf("%d",&g);
                        switch(g)
						{
						    case 1 : 
							    printf("\n������Ҫ���ҵ����֣�\n");
								scanf("%s",name);
								    k=Search_name(H,name);
								printf("���Ҹ��˵���Ϣ�ǣ�\n");
                                printf("���˵�������:%s\n",H[k].name);
                                printf("���˵�ѧ����:%s\n",H[k].num);
                                printf("���˵ĵ�ַ��:%s\n",H[k].add);
								break;
                            case 2 :
							    printf("\n������Ҫ�������Ϣ��\n");
                                printf("�����������:");
								scanf("%s",a0);
                                printf("����ĵ绰��:");
								scanf("%s",b0);
                                    printf("����ĵ�ַ��:");
								scanf("%s",c0);
                                    Insert_name(H,a0,b0,c0);
								printf("�����Ľ��:\n");
                                Print_name(H);
								break;
							case 3 :
                                printf("������Ҫɾ��������:\n");
								scanf("%s",name);
                                    Del_name(H,name);
								printf("ɾ�������Ϣ:\n");
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
					printf("1:����\n");
                    printf("2:����\n");
					printf("3:ɾ��\n");
					printf("0:����");
                    printf("���루0-3��:\n");
					scanf("%d",&g);
                    switch(g)
					{
					    case 1 :
						    printf("������Ҫ���ҵ�ѧ�ţ�\n");
                            scanf("%s",num);
							w=Search_num(H,num);
                            printf("���Ҹ��˵���Ϣ�ǣ�\n");
                            printf("���˵������ǣ�%s\n",H[w].name);
                            printf("���˵�ѧ����:%s\n",H[w].num);
                            printf("���˵ĵ�ַ��:%s\n",H[w].add);
                            break;
						case 2 :
                            printf("\n������Ҫ�������Ϣ��\n");
                            printf("�����������:");
							scanf("%s",a1);
                            printf("����ĵ绰��:");
							scanf("%s",b1);
                            printf("����ĵ�ַ��:");
							scanf("%s",c1);
                                Insert_num(H,a1,b1,c1);
							printf("�����Ľ��:\n");
                                Print_num(H);
							break;
                        case 3 :
						    printf("������Ҫɾ����ѧ�ţ�");
                          	scanf("%s",num);
							    Del_num(H,num);
                            printf("ɾ�������Ϣ��\n");
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
			printf("��ӭʹ�ã�");
            exit(0);
			break;
		}
		system("pause");
	}
}




