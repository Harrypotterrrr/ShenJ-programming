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

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

Status initial_l(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}

void ListInsert(LinkList *L, int n)
{
	LinkList p, tail = *L;
	p = (LinkList)malloc(sizeof(LNode));
	if (!p)
		exit(OVERFLOW);
	p->data = 1;
	(*L)->next = p;
	p->next = p;
	tail = p;

	for (int i = 2; i <= n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
}
 
int main()
{
	LinkList L = NULL;
	int i;
	int n, m, k;
	printf("n,m,k:\n");
	scanf("%d %d %d", &n, &m, &k);
	initial_l(&L);
	ListInsert(&L, n);

	LinkList p, q = L;
	for (int i = 0; i < k - 1; i++)
		q = q->next;
	p = q->next;
	q->next = p->next;
	printf("delete : %d\n", p->data);
	free(p);
	p = q;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			q = q->next;
			if (!q)
				q = L->next;
		}
		p = q->next;
		if (!p)
			p = L->next;
		q->next = p->next;
		printf("delete : %d\n", p->data);
		free(p);
		p = q;
	}
	free(L);
	L = NULL;

	return 0;
}
