/* 1651574 贾昊霖 1班*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

int main()
{
	int sum = 0;
	Date date;
	cout << "输入一个日期（yyyy mm dd）" << endl;
	cin >> date.year >> date.month >> date.day;
	bool isLeap = (!(date.year % 4) && (date.year % 100) || !(date.year % 400));
	int month[] = { 0, 31, 28 + isLeap,31,30,31,30,31,31,30,31,30,31 };
	if (date.month < 1 || date.month > 12) {
		cout << "输入错误-月份不正确\n";
		return 0;
	}
	if (date.day > month[date.month]) {
		cout << "输入错误-日与月的关系非法\n";
		return 0;
	}
	else {
		for (int i = 1; i < date.month; i++)
			sum += month[i];
		sum += date.day;
		cout << date.year << "-" << date.month << "-" << date.day << "是" << date.year << "年的第" << sum << "天" << endl;

	}

	return 0;
}
