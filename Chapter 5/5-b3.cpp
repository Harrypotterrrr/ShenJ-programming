/*1651574 1�� �����*/
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
		cout << "��ֱ������ꡢ�¡��յ�ֵ:\n";
		cin >> year >> month >> day;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (year < 2000 || year > 2030) {
			cout << "�������-��ݲ���ȷ\n";
			continue;
		}
		if (month > 12 || month < 1) {
			cout << "�������-�·ݲ���ȷ\n";
			continue;
		}
		bool leap = Judge_Year(year), flag;
		if(month == 2)
			flag = (day <= M[month] + leap);
		else
			flag = (day <= M[month]);
		if (!flag) {
			cout << "�������-�����µĹ�ϵ�Ƿ�\n";
			continue;
		}
		break;
	}
	sum = Calc(year, month, day);
	/*              output             */
	cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << sum << "��\n";
	return 0;
}
