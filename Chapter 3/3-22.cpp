/*1班 1651574 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	int sum = 1, n;
	cout << "请输入第几天桃子数为1\n";
	cin >> n;
	for (int i = 1; i < n; i++) {
		sum++;
		sum *= 2;
	}
	cout << "第1天的桃子数=" << sum << endl;
	return 0;
}
