/*1651574 ��1 �����*/
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
����1��main������û�ж���c��add������û�ж���z
����2��c=add(a,b)���ٷֺţ�int add(int x,int y)���ֺ�
����3��û��a��b��ֵ
����4����main�������У��ڵ���add����֮ǰû������������int add(int x, int y)
*/