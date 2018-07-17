/*1651574 1班 贾昊霖*/
#define CRE_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	void Hanoi(int, char, char, char);
	char start, end;
	int n;
	while (true) {
		cout << "请输入汉诺塔层数(1-16):\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n > 0 && n < 17)
			break;
	}
	cout << "请输入起始柱：" << endl;
	cin >> start;
	cout << "请输入目标柱：" << endl;
	while (cin >> end && (end == start || labs(end - start) == 32)) {
		cout << "目标柱(" << end << ")不能与起始柱(" << start << ")相同" << endl;
		cout << "请输入目标柱：" << endl;
	}
	if (start > 'C')
		start -= 32;
	if (end > 'C')
		end -= 32;
	cout << "移动步骤为：\n";
	Hanoi(n, start, end, char(3 * 'B' - start - end));
	return 0;
}
void Hanoi(int num, char from, char to, char by)
{
	static int sum = 1;
	if (num == 1) {
		cout <<setw(5)<<sum++<<": " << num << "# " << from << "-->" << to << endl;
		return;
	}
	Hanoi(num - 1, from, by, to);
	cout << setw(5) << sum++ << ": " << num<< "# " << from << "-->" << to << endl;
	Hanoi(num - 1, by, to, from);
}
