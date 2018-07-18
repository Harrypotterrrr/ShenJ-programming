/* 1班 贾昊霖 1651574 */
#include <iostream>
using namespace std;

int main()
{
	int num, arr[25] = { 0 }, i, ins;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束\n";
	for (i = 0 ; ; i++) {
		cin >> arr[i];
		if (arr[i] == -1)
			break;
	}
	cout << "原数组为：\n";
	for (int j = 0 ; j < i ; j++) {
		if (!j)
			cout << arr[j];
		else
			cout << " " << arr[j];
	}
	cout << "\n请输入要插入的正整数\n";
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
	cout << "插入后的数组为：\n";
	for (int j = 0 ; j <= i ; j++) {
		if (!j)
			cout << arr[j];
		else
			cout << " " << arr[j];
	}
	putchar('\n');
	return 0;
}