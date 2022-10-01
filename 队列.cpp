#include<stdio.h>
#define MAXSIZE 30
typedef char QElemType;
typedef struct{
	QElemType data[MAXSIZE];
	int f;//ͷָ��
	int r;//βָ��
}SqQueue;


void initQueue(SqQueue &Q)
{
	Q.f = Q.r = 0;
}

int getQueueLength(SqQueue Q)
{
	return (Q.r - Q.f + MAXSIZE)%MAXSIZE;
}


void enQueue(SqQueue &Q, QElemType e)
{
	if(Q.f == (Q.r + 1)%MAXSIZE){
		printf("������������Ӳ���ʧ�ܣ�\n");
		return;
	}
	Q.data[Q.r] = e;
	Q.r = (Q.r + 1)%MAXSIZE;
}


void deQueue(SqQueue &Q, QElemType &e){
	
	if(Q.f == Q.r){
		printf("�����ѿգ����Ӳ���ʧ�ܣ�\n");
		return;
	}
	e = Q.data[Q.f];
	printf("Ԫ��%c����\n", e);
	Q.f = (Q.f + 1)%MAXSIZE;
}


void createQueue(SqQueue &Q, int n)
{
	int i = 0;
	printf("������%d���ַ�����Ԫ�أ�\n", n);
	while(i < n){
		QElemType e;
		scanf("%c", &e);
		enQueue(Q, e);
		i++;
		getchar();
	}
}



void printQueue(SqQueue Q){
	printf("��ӡ���У�");
	int i = Q.f;
	while(i%MAXSIZE != Q.r){
		printf("%c ", Q.data[i]);
		i++;
	}
	printf("\n\n");
}



int main()
{
	SqQueue Q;
	initQueue(Q);
	createQueue(Q, 5);
	printQueue(Q);
 
	printf("ִ����Ӳ�����");
	printf("��������Ҫ��ӵ��ַ�Ԫ�أ�");
	QElemType e;
	scanf("%c", &e);
	enQueue(Q, e);
	printQueue(Q);
 
	printf("ִ�г��Ӳ�����");
	deQueue(Q, e);
	printQueue(Q);
 
}

