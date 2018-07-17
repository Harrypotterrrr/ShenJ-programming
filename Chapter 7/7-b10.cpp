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
#define SCREEN_WAY
typedef int OutputType;
using namespace std;

struct FileMatch
{
	char noCheck[10];
	char noMatch[10];
	char fileName[35];
	int bias;
	char outFileName[35];
};

bool IsDigital(const char *str)
{
	for (int i = 0; i < 7; i++)
		if (str[i] <'0' || str[i] > '9')
			return false;
	return true;
}

bool CheckNo(FileMatch &fm, const char *const *no)
{
	if (!strcmp(no[1], "all")) {
		if (strcmp(no[2], "all")) {
			cout << "检查学号是all，匹配学号必须是all\n";
			return false;
		}
		strcpy(fm.noCheck, "all");
		strcpy(fm.noMatch, "all");
		return true;
	}
	if (strlen(no[1]) != 7 || strlen(no[2]) != 7) {
		cout << "要检查的学号不是7位\n";
		return false;
	}
	if (!IsDigital(no[1]) || !IsDigital(no[2])) {
		cout << "要检查的学号不是7位数字\n";
		return false;
	}
	strcpy(fm.noCheck, no[1]);
	strcpy(fm.noMatch, no[2]);
	return true;
}

bool CheckFileName(FileMatch &fm, const char *fname, bool flag)
{
	if (strlen(fname) > 32 && !flag) {
		cout << "源程序文件名超过了32字节\n";
		return false;
	}
	if (strlen(fname) > 32 && flag) {
		cout << "输出结果文件名超过了32字节\n";
		return false;
	}
	if (!flag)
		strcpy(fm.fileName, fname);
	else
		strcpy(fm.outFileName, fname);
	return true;
}

void CheckRange(FileMatch &fm, const char *range)
{
	int sum = 0;
	for (int i = strlen(range) - 1; i >= 0; i--) {
		sum *= 10;
		sum += range[i] - '0';
	}
	fm.bias = 80;
	if (sum >= 60 && sum <= 100)
		fm.bias = sum;
}

int usage(const char *procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl;
	cout << "               1759999          1759998      all          80                screen" << endl;
	cout << "               1759999          all          3-b3.cpp     75                result.txt" << endl;
	cout << "               all              all          3-b3.cpp     80                check.dat" << endl;
	cout << "               all              all          all          85                screen" << endl;

	return 0;
}


int main(int argc, char**argv)
//int main()
{
	FileMatch fmatch;


	//char **argv;
	//int argc;
	//cin >> argc;
	//argv = new char*[5];
	//for (int i = 0; i < 5; i++)
	//	argv[i] = new char[50];
	//for (int i = 0; i < argc; i++)
	//	cin >> argv[i];

	if (argc < 2) {
		usage(argv[0]);
		return 0;
	}
	if (!CheckNo(fmatch, argv))
		return 0;
	if (!CheckFileName(fmatch, argv[3], 0))
		return 0;
	CheckRange(fmatch, argv[4]);
	if (!CheckFileName(fmatch, argv[5], 1))
		return 0;
	cout << "参数检查通过"
		<< "\n检查学号：" << fmatch.noCheck
		<< "\n匹配学号：" << fmatch.noMatch
		<< "\n源文件名：" << fmatch.fileName
		<< "\n匹配阈值：" << fmatch.bias
		<< "\n输出目标：" << fmatch.outFileName << endl;
	cout << endl;
	return 0;
}
