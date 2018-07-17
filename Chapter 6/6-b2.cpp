/* 1�� ����� 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void merge(int *list_a, int *list_b, int *list_c)
{
	int *p = list_a, *q = list_b, *r = list_c;
	while (*p != -1 && *q != -1) {
		if (*p < *q)
			*r++ = *p++;
		else
			*r++ = *q++;
	}
	while (*p != -1)
		*r++ = *p++;
	while (*q != -1)
		*r++ = *q++;
	*r = -1;
}
int main()
{
	int num1[25], *p = num1;
	int num2[25], *q = num2;
	int num3[55], *r = num3, tmp;
	cout << "�������һ������:\n";
	while (cin >> tmp) {
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		*p++ = tmp;
		if (tmp == -1)
			break;
	}
	cout << "������ڶ�������:\n";
	while (cin >> tmp) {
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		*q++ = tmp;
		if (tmp == -1)
			break;
	}
	cout << "����ĵ�һ����������Ϊ��\n";
	for (p = num1; *p != -1; )
		cout << *p++ << " ";
	putchar('\n');
	cout << "����ĵڶ�����������Ϊ��\n";
	for (q = num2; *q != -1; )
		cout << *q++ << " ";
	putchar('\n');

	merge(num1, num2, num3);

	cout << "�ϲ��������Ϊ��\n";
	for (r = num3; *r != -1;)
		cout << *r++ << " ";
	putchar('\n');
	return 0;
}