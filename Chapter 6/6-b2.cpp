/* 1班 贾昊霖 1651574 */
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
	cout << "请输入第一个数组:\n";
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
	cout << "请输入第二个数组:\n";
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
	cout << "输入的第一个整数序列为：\n";
	for (p = num1; *p != -1; )
		cout << *p++ << " ";
	putchar('\n');
	cout << "输入的第二个整数序列为：\n";
	for (q = num2; *q != -1; )
		cout << *q++ << " ";
	putchar('\n');

	merge(num1, num2, num3);

	cout << "合并后的数组为：\n";
	for (r = num3; *r != -1;)
		cout << *r++ << " ";
	putchar('\n');
	return 0;
}