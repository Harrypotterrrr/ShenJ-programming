/*1651574 1�� �����*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d,temp;
	cout << "�����ĸ�����ͬ����:\n";
	cin >> a >> b >> c >> d;
	//ð������
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
	cout<<"��С����������Ϊ:\n";
	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	return 0;
}
