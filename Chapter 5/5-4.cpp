/* 1�� ����� 1651574 */
#include <iostream>
using namespace std;

int main()
{
	int num, arr[25] = { 0 }, i, ins;
	cout << "��������������������������20��������-1����\n";
	for (i = 0 ; ; i++) {
		cin >> arr[i];
		if (arr[i] == -1)
			break;
	}
	cout << "ԭ����Ϊ��\n";
	for (int j = 0 ; j < i ; j++) {
		if (!j)
			cout << arr[j];
		else
			cout << " " << arr[j];
	}
	cout << "\n������Ҫ�����������\n";
	cin >> ins;
	for (int j = 0 ; j < i ; j++) {
		if (arr[j] > ins) {
			for (int k = i; k >= j;k--)
				arr[k] = arr[k - 1];
			arr[j] = ins;
			break;
		}
		if (j == i - 1)
			arr[i] = ins;
	}
	cout << "����������Ϊ��\n";
	for (int j = 0 ; j <= i ; j++) {
		if (!j)
			cout << arr[j];
		else
			cout << " " << arr[j];
	}
	putchar('\n');
	return 0;
}