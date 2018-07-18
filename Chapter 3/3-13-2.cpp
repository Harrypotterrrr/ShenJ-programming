/*1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入当月利润i(默认利润大于0)：\n";
	int i, ans, temp;
	cin >> i;
	temp = (i - 1) / 100000;
	switch (temp)
	{
		case 0:
			ans = int(i*0.1);
			break;
		case 1:
			ans = int(10000 + (i - 100000)*0.075);
			break;
		case 2:
		case 3:
			ans = int(17500 + (i - 200000)*0.05);
			break;
		case 4:
		case 5:
			ans = int(22500 + (i - 400000)*0.03);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			ans = int(25500 + (i - 600000)*0.015);
			break;
		default:
			ans = int(27000 + (i - 1000000)*0.01);
			break;
	}
	cout << "发奖金:\n"<< ans<< endl;
	return 0;
}
