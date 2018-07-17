/*1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int f(int x, int y, int z);
	cin >> a >> b >> c;
	c = f(a, b, c);
	cout << c << endl;
	return 0;
}
int f(int x, int y, int z)
{
	int m;
	if (x < y) m = x;
	else m = y;
	if (z < m) m = z;
	return (m);
}
/*
	功能：
		求输入三个整数的最小值
	输出：
		六次运行均输出10
*/