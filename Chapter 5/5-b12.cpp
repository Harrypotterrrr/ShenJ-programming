/*1∞‡ º÷Íª¡ÿ 1651574*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include <cmath>
using namespace std;

bool Compare(char str1[],char str2[])
{
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	int l = l1 <= l2 ? l1 : l2;
	for (int i = 0; i < l; i++) {
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;
	}
	return (l1 < l2);
}
void PrintStr(char str[][35],int i,int j,int k)
{
	cout << str[i] << " " << str[j] << " " << str[k] << endl;
}
int main()
{
	char str[3][35];
	while (true) {
		cout << "please input three strings: ";
		cin >> str[0] >> str[1] >> str[2];
		if (cin.good())
			break;
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if (Compare(str[0], str[1])) {
		if (Compare(str[1], str[2]))
			PrintStr(str, 0, 1, 2);
		else {
			if (Compare(str[0], str[2]))
				PrintStr(str, 0, 2, 1);
			else
				PrintStr(str, 2, 0, 1);
		}
	}
	else {
		if (Compare(str[0], str[2]))
			PrintStr(str, 1, 0, 2);
		else {
			if (Compare(str[1], str[2]))
				PrintStr(str, 1, 2, 0);
			else
				PrintStr(str, 2, 1, 0);
		}
	}
	return 0;
}
