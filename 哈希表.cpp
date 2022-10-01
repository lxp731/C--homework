#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <time.h>  

#define HASH_TABLE_MAX_SIZE 10000  
typedef struct HashNode_Struct HashNode;  
struct HashNode_Struct  {  
    char* sKey;  
    int nValue;  
    HashNode* pNext;  
};  //��ϣ�����ݽṹ 

HashNode* hashTable[HASH_TABLE_MAX_SIZE]; 
int hash_table_size;  //��ϣ���м�ֵ�Ե����� 

//��ʼ����ϣ�� 
void hash_table_init()  
{  
    hash_table_size = 0;  
    memset(hashTable, 0, sizeof(HashNode*) * HASH_TABLE_MAX_SIZE);
    //memset(void *s,int c,size_t n); 
    //��s�к�n���ֽڻ���c����������� 
    //�ú����ǶԽϴ�ṹ�������������������һ�����ķ��� 
}  


//ȥ���Ż���ϣ��  
unsigned int hash_table_hash_str(const char* skey)  
{  //�޷���unsigned�ܱ���2�����з������͵����������� 
    const signed char *p = (const signed char*)skey; //���� 
    unsigned int h = *p;  
    if(h)
    {  
        for(p += 1; *p != '\0'; ++p)  
            h = (h << 5) - h + *p;  
    }  
    return h;  
}
//���� 
void hash_table_insert(const char* skey, int nvalue)  
{  
    if(hash_table_size >= HASH_TABLE_MAX_SIZE) //�������Ĺ�ϣ���ȴ��ڵ�����󳤶� 
    {  
        printf("�ڴ����!\n");
        return;  
    }  

    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;  
  //���ڽ����ͻ��posΪ��ϣ���� 
    HashNode* pHead = hashTable[pos];
    while(pHead)
    {  
        if(strcmp(pHead->sKey, skey) == 0)  
        {  
            printf("%s������ͻ!\n", skey);
            return ;  
        }  
        pHead = pHead->pNext;  
    }  
    //��̬������㣬��ʼ���������ڴ�ռ� 
    HashNode* pNewNode = (HashNode*)malloc(sizeof(HashNode));  
    memset(pNewNode, 0, sizeof(HashNode));  
    pNewNode->sKey = (char*)malloc(sizeof(char) * (strlen(skey) + 1));  
    strcpy(pNewNode->sKey, skey);  
    pNewNode->nValue = nvalue;  

    //ָ����� 
    pNewNode->pNext = hashTable[pos];  
    hashTable[pos] = pNewNode;  
    //������ 
    hash_table_size++;  
}  
//ɾ�� 
void hash_table_remove(const char* skey)  
{  
    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE; 

    if(hashTable[pos])  
    {  
        HashNode* pHead = hashTable[pos];  
        HashNode* pLast = NULL;  
        HashNode* pRemove = NULL;  
        while(pHead)  
        {  
            if(strcmp(skey, pHead->sKey) == 0)  
            {   //��str1==str2���򷵻���;
                //��str1>str2���򷵻�����;
                //��str1<str2���򷵻ظ����� 
                pRemove = pHead;//����ȣ���pRemove��¼  
                break; 
            }  
            pLast = pHead;  //������ȣ����Ϻ��� 
            pHead = pHead->pNext;  
        }  
        if(pRemove)  
        {  
            if(pLast)
                pLast->pNext = pRemove->pNext;//ʵ��ɾ��1 
            else  
                hashTable[pos] = NULL;//ʵ��ɾ��2

            free(pRemove->sKey);  
            free(pRemove);  
        }  
    }  
}  

//���� 
HashNode* hash_table_lookup(const char* skey)  
{  
    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;  

    if(hashTable[pos])  
    {  
        HashNode* pHead = hashTable[pos];  
        while(pHead)  
        {  
            if(strcmp(skey, pHead->sKey) == 0)  
                return pHead;//���ҳɹ� 

            pHead = pHead->pNext;  
        }  
    }  
    return NULL;  
}  

//��ӡ 
void hash_table_print()  
{ 
    int i;  
    for(i = 0; i < HASH_TABLE_MAX_SIZE; ++i)  
        if(hashTable[i])//���� 
        {  
            HashNode* pHead = hashTable[i];  
            printf("%d=>", i);  
            while(pHead)  
            {  
                printf("%s:%d  ", pHead->sKey, pHead->nValue);  
                pHead = pHead->pNext;  
            }  
            printf("\n");  
        }  
}  

//�ͷ��ڴ� 
void hash_table_release()  
{  
    int i;  
    for(i = 0; i < HASH_TABLE_MAX_SIZE; ++i)  
    {  
        if(hashTable[i])  
        {  
            HashNode* pHead = hashTable[i];  
            while(pHead)  
            {  
                HashNode* pTemp = pHead;  
                pHead = pHead->pNext;  
                if(pTemp)  
                {  
                    free(pTemp->sKey);  
                    free(pTemp);  
                }  
                //����ͷ� 
            }  
        }  
    }  
}
#define MAX_STR_LEN 20  
#define MIN_STR_LEN 10  
void rand_str(char r[])  
{  
    int i;  
    int len = MIN_STR_LEN + rand() % (MAX_STR_LEN - MIN_STR_LEN);  
    for(i = 0; i < len - 1; ++i)  
        r[i] = 'a' + rand() % ( 'z' - 'a');  
    r[len - 1] = '\0';  
}  

int main(int argc, char** argv)  
{  
    srand(time(NULL));  
    hash_table_init();     
    int n = 10;  
    char str[MAX_STR_LEN + 1]; 
    const char *key1 = "aaa111";  
    const char *key2 = "bbb222";  
    const char *key3 = "ccc333";

    while(n--)  
    {  
        rand_str(str);  
        hash_table_insert(str, n);  
    }
    printf("����ǰ\n");
    hash_table_print(); 

    hash_table_insert(key1, 1);  
    hash_table_insert(key2, 2);  
    hash_table_insert(key3, 2);   

    printf("�����\n");
    hash_table_print();  

    HashNode* pNode = hash_table_lookup(key1);  
    printf("���ҽ��:%d\n", pNode->nValue);  
    pNode = hash_table_lookup(key2);  
    printf("���ҽ��:%d\n", pNode->nValue);

    printf("ɾ��֮ǰ:\n");  
    hash_table_print();  
    hash_table_remove(key3);  
    printf("ɾ��֮��:\n");  
    hash_table_print();  

    hash_table_release();  

    return 0;  
}  



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//
//#define N 34
//#define L 52 
//#define P 68
//
//
//typedef struct 
//{
//    char *name;
//    char *py;
//    int k;
//}old;
//old oldlist[N];
//
//typedef struct 
//{
//    char *name;
//    char *py;
//    int k;  
//    int b;  
//}hx;
//hx hlist[L];
//
//void InputOldlist()
//{  
//    int i,s=0,r;
//    oldlist[0].name="������";    oldlist[0].py="jiang long tao";
//    oldlist[1].name="�����";        oldlist[1].py="luo jia xing";
//    oldlist[2].name="�����";    oldlist[2].py="li cheng kun";
//    oldlist[3].name="������";        oldlist[3].py="wang zi zhen";
//    oldlist[4].name="����ΰ";    oldlist[4].py="lv jia wei";
//    oldlist[5].name="����ϲ";    oldlist[5].py="liu ming xi";
//    oldlist[6].name="���";    oldlist[6].py="li dan di";
//    oldlist[7].name="������";    oldlist[7].py="liu xiao peng";
//    oldlist[8].name="��˼;";    oldlist[8].py="wang si tu";
//    oldlist[9].name="��־��";    oldlist[9].py="zhang zhi gang";
//    oldlist[10].name="������";    oldlist[10].py="cai peng jun";
//    oldlist[11].name="������";    oldlist[11].py="yin hua heng";
//    oldlist[12].name="л�";    oldlist[12].py="xie chen";
//    oldlist[13].name="�ſ���";    oldlist[13].py="zhang kai cheng";
//    oldlist[14].name="Ѧ��Դ";    oldlist[14].py="xue wen yuan";
//    oldlist[15].name="����";    oldlist[15].py="jiang kai";
//    oldlist[16].name="����һ";    oldlist[16].py="ren zhao yi";
//    oldlist[17].name="��Ұ";    oldlist[17].py="chen ye";
//    oldlist[18].name="Ԭ��";    oldlist[18].py="yuan lei";
//    oldlist[19].name="��Զ��";    oldlist[19].py="li yuan hang";
//    oldlist[20].name="����";    oldlist[20].py="dong ze hua";
//    oldlist[21].name="κ����";    oldlist[21].py="wei zheng yang";
//    oldlist[22].name="����Ң";    oldlist[22].py="wang jun yao";
//    oldlist[23].name="������";    oldlist[23].py="wang chen yu";
//    oldlist[24].name="��ʿȺ";    oldlist[24].py="liu shi qun";
//    oldlist[25].name="�����";    oldlist[25].py="liu run feng";
//    oldlist[26].name="��һ��";    oldlist[26].py="li yi di";
//    oldlist[27].name="������";    oldlist[27].py="huang ya ni";
//    oldlist[28].name="��˼��";    oldlist[28].py="wang si qi";
//    oldlist[29].name="�Ż�";    oldlist[29].py="zhang hui";
//    oldlist[30].name="����";    oldlist[30].py="wang li";
//    oldlist[31].name="����";    oldlist[31].py="xu yu";
//    oldlist[32].name="�׺���";    oldlist[32].py="lei hai li";
//    oldlist[33].name="���ķ�";    oldlist[33].py="huang wen fei";
//     
//    for (i=0;i<N;i++)
//    {
//        
//        for(s=0,r=0;oldlist[i].py[r]!='\0';r++)
//        {    
//        
//            s=toascii(oldlist[i].py[r])+s;
//        }
//        oldlist[i].k=s;
//    }
//}
//
//void hash()
//{    int i,adr,d;
//    float average,sum=0;
//    for (i=0;i<L;i++)  
//    {
//        hlist[i].name="";
//        hlist[i].py="";
//        hlist[i].k=0;
//        hlist[i].b=0;
//    }
//    
//    for (i=0;i<N;i++)  
//    { 
//    
//        adr=(oldlist[i].k)%P;
//        d=adr;
//        if(hlist[adr].b==0)
//        {
//            hlist[adr].k=oldlist[i].k;
//            hlist[adr].name=oldlist[i].name;
//            hlist[adr].py=oldlist[i].py;
//            hlist[adr].b=1;
//            sum=sum+1;
//        }
//        else
//        {
//            do
//            {   d=(d+adr%10+1)%P;
//                sum=sum+1;
//            }while (hlist[d].b!=0);
//            hlist[d].k=oldlist[i].k;
//            hlist[d].name=oldlist[i].name;
//            hlist[d].py=oldlist[i].py;
//            hlist[d].b=1;
//        }
//    }
//    average=sum/30;
//    printf("ƽ�����ҳ���Ϊ:%f\n",average);
//    if(average>2)
//    hash();
//}
//
//
//void findlist()   
//{
//    char c[20];    
//    int i=0,d,g,adr,s=0;
//    printf("��������Ҫ���ҵ��˵�ƴ��:\n");
//    getchar();
//    gets(c);
//    
//    for(i=0;c[i]!='\0';i++)
//    {
//
//        s=toascii(c[i])+s;
//    }
//    adr=s%P;
//    d=adr;
//    if(strcmp(hlist[adr].py,c)==0)
//    {
//        printf("����:%s ƴ��:%s ��ϣ���д洢λ��:%d\n",hlist[adr].name,hlist[adr].py,adr);
//    }
//    else 
//         if(hlist[adr].b==0)
//            {
//              printf("��ϣ�����޼�¼!\n");
//            }
//         else 
//         {
//             g=0;
//             for (i=0;g==0;i++)
//             {    d=(d+adr%10+1)%P;
//                 if(hlist[d].b==0)
//                 {
//                     printf("��ϣ�����޼�¼!\n");
//                     g=1;
//                 }
//                 if(strcmp(hlist[d].py,c)==0)
//                 {
//                     printf("����:%s ƴ��:%s ��ϣ���д洢λ��:%d\n",hlist[d].name,hlist[d].py,d);
//                     g=1;
//                 }
//             }
//         }
//}
//
//void printlist()
//{
//    int i;
//    for(i=0;i<L;i++)
//    printf("%s    %s    %d \n",hlist[i].name,hlist[i].py,hlist[i].k);
//}
//
//int main()
//{
//    int ch;
//
//    InputOldlist();
//
//    hash();
//    
//    do
//    {
//        printf("1.����  2.�����ϣ��  3.�˳�����\n");
//        scanf("%d",&ch);
//        switch(ch)
//        {
//        case 1:
//            findlist();
//            printf("Press any key to continue.\n");
//            break;
//        case 2:
//            printlist();
//            printf("Press any key to continue.\n");
//            break;
//        case 3:
//            break;
//        default:  
//            printf("No this operation.\n");
//            printf("Press any key to continue.\n");
//        }
//        getchar();
//    }while (ch!=3);
//}
