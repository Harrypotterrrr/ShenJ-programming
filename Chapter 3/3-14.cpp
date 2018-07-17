/*1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d,temp;
	cout << "输入四个不相同的数:\n";
	cin >> a >> b >> c >> d;
	//冒泡排序
	if(a>b)
	{
		temp = b;
		b =a;
		a=temp;
	}
	if(b>c)
	{
		temp = b;
		b=c;
		c=temp;
	}
	if(c>d)
	{
		temp =d;
		d=c;
		c=temp;
	}
	if(a>b){
		temp = b;
		b =a;
		a=temp;
	}
	if(b>c)
	{
		temp =b;
		b=c;
		c=temp;
	}
	if(a>b)
	{
		temp = b;
		b =a;
		a=temp;
	}
	cout<<"从小到大排序结果为:\n";
	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	return 0;
}
