/*1班 1651574 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int year, month, week, day;
	int leap;
	while (1) {
		printf("请输入年份(2000 - 2030)和月份(1 - 12) :");
		scanf("%d%d", &year, &month);
		if (year < 2000 || year>2030) {
			printf("年输入有误\n");
			continue;
		}
		if (month >= 1 && month <= 12)
			break;
		else
			printf("月输入有误\n");
	}
	leap = ((year % 4) && !(year % 100) || (year % 400));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		day = 31;
	else if (month != 2)
		day = 30;
	else
		day = 28 + leap;
	printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) :\n", year, month);
	scanf("%d", &week);
	while (week < 0 || week > 6) {
		printf("星期输入有误\n");
		scanf("%d", &week);
	}
	printf("%d年%d月的月历为：\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
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
