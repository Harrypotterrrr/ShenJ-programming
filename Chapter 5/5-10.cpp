/*1651574 1班 贾昊霖*/
#include <iostream>
#include <string>
//#include <Windows.h>
#include <iomanip>
#include <cmath>
#define eps 1e-8
enum LetterType{Capital,Lowercase,Number,Space,Other};
using namespace std;
void Count(char str[],int num[])
{
	for (int i = 0; ; i++) {
		if (str[i] == '\0')
			break;	//不让用strlen我也很无奈啊...
		if (str[i] <= 'Z' && str[i] >= 'A')
			num[Capital]++;
		else if (str[i] <= 'z' && str[i] >= 'a')
			num[Lowercase]++;
		else if (str[i] <= '9' && str[i] >= '0')
			num[Number]++;
		else if (str[i] == ' ')
			num[Space]++;
		else
			num[Other]++;
	}
}
int main()
{
	int num[8] = { 0 };
	char str[85];
	cout << "请输入第1行\n";
	gets_s(str);
	Count(str, num);
	cout << "请输入第2行\n";
	gets_s(str);
	Count(str, num);
	cout << "请输入第3行\n";
	gets_s(str);
	Count(str, num);
	cout << "大写 : " << num[Capital]<<endl;
	cout << "小写 : " << num[Lowercase] << endl;
	cout << "数字 : " << num[Number] << endl;
	cout << "空格 : " << num[Space] << endl;
	cout << "其它 : " << num[Other] << endl;
	return 0;
}
