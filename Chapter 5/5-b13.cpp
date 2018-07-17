/*1∞‡ º÷Íª¡ÿ 1651574*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include <cmath>
#define MAX_LENGTH 1000
using namespace std;
void InputData(char name[][15], char num[][15], int n)
{
	for (int i = 0; i < n; i++) {
		while (true) {
			cout << "input name and number of the student " << i + 1 << ":";
			cin >> name[i] >> num[i];
			if (cin.good())
				break;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}
void SearchStu(char name[][15], char num[][15], char find[], int n)
{
	for (int i = 0; i < n; i++) {
		if (!strcmp(name[i], find)) {
			cout << name[i] << "has been found, his number is "<< num[i] << endl;
			return;
		}
	}
	cout << "can't find this name\n";
}
int main()
{
	char name[MAX_LENGTH][15], num[MAX_LENGTH][15];
	char find[15];
	int n;
	while (true) {
		cout << "please input number of this class: ";
		cin >> n;
		if (cin.good())
			break;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	InputData(name, num, n);
	cout << "please input name you want find :\n";
	cin >> find;
	SearchStu(name, num, find, n);
	return 0;
}
