/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double a, b, c, delta, pre, rear;
	cout << "请输入一元二次方程的三个系数a,b,c:\n";
	cin >> a >> b >> c;
	if (!a) {
		cout << "不是一元二次方程\n";
		return 0;
	}
	delta = b * b - 4 * a * c;
	pre = -b / (2 * a);
	if (delta < 0) {
		rear = sqrt(-delta) / (2 * a);
		cout<< "有两个虚根：\n"
			<<"x1="<< pre << "+" << rear << "i\n"
			<<"x2="<< pre << "-" << rear << "i\n";
	}
	else{
		rear = sqrt(delta) / (2 * a);
		if (!delta)
			cout << "有两个相等实根:\nx1=x2=" << pre + rear << endl;
		else 
			cout<< "有两个不等实根：\n"
				<<"x1="<< pre +rear << "\n"
				<<"x2="<< pre -rear << "\n";
	}
	return 0;
}
