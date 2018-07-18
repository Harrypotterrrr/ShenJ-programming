/* 1∞‡ º÷Íª¡ÿ 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	const char *p[12] = { "January","February","March","April","May","June",
		"July","August","September","October","November","December" };

	int n;
	while (true) {
		cout << "«Î ‰»Î‘¬∑›:\n";
		cin >> n;
		if (cin.good())
			break;;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	if (n > 12 || n < 1) {
		cout << "invalid\n";
		return 0;
	}
	cout << p[n - 1] << endl;
	return 0;
}