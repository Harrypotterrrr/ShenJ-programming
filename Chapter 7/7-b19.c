/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef int Status;
#define ERROR -1
#define WIN 1
#define LIN 2



void Convert_wtol(FILE *fout, char out)
{
	static int flag = 1;
	if (!flag) {
		if (out == 0x0d)
			fputc((char)0x0d, fout);
		else {
			if (out == 0x0a)
				fputc((char)0x0a, fout);
			else {
				fputc((char)0x0d, fout);
				fputc(out, fout);
			}
			flag = 1;
		}
	}
	else {
		if (out == 0x0d)
			flag = 0;
		else
			fputc(out, fout);
	}
}

void Convert_ltow(FILE *fout, char out)
{
	if (out == 0x0a) {
		fputc((char)0x0d, fout);
		fputc((char)0x0a, fout);
	}
	else
		fputc(out, fout);
}

Status IsWindows(char *finName)
{
	FILE *fin;
	fin = fopen(finName, "rb");
	if (!fin) {
		fprintf(stderr, "打开%s失败！\n", finName);
		return ERROR;
	}
	char ch;
	int preIs0d = 0, isWin = 0;
	while (!feof(fin)) {
		ch = fgetc(fin);
		if (ch == (char)(0x0d))
			preIs0d = 1;
		else if (preIs0d && ch != (char)(0x0a))
			preIs0d = 0;
		else if (preIs0d && ch == (char)(0x0a)) {
			isWin = 1;
			break;
		}
	}
	fclose(fin);
	if (isWin)
		return WIN;
	return LIN;
}

int main(int argc, char**argv)
//int main()
{
	FILE *fin = NULL;
	FILE *fout = NULL;
	char finName[20], foutName[20], ch;
	//char finName[20] = "1.txt", foutName[20] = "out.docx", tmp_mem[38];
	if (argc == 3 && !strcmp(argv[1], "-check")) {
		strcpy(finName, argv[2]);
		int s = IsWindows(finName);
		if (s == WIN)
			fprintf(stdout, "Windows格式\n");
		else if (s == LIN)
			fprintf(stdout, "Linux格式\n");
	}
	else if (argc == 5 && !strcmp(argv[1], "-convert")) {
		int isWin;
		strcpy(finName, argv[3]);
		strcpy(foutName, argv[4]);

		fin = fopen(finName, "rb");
		if (!fin) {
			fprintf(stderr, "打开%s失败！\n", finName);
			return 0;
		}


		if (!strcmp(argv[2], "wtol")) {
			int s = IsWindows(finName);
			if (s == LIN) {
				fprintf(stderr, "文件格式错误\n");
				return 0;
			}
			else if (s == WIN)
				isWin = 1;
			else
				return 0;
		}
		else if (!strcmp(argv[2], "ltow")) {
			int s = IsWindows(finName);
			if (s == WIN) {
				fprintf(stderr, "文件格式错误\n");
				return 0;
			}
			else if (s == LIN)
				isWin = 0;
			else
				return 0;
		}
		else {
			fprintf(stderr, "输入命令有误\n");
			fclose(fin);
			return 0;
		}

		fout = fopen(foutName, "wb");
		if (!fout) {
			fprintf(stderr, "打开%s失败\n", foutName);
			return 0;
		}
		while (!feof(fin)) {
			ch = fgetc(fin);
			if (isWin)
				Convert_wtol(fout, ch);
			else
				Convert_ltow(fout, ch);
		}
	}
	else
		fprintf(stderr, "命令有错!\n");

	return 0;
}