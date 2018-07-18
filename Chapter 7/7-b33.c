//1651574 ����� 1��
//¬���� ʯ��� ����� ������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//���������������Ҫͷ�ļ�����������

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define LOVERFLOW   -2

typedef int Status;

typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

typedef struct LNode {
	ElemType      data;	//�������
	struct LNode *next;	//���ֱ�Ӻ�̵�ָ��
} LNode, *LinkList;

/* ---------------------
   �˴�����������������
   --------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
int create_L(LinkList *L)
{
	//���뺯��ʵ��
	int num;

	*L = (LinkList)malloc(sizeof(LNode));
	LinkList tail = (*L);
	if (!tail) {
		printf("�ڴ��Ѿ��ľ�!");
		exit(LOVERFLOW);
	}
	(*L)->next = NULL;
	while (scanf("%d", &num) && num != -1) {
		LinkList p = (*L)->next;

		p = (LinkList)malloc(sizeof(LNode));
		if (!p) {
			printf("�ڴ��Ѿ��ľ�!");
			exit(LOVERFLOW);
		}

		p->data = num;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int destroy_L(LinkList *L)
{
	//���뺯��ʵ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int output_L(LinkList L, const char *prompt)
{
	//���뺯��ʵ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void xor_L(LinkList *La, LinkList *Lb)
{
	//���뺯��ʵ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void usage(const char *procname)
{
	printf("Usage : %s ִ�в��Գ���\n", procname);
	printf("        %s  -makedat filename ���ɲ��������ļ�\n", procname);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int makedat(const char *filename)
{
	const int min_num = 500, range = 1000; //���峣���������޸�
	const int num_of_add_enter = 20;

	FILE *fout;
	if ((fout = fopen(filename, "w")) == NULL) {
		printf("�޷�����%s�ļ�.\n", filename);
		return -1;
	}

	srand((unsigned int)time(0));
	int La_num = min_num + rand() % range;	// La���������500~1499
	int Lb_num = min_num + rand() % range;	// La���������500~1499
	int i;

	for (i = 1; i <= La_num; i++) {
		fprintf(fout, "%d ", rand() % (min_num + range));	//0-1500֮�����������֤���ظ�
		if (i % num_of_add_enter == 0)	//ÿ20����һ��
			fprintf(fout, "\n");
	}
	fprintf(fout, "-1\n");

	for (i = 1; i <= Lb_num; i++) {
		fprintf(fout, "%d ", rand() % (min_num + range));	//0-1500֮�����������֤���ظ�
		if (i % num_of_add_enter == 0)	//ÿ20����һ��
			fprintf(fout, "\n");
	}
	fprintf(fout, "-1\n");

	fclose(fout);

	printf("%s�ļ��ѽ���\n", filename);

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
		return -1; //�������д��������������Ϊ�Ǵ���
	}

	fprintf(stderr, "�����������������Խ�������La��-1����\n");
	create_L(&La);

	fprintf(stderr, "�����������������Խ�������Lb��-1����\n");
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
