/*c语言实现链表*/

#include <stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int ElemType;


//单链表
//线性表的单链表存储结构
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

/*初始化链表*/
LNode* initLink() {
	LNode* p = (LNode*)malloc(sizeof(LNode));//创建一个头结点
	LNode* temp = p;//声明一个指针指向头结点，用于遍历链表
	//生成链表
	for (int i = 1; i < 5; i++) {
		//创建节点并初始化
		LNode* a = (LNode*)malloc(sizeof(LNode));
		a->data = i;
		a->next = NULL;
		//建立新节点与直接前驱节点的逻辑关系
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

/* 创建链表*/
void createlist(LNode* L, int n) {
	
	for (int i = n; i > 0; --i) {
		LNode* p = (LNode*)malloc(sizeof(LNode));//创建一个新结点
		printf("输入结点的值:");
		scanf("%d",&p->data);
		//p->next = L->next; 
		//L->next = p;  //从表头插入

		p->next = NULL;
		L->next = p;
		L = L->next; //从表尾插入
	}
}

/* 插入 */
Status Insert(LNode* L, int i, int e) {
	int j ;
	LNode* p;
	p = L;
	for (j = 1; j < i; j++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("插入位置不当");
			return 0;
		}
	}
	LNode* q = (LNode*)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
/*删除*/
Status Delete(LNode* L, int i) {
	LNode* p = L;
	int j;
	for (j = 1; j < i; j++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("删除位置不当");
			return 0;
		}
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

/* 查找第n个元素*/
Status find(LNode* L, int n) {
	LNode* p = L;
	for (int i = 0; i < n;i++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("查询位置不当");
			return 0;
		}

	}
	printf("第%d个元素是%d\n",n, p->data);
}

/* 将第n个元素改为e*/
Status change(LNode* L, int n,int e) {
	LNode* p = L;
	for (int i = 0; i < n; i++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("修改位置不当");
			return 0;
		}

	}
	p->data = e;
	return 1;
}


/*得到链表的长度*/
Status getlength(LNode* L) {
	LNode* p = L;
	int length=0;
	while (p->next) {
		length++;
		p = p->next;
	}
	printf("链表长度为%d\n ", length);
}

/* 遍历链表 */
void display(LNode* L) {
	LNode* temp = L;//将temp指针重新指向头结点
	//只要temp指针指向的结点的next不是Null，就执行输出语句。
	while (temp->next) {
		temp = temp->next;
		printf("%d\n ", temp->data);
		
	}
}

//int main() {
//	int m;
//	//LNode* L = initLink();
//	//m=Insert(L, 2, 5);
//	//m = Delete(L, 3);
//
//	//m = change(L, 1, 5);
//	LNode *L= (LNode*)malloc(sizeof(LNode));
//	L->next = NULL;
//	createlist(L,5);
//	m = getlength(L);
//	display(L);
//
//	return 0;
//}