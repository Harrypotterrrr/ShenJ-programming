/*1651574 1�� �����*/
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
			break;	//������strlen��Ҳ�����ΰ�...
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
	cout << "�������1��\n";
	gets_s(str);
	Count(str, num);
	cout << "�������2��\n";
	gets_s(str);
	Count(str, num);
	cout << "�������3��\n";
	gets_s(str);
	Count(str, num);
	cout << "��д : " << num[Capital]<<endl;
	cout << "Сд : " << num[Lowercase] << endl;
	cout << "���� : " << num[Number] << endl;
	cout << "�ո� : " << num[Space] << endl;
	cout << "���� : " << num[Other] << endl;
	return 0;
}
