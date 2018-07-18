/*1651574 ����� 1��*/
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
	DuLinkList p = L->next; //ָ����Ԫ���
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
		q = p->next;   //ץס�������һ�����
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
	ET e[] = { { 1001, "����", 'M', 76.5, "�Ϻ���������" },
	{ 1002, "����", 'F', 87, "�Ϻ���������" },
	{ 1003, "����", 'M', 80, "�㽭ʡ������" },
	{ 1004,"�����",'M',100,"������������" },
	{ 1005,"xxxx",'F',20,"xxxx" },
	{ 1006,"yyyy",'M',0,"yyyy" }, };
	initial_l(&L);
	for (i = 0; i < 3; i++)
		ListInsert_DuL(&L, getLength_l(L) + 1, e + i);

	printf("�ı�ǰ��\n");
	traverse_l(L, MyVisit);

	printf("�����һ����\n");
	if (ListInsert_DuL(&L, 1, e + 3) == OK)
		printf("�ɹ�\n");
	else
		printf("ʧ��\n");
	traverse_l(L, MyVisit);


	printf("�������\n");
	if (ListInsert_DuL(&L, getLength_l(L) + 1, e + 4) == OK)
		printf("�ɹ�\n");
	else
		printf("ʧ��\n");
	traverse_l(L, MyVisit);

	printf("������Ҫ����Ԫ�ص�λ��\n");
	scanf("%d", &pos);
	if (pos < 0 || pos>6)
		printf("ʧ��\n");
	if (ListInsert_DuL(&L, pos, e + 5) == OK)
		printf("�ɹ�\n");
	else
		printf("ʧ��\n");

	ElemType elem;
	printf("ɾ����һ��Ԫ�أ�\n");
	if (ListDelete_DuL(&L, 1, &elem) == OK)
		printf("ɾ���ɹ�\n");
	else
		printf("ɾ��ʧ��\n");
	//printf("ɾ����Ԫ��:\n");
	//MyVisit(elem);
	traverse_l(L, MyVisit);

	printf("ɾ�����һ��Ԫ�أ�\n");
	if (ListDelete_DuL(&L, getLength_l(L), &elem) == OK)
		printf("ɾ���ɹ�\n");
	else
		printf("ɾ��ʧ��\n");
	//printf("ɾ����Ԫ��:\n");
	//MyVisit(elem);
	traverse_l(L, MyVisit);

	printf("��������\n");
	traverse_l(L, MyVisit);

	destroy_l(&L);

	return 0;
}
