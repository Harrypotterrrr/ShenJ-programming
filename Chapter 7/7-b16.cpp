/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>

using namespace std;
void Solve(char *mem, int k = 16)
{
	static int n = 0;
	cout << hex << setw(8) << setfill('0') << n << "  ";
	for (int i = 0; i < 16; i++) {
		if (i < k) {
			if (i == 8)
				cout << "- ";
			cout << setfill('0') << setw(2) << uppercase << (short(mem[i]) & 0x00ff) << " ";
			if (mem[i] < 33 || mem[i] == 127)
				mem[i] = '.';
		}
		else {
			if (i == 8)
				cout << "  ";
			cout << "   ";
		}
	}
	cout << "    " << mem << endl;
	n += 16;
}
int main(int argc, char**argv)
{
	ifstream fin;
	char filename[20], tmp_mem[20];
	if (argc == 1) {					//no parameter
		cout << "文件名一下形式均可以：\n"
			<< "a.txt：不带路径形式\n"
			<< "..\\data\\b.dat：相对路径形式\n"
			<< "C : \\Windows\\System32\\c.dat：绝对相对路径形式\n"
			<< "请输入文件名 : ";
		cin >> filename;
	}
	else
		strcpy(filename, argv[1]);
	fin.open(filename, ios::binary);	//ios::binary
	if (!fin.is_open()) {
		cout << "打开" << filename << "失败！\n";
		return 0;
	}
	//system("mode con cols=100 lines=40");
	//cout << filename << endl;
	int i;
	for (i = 0; !fin.eof(); i++) {
		fin.get(tmp_mem[i]);
		if (i == 15) {
			tmp_mem[16] = '\0';
			i = -1;
			Solve(tmp_mem);
		}
	}
	if (i) {
		tmp_mem[i - 1] = '\0';	// i - 1 !
		Solve(tmp_mem, i - 1);
	}

	fin.close();
	return 0;
}