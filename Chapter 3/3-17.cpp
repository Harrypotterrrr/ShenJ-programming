/*1�� 1651574 �����*/
#include <iostream>
using namespace std;
int main()
{
	cout << "��������������a,n��" << endl;
	int a, n, temp = 0, sum = 0;
	cin >> a >> n;
	for (int i = 1; i <= n; i++) {
		temp *= 10;
		temp += a;
		sum += temp;
	}
	cout << "S=" << sum << endl;
	return 0;
}
