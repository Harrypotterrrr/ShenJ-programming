/*1班 1651574 贾昊霖 */
#include <iostream>
using namespace std;
int main()
{
	int x;
	while (true) {
		cout << "请输入x的值(0-100)：";
		cin >> x;
		if(cin.fail()){
			cout << "输入有误!\n";
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
