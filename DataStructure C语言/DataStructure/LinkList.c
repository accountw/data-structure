/*c����ʵ������*/

#include <stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int ElemType;


//������
//���Ա�ĵ�����洢�ṹ
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

/*��ʼ������*/
LNode* initLink() {
	LNode* p = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
	LNode* temp = p;//����һ��ָ��ָ��ͷ��㣬���ڱ�������
	//��������
	for (int i = 1; i < 5; i++) {
		//�����ڵ㲢��ʼ��
		LNode* a = (LNode*)malloc(sizeof(LNode));
		a->data = i;
		a->next = NULL;
		//�����½ڵ���ֱ��ǰ���ڵ���߼���ϵ
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

/* ��������*/
void createlist(LNode* L, int n) {
	
	for (int i = n; i > 0; --i) {
		LNode* p = (LNode*)malloc(sizeof(LNode));//����һ���½��
		printf("�������ֵ:");
		scanf("%d",&p->data);
		//p->next = L->next; 
		//L->next = p;  //�ӱ�ͷ����

		p->next = NULL;
		L->next = p;
		L = L->next; //�ӱ�β����
	}
}

/* ���� */
Status Insert(LNode* L, int i, int e) {
	int j ;
	LNode* p;
	p = L;
	for (j = 1; j < i; j++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("����λ�ò���");
			return 0;
		}
	}
	LNode* q = (LNode*)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
/*ɾ��*/
Status Delete(LNode* L, int i) {
	LNode* p = L;
	int j;
	for (j = 1; j < i; j++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("ɾ��λ�ò���");
			return 0;
		}
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

/* ���ҵ�n��Ԫ��*/
Status find(LNode* L, int n) {
	LNode* p = L;
	for (int i = 0; i < n;i++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("��ѯλ�ò���");
			return 0;
		}

	}
	printf("��%d��Ԫ����%d\n",n, p->data);
}

/* ����n��Ԫ�ظ�Ϊe*/
Status change(LNode* L, int n,int e) {
	LNode* p = L;
	for (int i = 0; i < n; i++) {
		if (p->next) {
			p = p->next;
		}
		else {
			printf("�޸�λ�ò���");
			return 0;
		}

	}
	p->data = e;
	return 1;
}


/*�õ�����ĳ���*/
Status getlength(LNode* L) {
	LNode* p = L;
	int length=0;
	while (p->next) {
		length++;
		p = p->next;
	}
	printf("������Ϊ%d\n ", length);
}

/* �������� */
void display(LNode* L) {
	LNode* temp = L;//��tempָ������ָ��ͷ���
	//ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
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