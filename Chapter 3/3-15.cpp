/*1�� 1651574 �����*/
#include <iostream>
using namespace std;
int main()
{
	cout << "��������������m,n��" << endl;
	int m, n, ans;
	cin >> m >> n;
	int Min = m >= n ? n : m;
	for (int i = Min; i >= 1; i--)
		if (!(m%i) && !(n%i)) {
			ans = i;
			break;
		}
	cout << "���Լ����" << ans << endl;
	cout << "��С��������" << m * n / ans << endl;
	return 0;
}
