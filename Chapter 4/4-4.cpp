/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Factorial(int);
	int sum = 0, a, b, c;
	cout << "���������ְɸ�:\n";
	cin >> a >> b >> c;
	sum += Factorial(a) + Factorial(b) + Factorial(c);
	cout << "���ǣ�" << sum << endl;
}
int Factorial(int x)
{
	int ans = 1;
	for (int i = 1; i <= x; i++)
		ans *= i;
	return ans;
}