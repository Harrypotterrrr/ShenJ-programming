/* 1651574 贾昊霖 1班*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<math.h>
#define N 10

struct Student
{
	int no;
	char name[9];
	float score[3];
	float var;
};

void input(struct Student st[N])
{
	int i, j;
	for (i = 0; i < N; i++) {
		printf("请输入第%2d个学生的信息：", i + 1);
		scanf("%d%s", &st[i].no, st[i].name);
		for (j = 0; j < 3; j++)
			scanf("%f", &st[i].score[j]);
	}
}

void output_var(struct Student st[N])
{
	int i;
	printf("10个同学的平均成绩依次为：\n");
	printf("序号 学号     姓名     三门课成绩     平均成绩\n");
	printf("=============================================\n");
	for (i = 0; i < N; i++)
		printf("%-4d %-8d %-8s %-4g %-4g %-4g %-4.2f\n", i + 1, st[i].no, st[i].name, st[i].score[0], st[i].score[1], st[i].score[2], st[i].var);
}

float cal(struct Student st[N])
{
	float max = 0, temp;
	for (int i = 0; i < N; i++){
		temp = 0;
		for (int j = 0; j < 3; j++)
			temp += st[i].score[j];
		st[i].var = temp / 3;
		if (st[i].var > max)
			max = st[i].var;
	}
	return max;
}

void output_max(struct Student st[N], float max)
{
	printf("最高分学生为：\n");
	printf("10个同学的平均成绩依次为：\n");
	printf("序号 学号     姓名     三门课成绩     平均成绩\n");
	printf("=============================================\n");

	int i;
	for (i = 0; i < N; i++)
		if (fabs(st[i].var - max) < 10e-4)
			printf("%-4d %-8d %-8s %-4g %-4g %-4g %-4.2f\n", i + 1, st[i].no, st[i].name, st[i].score[0], st[i].score[1], st[i].score[2], st[i].var);
}

int main()
{
	struct Student st[N];
	float max;

	input(st);
	max = cal(st);

	output_var(st);
	output_max(st, max);

	return 0;
}
