/* 1651574 ����� 1��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct Date
{
	int year;
	int month;
	int day;
};

int days(struct Date* date)
{
	int isLeap = (!(date->year % 4) && (date->year % 100) || !(date->year % 400));
	int month[] = { 0, 31, 28 + isLeap,31,30,31,30,31,31,30,31,30,31 };

	if (date->day > month[date->month - 1])
		return 0;

	int sum = 0;
	for (int i = 1; i < date->month; i++)
		sum += month[i];
	sum += date->day;
	return sum;
}

int main()
{
	struct Date date;
	printf("����һ�����ڣ�yyyy mm dd��\n");
	scanf("%d%d%d", &date.year, &date.month, &date.day);

	int sum;
	if (date.month < 1 || date.month > 12) {
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}
	sum = days(&date);
	if (!sum)
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
	else
		printf("%d-%d-%d��%d��ĵ�%d��\n", date.year, date.month, date.day, date.year, sum);
	return 0;
}



