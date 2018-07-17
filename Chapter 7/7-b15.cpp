/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
typedef int Status;
#define ERROR -1
#define WIN 1
#define LIN 2



void Convert_wtol(ofstream &fout, char out)
{
	static bool flag = true;
	if (!flag) {
		if (out == 0x0d)
			fout << char(0x0d);
		else {
			if (out == 0x0a)
				fout << char(0x0a);
			else
				fout << char(0x0d) << out;
			flag = true;
		}
	}
	else {
		if (out == 0x0d)
			flag = false;
		else
			fout << out;
	}
}

void Convert_ltow(ofstream &fout, char out)
{
	if (out == 0x0a)
		fout << char(0x0d) << char(0x0a);
	else
		fout << out;
}

Status IsWindows(char *finName)
{
	ifstream fin;
	fin.open(finName, ios::binary);	//ios::binary
	if (!fin.is_open()) {
		cerr << "打开" << finName << "失败！\n";
		return ERROR;
	}
	char ch;
	bool preIs0d = false, isWin = false;
	while (!fin.eof()) {
		fin.get(ch);
		if (ch == char(0x0d))
			preIs0d = true;
		else if (preIs0d && ch != char(0x0a))
			preIs0d = false;
		else if (preIs0d && ch == char(0x0a)) {
			isWin = true;
			break;
		}
	}
	fin.close();
	if (isWin)
		return WIN;
	return LIN;
}

int main(int argc, char**argv)
//int main()
{
	ifstream fin;
	ofstream fout;
	char finName[20], foutName[20], ch;
	//char finName[20] = "1.txt", foutName[20] = "out.docx", tmp_mem[38];
	if (argc == 3 && !strcmp(argv[1], "-check")) {
		strcpy(finName, argv[2]);
		int s = IsWindows(finName);
		if (s == WIN)
			cout << "Windows格式\n";
		else if (s == LIN)
			cout << "Linux格式\n";
	}
	else if (argc == 5 && !strcmp(argv[1], "-convert")) {
		bool isWin;
		strcpy(finName, argv[3]);
		strcpy(foutName, argv[4]);

		fin.open(finName, ios::binary);	//ios::binary
		if (!fin.is_open()) {
			cout << "打开" << finName << "失败！\n";
			return 0;
		}


		if (!strcmp(argv[2], "wtol")) {
			int s = IsWindows(finName);
			if (s == LIN) {
				cerr << "文件格式错误\n";
				return 0;
			}
			else if (s == WIN)
				isWin = true;
			else
				return 0;
		}
		else if (!strcmp(argv[2], "ltow")) {
			int s = IsWindows(finName);
			if (s == WIN) {
				cerr << "文件格式错误\n";
				return 0;
			}
			else if (s == LIN)
				isWin = false;
			else
				return 0;
		}
		else {
			cerr << "输入命令有误\n";
			fin.close();
			return 0;
		}

		fout.open(foutName, ios::out | ios::binary);	//ios::binary important!!
		if (!fout.is_open()) {
			cout << "打开" << foutName << "失败！\n";
			return 0;
		}
		while (!fin.eof()) {
			fin.get(ch);
			if (isWin)
				Convert_wtol(fout, ch);
			else
				Convert_ltow(fout, ch);
		}
	}
	else
		cerr << "命令有错!\n";

	return 0;
}