/* c����ʵ��˳��� */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef struct {
	ElemType* elem; // ˳���Ԫ��
	int length;     // ˳�����
	int listsize;   // ˳���洢����
} SqList;

// �����˳���
int InitList(SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType));
	if (!L->elem) return ERROR;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

// ��ȡ˳����i��Ԫ��
ElemType GetListElem(SqList* L, int i)
{
	if (i < 1 || i > L->length)
		return ERROR;
	else
		return L->elem[i - 1];
}

// ��λĿ��Ԫ����˳�����λ��
int LocateListElem(SqList* L, ElemType e)
{
	int i = 1;
	ElemType* p = L->elem;
	while (*p != e && i <= L->length)
	{
		i++;
		p++;
	}
	if (i > L->length)
		return 0;
	else
		return i;
}

// ��˳����i��λ�ò���Ԫ��
int InsertListElem(SqList* L, int i, ElemType e)
{
	int k;
	if (i < 1 || i > L->length + 1) return ERROR;
	if (L->length >= L->listsize)
	{
		L->elem = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!L->elem) return ERROR;
		L->listsize += LISTINCREMENT;
	}

	for (k = L->length - 1; k >= i - 1; k--)
		L->elem[k + 1] = L->elem[k];
	L->elem[i - 1] = e;
	L->length++;
	return OK;
}

// ɾ��˳����i��Ԫ��
int DeleteListElem(SqList* L, int i)
{
	int k;
	if (i < 1 || i >L->length) return ERROR;
	for (k = i; k <= L->length; k++)
		L->elem[k - 1] = L->elem[k];
	L->length--;
	return OK;
}

// �޸�˳����i��Ԫ��
int UpdateListElem(SqList* L, int i, ElemType e)
{
	if (i < 1 || i >L->length) return ERROR;
	L->elem[i - 1] = e;
	return OK;
}

// ���˳���ȫ��Ԫ��
void PrintList(SqList* L)
{
	int i;
	if (L->length == 0)
		printf("\n˳���Ϊ�գ�\n\n");
	else
		for (i = 1; i <= L->length; i++)
			printf("%d ", L->elem[i - 1]);
	printf("\n");
}

