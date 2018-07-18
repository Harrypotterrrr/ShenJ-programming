/* 1651574 1班 贾昊霖 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

using namespace std;

int  read_hzk48(FILE *fphzk48t, FILE *fphzk48s, unsigned char hz[2], unsigned char buf[288])
{
	int  qm, wm;
	long offset;
	FILE *fphzk48;

	qm = hz[0] - 0xA0;
	wm = hz[1] - 0xA0;

	if (qm < 16) {
		fphzk48 = fphzk48t;
		offset = (long)((qm - 1) * 94 + (wm - 1)) * 288;
	}
	else {
		fphzk48 = fphzk48s;
		offset = (long)((qm - 1 - 15) * 94 + (wm - 1)) * 288;
	}

	fseek(fphzk48, offset, SEEK_SET);
	if (fread((char *)buf, 1, 288, fphzk48) != 288)
		return -1;

	return 0;
}

vector<vector<int>> convert(char* hz)
{
	vector<vector<int>>asd;
	vector<int>temp(48, 0);
	for (int i = 0; i < 48; i++)
		asd.push_back(temp);


	int  ret;
	FILE *fphzk48t, *fphzk48s;
	int  i, j, k;
	unsigned char buf[288];
	unsigned char mask;

	fphzk48t = fopen("HZK48T", "rb");
	fphzk48s = fopen("HZK48S", "rb");
	if (fphzk48t && fphzk48s) {
		read_hzk48(fphzk48t, fphzk48s, (unsigned char *)hz, buf);
		ret = 0;
		for (i = 0; i < 48; i++) {
			for (j = 0; j < 6; j++) {
				mask = 0x80;
				for (k = 0; k < 8; k++) {
					if (buf[i * 6 + j] & mask)
						asd[i][j * 8 + k] = 1;
					else
						asd[i][j * 8 + k] = 0;
					mask = mask >> 1;
				}
			}
		}
	}
	fclose(fphzk48t);
	fclose(fphzk48s);
	return asd;
}

int main(int argc, char *argv[])
{
	cout << "假期做的大作业....没派上用场,由于时间原因(还要继续刚CPU),在这里苟且一下交个简化版的吧...\n";
	cout << "请输入回车继续\n";
	while (char c = _getch() != '\r')
		;
	system("cls");
	cout << "请输入一串中文\n";
	char s[1024];
	cin >> s;
	vector<vector<int>> V[1024];
	for (int i = 0; i < strlen(s) / 2; i++) {
		char tmp[3];
		strncpy(tmp, s+i*2, 2);
		tmp[2] = '\0';
		V[i] = convert(s+i*2);
	}
	char fileName[1024];
	strcpy(fileName,s);
	strcat(fileName, ".txt");
	ofstream fout(fileName, ios::binary);
	for (int i = 0; i < 48; i++) {
		for (int j = 0; j < 48; j++)
			fout << "0";
		fout << "000";

		for (int k = 0; k < strlen(s) / 2; k++) {
			for (int j = 0; j < 48; j++)
				fout << V[k][i][j];
			fout << "000";
		}

		for (int j = 0; j < 48; j++)
			fout << "0";
		fout << "000";

		fout << endl;
	}
	fout.close();
	char addr[1024];
	strcpy(addr, fileName);
	system(addr);
	return 0;
}