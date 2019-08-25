//��ʽ���е�ʵ��

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


//����������
typedef struct QNode {
	ElemType data;
	struct QNode* next;

}LQNode, *QueuePtr;

//�����������
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//��ʼ������
void initQueue(LinkQueue* L) {
	L->front = L->rear = (LQNode*)malloc(sizeof(LQNode));
	L->front->next = NULL;
}

//�ж϶����Ƿ�Ϊ��
int emptyQueue(LinkQueue L) {
	if (L.front->next == NULL)
		return 1;
	else
		return 0;

}

//��Ӳ���
int enQueue(LinkQueue* L, ElemType e) {
	LQNode* s;
	s = (LQNode*)malloc(sizeof(LQNode));
	s->data = e;
	s->next = NULL;
	L->rear->next = s;
	L->rear = s;
	return 1;

}
 //���Ӳ���
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

//ȡ��ͷԪ��
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

//��ն���
void clearQueue(LinkQueue* L) {
	while (L->front!=NULL)
	{
		L->rear = L->front->next;
		free(L->front);
		L->front = L->rear;
	}
}