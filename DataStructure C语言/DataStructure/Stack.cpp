//c���ԣ�ջ��˳���ʾ��ʵ��
//����˳��洢�ṹ��ջ��Ϊ˳��ջ��˳��ջ����һ��������
//�洢��Ԫ���ջ�е�Ԫ�أ����˳�����δ�ջ�׵�ջ��

#include <stdio.h>
#define STACKSIZE 100

typedef  int ElemType;

typedef struct {
	ElemType stack[STACKSIZE];
	int top;

}SeqStack;

//��ʼ��ջ
void initStack(SeqStack* s) {
	s->top = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int stackEmpty(SeqStack s) {
	if (s.top == 0)
		return 1;
	else
		return 0;
	
}

//ȡջ��Ԫ��
int getTop(SeqStack s, ElemType* e) {


	if (s.top <= 0) {
		printf("��ջ");
		return 0;

	}
	else {
		*e = s.stack[s.top - 1];
		return 1;
	}
}

//��ջ

int pushStack(SeqStack* s, ElemType e) {
	if (s->top >= STACKSIZE) {
		printf("ջ����");
		return 0;

	}
	else {
		s->stack[s->top] = e;
		s->top++;
		return 1;
	}
}

//��ջ

int popStack(SeqStack* s, ElemType* e) {
	if (s->top = 0) {
		printf("��ջ");
		return 0;
	}
	else {
		s->top--;
		*e = s->stack[s->top];
		return 1;
	}
}

//�õ�ջ�ĳ���
int getLength(SeqStack s) {
	return s.top;
}

//���ջ
void clearStack(SeqStack* s) {
	s->top = 0;
}