/*1�� 1651574 ����� */
#include <iostream>
using namespace std;
int main()
{
	int x;
	while (true) {
		cout << "������x��ֵ(0-100)��";
		cin >> x;
		if(cin.fail()){
			cout << "��������!\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	cout << "x=" << x << endl;
	return 0;
}
