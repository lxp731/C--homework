#include<stdio.h>
#define MAXSIZE 30
typedef char QElemType;
typedef struct{
	QElemType data[MAXSIZE];
	int f;//头指针
	int r;//尾指针
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
		printf("队列已满，入队操作失败！\n");
		return;
	}
	Q.data[Q.r] = e;
	Q.r = (Q.r + 1)%MAXSIZE;
}


void deQueue(SqQueue &Q, QElemType &e){
	
	if(Q.f == Q.r){
		printf("队列已空，出队操作失败！\n");
		return;
	}
	e = Q.data[Q.f];
	printf("元素%c出队\n", e);
	Q.f = (Q.f + 1)%MAXSIZE;
}


void createQueue(SqQueue &Q, int n)
{
	int i = 0;
	printf("请输入%d个字符队列元素：\n", n);
	while(i < n){
		QElemType e;
		scanf("%c", &e);
		enQueue(Q, e);
		i++;
		getchar();
	}
}



void printQueue(SqQueue Q){
	printf("打印队列：");
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
 
	printf("执行入队操作：");
	printf("请输入您要入队的字符元素：");
	QElemType e;
	scanf("%c", &e);
	enQueue(Q, e);
	printQueue(Q);
 
	printf("执行出队操作：");
	deQueue(Q, e);
	printQueue(Q);
 
}

