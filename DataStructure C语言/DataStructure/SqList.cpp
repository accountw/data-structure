/* c语言实现顺序表 */
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
	ElemType* elem; // 顺序表元素
	int length;     // 顺序表长度
	int listsize;   // 顺序表存储容量
} SqList;

// 构造空顺序表
int InitList(SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType));
	if (!L->elem) return ERROR;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

// 获取顺序表第i个元素
ElemType GetListElem(SqList* L, int i)
{
	if (i < 1 || i > L->length)
		return ERROR;
	else
		return L->elem[i - 1];
}

// 定位目标元素在顺序表中位置
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

// 在顺序表第i个位置插入元素
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

// 删除顺序表第i个元素
int DeleteListElem(SqList* L, int i)
{
	int k;
	if (i < 1 || i >L->length) return ERROR;
	for (k = i; k <= L->length; k++)
		L->elem[k - 1] = L->elem[k];
	L->length--;
	return OK;
}

// 修改顺序表第i个元素
int UpdateListElem(SqList* L, int i, ElemType e)
{
	if (i < 1 || i >L->length) return ERROR;
	L->elem[i - 1] = e;
	return OK;
}

// 输出顺序表全部元素
void PrintList(SqList* L)
{
	int i;
	if (L->length == 0)
		printf("\n顺序表为空！\n\n");
	else
		for (i = 1; i <= L->length; i++)
			printf("%d ", L->elem[i - 1]);
	printf("\n");
}

