/*1�� 1651574 �����*/
#include <iostream>
using namespace std;
int main()
{
	int sum = 1, n;
	cout << "������ڼ���������Ϊ1\n";
	cin >> n;
	for (int i = 1; i < n; i++) {
		sum++;
		sum *= 2;
	}
	cout << "��1���������=" << sum << endl;
	return 0;
}
