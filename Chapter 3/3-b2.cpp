/*1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;

int main()
{

	int a, a0, a1, a2, a3, a4;
	cout << "输入一个不大于30000的正整数：" << endl;
	cin >> a;
	a0 = a % 10;
	a1 = (a / 10) % 10;
	a2 = (a / 100) % 10;
	a3 = (a / 1000) % 10;
	a4 = (a / 10000) % 10;
	cout <<"万位：" << a4 << endl
		<< "千位：" << a3 << endl
		<< "百位：" << a2 << endl
		<< "十位：" << a1 << endl
		<< "个位：" << a0 << endl;
	return 0;
}