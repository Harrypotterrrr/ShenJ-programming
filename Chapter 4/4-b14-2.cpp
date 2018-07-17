/*1651574 1�� �����*/
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
		cout << "�����뺺ŵ������(1-16):\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n > 0 && n < 17)
			break;
	}
	cout << "��������ʼ����" << endl;
	cin >> start;
	cout << "������Ŀ������" << endl;
	while (cin >> end && (end == start || labs(end - start) == 32)) {
		cout << "Ŀ����(" << end << ")��������ʼ��(" << start << ")��ͬ" << endl;
		cout << "������Ŀ������" << endl;
	}
	if (start > 'C')
		start -= 32;
	if (end > 'C')
		end -= 32;
	cout << "�ƶ�����Ϊ��\n";
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
