/*1651574 1�� �����*/
/*¬���� ������ ����� ������ ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef int Status;
#define ERROR -1
#define WIN 1
#define LIN 2


void StoreMem(FILE *fout, char *mem)
{
	unsigned int tmp = 0;
	static int flag = 1;
	if (mem[0] <= 'Z' && mem[0] >= 'A')
		tmp += 16 * (mem[0] - 'A' + 10);
	else if (mem[0] <= 'z' && mem[0] >= 'a')
		tmp += 16 * (mem[0] - 'a' + 10);
	else
		tmp += 16 * (mem[0] - '0');

	if (mem[1] <= 'Z' && mem[1] >= 'A')
		tmp += mem[1] - 'A' + 10;
	else if (mem[1] <= 'z' && mem[1] >= 'a')
		tmp += mem[1] - 'a' + 10;
	else
		tmp += mem[1] - '0';

	char out = (char)(tmp & 0x00FF);
	fprintf(fout, "%c", out);
}

int main(int argc, char**argv)
//int main()
{
	FILE *fin;
	FILE *fout;
	char finName[20], foutName[20], tmp_mem[38];
	if (argc < 3) {
		fscanf(stdin, "��ֱ������ת�����ļ���������ļ�����\n");
		fscanf(stdin, "%s%s", finName, foutName);
	}
	else {
		strcpy(finName, argv[1]);
		strcpy(foutName, argv[2]);
	}
	//char finName[20] = "1.txt", foutName[20] = "out.docx", tmp_mem[38];
	fin = fopen(finName, "rb");
	fout = fopen(foutName, "wb");

	if (!fin) {
		fprintf(stdout, "��%sʧ�ܣ�\n", finName);
		return 0;
	}
	if (!fout) {
		fprintf(stdout, "��%sʧ�ܣ�\n", foutName);
		return 0;
	}
	int n = 0;
	while (!feof(fin)) {
		fscanf(fin, "%s", tmp_mem);//��ȡǰ���00000001���
		for (int i = 0; i < 8 && !feof(fin); i++) {	//��8��
			fscanf(fin, "%s", tmp_mem);
			if (strlen(tmp_mem) != 2 || feof(fin))
				break;
			StoreMem(fout, tmp_mem);
		}
		if (strlen(tmp_mem) != 2 || feof(fin))
			break;
		fscanf(fin, "%s", tmp_mem);
		for (int i = 0; i < 8 && (!feof(fin)); i++) {
			fscanf(fin, "%s", tmp_mem);
			if (strlen(tmp_mem) != 2 || feof(fin))
				break;
			StoreMem(fout, tmp_mem);
		}
		if (strlen(tmp_mem) != 2 || feof(fin))
			break;
		fscanf(fin, "%s", tmp_mem);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}