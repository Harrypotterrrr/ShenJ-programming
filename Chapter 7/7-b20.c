/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef int Status;
#define ERROR -1
#define WIN 1
#define LIN 2

void Solve(char *mem, int k)
{
	static int n = 0;
	fprintf(stdout, "%08x ", n);
	for (int i = 0; i < 16; i++) {
		if (i < k) {
			if (i == 8)
				fprintf(stdout, "- ");
			fprintf(stdout, "%02X ", ((short)mem[i] & 0x00ff));
			if (mem[i] < 33 || mem[i] == 127)
				mem[i] = '.';
		}
		else {
			if (i == 8)
				fprintf(stdout, "  ");
			fprintf(stdout, "   ");
		}
	}
	fprintf(stdout, "    %s\n",mem);
	n += 16;
}
int main(int argc, char**argv)
{
	FILE *fin;
	char fileName[20], tmp_mem[20];
	if (argc == 1) {					//no parameter
		fprintf(stdout, "文件名一下形式均可以：\na.txt：不带路径形式\n");
		fprintf(stdout, "..\\data\\b.dat：相对路径形式\n\C : \\Windows\\System32\\c.dat");
		fprintf(stdout, "：绝对相对路径形式\n请输入文件名 : ");
		fscanf(stdin, "%s", fileName);
	}
	else
		strcpy(fileName, argv[1]);
	
	fin = fopen(fileName, "rb");
	if (!fin) {
		fprintf(stderr, "打开%s失败！\n", fileName);
		return 0;
	}
	//system("mode con cols=100 lines=40");
	//cout << fileName << endl;
	int i;
	for (i = 0; !feof(fin); i++) {
		tmp_mem[i] = fgetc(fin);
		if (i == 15) {
			tmp_mem[16] = '\0';
			i = -1;
			Solve(tmp_mem, 16);
		}
	}
	if (i) {
		tmp_mem[i - 1] = '\0';	// i - 1 !
		Solve(tmp_mem, i - 1);
	}

	fclose(fin);
	return 0;
}