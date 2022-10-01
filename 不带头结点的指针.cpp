typedef int elemType ;
 
// ���嵥����������
typedef struct ListNode{
    elemType element;      //������
    struct ListNode *next;   //��ַ��
}Node;

��2����ʼ�����Ա�
// 1.��ʼ�����Ա����õ�����ı�ͷָ��Ϊ��
void initList(Node *pNode){
 
    pNode = NULL;
    printf("%s����ִ�У���ʼ���ɹ�\n",__FUNCTION__);
}
������һ��ͷ���󣬰Ѹ�ͷ�������Ϊ�գ�����������͵�ַ����Ϊ�գ�������ɸ�����ĳ�ʼ����
��3���������Ա�

// 2.�������Ա��˺������븺����ֹ��ȡ����
Node *creatList(Node *pHead){
 
    Node *p1;//��ͷ�ڵ㣬ʼ��ָ��ͷ���
    Node *p2;//��β�ڵ㣬ʼ��ָ����������һ��Ԫ��
 
    p1 = p2 = (Node *)malloc(sizeof(Node)); //�����½ڵ�,����ռ�
    if(p1 == NULL || p2 == NULL){
 
        printf("�ڴ����ʧ��\n");
        exit(0);
    }
    memset(p1,0,sizeof(Node));
 
    scanf("%d",&p1->element);    //�����½ڵ��ֵ
    p1->next = NULL;         //�½ڵ��ָ����Ϊ��
    while(p1->element > 0){        //�����ֵ����0�������ֱ�������ֵΪ��
        if(pHead == NULL){       //�ձ������ͷ
            pHead = p1;          //ֱ�Ӱ�p1��Ϊͷ��㣬Ҳ�������Ϊ��pHeadͷ���ָ��p1
        }else{
            p2->next = p1;       //�ǿձ������β
        }
        p2 = p1;                //p1�����p1����β��㣬����p2Ҫָ��β���
        p1 = (Node *)malloc(sizeof(Node));    //��������һ���ڵ�
        if(p1 == NULL || p2 == NULL){
 
            printf("�ڴ����ʧ��\n");
            exit(0);
        }
        memset(p1,0,sizeof(Node));
        scanf("%d",&p1->element);
        p1->next = NULL;
    }
    printf("%s����ִ�У��������ɹ�\n",__FUNCTION__);
    return pHead;           //���������ͷָ��
}

������ʹ���ֶ��ķ�ʽ����Ԫ�أ�ֱ������0���߸���ֹͣ��

��4����ӡ����

// 3.��ӡ��������ı���
void printList(Node *pHead){
    if(NULL == pHead){   //����Ϊ��
        printf("%s����ִ�У�����Ϊ��\n",__FUNCTION__);
    }else{
        while(NULL != pHead){
            
            printf("%d ",pHead->element);
            pHead = pHead->next;
        }
        printf("\n");
    }
}

ʹ�õ�ַ��˳���ӡ���ɡ�


��5���������

// 4.������Ա�L�е�����Ԫ�أ����ͷŵ�����L�����еĽ�㣬ʹ֮��Ϊһ���ձ�
void clearList(Node *pHead){
 
    Node *pNext;            //����һ����pHead���ڽڵ�,���Ϊ��ǰ�ڵ����һ���ڵ�
    if(pHead == NULL){
        printf("%s����ִ�У�����Ϊ��\n",__FUNCTION__);
    }
    while(pHead->next != NULL){
 
        pNext = pHead->next;//������һ����ָ��
        free(pHead);   //�ͷŵ�ǰ�ڵ�
        pHead = pNext;      //ָ����һ���ڵ�
    }
    printf("%s����ִ�У������Ѿ����\n",__FUNCTION__);
}

��Ҫ�����Ƿ���ճɹ�������ʹ�ã�4���е������ӡ���鼴�ɡ�
��6������������

// 5.���ص�����ĳ���
int sizeList(Node *pHead){
 
    int size = 0;
    while(pHead != NULL){
 
        size++;
        pHead = pHead->next;
    }
    printf("%s����ִ�У������� %d \n",__FUNCTION__,size);
    return size;    //�����ʵ�ʳ���
}

Ҳ���Ǽ����ж��ٸ��ڵ㡣
��7���ж������Ƿ�Ϊ��

// 6.��鵥�����Ƿ�Ϊ�գ���Ϊ���򷵻أ������򷵻أ�
int isEmptyList(Node *pHead){
    if(pHead == NULL){
 
        printf("%s����ִ�У�����Ϊ��\n",__FUNCTION__);
        return 1;
    }
    printf("%s����ִ�У�����ǿ�\n",__FUNCTION__);
 
    return 0;
}

��8����������ĳ��λ��Ԫ��
// 7.���ص������е�pos������е�Ԫ�أ���pos������Χ����ֹͣ��������
void getElement(Node *pHead, int pos){
 
    int i = 0;
    if(pos < 1){
        printf("%s����ִ�У�posֵ�Ƿ�\n",__FUNCTION__);
    }
 
    if(pHead == NULL){
        printf("%s����ִ�У�����Ϊ��\n",__FUNCTION__);
    }
 
    while(pHead != NULL){
 
        i++;
        if(i == pos){
            break;
        }
        pHead = pHead->next;    //�Ƶ���һ���
    }
    if(i < pos){                  //posֵ����������
        printf("%s����ִ�У�posֵ����������\n",__FUNCTION__);
    }
 
    printf("%s����ִ�У�λ�� %d �е�Ԫ��Ϊ %d\n",__FUNCTION__,pos,pHead->element);
}

��9������ĳԪ��ֵ�������е��ڴ��ַ
// 8.�ӵ������в��Ҿ��и���ֵx�ĵ�һ��Ԫ�أ������ҳɹ��򷵻ظý��data��Ĵ洢��ַ�����򷵻�NULL
elemType* getElemAddr(Node *pHead, elemType x){
    if(NULL == pHead){
 
        printf("%s����ִ�У�����Ϊ��\n",__FUNCTION__);
        return NULL;
    }
 
    while((pHead->element != x) && (NULL != pHead->next)) {//�ж��Ƿ�����ĩβ���Լ��Ƿ������Ҫ�ҵ�Ԫ��
        pHead = pHead->next;
    }
 
    if((pHead->element != x) && (pHead != NULL)){
        //���������һ���ڵ�
        printf("%s����ִ�У���������δ�ҵ�xֵ\n",__FUNCTION__);
        return NULL;
    }
 
    if(pHead->element == x){
        printf("%s����ִ�У�Ԫ�� %d �ĵ�ַΪ 0x%x\n",__FUNCTION__,x,&(pHead->element));
    }
 
    return &(pHead->element);//����Ԫ�صĵ�ַ
}

��10���޸�ĳ���ڵ��ֵ

// 9.�ѵ������е�pos������ֵ�޸�Ϊx��ֵ�����޸ĳɹ����أ������򷵻أ�
int modifyElem(Node *pNode,int pos,elemType x){
 
    int i = 0;
    if(NULL == pNode){
        printf("%s����ִ�У�����Ϊ��\n",__FUNCTION__);
        return 0;
    }
 
    if(pos < 1){
 
        printf("%s����ִ�У�posֵ�Ƿ�\n",__FUNCTION__);
        return 0;
    }
 
    while(pNode != NULL){
 
        i++;
        if(i == pos){
            break;
        }
        pNode = pNode->next; //�Ƶ���һ���
    }
 
    if(i < pos) {                 //posֵ����������
 
        printf("%s����ִ�У�posֵ����������\n",__FUNCTION__);
        return 0;
    }
    pNode->element = x;
    printf("%s����ִ��\n",__FUNCTION__);
 
    return 1;
}

��11����ͷ����һ���ڵ�
// 10.������ı�ͷ����һ��Ԫ��
int insertHeadList(Node **pNode,elemType insertElem){
 
    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert,0,sizeof(Node));
    pInsert->element = insertElem;
    pInsert->next = *pNode;
    *pNode = pInsert;          //ͷ�ڵ�*pNodeָ��ղ���Ľڵ㣬ע�����һ�д����ǰ��˳��
    printf("%s����ִ�У����ͷ����Ԫ�سɹ�\n",__FUNCTION__);
 
    return 1;
}

��12����β����һ���ڵ�
// 11.�������ĩβ���һ��Ԫ��
int insertLastList(Node **pNode,elemType insertElem){
 
    Node *pInsert;
    Node *pHead;
 
    pHead = *pNode;
    pInsert = (Node *)malloc(sizeof(Node)); //����һ���½ڵ�
    memset(pInsert,0,sizeof(Node));
    pInsert->element = insertElem;
 
    while(pHead->next != NULL){
        pHead = pHead->next;
    }
    pHead->next = pInsert;   //������ĩβ�ڵ����һ���ָ������ӵĽڵ�
 
    printf("%s����ִ�У����β����Ԫ�سɹ�\n",__FUNCTION__);
    
    return 1;
}

��13�����Ժ���
int main(int argc, const char * argv[]) {
 
    Node *pList;            //����ͷ���
 
    initList(pList);       //�����ʼ��
    printList(pList);       //����������ӡ����
 
    pList = creatList(pList); //��������
    printList(pList);
 
    sizeList(pList);        //����ĳ���
    printList(pList);
 
    isEmptyList(pList);     //�ж������Ƿ�Ϊ������
 
    getElement(pList,3);  //��ȡ������Ԫ�أ����Ԫ�ز���3�����򷵻�0
    printList(pList);
 
    getElemAddr(pList,5);   //���Ԫ��5���ڴ��ַ
 
    modifyElem(pList,4,1);  //��������λ��4�ϵ�Ԫ���޸�Ϊ1
    printList(pList);
 
    insertHeadList(&pList,5);   //��ͷ����Ԫ��5
    printList(pList);
 
    insertLastList(&pList,10);  //��β����Ԫ��10
    printList(pList);
 
    clearList(pList);       //�������
    printList(pList);
 
    return 0;
}

