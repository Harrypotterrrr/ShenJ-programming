/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	while(true){
	int is_power(int, int);
	int num, base;
	while (true) {
		cout << "请输入整数num及基数base：\n";
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

	cout << "十进制整数" << num;
	if(!is_power(num,base))
		cout<<"不";
	cout << "是" << base << "的幂\n";
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
