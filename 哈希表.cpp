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
};  //哈希表数据结构 

HashNode* hashTable[HASH_TABLE_MAX_SIZE]; 
int hash_table_size;  //哈希表中键值对的数量 

//初始化哈希表 
void hash_table_init()  
{  
    hash_table_size = 0;  
    memset(hashTable, 0, sizeof(HashNode*) * HASH_TABLE_MAX_SIZE);
    //memset(void *s,int c,size_t n); 
    //将s中后n个字节换成c所代表的内容 
    //该函数是对较大结构体或数组进行清零操作的一种最快的方法 
}  


//去符号化哈希表  
unsigned int hash_table_hash_str(const char* skey)  
{  //无符号unsigned能保存2倍与有符号类型的正整型数据 
    const signed char *p = (const signed char*)skey; //常量 
    unsigned int h = *p;  
    if(h)
    {  
        for(p += 1; *p != '\0'; ++p)  
            h = (h << 5) - h + *p;  
    }  
    return h;  
}
//插入 
void hash_table_insert(const char* skey, int nvalue)  
{  
    if(hash_table_size >= HASH_TABLE_MAX_SIZE) //如果定义的哈希表长度大于等于最大长度 
    {  
        printf("内存溢出!\n");
        return;  
    }  

    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;  
  //用于解决冲突，pos为哈希函数 
    HashNode* pHead = hashTable[pos];
    while(pHead)
    {  
        if(strcmp(pHead->sKey, skey) == 0)  
        {  
            printf("%s发生冲突!\n", skey);
            return ;  
        }  
        pHead = pHead->pNext;  
    }  
    //动态建立结点，初始化，分配内存空间 
    HashNode* pNewNode = (HashNode*)malloc(sizeof(HashNode));  
    memset(pNewNode, 0, sizeof(HashNode));  
    pNewNode->sKey = (char*)malloc(sizeof(char) * (strlen(skey) + 1));  
    strcpy(pNewNode->sKey, skey);  
    pNewNode->nValue = nvalue;  

    //指针后移 
    pNewNode->pNext = hashTable[pos];  
    hashTable[pos] = pNewNode;  
    //表长增加 
    hash_table_size++;  
}  
//删除 
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
            {   //若str1==str2，则返回零;
                //若str1>str2，则返回正数;
                //若str1<str2，则返回负数。 
                pRemove = pHead;//若相等，用pRemove记录  
                break; 
            }  
            pLast = pHead;  //若不相等，不断后移 
            pHead = pHead->pNext;  
        }  
        if(pRemove)  
        {  
            if(pLast)
                pLast->pNext = pRemove->pNext;//实现删除1 
            else  
                hashTable[pos] = NULL;//实现删除2

            free(pRemove->sKey);  
            free(pRemove);  
        }  
    }  
}  

//查找 
HashNode* hash_table_lookup(const char* skey)  
{  
    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;  

    if(hashTable[pos])  
    {  
        HashNode* pHead = hashTable[pos];  
        while(pHead)  
        {  
            if(strcmp(skey, pHead->sKey) == 0)  
                return pHead;//查找成功 

            pHead = pHead->pNext;  
        }  
    }  
    return NULL;  
}  

//打印 
void hash_table_print()  
{ 
    int i;  
    for(i = 0; i < HASH_TABLE_MAX_SIZE; ++i)  
        if(hashTable[i])//表不空 
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

//释放内存 
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
                //逐个释放 
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
    printf("插入前\n");
    hash_table_print(); 

    hash_table_insert(key1, 1);  
    hash_table_insert(key2, 2);  
    hash_table_insert(key3, 2);   

    printf("插入后\n");
    hash_table_print();  

    HashNode* pNode = hash_table_lookup(key1);  
    printf("查找结果:%d\n", pNode->nValue);  
    pNode = hash_table_lookup(key2);  
    printf("查找结果:%d\n", pNode->nValue);

    printf("删除之前:\n");  
    hash_table_print();  
    hash_table_remove(key3);  
    printf("删除之后:\n");  
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
//    oldlist[0].name="江龙涛";    oldlist[0].py="jiang long tao";
//    oldlist[1].name="骆佳兴";        oldlist[1].py="luo jia xing";
//    oldlist[2].name="李承坤";    oldlist[2].py="li cheng kun";
//    oldlist[3].name="王子振";        oldlist[3].py="wang zi zhen";
//    oldlist[4].name="吕佳伟";    oldlist[4].py="lv jia wei";
//    oldlist[5].name="刘明喜";    oldlist[5].py="liu ming xi";
//    oldlist[6].name="李丹迪";    oldlist[6].py="li dan di";
//    oldlist[7].name="刘晓鹏";    oldlist[7].py="liu xiao peng";
//    oldlist[8].name="王思途";    oldlist[8].py="wang si tu";
//    oldlist[9].name="张志刚";    oldlist[9].py="zhang zhi gang";
//    oldlist[10].name="蔡鹏均";    oldlist[10].py="cai peng jun";
//    oldlist[11].name="尹华恒";    oldlist[11].py="yin hua heng";
//    oldlist[12].name="谢琛";    oldlist[12].py="xie chen";
//    oldlist[13].name="张凯铖";    oldlist[13].py="zhang kai cheng";
//    oldlist[14].name="薛文源";    oldlist[14].py="xue wen yuan";
//    oldlist[15].name="蒋凯";    oldlist[15].py="jiang kai";
//    oldlist[16].name="任肇一";    oldlist[16].py="ren zhao yi";
//    oldlist[17].name="陈野";    oldlist[17].py="chen ye";
//    oldlist[18].name="袁灅";    oldlist[18].py="yuan lei";
//    oldlist[19].name="李远航";    oldlist[19].py="li yuan hang";
//    oldlist[20].name="东泽华";    oldlist[20].py="dong ze hua";
//    oldlist[21].name="魏正洋";    oldlist[21].py="wei zheng yang";
//    oldlist[22].name="王俊尧";    oldlist[22].py="wang jun yao";
//    oldlist[23].name="王晨雨";    oldlist[23].py="wang chen yu";
//    oldlist[24].name="刘士群";    oldlist[24].py="liu shi qun";
//    oldlist[25].name="刘润丰";    oldlist[25].py="liu run feng";
//    oldlist[26].name="李一迪";    oldlist[26].py="li yi di";
//    oldlist[27].name="黄雅妮";    oldlist[27].py="huang ya ni";
//    oldlist[28].name="王思圻";    oldlist[28].py="wang si qi";
//    oldlist[29].name="张卉";    oldlist[29].py="zhang hui";
//    oldlist[30].name="王丽";    oldlist[30].py="wang li";
//    oldlist[31].name="徐宇";    oldlist[31].py="xu yu";
//    oldlist[32].name="雷海莉";    oldlist[32].py="lei hai li";
//    oldlist[33].name="黄文菲";    oldlist[33].py="huang wen fei";
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
//    printf("平均查找长度为:%f\n",average);
//    if(average>2)
//    hash();
//}
//
//
//void findlist()   
//{
//    char c[20];    
//    int i=0,d,g,adr,s=0;
//    printf("请输入你要查找的人的拼音:\n");
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
//        printf("姓名:%s 拼音:%s 哈希表中存储位置:%d\n",hlist[adr].name,hlist[adr].py,adr);
//    }
//    else 
//         if(hlist[adr].b==0)
//            {
//              printf("哈希表中无记录!\n");
//            }
//         else 
//         {
//             g=0;
//             for (i=0;g==0;i++)
//             {    d=(d+adr%10+1)%P;
//                 if(hlist[d].b==0)
//                 {
//                     printf("哈希表中无记录!\n");
//                     g=1;
//                 }
//                 if(strcmp(hlist[d].py,c)==0)
//                 {
//                     printf("姓名:%s 拼音:%s 哈希表中存储位置:%d\n",hlist[d].name,hlist[d].py,d);
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
//        printf("1.查找  2.输出哈希表  3.退出程序\n");
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
