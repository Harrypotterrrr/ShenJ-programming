/*1651574 1班 贾昊霖*/
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
			return 128;		//	错误！
		num += (str[i] - '0');
	}
	if (num < 1)
		return 128;			//	错误!
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
		return 100;			//	错误!
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
		cout << "Usage 7-b11 [-l 大小] [-n 数量] [-t] IP地址\n";
		return 0;
	}
	//else if (strcmp(argv[0], str_ping)) {
	//	cout << "不是以-开头的合法参数\n";
	//	return 0;
	//}
	for (int i = 1; i < argc; i++) {
		if (isDigital(argv[i][0]) || argv[i][0] == '.') {
			if (!judgeIP(argv[i])) {
				cout << "IP地址不正确!\n";
				return 0;
			}
			strcpy(info.ip, argv[i]);
		}
		else if (argv[i][0] == '-') {
			if (argv[i][1] == 'l') {
				info.l = ana_l(argv[++i]);
				if (!info.l) {
					cout << "-l 没有后续参数\n";
					return 0;
				}
			}
			else if (argv[i][1] == 'n') {
				info.n = ana_n(argv[++i]);
				if (!info.n) {
					cout << "-n 没有后续参数\n";
					return 0;
				}
			}
			else if (argv[i][1] == 't')
				info.t = true;
			else {
				cout << "参数" << argv[i] << "不存在\n";
				return 0;
			}
		}
		else {
			cout << "输入的命令有误!\n";
			return 0;
		}
	}
	cout << "参数检查通过"
		<< "\n-n参数：" << info.l
		<< "\n-l参数：" << info.n
		<< "\n-t参数：" << info.t
		<< "\nIP地址：" << info.ip << endl;
	cout << endl;
	return 0;
}