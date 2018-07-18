/*1651574 贾昊霖 1班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define Error 0

typedef int Status;
struct student
{
	int *no;
	char *name;
	int *score;
	struct student *next;
};
typedef struct student* Stulist;

Status input(FILE **fin)
{
	*fin = fopen("list.txt", "r");
	if (!(*fin)) {
		printf("打开文件失败\n");
		return Error;
	}
	return OK;
}

Status AppendList(Stulist* head, FILE *fin)
{
	int no;
	char name[12];
	*head = (Stulist)malloc(sizeof(struct student));

	(*head)->name = (char*)malloc(sizeof(char));
	(*head)->no = (int*)malloc(sizeof(int));
	(*head)->score = (int*)malloc(sizeof(int));
	if (!(*head)->score)
		return Error;
	struct student *q = *head;
	q->next = NULL;
	while (fscanf(fin,"%d", &no), no != 9999999) {
		Stulist p = (Stulist)malloc(sizeof(struct student));
		p->no = (int*)malloc(sizeof(int));
		if (!p->no)
			return Error;
		*(p->no) = no;
		fscanf(fin, "%s", name);
		p->name = (char*)malloc(strlen(name) + 1);
		if (!p->name)
			return Error;
		strcpy(p->name, name);
		p->score = (int*)malloc(sizeof(int));
		if (!p->score)
			return Error;
		fscanf(fin, "%d", p->score);
		p->next = NULL;

		q->next = p;
		q = q->next;
	}
	fclose(fin);
	return OK;
}

void PrintList(Stulist head)
{
	Stulist p = head->next;
	while (p != NULL) {
		printf("%d %s %d\n", *(p->no), p->name, *(p->score));
		p = p->next;
	}
}

void DeleteList(Stulist head)
{
	Stulist p, q;
	p = head;
	while (p != NULL) {
		q = p->next;
		free(p->name);
		free(p->no);
		free(p->score);
		free(p);
		p = q;
	}
}

int main()
{
	Stulist head = NULL;
	FILE *fin;
	if (!input(&fin))
		return Error;

	if (!AppendList(&head, fin))
		return Error;
	PrintList(head);
	DeleteList(head);

	return 0;
}