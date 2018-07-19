/*1651574 计1 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	int add(int x, int y);
	int a, b, c;
	cin >> a >> b;
	c = add(a, b);
	cout << "a+b=" << c << endl;
	return 0;
}
int add(int x, int y)
{
	int z;
	z = x + y;
	return (z);
}
/*
错误1：main函数里没有定义c，add函数里没有定义z
错误2：c=add(a,b)后少分号，int add(int x,int y)后多分号
错误3：没给a和b赋值
错误4：在main函数体中，在调用add函数之前没有声明函数：int add(int x, int y)
*/