/*1651574 贾昊霖 1班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0


typedef int Status;

typedef struct student {
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
} *ElemType, ET;

typedef struct DuLNode {
	ElemType        data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, *DuLinkList;

Status MyVisit(ElemType e)
{
	printf("%d %s %c %f %s\n", e->num, e->name, e->sex, e->score, e->addr);
	return OK;
}


Status initial_l(DuLinkList *L)
{
	*L = (DuLNode *)malloc(sizeof(DuLNode));
	if (*L == NULL)
		exit(OVERFLOW);
	(*L)->prior = *L;
	(*L)->next = *L;
	return OK;
}

DuLinkList GetElemP_DuL(DuLinkList L, int k)
{
	DuLinkList p = L;
	int pos = 0;
	while (p != NULL && pos < k) {
		p = p->next;
		pos++;
	}
	if (!p || pos > k)
		return NULL;
	return p;
}

int getLength_l(DuLinkList L)
{
	DuLinkList p = L->next; //指向首元结点
	int len = 0;
	do {
		p = p->next;
		len++;
	} while (p != L);
	return len;
}

Status traverse_l(DuLinkList L, Status(*visit)(ElemType e))
{
	DuLinkList p = L->next;
	do {
		if ((*visit)(p->data) != TRUE)
			break;
		p = p->next;
	} while (p != L);
	if (p != L->next)
		return ERROR;
	printf("\n");
	return OK;
}


Status ListInsert_DuL(DuLinkList *L, int i, ElemType e)
{
	DuLNode *p, *s;
	if (!(p = GetElemP_DuL(*L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		exit(OVERFLOW);
	if(!(s->data = (ElemType)malloc(sizeof(ET))))
		exit(OVERFLOW);

	//s->data = e;
	*(s->data) = *e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

Status ListDelete_DuL(DuLinkList *L, int i, ElemType *e)
{
	DuLNode *p;
	if (!(p = GetElemP_DuL(*L, i)))
		return ERROR;
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p->data);
	free(p);
	return OK;
}

Status destroy_l(DuLinkList *L)
{
	DuLinkList q, p = *L;
	do {
		q = p->next;   //抓住链表的下一个结点
		if(p != *L)
			free(p->data);
		free(p);
		p = q;
	} while (p != *L);
	*L = NULL;
	return OK;
}


int main()
{
	DuLinkList L;
	int i, pos;
	ET e[] = { { 1001, "张三", 'M', 76.5, "上海市杨浦区" },
	{ 1002, "李四", 'F', 87, "上海市普陀区" },
	{ 1003, "王五", 'M', 80, "浙江省杭州市" },
	{ 1004,"贾昊霖",'M',100,"北京市西城区" },
	{ 1005,"xxxx",'F',20,"xxxx" },
	{ 1006,"yyyy",'M',0,"yyyy" }, };
	initial_l(&L);
	for (i = 0; i < 3; i++)
		ListInsert_DuL(&L, getLength_l(L) + 1, e + i);

	printf("改变前：\n");
	traverse_l(L, MyVisit);

	printf("插入第一个：\n");
	if (ListInsert_DuL(&L, 1, e + 3) == OK)
		printf("成功\n");
	else
		printf("失败\n");
	traverse_l(L, MyVisit);


	printf("插入最后：\n");
	if (ListInsert_DuL(&L, getLength_l(L) + 1, e + 4) == OK)
		printf("成功\n");
	else
		printf("失败\n");
	traverse_l(L, MyVisit);

	printf("请输入要插入元素的位序：\n");
	scanf("%d", &pos);
	if (pos < 0 || pos>6)
		printf("失败\n");
	if (ListInsert_DuL(&L, pos, e + 5) == OK)
		printf("成功\n");
	else
		printf("失败\n");

	ElemType elem;
	printf("删除第一个元素：\n");
	if (ListDelete_DuL(&L, 1, &elem) == OK)
		printf("删除成功\n");
	else
		printf("删除失败\n");
	//printf("删除的元素:\n");
	//MyVisit(elem);
	traverse_l(L, MyVisit);

	printf("删除最后一个元素：\n");
	if (ListDelete_DuL(&L, getLength_l(L), &elem) == OK)
		printf("删除成功\n");
	else
		printf("删除失败\n");
	//printf("删除的元素:\n");
	//MyVisit(elem);
	traverse_l(L, MyVisit);

	printf("最后的链表：\n");
	traverse_l(L, MyVisit);

	destroy_l(&L);

	return 0;
}
