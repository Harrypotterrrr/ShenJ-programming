/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;
int main()
{
	int arr[1005] = { 0 }, n;
	cout << "请输入任意成绩（最多1000个），以-1结束\n";
	for (n = 0; ; n++) {
		cin >> arr[n];
		if (arr[n] == -1)
			break;
	}
	cout << "输入的数组为：\n";
	for (int i = 0; i < n; i++) {
		if (!(i % 10) && i)
			putchar('\n');
		if (!(i % 10))
			cout << arr[i];
		else
			cout << " " << arr[i];
	}
	putchar('\n');
	cout << "分数与名次的对应关系为：\n";
	/*				sort			  */
	int temp;
	for (int i = 1; i <= n - 1; i++)
		for (int j = 0; j <= n - i - 1; j++)
			if (arr[j] < arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
	int rank = 1;
	for (int i = 0; i < n;i++) {
		if (i && arr[i] != arr[i - 1])
			rank = i + 1;
		cout << arr[i] << "  " << rank << endl;
	}
	return 0;
}
