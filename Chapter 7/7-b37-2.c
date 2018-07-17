/*1651574 º÷Íª¡ÿ 1∞‡*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0


typedef int Status;

typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, *DuLinkList;

Status initial_l(DuLinkList *L)
{
	*L = (DuLNode *)malloc(sizeof(DuLNode));
	if (*L == NULL)
		exit(OVERFLOW);
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return OK;
}

void ListInsert_DuL(DuLinkList *L, int n)
{
	DuLinkList p ,tail = *L;
	p = (DuLinkList)malloc(sizeof(DuLNode));
	if (!p)
		exit(OVERFLOW);
	p->data = 1;
	(*L)->next = p;
	p->next = p;
	p->prior = p;
	tail = p;

	for (int i = 2; i <= n; i++) {
		p = (DuLinkList)malloc(sizeof(DuLNode));
		p->data = i;
		p->next = (*L)->next;
		p->prior = tail;
		(*L)->next->prior = p;
		tail->next = p;
		tail = p;
	}
}
void ListDelete_Dul(DuLinkList *L, DuLinkList p)
{
	if (p == (*L)->next)
		(*L)->next = p->prior;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	p = NULL;
}
int main()
{
	DuLinkList L = NULL;
	int i;
	int n, m, k;
	printf("n,m,k:\n");
	scanf("%d %d %d", &n, &m, &k);
	initial_l(&L);
	ListInsert_DuL(&L, n);
	
	DuLinkList p = L->next, q;
	for (int i = 0; i < k - 1; i++)
		p = p->next;
	printf("delete : %d\n", p->data);
	q = p->prior;
	ListDelete_Dul(&L, p);
	p = q;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++)
			p = p->next;
		printf("delete : %d\n", p->data);
		q = p->prior;
		ListDelete_Dul(&L, p);
		p = q;
	}
	free(L);
	L = NULL;

	return 0;
}
