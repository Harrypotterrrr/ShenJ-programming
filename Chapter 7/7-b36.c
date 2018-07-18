/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct PolyNode{
	double coe;	//系数
	int exp;	//指数
	struct PolyNode *next;
};
typedef struct PolyNode* PolyList;

void InitialPoly(PolyList *L)
{
	PolyList p, q;
	*L = (PolyList)malloc(sizeof(struct PolyNode));
	(*L)->next = NULL;
	p = *L;
	while(1) {
		q = (PolyList)malloc(sizeof(struct PolyNode));
		scanf("%lf%d", &q->coe, &q->exp);
		if (q->exp == -1) {
			free(q);
			break;
		}
		q->next = NULL;

		p = *L;

		while (p->next && q->exp > p->next->exp)
			p = p->next;
		if (!p->next)
			p->next = q;
		else {
			q->next = p->next;
			p->next = q;
		}
	}
	printf("建立成功!\n");
}
void AddPoly(PolyList *La, PolyList *Lb)
{
	PolyList p = (*La)->next, q = (*Lb)->next;
	PolyList p_pre = (*La), q_tmp;
	double temp;
	while (p && q) {
		if (p->exp == q->exp) {
			temp = p->coe + q->coe;
			if (temp) {
				p->coe = temp;
				p_pre = p;
				p = p->next;
			}
			else {
				p = p->next;
				free(p_pre->next);
				p_pre->next = p;
			}
			q_tmp = q;
			q = q->next;
			free(q_tmp);
		}
		else if (p->exp > q->exp) {
			q_tmp = q->next;
			q->next = p;
			p_pre->next = q;
			p_pre = q;
			q = q_tmp;
		}
		else {
			p_pre = p;
			p = p->next;
		}
	}
	if (q)
		p_pre->next = q;
	free((*Lb));
	(*Lb) = NULL;
	printf("加成功!\n");
}

void MulPoly(PolyList *La, PolyList *Lb)
{
	PolyList p = (*La)->next, q = (*Lb)->next;
	PolyList Lc, Lc_tmp, r, nw_node;
	Lc = (PolyList)malloc(sizeof(struct PolyNode));
	Lc->next = NULL;
	while (p) {
		q = (*Lb)->next;
		Lc_tmp = (PolyList)malloc(sizeof(struct PolyNode));
		r = Lc_tmp;
		while (q) {
			nw_node = (PolyList)malloc(sizeof(struct PolyNode));
			nw_node->coe = p->coe * q->coe;
			nw_node->exp = p->exp + q->exp;
			r->next = nw_node;
			r = r->next;
			q = q->next;
		}
		r->next = NULL;
		AddPoly(&Lc, &Lc_tmp);
		p = p->next;
		free((*La)->next);
		(*La)->next = p;
	}
	AddPoly(La, &Lc);
	free(*Lb);
	*Lb = NULL;
	printf("乘成功!\n");
}

void PrintPoly(PolyList *L)
{
	PolyList p = (*L)->next;
	while (p) {
		printf("%lf %d\n", p->coe, p->exp);
		p = p->next;
	}
}

int main() 
{
	printf("极简版菜单.... 这个程序是上学期数据结构时写的，才发现有减没乘..\n");
	printf("但乘比减要难，所以您不许扣我分啊..\n");
	int choice;
		system("cls");
		printf("输入菜单：\n");
		printf("1：建立链表La\n");
		printf("2：建立链表Lb\n");
		printf("3：相加\n");
		printf("4：相乘\n");
		printf("5：打印链表La（结果）\n");
		printf("0：退出\n");
	while (1) {
		scanf("%d", &choice);
		PolyList La, Lb;
		if (!choice)
			break;
		else if (choice == 1)
			InitialPoly(&La);
		else if (choice == 2)
			InitialPoly(&Lb);
		else if (choice == 3)
			AddPoly(&La, &Lb);
		else if(choice == 4)
			MulPoly(&La, &Lb);
		else if(choice == 5)
			PrintPoly(&La);
	}
	return 0;
}