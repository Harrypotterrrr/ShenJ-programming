/*1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入当月利润i：\n";
	int i, ans;
	cin >> i;
	if (i <= 100000)
		ans = int(i*0.1);
	else if (i <= 200000)
		ans = int(10000 + (i - 100000)*0.075);
	else if (i <= 400000)
		ans = int(10000 + 7500 + (i - 200000)*0.05);
	else if (i <= 600000)
		ans = int(10000 + 7500 + 5000 + (i - 400000)*0.03);
	else if (i <= 1000000)
		ans = int(10000 + 7500 + 5000 + 3000 + (i - 600000)*0.015);
	else
		ans = int(10000 + 7500 + 5000 + 3000 + 1500 + (i - 1000000)*0.01);
	cout << "发奖金:\n"<<ans<< endl;
	return 0;
}
