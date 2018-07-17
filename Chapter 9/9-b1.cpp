/* 1651574 1�� ����� */
#include <iostream>
using namespace std;

const int M[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
	public:
		int calc_days();     //�����ǵ���ĵڼ���
		/* ������Բ���������Ҫ�����Ա�����Ķ��壬�������� */
		Days(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d) {};
};

/* �˴��������Ա����������ʵ�� */

int Days::is_leap_year()
{
	return !(year % 4) && (year % 100) || !(year % 400);
}

int Days::calc_days()
{
	if (day > M[month])
		return -1;
	int sum = 0, isLeap = is_leap_year();
	for (int i = 1; i < month; i++) 
		sum += M[i] + (i == 2 && isLeap);
	sum += day;
	return sum;
}

/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
		}

	return 0;
}
