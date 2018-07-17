/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	int Zeller(int, int, int);
	bool judge(int, int, int);
	void PrintAns(int);

	int year, month, day, week;
	bool flag;

	while (true) {
		cout << "请输入年份(1900-2100)、月、日：\n";
		cin >> year >> month >> day;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (judge(year, month, day))
			break;
	}

	week = Zeller(year, month, day) % 7;
	cout << "星期";
	PrintAns(week);
	return 0;
}
void PrintAns(int week)
{
	switch (week) {
		case(0):
			cout << "日\n";
			break;
		case(1):
			cout << "一\n";
			break;
		case(2):
			cout << "二\n";
			break;
		case(3):
			cout << "三\n";
			break;
		case(4):
			cout << "四\n";
			break;
		case(5):
			cout << "五\n";
			break;
		default:
			cout << "六\n";
	}
}
bool judge(int year, int month, int day)
{
	bool leap = (!(year % 4) && (year % 100) || !(year % 400));
	bool flag = true;
	if (year < 2000 || year > 2030) {
		cout << "年份不正确，请重新输入\n";
		//printf("年份不正确，请重新输入\n");
		flag = false;
	}
	else if (month < 1 || month > 12) {
		cout << "月份不正确，请重新输入\n";
		//printf("月份不正确，请重新输入\n");
		flag = false;
	}
	else {
		if (day < 0)
			flag = false;
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31)
				flag = false;
		}
		else if (month == 2) {
			if (day > 28 + leap)
				flag = false;
		}
		else
			if (day > 30)
				flag = false;
		if (!flag) {
			cout << "日不正确，请重新输入\n";
			//printf("日不正确，请重新输入\n");
		}

	}
	return flag ? true : false;
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

