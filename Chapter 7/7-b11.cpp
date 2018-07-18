/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>
#define ERROR 0
#define OK 1
#define COL 9	//not 16
typedef int Status;
using namespace std;
const char str_ping[20] = "ping";

struct IP
{
	char ip[16];
	int l = 100, n = 128;
	bool t = false;
};
bool isDigital(char c)
{
	return (c >= '0') && (c <= '9');
}

bool judgeIP(const char *ip)
{
	int num, temp = 0, ctr_num = 0;
	int len = strlen(ip);
	for (int i = 0; i < len; i++) {
		num = 0;
		do {
			if (!isDigital(ip[i]) || num > 255)
				return false;
			temp = ip[i++] - '0';
			num *= 10;
			num += temp;
		} while (ip[i] && ip[i] != '.');
		if (num < 0 || num > 255)
			return false;
		ctr_num++;
	}
	if (ctr_num != 4)
		return false;
	return true;
}

int ana_n(const char *str)
{
	if (str[0] == '-' && isDigital(str[1]))
		return 128;
	if (judgeIP(str) || str[0] == '-')
		return	ERROR;
	int num = 0, k = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		num *= 10;
		if (!isDigital(str[i]))
			return 128;		//	����
		num += (str[i] - '0');
	}
	if (num < 1)
		return 128;			//	����!
	else if (num < 10000)
		return num;
	else
		return 10000;
}
int ana_l(const char *str)
{
	if (str[0] == '-' && isDigital(str[1]))
		return 100;
	if (judgeIP(str) || str[0] == '-')
		return	ERROR;
	int num = 0, k = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		num *= 10;
		if (!isDigital(str[i]))
			return 100;
		num += (str[i] - '0');
	}
	if (num < 64)
		return 100;			//	����!
	else if (num < 64000)
		return num;
	else
		return 64000;
}

int main(int argc, char**argv)
//int main()
{
	IP info;

	//char argv[6][50];
	//int argc;
	//cin >> argc;
	//for (int i = 0; i < argc; i++)
	//	cin >> argv[i];

	if (argc < 2) {
		cout << "Usage 7-b11 [-l ��С] [-n ����] [-t] IP��ַ\n";
		return 0;
	}
	//else if (strcmp(argv[0], str_ping)) {
	//	cout << "������-��ͷ�ĺϷ�����\n";
	//	return 0;
	//}
	for (int i = 1; i < argc; i++) {
		if (isDigital(argv[i][0]) || argv[i][0] == '.') {
			if (!judgeIP(argv[i])) {
				cout << "IP��ַ����ȷ!\n";
				return 0;
			}
			strcpy(info.ip, argv[i]);
		}
		else if (argv[i][0] == '-') {
			if (argv[i][1] == 'l') {
				info.l = ana_l(argv[++i]);
				if (!info.l) {
					cout << "-l û�к�������\n";
					return 0;
				}
			}
			else if (argv[i][1] == 'n') {
				info.n = ana_n(argv[++i]);
				if (!info.n) {
					cout << "-n û�к�������\n";
					return 0;
				}
			}
			else if (argv[i][1] == 't')
				info.t = true;
			else {
				cout << "����" << argv[i] << "������\n";
				return 0;
			}
		}
		else {
			cout << "�������������!\n";
			return 0;
		}
	}
	cout << "�������ͨ��"
		<< "\n-n������" << info.l
		<< "\n-l������" << info.n
		<< "\n-t������" << info.t
		<< "\nIP��ַ��" << info.ip << endl;
	cout << endl;
	return 0;
}