/*1651574 1∞‡ º÷Íª¡ÿ*/
#define CRE_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	void Print(int);
	int n;
	cout << "¿¥∏ˆ ˝◊÷∞…∏Á:\n";
	cin >> n;
	if (n < 0)
		Print(-n);
	else
		Print(n);
	if (n < 0)
		cout << '-';
	putchar('\n');
	return 0;
}
void Print(int num)
{
	if (!num)
		return;
	cout << num % 10<<" ";
	Print(num / 10);
}