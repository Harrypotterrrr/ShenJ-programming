/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	while(true){
	int is_power(int, int);
	int num, base;
	while (true) {
		cout << "����������num������base��\n";
		cin >> num >>base;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			//cin.ignore(cin.rdbuf()->in_avail(), '\n');
			continue;
		}
		if (num > 0 && base >= 2)
			break;
	}

	cout << "ʮ��������" << num;
	if(!is_power(num,base))
		cout<<"��";
	cout << "��" << base << "����\n";
	}
	return 0;
}
int is_power(int num, int base)
{
	if (num == 1)
		return 1;
	if (num % base)
		return 0;
	return is_power(num / base, base);
}
