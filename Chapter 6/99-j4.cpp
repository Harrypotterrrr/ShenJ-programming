/* 1651574 º÷Íª¡ÿ 1∞‡ */
#include<iostream>
using namespace std;

template<int N>
void test( int(&array)[N])
{
	cout << sizeof(array) << endl;
}
int main()
{
	int t1[10], t2[20];
	test(t1);
	test(t2);
	return 0;
}