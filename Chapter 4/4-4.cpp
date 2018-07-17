/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Factorial(int);
	int sum = 0, a, b, c;
	cout << "来三个数字吧哥:\n";
	cin >> a >> b >> c;
	sum += Factorial(a) + Factorial(b) + Factorial(c);
	cout << "答案是：" << sum << endl;
}
int Factorial(int x)
{
	int ans = 1;
	for (int i = 1; i <= x; i++)
		ans *= i;
	return ans;
}