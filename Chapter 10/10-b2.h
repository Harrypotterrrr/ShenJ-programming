/* 1651574 贾昊霖 1班 */
#include <iostream>
using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
	private:
		int year;
		int month;
		int day;
		/* 不允许添加数据成员 */
	public:
		/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
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

/* 如果有其它全局函数需要声明，写于此处 */

int month2day(int, int);
bool isLeap(int);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */

const int M[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
