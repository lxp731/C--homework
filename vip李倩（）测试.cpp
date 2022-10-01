#ifndef VIP_HEAD
#define VIP_HEAD

typedef struct node /*定义结构体*/
{ 
    int num; //会员号
    char name[15];//姓名
    char type[9]; //类型
    int age;  //年龄
    int english; //英语成绩
    int math; //数学成绩
    int computer;//计算机成绩
    int average; //平均成绩
    struct node *next; //链表指针域
}vip_info;

//VIP信息链表
extern vip_info* vip_list;  //全局变量声明


//初始化函数声明
//初始化VIP信息链表
void init_vip_info_list();
//判断VIP信息链表是否为空
int vip_list_empty();

//操作函数声明
//向系统信息表中添加VIP信息记录
int add_vip_info();
//根据会员号删除VIP信息
int delete_vip_info(int num);
//根据会员号修改VIP信息
int modify_vip_info(int num);
//根据会员号查找VIP信息
vip_info* search_vip_info(int num);
//输出每个VIP的平均成绩
void display_average();
//显示所有VIP信息
void display_vip_info();
//将VIP信息保存到文件
int save_file();
//从文件中读取VIP信息
int read_file();
#endif

#include <stdio.h>
#include <string.h>
#include <malloc.h>

//初始化VIP信息链表
void init_vip_info_list()
{
    //VIP信息链表头结点
    vip_list = (vip_info*)malloc(sizeof(vip_info));
    vip_list->next = NULL;
}
//判断VIP信息链表是否为空
int vip_list_empty()
{
    return vip_list->next == NULL;
}
//操作函数实现
//向系统信息表中添加VIP信息记录
int add_vip_info()
{
    vip_info *pstu = (vip_info*)malloc(sizeof(vip_info));
    if(pstu == NULL)
    {
        printf("内存分配失败.\n");
        return 0;
    }
    printf("请按要求一次输入VIP的信息.\n");
    printf("请输入会员号: ");
    scanf("%d",&pstu->num);
    //判断该会员号是否已经存在
    if(search_vip_info(pstu->num) != NULL)
    {
        printf("该会员号已经存在VIP信息表中.\n");
        return 0;
    }
    printf("请输入姓名: ");
    getchar();
    gets(pstu->name);
    printf("请输入类型: ");
    scanf("%s",pstu->type);
    printf("请输入年龄: ");
    scanf("%d",&pstu->age);
    printf("请输入英语成绩: ");
    scanf("%d",&pstu->english);
    printf("请输入数学成绩: ");
    scanf("%d",&pstu->math);
    printf("请输入计算机成绩: ");
    scanf("%d",&pstu->computer);
    pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
    //每次从VIP信息链表的头部插入;
    pstu->next = vip_list->next;
    vip_list->next = pstu;
    return 1;
}
//根据会员号删除VIP信息
int delete_vip_info(int num)
{
    vip_info *pstu;
    vip_info *qstu;
    if(search_vip_info(num) == NULL)
    {
        printf("不存在该学好为%d的VIP信息.\n",num);
        return 0;
    }
    pstu = vip_list->next;
    qstu = vip_list;
    while(pstu->num != num)
    {
        qstu = pstu;
        pstu = pstu->next;
    }
    qstu->next = pstu->next;
    free(pstu);
    return 1;
}
//根据会员号修改VIP信息
int modify_vip_info(int num)
{
    int choice;
    vip_info *pstu = search_vip_info(num);
    if(pstu == NULL)
    {
        printf("不存在该学好为%d的VIP信息.\n",num);
        return 0;
    }
    printf("1.姓名 2.类型 3.年龄 4.英语成绩 5.数学成绩 6.计算机成绩.\n");
    printf("请选择修改的信息: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("请输入新的姓名: ");
        getchar();
        gets(pstu->name);
        break;
    case 2:
        printf("请输入新的类型: ");
        scanf("%s",pstu->type);
        break;
    case 3:
        printf("请输入新的年龄: ");
        scanf("%d",&pstu->age);
        break;
    case 4:
        printf("请输入新的英语成绩: ");
        scanf("%d",&pstu->english);
        break;
    case 5:
        printf("请输入新的数学成绩: ");
        scanf("%d",&pstu->math);
        break;
    case 6:
        printf("请输入新的计算机成绩: ");
        scanf("%d",&pstu->computer);
        break;
    default:
        printf("请按提示要求操作.\n");
    }
    return 1;
}
//根据会员号查找VIP信息
vip_info* search_vip_info(int num)
{
    vip_info *pstu;
    pstu = vip_list->next;
    while(pstu  && pstu->num != num)
    {

        pstu = pstu->next;
    }
    return pstu;
}
//输出每个VIP的平均成绩
void display_average()
{
    vip_info *pstu;
    pstu = vip_list->next;
    while(pstu)
    {
        printf("会员号为%d，姓名为%s的VIP平均成绩为: %d\n",pstu->num,pstu->name,pstu->average);
        pstu = pstu->next;
    }
}
//显示所有VIP信息
void display_vip_info()
{
    vip_info *pstu;
    pstu = vip_list->next;
    printf("所有VIP信息如下所示.\n");
    printf("会员号\t姓名\t类型\t年龄\t英语\t数学\t计算机\t平均成绩.\n");
    while(pstu)
    {
        printf("%d\t",pstu->num);
        printf("%s\t",pstu->name);
        printf("%s\t",pstu->type);
        printf("%d  \t",pstu->age);
        printf("%d   \t",pstu->english);
        printf("%d  \t",pstu->math);
        printf("%d    \t",pstu->computer);
        printf("%d\n",pstu->average);
        pstu = pstu->next;
    }
}
//将VIP信息保存到文件
int save_file()
{
    FILE *pfile;
    vip_info *pstu;
    pfile = fopen("vip.txt","w");
    if(pfile == NULL)
    {
        printf("打开文件失败.\n");
        return 0;
    }
    pstu = vip_list->next;
    while(pstu)
    {
        fprintf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d",pstu->num,pstu->name,pstu->type,pstu->age,
            pstu->english,pstu->math,pstu->computer,pstu->average);
        pstu = pstu->next;
    }
    fclose(pfile);
    return 1;
}

//从文件中读取VIP信息
int read_file()
{
    FILE *pfile;
    vip_info *pstu;
    pfile = fopen("vip.txt","r");
    if(pfile == NULL)
    {
        printf("打开文件失败.\n");
        return 0;
    }
    while(!feof(pfile))
    {
        pstu = (vip_info*)malloc(sizeof(vip_info));
        fscanf(pfile,"%5d%15s%9s%4d%4d%4d%4d%4d",&pstu->num,pstu->name,pstu->type,&pstu->age,
            &pstu->english,&pstu->math,&pstu->computer,&pstu->average);
        pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
        //每次从VIP信息链表的头部插入;
        pstu->next = vip_list->next;
        vip_list->next = pstu;
    }
    fclose(pfile);
    return 1;
}

#include <stdlib.h>
#include <stdio.h>

void menu();

//VIP信息链表
vip_info* vip_list;

//用户可以选择1-7可以分别进行VIP信息的查看、添加、删除，修改，计算平均成绩，保存，退出系统操作。
int main()
{
    int choice;
    int num;
    printf("**************************\n");
    printf("欢迎使用VIP信息管理系统\n");
    printf("**************************\n");
    printf("-----------------------------\n");
    init_vip_info_list();
    if(read_file())
        printf("从文件中读取VIP信息成功.\n");
    else
        printf("从文字中读取VIP信息失败.\n");
    printf("-----------------------------\n");
    menu();
    while(1)
    {
        printf("请选择操作: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(vip_list_empty())
                printf("VIP信息表为空，请先添加VIP信息.\n");
            else
                display_vip_info();
            break;
        case 2:
            if(add_vip_info())
                printf("添加VIP信息成功.\n");
            else
                printf("添加VIP信息失败.\n");
            break;
        case 3:
            if(vip_list_empty())
                printf("VIP信息表为空，请先添加VIP信息.\n");
            else
            {
                printf("请输入要删除VIP信息的会员号: ");
                scanf("%d",&num);
                if(delete_vip_info(num))
                    printf("成功删除该会员号对应的VIP信息.\n");
                else
                    printf("删除失败.\n");
            }
            break;
        case 4:
            if(vip_list_empty())
                printf("VIP信息表为空，请先添加VIP信息.\n");
            else
            {
                printf("请输入要修改VIP信息的会员号: ");
                scanf("%d",&num);
                if(modify_vip_info(num))
                    printf("成功修改该会员号对应的VIP信息.\n");
                else
                    printf("修改失败.\n");
            }
            break;
        case 5:
            if(vip_list_empty())
                printf("VIP信息表为空，请先添加VIP信息.\n");
            else
                display_average();
            break;
        case 6:
            if(vip_list_empty())
                printf("VIP信息表为空，请先添加VIP信息.\n");
            else
                if(save_file())
                    printf("保存VIP信息成功.\n");
                else
                    printf("保存VIP信息失败.\n");
            break;
        case 0:
            printf("欢迎下次使用,再见.\n");
            system("pause");
            exit(0);
            break;
        default:
            printf("输入错误，请重新选择操作.\n");
        }
    }
    system("pause");
    return 0;
}

void menu()
{
    printf("1.查看VIP信息.\n");
    printf("2.添加VIP信息.\n");
    printf("3.删除VIP信息.\n");
    printf("4.修改VIP信息.\n");
    printf("5.输出平均成绩.\n");
    printf("6.保存VIP信息.\n");
    printf("0.退出系统操作.\n");
}

