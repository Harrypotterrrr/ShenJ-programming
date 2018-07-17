/*1651574 贾昊霖 1班*/
#include <iostream>
#include <iomanip>
#include <bitset>
#define OK 1
#define Error 0
using namespace std;

typedef int Status;

bool judge_c(char c)
{
	return ((c<='J')&&(c>='A')) || ((c>='a')&&(c<='j'));
}
#define ON 2
#define OFF 1
int judge_str(char *str)
{
	if (!strcmp(str, "on") || !strcmp(str, "ON") || !strcmp(str, "On"))
		return ON;
	else if (!strcmp(str, "off") || !strcmp(str, "OFF") || !strcmp(str, "Off"))
		return OFF;
	return Error;
}
void ChangeShut(short* shut, int k, int tag)
{
	int n = 1 << k;
	if (tag == ON)
		*shut |= n;
	else
		*shut &= ~n;
}
void output(short* shut)
{
	short bit = 0x01;
	cout << "当前状态：0x" << hex << setw(4) << setfill('0') << *shut << endl;
	for (int i = 0; i < 10; i++)
		cout << char('A' + i) << '\t';
	cout << endl;
	for (int i = 0; i < 10; i++) {
		short r = bit & (*shut >> i);
		if (r)
			cout << "ON\t";
		else
			cout << "OFF\t";
	}
	putchar('\n');
}
void input(short* shut)
{
	char c[5], str[5];
	int tag;
	do {
		cout << "请以 A ON/ J OFF 这样的格式输入，输入Q退出\n";
		cin >> c>>str;
		if (!strcmp(c, "Q"))
			break;
		tag = judge_str(str);
		if (c[0] >= 'a' && c[0] <= 'z')
			c[0] -= 32;
		if (!judge_c(c[0]) || tag == Error)
			continue;
		ChangeShut(shut, c[0] - 'A', tag);
		output(shut);
	} while (true);
	//while (cin >> c && strcmp(c, "Q")) {
	//	cin >> str;
	//	tag = judge_str(str);
	//	if (!judge_c(c[0]) || tag == Error)
	//		continue;

	//	cout << "请以 A ON/ J OFF 这样的格式输入，输入 Q推出\n";
	//}
}
int main()
{
	short shut = 0x0000;
	cout << "初始状态：0x"<<hex<<setw(4)<<setfill('0')<<shut<<endl;
	input(&shut);
	return 0;
}