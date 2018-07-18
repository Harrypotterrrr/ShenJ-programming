/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define eps 1e-8
int main()
{
	int Zeller(int, int, int);
	int judge(int, int, int);
	void PrintAns(int);

	int year, month, day, week;
	int flag;

	while (1) {
		printf("请输入年份(1900-2100)、月、日：\n");
		if (!scanf("%d", &year) || !scanf("%d", &month) || !scanf("%d", &day)) {
			rewind(stdin);		//指针指回文件开始
			//fflush(stdin);	//清空缓冲区
			continue;
		}
		if (judge(year, month, day))
			break;
	}

	week = Zeller(year, month, day) % 7;
	int n = printf("星期");
	//printf("%d", n);
	fflush(stdout);
	PrintAns(week);
	return 0;


}
void PrintAns(int week)
{
	switch (week) {
		case(0):
			printf("日");
			break;
		case(1):
			printf("一");
			break;
		case(2):
			printf("二");
			break;
		case(3):
			printf("三");
			break;
		case(4):
			printf("四");
			break;
		case(5):
			printf("五");
			break;
		default:
			printf("六");
	}
}
int judge(int year, int month, int day)
{
	int leap = (!(year % 4) && (year % 100) || !(year % 400));
	int flag = 1;
	if (year < 2000 || year > 2030) {
		printf("年份不正确，请重新输入\n");
		flag = 0;
	}
	else if (month < 1 || month > 12) {
		printf("月份不正确，请重新输入\n");
		flag = 0;
	}
	else {
		if (day < 0)
			flag = 0;
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31)
				flag = 0;
		}
		else if (month == 2) {
			if (day > 28 + leap)
				flag = 0;
		}
		else
			if (day > 30)
				flag = 0;
		if (!flag) {
			printf("日不正确，请重新输入\n");
		}

	}
	return flag ? 1 : 0;
}
int Zeller(int year, int month, int day)
{
	int c, week;
	year %= 100;
	c = year / 100;
	if (month < 3)
		month += 12;
	week = year + year / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1;
	return week;
}

