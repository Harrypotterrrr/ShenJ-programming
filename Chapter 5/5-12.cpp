/*1651574 1班 贾昊霖*/
#include <iostream>
#include <string>
//#include <Windows.h>
#include <iomanip>
#include <cmath>
#define eps 1e-8
enum LetterType { Capital, Lowercase, Number, Space, Other };
using namespace std;
void Decode(char str[])
{
	for (int i = 0; ; i++) {
		if (str[i] == '\0')
			break;	//不让用strlen我也很无奈啊...
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = (str[i] - 'A' + 26 - 1) % 26 + 'A';
		else if (str[i] <= 'z'&& str[i] >= 'a')
			str[i] = (str[i] - 'a' + 26 - 1) % 26 + 'a';
	}
}
int main()
{
	char str[85];
	cout << "请输入密码串\n";
	gets_s(str);
	cout << "密文：" << str << endl;
	Decode(str);
	cout << "原文：" << str << endl;
	return 0;
}
