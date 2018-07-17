/*1班 贾昊霖 1651574*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#define MAX_LENGTH 1000
using namespace std;
enum LetterType { Uppercase, Lowercase, Number, Other };
int Locate(char code[], int n)
{
	int loc = rand() % n;
	while (code[loc])
		loc = (loc + 1) % n;
	return loc;
}
char CreateChar(int k)
{
	switch (k) {
		case(Uppercase):
			return rand() % 26 + 'A';
		case(Lowercase):
			return rand() % 26 + 'a';
		case(Number):
			return rand() % 10 + '0';
		case(Other):
			while (true) {
				char c = rand() % (126 - 33) + '!';
				if ((c < 'a' || c >'z') && (c <'A' || c>'Z') && (c<'0' || c>'9'))
					return c;
			}
	}
}
void CreateCode(char code[], int n, int LimitNum[])
{
	int loc, sum = 0;
	char c;
	for (int k = Uppercase; k <= Other; k++) {
		for (int i = 0; i < LimitNum[k]; i++) {
			c = CreateChar(k);
			loc = Locate(code, n);
			code[loc] = c;
			sum++;
		}
	}
	while (sum++ < n) {
		c = rand() % (126 - 33) + '!';
		loc = Locate(code, n);
		code[loc] = c;
	}
	code[n] = '\0';
}
int main()
{
	srand(unsigned(time(NULL)));
	char code[MAX_LENGTH] = {'\0'};
	int n,LimitNum[5];

	/*initial setting begin*/
	while (true) {
		cout << "请输入密码长度（12-16）\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 12 && n <= 16)
			break;
	}
	while (true) {
		cout << "请输入大写字母个数（至少两个）\n";
		cin >>LimitNum[Uppercase];
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (LimitNum[Uppercase] >=2)
			break;
	}
	while (true) {
		cout << "请输入小写字母个数（至少两个）\n";
		cin >> LimitNum[Lowercase];
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (LimitNum[Lowercase] >= 2)
			break;
	}
	while (true) {
		cout << "请输入数字个数（至少两个）\n";
		cin >> LimitNum[Number];
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (LimitNum[Number] >= 2)
			break;
	}
	while (true) {
		cout << "请输入其他字符个数（至少两个）\n";
		cin >> LimitNum[Other];
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (LimitNum[Other] >= 2)
			break;
	}
	/*end of Initial setting*/

	cout << n;
	for (int i = Uppercase; i <= Other; i++)
		cout << " " << LimitNum[i];
	putchar('\n');
	for (int i = 1; i <= 10; i++) {
		memset(code, '\0', sizeof code);
		CreateCode(code, n, LimitNum);
		cout << code << endl;
	}
	return 0;
}
