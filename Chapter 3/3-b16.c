/*1�� 1651574 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int year, month, week, day;
	int leap;
	while (1) {
		printf("���������(2000 - 2030)���·�(1 - 12) :");
		scanf("%d%d", &year, &month);
		if (year < 2000 || year>2030) {
			printf("����������\n");
			continue;
		}
		if (month >= 1 && month <= 12)
			break;
		else
			printf("����������\n");
	}
	leap = ((year % 4) && !(year % 100) || (year % 400));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		day = 31;
	else if (month != 2)
		day = 30;
	else
		day = 28 + leap;
	printf("������%d��%d��1�յ�����(0-6��ʾ������-������) :\n", year, month);
	scanf("%d", &week);
	while (week < 0 || week > 6) {
		printf("������������\n");
		scanf("%d", &week);
	}
	printf("%d��%d�µ�����Ϊ��\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	week = week % 7;
	int chg = 0;
	int i;
	for (i = 0; i < week; i++, chg++) {
		if (!i)
			printf("      ");
		else
			printf("        ");
	}
	for (int i = 1; i <= day; i++, chg++, chg %= 7) {
		if (!chg && i != 1)
			putchar('\n');
		if (!chg)
			printf("%4d  ", i);
		else
			printf("%6d  ", i);
	}
	putchar('\n');
	return 0;
}
