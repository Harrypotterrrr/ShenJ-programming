/* 1∞‡ º÷Íª¡ÿ 1651574 */
#include <iostream>
using namespace std;
int main()
{
	bool light[105] = { false };
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j*i <= 100; j++) {
			if (i*j <= 100)
				light[i*j] = !light[i*j];
		}
	}
	bool flag = true;
	for (int i = 1; i <= 100; i++) {
		if (light[i] && flag) {
			cout << i;
			flag = false;
		}
		else if (light[i])
			cout << " " << i;
	}
	putchar('\n');
	return 0;
}