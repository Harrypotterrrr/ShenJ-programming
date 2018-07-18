/* 1651574 1班 贾昊霖 */
#include <iostream>
using namespace std;

const int M[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
	public:
		int calc_days();     //计算是当年的第几天
		/* 下面可以补充其它需要的类成员函数的定义，数量不限 */
		Days(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d) {};
};

/* 此处给出类成员函数的体外实现 */

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

/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
		}

	return 0;
}
