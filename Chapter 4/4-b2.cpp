/*1651574 1�� �����*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	bool Judge(int, int);
	void PrintCalendar(int, int);
	void PrintAns(int);
	int year, month;

	while (true) {
		cout << "��������(1900-2100)���£�\n";
		cin >> year >> month;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (Judge(year, month))
			break;
	}

	PrintCalendar(year, month);
	return 0;
}
bool Judge(int year, int month)
{
	bool flag = true;
	if (year < 2000 || year > 2030) {
		cout << "��ݲ���ȷ������������\n";
		//printf("��ݲ���ȷ������������\n");
		flag = false;
	}
	else if (month < 1 || month > 12) {
		cout << "�·ݲ���ȷ������������\n";
		//printf("�·ݲ���ȷ������������\n");
		flag = false;
	}
	return flag ? true : false;
}
int Zeller(int year, int month, int day)
{
	int century, week;
	year %= 100;
	century = year / 100;
	if (month < 3)
		month += 12;
	week = year + year / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10 + day - 1;
	return week % 7;
}
int CalculateDay(int year, int month)
{
	bool leap;
	int day;
	leap = (!(year % 4) && !(year % 100) || (year % 400));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		day = 31;
	else if (month != 2)
		day = 30;
	else
		day = 28 + leap;
	return day;
}
void PrintCalendar(int year, int month)
{
	int week, day;
	bool leap;

	week = Zeller(year, month, 1);
	day = CalculateDay(year, month);

	cout << year << "��" << month << "�µ�����Ϊ��\n";
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������\n";
	int chg = 0;
	for (int i = 0; i < week; i++, chg++) {
		if (!i)
			cout << setw(6) << " ";
		else
			cout << setw(8) << " ";
	}
	for (int i = 1; i <= day; i++, chg++, chg %= 7) {
		if (!chg && i != 1)
			putchar('\n');
		if (!chg)
			cout << setw(4) << i << "  ";
		else
			cout << setw(6) << i << "  ";
	}
	putchar('\n');
}
