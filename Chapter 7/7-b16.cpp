/*1651574 1�� �����*/
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
		cout << "�ļ���һ����ʽ�����ԣ�\n"
			<< "a.txt������·����ʽ\n"
			<< "..\\data\\b.dat�����·����ʽ\n"
			<< "C : \\Windows\\System32\\c.dat���������·����ʽ\n"
			<< "�������ļ��� : ";
		cin >> filename;
	}
	else
		strcpy(filename, argv[1]);
	fin.open(filename, ios::binary);	//ios::binary
	if (!fin.is_open()) {
		cout << "��" << filename << "ʧ�ܣ�\n";
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