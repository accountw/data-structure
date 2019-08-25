//����������ʽ�洢
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//����������Ľ��
typedef struct Node {
	ElemType data;
	struct Node* lchild; //ָ�����ӽ��
	struct Node* rchild; //ָ���к��ӽ��
}*BiTree,BitNode;

//��ʼ��������
void initBitTree(BiTree *T) {
	*T = NULL;
}

//���ٶ�����
void destoryBitTree(BiTree* T) {
	if (*T) {
		if ((*T)->lchild)
			destoryBitTree(&((*T)->lchild));
		if ((*T)->rchild)
			destoryBitTree(&((*T)->rchild));
		free(*T);
		*T = NULL;

	}
}

//����������
//���õݹ鴴��������
void createBitTree(BiTree* T) {
	ElemType a;
	scanf("%c", &a);
	if (a == '#')//#��ʾ��
		* T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BitNode));
		if (!*T)
			exit(-1);
		(*T)->data = a;
		createBitTree(&((*T)->lchild));
		createBitTree(&((*T)->rchild));
	}
}


//����������������
//������c���뵽p�����,�Ҳ�������
int insertLchild(BiTree p, BiTree c) {
	if (p) {
		c->rchild = p->lchild;
		p->lchild = c;

	}
	return 0;
}

//���ض���������ָ�����
//����Ԫ��ֵΪ1�Ľ�㲢����
//���ö��б�����
BiTree point(BiTree T, ElemType e) {
	BiTree q[100];
	int front = 0, rear = 0;
	BitNode* p;
	if (T) {
		q[rear] = T;
		rear++;
		while (front != rear) {
			p = q[front];
			front++;
			if (p->data == e) {
				return p;
			}
			if (p->lchild) {
				q[rear] = p->lchild;
				rear++;
			}
			if (p->rchild) {
				q[rear] = p->rchild;
				rear++;
			}
		}
	}
	return NULL;
}

//�������
//�ȷ��ʸ��ڵ�
//�������������
//�������������
//ʹ�õݹ�
void preOrderTraverse(BiTree T) {
	if (T) {
		printf("%c", T->data);
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
	}
}
//�ǵݹ�
//ʹ��ջ
void preOrderTraverse1(BiTree T) {
	BiTree stack[100];
	int top;
	BitNode* p;
	top = 0;
	p = T;
	while (p!=NULL||top>0)
	{
		while (p != NULL) {
			printf("%c", p->data);
			stack[top++] = p;
			p = p->lchild;
		}
		if (top > 0) {
			p = stack[--top];
			p = p->rchild;
		}
	}
}

//�������
//�������������
//���ʸ����
//�������������
//�ݹ�
void preOrderTraverse2(BiTree T) {
	if (T) {
		preOrderTraverse(T->lchild);
		printf("%c", T->data);
		preOrderTraverse(T->rchild);
	}
}
//ջ
void preOrderTraverse3(BiTree T) {
	BiTree stack[100];
	int top;
	BitNode* p;
	top = 0;
	p = T;
	while (p != NULL || top > 0)
	{
		while (p != NULL) {
			stack[top++] = p;
			p = p->lchild;
		}
		if (top > 0) {
			p = stack[--top];
			printf("%c", p->data);
			p = p->rchild;
		}
	}
}

//��������
//��������������
//��������������
//���ʸ����
void preOrderTraverse4(BiTree T) {
	if (T) {
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
		printf("%c", T->data);
		
	}
}
void preOrderTraverse5(BiTree T) {
	BiTree stack[100];
	int top;
	BitNode* p,*q;
	top = 0;
	p = T;
	q = NULL;
	while (p != NULL || top > 0)
	{
		while (p != NULL) {
			stack[top++] = p;
			p = p->lchild;
		}
		if (top > 0) {
			p = stack[top-1];
			if (p->rchild == NULL || p->rchild == q) {
				printf("%c", p->data);
				q = p;
				p = NULL;
				top--;
			}
			else
				p = p->rchild;
		}
	}
}