/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-8
const int M[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
using namespace std;
int Calc(int year, int month, int day)
{
	int sum = 0;
	for (int i = 1; i < month; i++)
		sum += M[i];
	sum += day;
	return sum;
}
bool Judge_Year(int year)
{
	return (!(year % 4) && (year % 100) || !(year % 400));
}
int main()
{
	int year, month, day, sum;
	/*              input             */
	while (true) {
		cout << "请分别输入年、月、日的值:\n";
		cin >> year >> month >> day;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (year < 2000 || year > 2030) {
			cout << "输入错误-年份不正确\n";
			continue;
		}
		if (month > 12 || month < 1) {
			cout << "输入错误-月份不正确\n";
			continue;
		}
		bool leap = Judge_Year(year), flag;
		if(month == 2)
			flag = (day <= M[month] + leap);
		else
			flag = (day <= M[month]);
		if (!flag) {
			cout << "输入错误-日与月的关系非法\n";
			continue;
		}
		break;
	}
	sum = Calc(year, month, day);
	/*              output             */
	cout << year << "-" << month << "-" << day << "是" << year << "年的第" << sum << "天\n";
	return 0;
}
