/*1651574 1�� �����*/
#define CRE_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int A[15] = { 0 }, B[15] = { 0 }, C[15] = { 0 };
int pa = 1, pb = 1, pc = 1;
void PrintPlates()
{
	cout << "A:";
	for (int i = 1; i <= 10;i++) {
		if (i < pa)
			cout << setw(2) << A[i];
		else
			cout << "  ";
	}
	cout << " B:";
	for (int i = 1; i <= 10;i++) {
		if (i < pb)
			cout << setw(2) << B[i];
		else
			cout << "  ";
	}
	cout << " C:";
	for (int i = 1; i <= 10;i++) {
		if (i < pc)
			cout << setw(2) << C[i];
		else
			cout << "  ";
	}
	putchar('\n');
}
void MovePlate(char from, char to)
{
	int tmp;
	switch (from) {
		case('A'):
			tmp = A[--pa];
			break;
		case('B'):
			tmp = B[--pb];
			break;
		default:
			tmp = C[--pc];
	}
	switch (to) {
		case('A'):
			A[pa++] = tmp;
			break;
		case('B'):
			B[pb++] = tmp;
			break;
		default:
			C[pc++] = tmp;
	}
}
void Hanoi(int num, char from, char to, char by)
{
	static int sum = 1;
	if (num == 1) {
		cout << "��" << setw(4) << sum++
			<< " ��( " << num << "): " << from << "-->" << to << " ";
		MovePlate(from, to);
		PrintPlates();
		return;
	}
	Hanoi(num - 1, from, by, to);
	cout << "��" << setw(4) << sum++
		<< " ��( " << num << "): " << from << "-->" << to << " ";
	MovePlate(from, to);
	PrintPlates();
	Hanoi(num - 1, by, to, from);
}

void InitPlates(int n, char start, char end)
{
	if (start == 'A') {
		for (int i = 1; i <= n; i++)
			A[i] = n - i + 1;
		pa = n + 1;
	}
	else if (start == 'B') {
		for (int i = 1; i <= n; i++)
			B[i] = n - i + 1;
		pb = n + 1;
	}
	else {
		for (int i = 1; i <= n; i++)
			C[i] = n - i + 1;
		pc = n + 1;
	}
	cout << "��ʼ:                ";
	PrintPlates();
}
int main()
{
	char start, end;
	int n;
	while (true) {
		cout << "�����뺺ŵ������(1-10):\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n > 0 && n <= 10)
			break;
	}
	cout << "��������ʼ��:" << endl;
	cin >> start;
	cout << "������Ŀ����:" << endl;
	while (cin >> end && (end == start || labs(end - start) == 32)) {
		cout << "Ŀ����(" << end << ")��������ʼ��(" << start << ")��ͬ" << endl;
		cout << "������Ŀ����:" << endl;
	}
	if (start > 'C')
		start -= 32;
	if (end > 'C')
		end -= 32;
	InitPlates(n, start, end);

	Hanoi(n, start, end, char(3 * 'B' - start - end));
	return 0;
}
