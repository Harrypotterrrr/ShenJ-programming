/*1∞‡ º÷Íª¡ÿ 1651574*/
#include<iostream>
#include<cstring>
#include <cmath>
#define Capital 1
#define Lowercase 2
#define Other 0
using namespace std;
int JudgeChar(char c)
{
	if (c >= 'A' && c <= 'Z')
		return Capital;
	else if ((c >= 'a' && c <= 'z'))
		return Lowercase;
	return Other;
}
void Convert(char str[])
{
	int len = strlen(str);
	bool InitChar = true;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')
			InitChar = true;
		else if (JudgeChar(str[i]) == Capital) {
			if (!InitChar)
				str[i] += 32;
			InitChar = false;
		}
		else if (JudgeChar(str[i]) == Lowercase) {
			if (InitChar)
				str[i] -= 32;
			InitChar = false;
		}
	}
}
int main()
{
	char str[1000];
	cout << "«Î ‰»Î◊÷∑˚¥Æ\n";
	gets_s(str);
	Convert(str);
	cout << str << endl;
	return 0;
}
