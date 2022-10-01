#ifndef STUDENT_HEAD
#define STUDENT_HEAD

typedef struct node /*����ṹ��*/
{ 
    int num; //��Ա��
    char name[15];//����
    char sex[9]; //�Ա�
    int age;  //����
    int english; //��Ա���� 
//    int math; //��ѧ�ɼ�
//    int computer;//������ɼ�
//    int average; //ƽ���ɼ�
    struct node *next; //����ָ����
}student_info;

//��Ա��Ϣ����
extern student_info* student_list;  //ȫ�ֱ�������


//��ʼ����������
//��ʼ����Ա��Ϣ����
void init_student_info_list();
//�жϻ�Ա��Ϣ�����Ƿ�Ϊ��
int student_list_empty();

//������������
//��ϵͳ��Ϣ������ӻ�Ա��Ϣ��¼
int add_student_info();
//���ݻ�Աɾ��ѧ����Ϣ
int delete_student_info(int num);
//���ݻ�Ա���޸Ļ�Ա��Ϣ
int modify_student_info(int num);
//���ݻ�Ա�Ų��һ�Ա��Ϣ
student_info* search_student_info(int num);
//���ÿ����Ա��ƽ���ɼ�
void display_average();
//��ʾ���л�Ա��Ϣ
void display_student_info();
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
void init_student_info_list()
{
    //��Ա��Ϣ����ͷ���
    student_list = (student_info*)malloc(sizeof(student_info));
    student_list->next = NULL;
}
//�жϻ�Ա��Ϣ�����Ƿ�Ϊ��
int student_list_empty()
{
    return student_list->next == NULL;
}
//��������ʵ��
//��ϵͳ��Ϣ�������ѧ����Ϣ��¼
int add_student_info()
{
    student_info *pstu = (student_info*)malloc(sizeof(student_info));
    if(pstu == NULL)
    {
        printf("�ڴ����ʧ��.\n");
        return 0;
    }
    printf("�밴Ҫ��һ������ѧ������Ϣ.\n");
    printf("������ѧ��: ");
    scanf("%d",&pstu->num);
    //�жϸ�ѧ���Ƿ��Ѿ�����
    if(search_student_info(pstu->num) != NULL)
    {
        printf("��ѧ���Ѿ�����ѧ����Ϣ����.\n");
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
    scanf("%d",&pstu->english);
    printf("��������ѧ�ɼ�: ");
    scanf("%d",&pstu->math);
    printf("�����������ɼ�: ");
    scanf("%d",&pstu->computer);
    pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
    //ÿ�δ�ѧ����Ϣ�����ͷ������;
    pstu->next = student_list->next;
    student_list->next = pstu;
    return 1;
}
//����ѧ��ɾ��ѧ����Ϣ
int delete_student_info(int num)
{
    student_info *pstu;
    student_info *qstu;
    if(search_student_info(num) == NULL)
    {
        printf("�����ڸ�ѧ��Ϊ%d��ѧ����Ϣ.\n",num);
        return 0;
    }
    pstu = student_list->next;
    qstu = student_list;
    while(pstu->num != num)
    {
        qstu = pstu;
        pstu = pstu->next;
    }
    qstu->next = pstu->next;
    free(pstu);
    return 1;
}
//����ѧ���޸�ѧ����Ϣ
int modify_student_info(int num)
{
    int choice;
    student_info *pstu = search_student_info(num);
    if(pstu == NULL)
    {
        printf("�����ڸ�ѧ��Ϊ%d��ѧ����Ϣ.\n",num);
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
    case 4:
        printf("�������µ�Ӣ��ɼ�: ");
        scanf("%d",&pstu->english);
        break;
    case 5:
        printf("�������µ���ѧ�ɼ�: ");
        scanf("%d",&pstu->math);
        break;
    case 6:
        printf("�������µļ�����ɼ�: ");
        scanf("%d",&pstu->computer);
        break;
    default:
        printf("�밴��ʾҪ�����.\n");
    }
    return 1;
}
//����ѧ�Ų���ѧ����Ϣ
student_info* search_student_info(int num)
{
    student_info *pstu;
    pstu = student_list->next;
    while(pstu  && pstu->num != num)
    {

        pstu = pstu->next;
    }
    return pstu;
}
//���ÿ��ѧ����ƽ���ɼ�
void display_average()
{
    student_info *pstu;
    pstu = student_list->next;
    while(pstu)
    {
        printf("ѧ��Ϊ%d������Ϊ%s��ѧ��ƽ���ɼ�Ϊ: %d\n",pstu->num,pstu->name,pstu->average);
        pstu = pstu->next;
    }
}
//��ʾ����ѧ����Ϣ
void display_student_info()
{
    student_info *pstu;
    pstu = student_list->next;
    printf("����ѧ����Ϣ������ʾ.\n");
    printf("ѧ��\t����\t�Ա�\t����\tӢ��\t��ѧ\t�����\tƽ���ɼ�.\n");
    while(pstu)
    {
        printf("%d\t",pstu->num);
        printf("%s\t",pstu->name);
        printf("%s\t",pstu->sex);
        printf("%d  \t",pstu->age);
        printf("%d   \t",pstu->english);
        printf("%d  \t",pstu->math);
        printf("%d    \t",pstu->computer);
        printf("%d\n",pstu->average);
        pstu = pstu->next;
    }
}
//��ѧ����Ϣ���浽�ļ�
int save_file()
{
    FILE *pfile;
    student_info *pstu;
    pfile = fopen("student.txt","w");
    if(pfile == NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    pstu = student_list->next;
    while(pstu)
    {
        fprintf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d",pstu->num,pstu->name,pstu->sex,pstu->age,
            pstu->english,pstu->math,pstu->computer,pstu->average);
        pstu = pstu->next;
    }
    fclose(pfile);
    return 1;
}

//���ļ��ж�ȡѧ����Ϣ
int read_file()
{
    FILE *pfile;
    student_info *pstu;
    pfile = fopen("student.txt","r");
    if(pfile == NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    while(!feof(pfile))
    {
        pstu = (student_info*)malloc(sizeof(student_info));
        fscanf(pfile,"%5d%15s%9s%4d%4d%4d%4d%4d",&pstu->num,pstu->name,pstu->sex,&pstu->age,
            &pstu->english,&pstu->math,&pstu->computer,&pstu->average);
        pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
        //ÿ�δ�ѧ����Ϣ�����ͷ������;
        pstu->next = student_list->next;
        student_list->next = pstu;
    }
    fclose(pfile);
    return 1;
}
//#include "student.h"
#include <stdlib.h>
#include <stdio.h>

void menu();

//ѧ����Ϣ����
student_info* student_list;

//�û�����ѡ��1-7���Էֱ����ѧ����Ϣ�Ĳ鿴����ӡ�ɾ�����޸ģ�����ƽ���ɼ������棬�˳�ϵͳ������
int main()
{
    int choice;
    int num;
    printf("**************************\n");
    printf("��ӭʹ��ѧ����Ϣ����ϵͳ\n");
    printf("**************************\n");
    printf("-----------------------------\n");
    init_student_info_list();
    if(read_file())
        printf("���ļ��ж�ȡѧ����Ϣ�ɹ�.\n");
    else
        printf("�������ж�ȡѧ����Ϣʧ��.\n");
    printf("-----------------------------\n");
    menu();
    while(1)
    {
        printf("��ѡ�����: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(student_list_empty())
                printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
            else
                display_student_info();
            break;
        case 2:
            if(add_student_info())
                printf("���ѧ����Ϣ�ɹ�.\n");
            else
                printf("���ѧ����Ϣʧ��.\n");
            break;
        case 3:
            if(student_list_empty())
                printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
            else
            {
                printf("������Ҫɾ��ѧ����Ϣ��ѧ��: ");
                scanf("%d",&num);
                if(delete_student_info(num))
                    printf("�ɹ�ɾ����ѧ�Ŷ�Ӧ��ѧ����Ϣ.\n");
                else
                    printf("ɾ��ʧ��.\n");
            }
            break;
        case 4:
            if(student_list_empty())
                printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
            else
            {
                printf("������Ҫ�޸�ѧ����Ϣ��ѧ��: ");
                scanf("%d",&num);
                if(modify_student_info(num))
                    printf("�ɹ��޸ĸ�ѧ�Ŷ�Ӧ��ѧ����Ϣ.\n");
                else
                    printf("�޸�ʧ��.\n");
            }
            break;
        case 5:
            if(student_list_empty())
                printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
            else
                display_average();
            break;
        case 6:
            if(student_list_empty())
                printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
            else
                if(save_file())
                    printf("����ѧ����Ϣ�ɹ�.\n");
                else
                    printf("����ѧ����Ϣʧ��.\n");
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
    printf("1.�鿴ѧ����Ϣ.\n");
    printf("2.���ѧ����Ϣ.\n");
    printf("3.ɾ��ѧ����Ϣ.\n");
    printf("4.�޸�ѧ����Ϣ.\n");
    printf("5.���ƽ���ɼ�.\n");
    printf("6.����ѧ����Ϣ.\n");
    printf("0.�˳�ϵͳ����.\n");
}
