//二叉树的链式存储
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//定义二叉树的结点
typedef struct Node {
	ElemType data;
	struct Node* lchild; //指向左孩子结点
	struct Node* rchild; //指向有孩子结点
}*BiTree,BitNode;

//初始化二叉树
void initBitTree(BiTree *T) {
	*T = NULL;
}

//销毁二叉树
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

//创建二叉树
//利用递归创建二叉树
void createBitTree(BiTree* T) {
	ElemType a;
	scanf("%c", &a);
	if (a == '#')//#表示空
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


//二叉树的左插入操作
//将子树c插入到p结点中,右插入类似
int insertLchild(BiTree p, BiTree c) {
	if (p) {
		c->rchild = p->lchild;
		p->lchild = c;

	}
	return 0;
}

//返回二叉树结点的指针操作
//查找元素值为1的结点并返回
//利用队列遍历树
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

//先序遍历
//先访问根节点
//先序遍历左子树
//先序遍历右子树
//使用递归
void preOrderTraverse(BiTree T) {
	if (T) {
		printf("%c", T->data);
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
	}
}
//非递归
//使用栈
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

//中序遍历
//中序遍历左子树
//访问根结点
//中序遍历右子树
//递归
void preOrderTraverse2(BiTree T) {
	if (T) {
		preOrderTraverse(T->lchild);
		printf("%c", T->data);
		preOrderTraverse(T->rchild);
	}
}
//栈
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

//后续遍历
//后续遍历左子树
//后续遍历右子树
//访问根结点
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