//链式队列的实现

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


//定义结点类型
typedef struct QNode {
	ElemType data;
	struct QNode* next;

}LQNode, *QueuePtr;

//定义队列类型
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化队列
void initQueue(LinkQueue* L) {
	L->front = L->rear = (LQNode*)malloc(sizeof(LQNode));
	L->front->next = NULL;
}

//判断队列是否为空
int emptyQueue(LinkQueue L) {
	if (L.front->next == NULL)
		return 1;
	else
		return 0;

}

//入队操作
int enQueue(LinkQueue* L, ElemType e) {
	LQNode* s;
	s = (LQNode*)malloc(sizeof(LQNode));
	s->data = e;
	s->next = NULL;
	L->rear->next = s;
	L->rear = s;
	return 1;

}
 //出队操作
int deQueue(LinkQueue* L) {
	ElemType e;
	LQNode* s;
	if (L->front->next == NULL) {
		return -1;
	}
	else {
		s = L->front->next;
		e = s->data;
		L->front->next = s->next;
		if (L->rear == s)
			L->rear = L->front;
		free(s);
		return e;
	}
}

//取队头元素
int getHead(LinkQueue L, ElemType *e) {
	
	LQNode* s;
	if (L.front = L.rear) {
		return -1;
	}
	else
	{
		s = L.front->next;
		*e = s->data;
		return 1;
	}
}

//清空队列
void clearQueue(LinkQueue* L) {
	while (L->front!=NULL)
	{
		L->rear = L->front->next;
		free(L->front);
		L->front = L->rear;
	}
}