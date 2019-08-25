//c���� ջ����ʽ��ʾ��ʵ��
/*����˳��洢��ջҲ����˳������Ƶ�ȱ�㣺
����˳��洢��ջ����˳��ջ�Ĵ洢�ռ��޷�����ȷ����
���ջ�ռ�����С�����ܻ������������ջ�ռ�������
��������ɴ洢�ռ��˷ѣ���˿��Բ�����ʽ�洢�ṹ��ʾջ*/

#include <stdio.h>
#include<stdlib.h>



typedef  int ElemType;

//������ջ���
typedef struct node {
	ElemType data;
	struct  node* next;

}LinkStack;

//��ʼ����ջ
LinkStack* initStack() {
	LinkStack* top = (LinkStack*)malloc(sizeof(LinkStack));
	top->next = NULL;
	return top;
}

//�ж��Ƿ�Ϊ��ջ
int stackEmpty(LinkStack *top) {
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

//��ջ

int pushStack(LinkStack* top, ElemType e) {
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = e;
	p->next = top->next;
	top->next = p;
	return 1;
}

//��ջ
int popStack(LinkStack* top) {
	LinkStack* p;
	ElemType e;
	p = top->next;
	if (!p) {
		printf("��ջ");
		exit(1);
	}
	top->next = p->next;
	e = p->data;
	free(p);
	return e;
}

//ȡջ��Ԫ��
int getTop(LinkStack* top, ElemType e) {
	LinkStack* p;
	p = top->next;
	if (!p) {
		printf("��ջ");
		return 0;
	}
	e = p->data;
	return 1;
}


//�õ�ջ�ĳ���
int getLength(LinkStack *top) {
	LinkStack* p;
	int count = 0;
	p = top;
	while (p->next) {
		p = p->next;
		count++;
	}
	return count;
}


//������ջ
void destoryStack(LinkStack* top) {
	LinkStack* p, * q;
	p = top;
	while (!p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

int main() {
	/*int N = 28;
	LinkStack* p, * top = NULL;
	do {
		p= (LinkStack*)malloc(sizeof(LinkStack));
		p->data = N % 8;
		p->next = top;
		top = p;
		N = N / 8;
	} while (N != 0);
	while (top!=NULL)
	{
		p = top;
		printf("%d", p->data);
		top = top->next;
		free(p);
	}*/
	int n = 28;
	int x;
	LinkStack* p=initStack();
	while (n > 0) {
		x = n % 8;
		pushStack(p, x);
		n = n / 8;
	}
	while (!stackEmpty(p)) {
		x=popStack(p);
		printf("%d", x);
	}
}
