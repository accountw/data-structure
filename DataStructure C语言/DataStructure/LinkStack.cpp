//c语言 栈的链式表示与实现
/*采用顺序存储的栈也具有顺序表类似的缺点：
采用顺序存储的栈，即顺序栈的存储空间无法事先确定，
如果栈空间分配过小，可能会造成溢出；如果栈空间分配过大，
又容易造成存储空间浪费，因此可以采用链式存储结构表示栈*/

#include <stdio.h>
#include<stdlib.h>



typedef  int ElemType;

//定义链栈结点
typedef struct node {
	ElemType data;
	struct  node* next;

}LinkStack;

//初始化链栈
LinkStack* initStack() {
	LinkStack* top = (LinkStack*)malloc(sizeof(LinkStack));
	top->next = NULL;
	return top;
}

//判断是否为空栈
int stackEmpty(LinkStack *top) {
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

//进栈

int pushStack(LinkStack* top, ElemType e) {
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = e;
	p->next = top->next;
	top->next = p;
	return 1;
}

//出栈
int popStack(LinkStack* top) {
	LinkStack* p;
	ElemType e;
	p = top->next;
	if (!p) {
		printf("空栈");
		exit(1);
	}
	top->next = p->next;
	e = p->data;
	free(p);
	return e;
}

//取栈顶元素
int getTop(LinkStack* top, ElemType e) {
	LinkStack* p;
	p = top->next;
	if (!p) {
		printf("空栈");
		return 0;
	}
	e = p->data;
	return 1;
}


//得到栈的长度
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


//销毁链栈
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
