#ifndef VIP_HEAD
#define VIP_HEAD

typedef struct node /*����ṹ��*/
{ 
    int num; //��Ա��
    char name[15];//����
    char sex[9]; //�Ա�
    int age;  //����
    char [10]; //��Ա���� 
//    int math; //��ѧ�ɼ�
//    int computer;//������ɼ�
//    int average; //ƽ���ɼ�
    struct node *next; //����ָ����
}VIP_info;

//��Ա��Ϣ����
extern VIP_info* VIP_list;  //ȫ�ֱ�������


//��ʼ����������
//��ʼ����Ա��Ϣ����
void init_VIP_info_list();
//�жϻ�Ա��Ϣ�����Ƿ�Ϊ��
int VIP_list_empty();

//������������
//��ϵͳ��Ϣ������ӻ�Ա��Ϣ��¼
int add_VIP_info();
//���ݻ�Աɾ����Ա��Ϣ
int delete_VIP_info(int num);
//���ݻ�Ա���޸Ļ�Ա��Ϣ
int modify_VIP_info(int num);
//���ݻ�Ա�Ų��һ�Ա��Ϣ
VIP_info* search_VIP_info(int num);
//���ÿ����Ա��ƽ���ɼ�
void display_average();
//��ʾ���л�Ա��Ϣ
void display_VIP_info();
//����Ա��Ϣ���浽�ļ�
int save_file();
//���ļ��ж�ȡ��Ա��Ϣ
int read_file();
#endif
//#include <VIP.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//��ʼ����Ա��Ϣ����
void init_VIP_info_list()
{
    //��Ա��Ϣ����ͷ���
    VIP_list = (VIP_info*)malloc(sizeof(VIP_info));
    VIP_list->next = NULL;
}
//�жϻ�Ա��Ϣ�����Ƿ�Ϊ��
int VIP_list_empty()
{
    return VIP_list->next == NULL;
}
//��������ʵ��
//��ϵͳ��Ϣ������ӻ�Ա��Ϣ��¼
int add_VIP_info()
{
    VIP_info *pstu = (VIP_info*)malloc(sizeof(VIP_info));
    if(pstu == NULL)
    {
        printf("�ڴ����ʧ��.\n");
        return 0;
    }
    printf("�밴Ҫ��һ�������Ա����Ϣ.\n");
    printf("�������Ա��: ");
    scanf("%d",&pstu->num);
    //�жϸû�Ա���Ƿ��Ѿ�����
    if(search_VIP_info(pstu->num) != NULL)
    {
        printf("�û�Ա���Ѿ����ڻ�Ա��Ϣ����.\n");
        return 0;
    }
    printf("����������: ");
    getchar();
    gets(pstu->name);
    printf("�������Ա�: ");
    scanf("%s",pstu->sex);
    printf("����������: ");
    scanf("%d",&pstu->age);
    printf("������Ӣ��ɼ�: ");
//    scanf("%d",&pstu->english);
//    printf("��������ѧ�ɼ�: ");
//    scanf("%d",&pstu->math);
//    printf("�����������ɼ�: ");
//    scanf("%d",&pstu->computer);
//    pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
    //ÿ�δӻ�Ա��Ϣ�����ͷ������;
    pstu->next = VIP_list->next;
    VIP_list->next = pstu;
    return 1;
}
//���ݻ�Ա��ɾ����Ա��Ϣ
int delete_VIP_info(int num)
{
    VIP_info *pstu;
    VIP_info *qstu;
    if(search_VIP_info(num) == NULL)
    {
        printf("�����ڸ�ѧ��Ϊ%d�Ļ�Ա��Ϣ.\n",num);
        return 0;
    }
    pstu = VIP_list->next;
    qstu = VIP_list;
    while(pstu->num != num)
    {
        qstu = pstu;
        pstu = pstu->next;
    }
    qstu->next = pstu->next;
    free(pstu);
    return 1;
}
//���ݻ�Ա���޸Ļ�Ա��Ϣ
int modify_VIP_info(int num)
{
    int choice;
    VIP_info *pstu = search_VIP_info(num);
    if(pstu == NULL)
    {
        printf("�����ڸ�ѧ��Ϊ%d�Ļ�Ա��Ϣ.\n",num);
        return 0;
    }
    printf("1.���� 2.�Ա� 3.���� 4.Ӣ��ɼ� 5.��ѧ�ɼ� 6.������ɼ�.\n");
    printf("��ѡ���޸ĵ���Ϣ: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("�������µ�����: ");
        getchar();
        gets(pstu->name);
        break;
    case 2:
        printf("�������µ��Ա�: ");
        scanf("%s",pstu->sex);
        break;
    case 3:
        printf("�������µ�����: ");
        scanf("%d",&pstu->age);
        break;
//    case 4:
////        printf("�������µ�Ӣ��ɼ�: ");
////        scanf("%d",&pstu->english);
////        break;
////    case 5:
////        printf("�������µ���ѧ�ɼ�: ");
////        scanf("%d",&pstu->math);
////        break;
////    case 6:
////        printf("�������µļ�����ɼ�: ");
////        scanf("%d",&pstu->computer);
////        break;
//    default:
//        printf("�밴��ʾҪ�����.\n");
//    }
//    return 1;
//}
//���ݻ�Ա�Ų��һ�Ա��Ϣ
VIP_info* search_VIP_info(int num)
{
    VIP_info *pstu;
    pstu = VIP_list->next;
    while(pstu  && pstu->num != num)
    {

        pstu = pstu->next;
    }
    return pstu;
}
////���ÿ����Ա��ƽ���ɼ�
//void display_average()
//{
//    VIP_info *pstu;
//    pstu = VIP_list->next;
//    while(pstu)
//    {
//       // printf("��Ա��Ϊ%d������Ϊ%s�Ļ�Աƽ���ɼ�Ϊ: %d\n",pstu->num,pstu->name,pstu->average);
//        pstu = pstu->next;
//    }
//}
//��ʾ���л�Ա��Ϣ
void display_VIP_info()
{
    VIP_info *pstu;
    pstu = VIP_list->next;
    printf("���л�Ա��Ϣ������ʾ.\n");
    printf("��Ա��\t����\t�Ա�\t����.\n");
    while(pstu)
    {
        printf("%d\t",pstu->num);
        printf("%s\t",pstu->name);
        printf("%s\t",pstu->sex);
        printf("%d  \t",pstu->age);
//	    printf("%d   \t",pstu->english);
//        printf("%d  \t",pstu->math);
//        printf("%d    \t",pstu->computer);
//        printf("%d\n",pstu->average);
        pstu = pstu->next;
    }
}
//����Ա��Ϣ���浽�ļ�
int save_file()
{
    FILE *pfile;
    VIP_info *pstu;
    pfile = fopen("VIP.txt","w");
    if(pfile == NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    pstu = VIP_list->next;
    while(pstu)
    {
        fprintf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d",pstu->num,pstu->name,pstu->sex,pstu->age,
 //           pstu->english,pstu->math,pstu->computer,pstu->average);
   //     pstu = pstu->next;
    }
    fclose(pfile);
    return 1;
}

//���ļ��ж�ȡ��Ա��Ϣ
int read_file()
{
    FILE *pfile;
    VIP_info *pstu;
    pfile = fopen("VIP.txt","r");
    if(pfile == NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    while(!feof(pfile))
    {
        pstu = (VIP_info*)malloc(sizeof(VIP_info));
        fscanf(pfile,"%5d%15s%9s%4d%4d%4d%4d%4d",&pstu->num,pstu->name,pstu->sex,&pstu->age,
            &pstu->english,&pstu->math,&pstu->computer,&pstu->average);
        pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
        //ÿ�δӻ�Ա��Ϣ�����ͷ������;
        pstu->next = VIP_list->next;
        VIP_list->next = pstu;
    }
    fclose(pfile);
    return 1;
}
//#include "VIP.h"
#include <stdlib.h>
#include <stdio.h>

void menu();

//��Ա��Ϣ����
VIP_info* VIP_list;

//�û�����ѡ��1-7���Էֱ���л�Ա��Ϣ�Ĳ鿴����ӡ�ɾ�����޸ģ�����ƽ���ɼ������棬�˳�ϵͳ������
int main()
{
    int choice;
    int num;
    printf("**************************\n");
    printf("��ӭʹ�û�Ա��Ϣ����ϵͳ\n");
    printf("**************************\n");
    printf("-----------------------------\n");
    init_VIP_info_list();
    if(read_file())
        printf("���ļ��ж�ȡ��Ա��Ϣ�ɹ�.\n");
    else
        printf("�������ж�ȡ��Ա��Ϣʧ��.\n");
    printf("-----------------------------\n");
    menu();
    while(1)
    {
        printf("��ѡ�����: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(VIP_list_empty())
                printf("��Ա��Ϣ��Ϊ�գ�������ӻ�Ա��Ϣ.\n");
            else
                display_VIP_info();
            break;
        case 2:
            if(add_VIP_info())
                printf("��ӻ�Ա��Ϣ�ɹ�.\n");
            else
                printf("��ӻ�Ա��Ϣʧ��.\n");
            break;
        case 3:
            if(VIP_list_empty())
                printf("��Ա��Ϣ��Ϊ�գ�������ӻ�Ա��Ϣ.\n");
            else
            {
                printf("������Ҫɾ����Ա��Ϣ�Ļ�Ա��: ");
                scanf("%d",&num);
                if(delete_VIP_info(num))
                    printf("�ɹ�ɾ���û�Ա�Ŷ�Ӧ�Ļ�Ա��Ϣ.\n");
                else
                    printf("ɾ��ʧ��.\n");
            }
            break;
        case 4:
            if(VIP_list_empty())
                printf("��Ա��Ϣ��Ϊ�գ�������ӻ�Ա��Ϣ.\n");
            else
            {
                printf("������Ҫ�޸Ļ�Ա��Ϣ�Ļ�Ա��: ");
                scanf("%d",&num);
                if(modify_VIP_info(num))
                    printf("�ɹ��޸ĸû�Ա�Ŷ�Ӧ�Ļ�Ա��Ϣ.\n");
                else
                    printf("�޸�ʧ��.\n");
            }
            break;
        case 5:
            if(VIP_list_empty())
                printf("��Ա��Ϣ��Ϊ�գ�������ӻ�Ա��Ϣ.\n");
            else
                display_average();
            break;
        case 6:
            if(VIP_list_empty())
                printf("��Ա��Ϣ��Ϊ�գ�������ӻ�Ա��Ϣ.\n");
            else
                if(save_file())
                    printf("�����Ա��Ϣ�ɹ�.\n");
                else
                    printf("�����Ա��Ϣʧ��.\n");
            break;
        case 0:
            printf("��ӭ�´�ʹ��,�ټ�.\n");
            system("pause");
            exit(0);
            break;
        default:
            printf("�������������ѡ�����.\n");
        }
    }
    system("pause");
    return 0;
}

void menu()
{
    printf("1.�鿴��Ա��Ϣ.\n");
    printf("2.��ӻ�Ա��Ϣ.\n");
    printf("3.ɾ����Ա��Ϣ.\n");
    printf("4.�޸Ļ�Ա��Ϣ.\n");
    printf("5.���ƽ���ɼ�.\n");
    printf("6.�����Ա��Ϣ.\n");
    printf("0.�˳�ϵͳ����.\n");
}

