/* 1651574 ����� 1�� */
#include <iostream>
using namespace std;

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
	private:
		int year;
		int month;
		int day;
		/* ������������ݳ�Ա */
	public:
		/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
		Date();
		Date(int,int,int);
		void set(int, int = 1, int = 1);
		void get(int&, int&, int&);
		void show();
		Date(int);
		friend ostream& operator<<(ostream&, const Date&);
		friend istream& operator>>(istream&, Date&);

		operator int();
		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);
		
		friend Date operator+(Date&, int);
		friend Date operator-(Date&, int);
		friend Date operator+(int,Date &);
};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */

int month2day(int, int);
bool isLeap(int);
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */

const int M[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
