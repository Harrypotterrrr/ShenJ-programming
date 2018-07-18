/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
bool Judge(char *str)
{
	if (!str)
		return false;
	int len = strlen(str);
	if (len == 1 || len == 0)
		return true;
	for (int i = 0; i < len / 2 - 1; i++)
		if (*(str + i) != *(str + len - 1 - i))
			return false;
	return true;
}
int main()
{
	char str[1000];
	cout << "请输入一个长度小于80的字符串\n";
	gets_s(str);
	if (Judge(str))
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}