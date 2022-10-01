#ifndef VIP_HEAD
#define VIP_HEAD

typedef struct node /*����ṹ��*/
{ 
    int num; //��Ա��
    char name[15];//����
    char type[9]; //����
    int age;  //����
    int english; //Ӣ��ɼ�
    int math; //��ѧ�ɼ�
    int computer;//������ɼ�
    int average; //ƽ���ɼ�
    struct node *next; //����ָ����
}vip_info;

//VIP��Ϣ����
extern vip_info* vip_list;  //ȫ�ֱ�������


//��ʼ����������
//��ʼ��VIP��Ϣ����
void init_vip_info_list();
//�ж�VIP��Ϣ�����Ƿ�Ϊ��
int vip_list_empty();

//������������
//��ϵͳ��Ϣ�������VIP��Ϣ��¼
int add_vip_info();
//���ݻ�Ա��ɾ��VIP��Ϣ
int delete_vip_info(int num);
//���ݻ�Ա���޸�VIP��Ϣ
int modify_vip_info(int num);
//���ݻ�Ա�Ų���VIP��Ϣ
vip_info* search_vip_info(int num);
//���ÿ��VIP��ƽ���ɼ�
void display_average();
//��ʾ����VIP��Ϣ
void display_vip_info();
//��VIP��Ϣ���浽�ļ�
int save_file();
//���ļ��ж�ȡVIP��Ϣ
int read_file();
#endif

#include <stdio.h>
#include <string.h>
#include <malloc.h>

//��ʼ��VIP��Ϣ����
void init_vip_info_list()
{
    //VIP��Ϣ����ͷ���
    vip_list = (vip_info*)malloc(sizeof(vip_info));
    vip_list->next = NULL;
}
//�ж�VIP��Ϣ�����Ƿ�Ϊ��
int vip_list_empty()
{
    return vip_list->next == NULL;
}
//��������ʵ��
//��ϵͳ��Ϣ�������VIP��Ϣ��¼
int add_vip_info()
{
    vip_info *pstu = (vip_info*)malloc(sizeof(vip_info));
    if(pstu == NULL)
    {
        printf("�ڴ����ʧ��.\n");
        return 0;
    }
    printf("�밴Ҫ��һ������VIP����Ϣ.\n");
    printf("�������Ա��: ");
    scanf("%d",&pstu->num);
    //�жϸû�Ա���Ƿ��Ѿ�����
    if(search_vip_info(pstu->num) != NULL)
    {
        printf("�û�Ա���Ѿ�����VIP��Ϣ����.\n");
        return 0;
    }
    printf("����������: ");
    getchar();
    gets(pstu->name);
    printf("����������: ");
    scanf("%s",pstu->type);
    printf("����������: ");
    scanf("%d",&pstu->age);
    printf("������Ӣ��ɼ�: ");
    scanf("%d",&pstu->english);
    printf("��������ѧ�ɼ�: ");
    scanf("%d",&pstu->math);
    printf("�����������ɼ�: ");
    scanf("%d",&pstu->computer);
    pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
    //ÿ�δ�VIP��Ϣ�����ͷ������;
    pstu->next = vip_list->next;
    vip_list->next = pstu;
    return 1;
}
//���ݻ�Ա��ɾ��VIP��Ϣ
int delete_vip_info(int num)
{
    vip_info *pstu;
    vip_info *qstu;
    if(search_vip_info(num) == NULL)
    {
        printf("�����ڸ�ѧ��Ϊ%d��VIP��Ϣ.\n",num);
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
//���ݻ�Ա���޸�VIP��Ϣ
int modify_vip_info(int num)
{
    int choice;
    vip_info *pstu = search_vip_info(num);
    if(pstu == NULL)
    {
        printf("�����ڸ�ѧ��Ϊ%d��VIP��Ϣ.\n",num);
        return 0;
    }
    printf("1.���� 2.���� 3.���� 4.Ӣ��ɼ� 5.��ѧ�ɼ� 6.������ɼ�.\n");
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
        printf("�������µ�����: ");
        scanf("%s",pstu->type);
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
//���ݻ�Ա�Ų���VIP��Ϣ
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
//���ÿ��VIP��ƽ���ɼ�
void display_average()
{
    vip_info *pstu;
    pstu = vip_list->next;
    while(pstu)
    {
        printf("��Ա��Ϊ%d������Ϊ%s��VIPƽ���ɼ�Ϊ: %d\n",pstu->num,pstu->name,pstu->average);
        pstu = pstu->next;
    }
}
//��ʾ����VIP��Ϣ
void display_vip_info()
{
    vip_info *pstu;
    pstu = vip_list->next;
    printf("����VIP��Ϣ������ʾ.\n");
    printf("��Ա��\t����\t����\t����\tӢ��\t��ѧ\t�����\tƽ���ɼ�.\n");
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
//��VIP��Ϣ���浽�ļ�
int save_file()
{
    FILE *pfile;
    vip_info *pstu;
    pfile = fopen("vip.txt","w");
    if(pfile == NULL)
    {
        printf("���ļ�ʧ��.\n");
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

//���ļ��ж�ȡVIP��Ϣ
int read_file()
{
    FILE *pfile;
    vip_info *pstu;
    pfile = fopen("vip.txt","r");
    if(pfile == NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    while(!feof(pfile))
    {
        pstu = (vip_info*)malloc(sizeof(vip_info));
        fscanf(pfile,"%5d%15s%9s%4d%4d%4d%4d%4d",&pstu->num,pstu->name,pstu->type,&pstu->age,
            &pstu->english,&pstu->math,&pstu->computer,&pstu->average);
        pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
        //ÿ�δ�VIP��Ϣ�����ͷ������;
        pstu->next = vip_list->next;
        vip_list->next = pstu;
    }
    fclose(pfile);
    return 1;
}

#include <stdlib.h>
#include <stdio.h>

void menu();

//VIP��Ϣ����
vip_info* vip_list;

//�û�����ѡ��1-7���Էֱ����VIP��Ϣ�Ĳ鿴����ӡ�ɾ�����޸ģ�����ƽ���ɼ������棬�˳�ϵͳ������
int main()
{
    int choice;
    int num;
    printf("**************************\n");
    printf("��ӭʹ��VIP��Ϣ����ϵͳ\n");
    printf("**************************\n");
    printf("-----------------------------\n");
    init_vip_info_list();
    if(read_file())
        printf("���ļ��ж�ȡVIP��Ϣ�ɹ�.\n");
    else
        printf("�������ж�ȡVIP��Ϣʧ��.\n");
    printf("-----------------------------\n");
    menu();
    while(1)
    {
        printf("��ѡ�����: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(vip_list_empty())
                printf("VIP��Ϣ��Ϊ�գ��������VIP��Ϣ.\n");
            else
                display_vip_info();
            break;
        case 2:
            if(add_vip_info())
                printf("���VIP��Ϣ�ɹ�.\n");
            else
                printf("���VIP��Ϣʧ��.\n");
            break;
        case 3:
            if(vip_list_empty())
                printf("VIP��Ϣ��Ϊ�գ��������VIP��Ϣ.\n");
            else
            {
                printf("������Ҫɾ��VIP��Ϣ�Ļ�Ա��: ");
                scanf("%d",&num);
                if(delete_vip_info(num))
                    printf("�ɹ�ɾ���û�Ա�Ŷ�Ӧ��VIP��Ϣ.\n");
                else
                    printf("ɾ��ʧ��.\n");
            }
            break;
        case 4:
            if(vip_list_empty())
                printf("VIP��Ϣ��Ϊ�գ��������VIP��Ϣ.\n");
            else
            {
                printf("������Ҫ�޸�VIP��Ϣ�Ļ�Ա��: ");
                scanf("%d",&num);
                if(modify_vip_info(num))
                    printf("�ɹ��޸ĸû�Ա�Ŷ�Ӧ��VIP��Ϣ.\n");
                else
                    printf("�޸�ʧ��.\n");
            }
            break;
        case 5:
            if(vip_list_empty())
                printf("VIP��Ϣ��Ϊ�գ��������VIP��Ϣ.\n");
            else
                display_average();
            break;
        case 6:
            if(vip_list_empty())
                printf("VIP��Ϣ��Ϊ�գ��������VIP��Ϣ.\n");
            else
                if(save_file())
                    printf("����VIP��Ϣ�ɹ�.\n");
                else
                    printf("����VIP��Ϣʧ��.\n");
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
    printf("1.�鿴VIP��Ϣ.\n");
    printf("2.���VIP��Ϣ.\n");
    printf("3.ɾ��VIP��Ϣ.\n");
    printf("4.�޸�VIP��Ϣ.\n");
    printf("5.���ƽ���ɼ�.\n");
    printf("6.����VIP��Ϣ.\n");
    printf("0.�˳�ϵͳ����.\n");
}

