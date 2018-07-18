/*1651574 1班 贾昊霖*/
#include <iostream>
//#include <Windows.h>
#include <iomanip>
#include <cmath>
#define eps 1e-8
const char space1[] = "            ";
const char space2[] = "     ";
const char space3[] = "    ";
using namespace std;
int Zeller(int year, int month, int day)
{
	int century, week;
	year %= 100;
	century = year / 100;
	if (month < 3) {
		month += 12;
		year --;
	}
	week = year + year / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10 + day - 1;
	return week % 7;
}
void PrintCalendar(int M[], int year, int month)
{
	for (int i = 0; i < 3;i++) {
		cout << space1;
		cout << month + i << "月";
		cout << space1 << space2;
	}
	putchar('\n');
	for (int i = 1; i <= 3; i++) {
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		cout << space2;
	}
	putchar('\n');
	int day[3] = { 1,1,1 }, num;
	cout << setiosflags(ios::left);
	/*				Initial				*/
	for (int i = 0; i < 3; i++) {
		int space = Zeller(year, month + i, 1);
		num = 0;					//ATTENTION!
		for (int j = 1; j <= space; j++) {
			cout << setw(4) << " ";
			num++;
		}
		while ((num % 7) || !num) {
			cout << setw(4) << day[i]++;
			num++;
		}
		cout << space3;
	}
	putchar('\n');
	/*				Left				*/
	while (true) {
		for (int i = 0; i < 3; i++) {
			num = 0;			//ATTENTION!
			while ((num % 7) || !num) {
				if (day[i] <= M[month + i])
					cout << setw(4) << day[i]++;
				else
					cout << setw(4) << " ";
				num++;
			}
			cout << space3;
		}
		putchar('\n');
		if (day[0] == M[month]+1 && day[1] == M[month + 1]+1 \
			&& day[2] == M[month + 2]+1)
			break;
		//Sleep(100);
	}
}
void AddLeapYear(int M[],int year)
{
	bool leap = (!(year % 4) && (year % 100) || !(year % 400));
	M[2] += leap;
}
int main()
{
	int M[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year;
	system("mode con cols=100 lines=40");
	while (true) {
		cout << "请输入年份(1900-2100)：";
		cin >> year;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (year <= 2100 && year >= 1900)
			break;
	}
	AddLeapYear(M, year);
	cout << year << "年的日历：\n\n";

	for (int i = 1; i <= 4; i++) {
		PrintCalendar(M, year, i * 3 - 2);
		putchar('\n');
	}
	putchar('\n');
	return 0;
}
