//1651574 贾昊霖 1班
//卢依雯 石佳琛 秦政睿 毕晓栋

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//如果其他编译器需要头文件，允许增加

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define LOVERFLOW   -2

typedef int Status;

typedef int ElemType;	//可根据需要修改元素的类型

typedef struct LNode {
	ElemType      data;	//存放数据
	struct LNode *next;	//存放直接后继的指针
} LNode, *LinkList;

/* ---------------------
   此处允许增加其他函数
   --------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
int create_L(LinkList *L)
{
	//补齐函数实现
	int num;

	*L = (LinkList)malloc(sizeof(LNode));
	LinkList tail = (*L);
	if (!tail) {
		printf("内存已经耗尽!");
		exit(LOVERFLOW);
	}
	(*L)->next = NULL;
	while (scanf("%d", &num) && num != -1) {
		LinkList p = (*L)->next;

		p = (LinkList)malloc(sizeof(LNode));
		if (!p) {
			printf("内存已经耗尽!");
			exit(LOVERFLOW);
		}

		p->data = num;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int destroy_L(LinkList *L)
{
	//补齐函数实现
	LinkList tail = (*L)->next, p = *L;
	while (p) {
		tail = p->next;
		free(p);
		p = tail;
	}
	*L = NULL;
	return OK;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int output_L(LinkList L, const char *prompt)
{
	//补齐函数实现
	LinkList p = L->next;

	printf("%s", prompt);
	for (int i = 1; p; i++, p = p->next) {
		if (!(i % 10) && i)
			putchar('\n');
		printf("%d ", p->data);
	}
	return OK;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void xor_L(LinkList *La, LinkList *Lb)
{
	//补齐函数实现
	LinkList pa = *La, pb = (*Lb)->next;
	while (pa->next) {
		pb = *Lb;
		while (pb->next && pb->next->data != pa->next->data)
			pb = pb->next;
		if (!(pb->next)) {
			pa = pa->next;
			continue;
		}
		LinkList tmp = pa->next;
		pa->next = pa->next->next;
		free(tmp);
		tmp = pb->next;
		pb->next = pb->next->next;
		free(tmp);
	}
	pa->next = (*Lb)->next;
	free(*Lb);
	*Lb = NULL;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void usage(const char *procname)
{
	printf("Usage : %s 执行测试程序\n", procname);
	printf("        %s  -makedat filename 生成测试数据文件\n", procname);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int makedat(const char *filename)
{
	const int min_num = 500, range = 1000; //定义常量，方便修改
	const int num_of_add_enter = 20;

	FILE *fout;
	if ((fout = fopen(filename, "w")) == NULL) {
		printf("无法建立%s文件.\n", filename);
		return -1;
	}

	srand((unsigned int)time(0));
	int La_num = min_num + rand() % range;	// La表的数量：500~1499
	int Lb_num = min_num + rand() % range;	// La表的数量：500~1499
	int i;

	for (i = 1; i <= La_num; i++) {
		fprintf(fout, "%d ", rand() % (min_num + range));	//0-1500之间随机数，保证有重复
		if (i % num_of_add_enter == 0)	//每20个换一行
			fprintf(fout, "\n");
	}
	fprintf(fout, "-1\n");

	for (i = 1; i <= Lb_num; i++) {
		fprintf(fout, "%d ", rand() % (min_num + range));	//0-1500之间随机数，保证有重复
		if (i % num_of_add_enter == 0)	//每20个换一行
			fprintf(fout, "\n");
	}
	fprintf(fout, "-1\n");

	fclose(fout);

	printf("%s文件已建立\n", filename);

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char **argv)
{
	LinkList La, Lb;

	if (argc == 2 && (strcmp(argv[1], "/?") == 0 || strcmp(argv[1], "/h") == 0)) {
		usage(argv[0]);
		return -1;
	}
	else if (argc == 3 && strcmp(argv[1], "-makedat") == 0) {
		makedat(argv[2]);
		return 0;
	}
	else if (argc > 1) {
		usage(argv[0]);
		return -1; //其它所有带参数的情况都认为是错误
	}

	fprintf(stderr, "请输入若干正整数以建立链表La，-1结束\n");
	create_L(&La);

	fprintf(stderr, "请输入若干正整数以建立链表Lb，-1结束\n");
	create_L(&Lb);

	output_L(La, "La(before union):\n");
	printf("\n");

	output_L(Lb, "Lb(before union):\n");
	printf("\n");

	xor_L(&La, &Lb);

	output_L(La, "La(after merge):\n");
	printf("\n");

	destroy_L(&La);

	return 0;
}
