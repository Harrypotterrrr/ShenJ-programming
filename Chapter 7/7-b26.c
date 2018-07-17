/*1651574 1�� �����*/
#if defined(_MSC_VER)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <io.h>

#elif defined(__linux) || defined(__linux__)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#endif

#define ERROR 0
#define OK 1
typedef int ErrorInfo;

const char suffix[3][6] = { ".cpp",".c",".h" };
enum OrderType { _checkTitle, _countLine, _analyseLine };

struct Student {
	char no[10];
	char name[10];
	int cls;
	struct Student* next;
};

struct FileDetail
{
	int line_valid;
	int line_purecomment;
	int line_comment;
	int char_valid;
	int char_comment;
	double ratio/* = char_valid / (char_valid + char_comment)*/;

	//int line_valid = 0;
	//int line_purecomment = 0;
	//int line_comment = 0;
	//int char_valid = 0;
	//int char_comment = 0;
	//double ratio/* = char_valid / (char_valid + char_comment)*/;

	//FileDetail(): 
	//line_valid(0),
	//line_purecomment(0),
	//line_comment(0),
	//char_valid(0),
	//char_comment(0){}

	//FileDetail() {
	//	line_valid = 0;
	//	line_purecomment = 0;
	//	line_comment = 0;
	//	char_valid = 0;
	//	char_comment = 0;
	//}

	//FileDetail() {};
};

union FileInfo
{
	int line_num;
	struct FileDetail file_detail;
};

void DeleteHead(struct Student **head)
{
	struct Student *p = *head;
	while (p) {
		*head = (*head)->next;
		free(p);
		p = *head;
	}
}

void PrintResult(ErrorInfo err_num, struct Student *stu, char *file_name, int tag, union FileInfo *info)
{
	printf("%s : %s : ", stu->name, file_name);
	if (err_num & (1 << 5)) {
		printf("δ�ύ\n");
		return;
	}
	if (tag == _checkTitle) {
		if (err_num & (1 << 0))
			printf("δ��ȡ��������Ϣ��\n");
		else if (err_num & (1 << 1))
			printf("������Ϣ��ȫ��\n");
		else if (err_num) {
			if (err_num & (1 << 2))
				printf("ѧ�Ų�ƥ��");
			if (err_num & (1 << 3))
				printf("������ƥ��");
			if (err_num & (1 << 4))
				printf("�༶��ƥ��");
			putchar('\n');
		}
		else
			printf("ͨ��\n");
	}
	else if (tag == _countLine)
		printf("��%d��\n", info->line_num);
	else if (tag == _analyseLine) {
		printf("��Ч��-%d ��ע����-%d ע����-%d ��Ч�ַ�-%d ע���ַ�-%d ����-%4lf\n", \
			info->file_detail.line_valid, info->file_detail.line_purecomment, \
			info->file_detail.line_comment, info->file_detail.char_valid, \
			info->file_detail.char_comment, info->file_detail.ratio * 100);
	}
	//printf("=========================\n");
}

void ana_class(char *str, int *cls)
{
	if (strstr(str, "1��") || strstr(str, "һ") || strstr(str, "��1"))
		*cls = 1;
	else if (strstr(str, "2��") || strstr(str, "��") || strstr(str, "��2"))
		*cls = 2;
	else if (strstr(str, "3��") || strstr(str, "��") || strstr(str, "��3"))
		*cls = 3;
	else if (strstr(str, "��ǿ") || strstr(str, "����ǿ��"))
		*cls = 4;
	else
		*cls = 0;
}

ErrorInfo JudgeTitle(FILE *fin, ErrorInfo *err_num, char(*info)[25])
{
	char str[64], *p, *q, c;

	do {
		c = fgetc(fin);
	} while (c == '\n' || c == ' ' || c == '\t');

	//choose 1 from 2 below

	ungetc(c, fin);
	//fseek(fin, -1, SEEK_CUR);

	fgets(str, 64, fin);

	if (feof(fin) || str[0] != '/' || (str[0] != '/' && str[1] != '*')) {
		*err_num = *err_num | (1 << 0);
		return ERROR;
	}
	if (str[1] == '*' && !(q = strstr(str, "*/"))) {
		*err_num = *err_num | (1 << 0);
		return ERROR;
	}
	p = str + 2;
	if (str[1] == '*')
		p[strlen(str) - 5] = '\0';
	else
		p[strlen(str) - 3] = '\0';

	char tmp_mem[50];
	strcpy(tmp_mem, p);

	if (sscanf(tmp_mem, "%s%s%s", info[0], info[1], info[2]) != 3) {
		*err_num = *err_num | (1 << 1);
		return ERROR;
	}
	return OK;
}

void CheckTitle(struct Student *student, FILE *fin, ErrorInfo *err_num)
{
	struct Student test = { "","",0,NULL };
	char info[3][25];
	if (JudgeTitle(fin, err_num, info) == ERROR)
		return;

	for (int i = 0; i < 3; i++) {
		if (!test.cls) {
			ana_class(info[i], &test.cls);
			if (test.cls)
				continue;
		}

		if (!strcmp(test.no, "")) {
			size_t len = strlen(info[i]), j;
			for (j = 0; j < len; j++)
				if (info[i][j] > '9' || info[i][j] < '0')
					break;
			if (j == len) {
				strcpy(test.no, info[i]);
				continue;
			}
		}
		if (!strcmp(test.name, ""))
			strcpy(test.name, info[i]);
	}

	if (strcmp(test.no, student->no))
		*err_num = *err_num | (1 << 2);
	if (strcmp(test.name, student->name))
		*err_num = *err_num | (1 << 3);
	if (test.cls != student->cls)
		*err_num = *err_num | (1 << 4);
}

union FileInfo LineAnalyse(FILE *fin)
{
	enum CommentSign { Norm, DoubleLineSign, LineStarSign };
	union FileInfo fileAnalyseLine;
	fileAnalyseLine.file_detail.line_comment = 0;
	fileAnalyseLine.file_detail.line_purecomment = 0;
	fileAnalyseLine.file_detail.line_valid = 0;
	fileAnalyseLine.file_detail.char_comment = 0;
	fileAnalyseLine.file_detail.char_valid = 0;
	char tmp_line[300];
	int len, i;
	int flag_comment = Norm; //	stack/**/
	for (fileAnalyseLine.file_detail.line_valid = 0; !feof(fin); fileAnalyseLine.file_detail.line_valid++) {
		fgets(tmp_line, 300, fin);
		len = strlen(tmp_line);
		for (i = len - 1; i >= 0; i--) {
			if (tmp_line[i] != ' ' && tmp_line[i] != '\n' && tmp_line[i] != '\t')
				break;
		}
		len = i + 1;
		tmp_line[len] = '\0';
		for (i = 0; i < len; i++) {
			if (tmp_line[i] != ' ' && tmp_line[i] != '\n' && tmp_line[i] != '\t')
				break;
		}
		strcpy(tmp_line, tmp_line + i);

		if (i == len)
			fileAnalyseLine.file_detail.line_valid--;
		else {
			for (int j = 0; j < len; j++) {
				if (j < len - 1 && tmp_line[j] == '/' && tmp_line[j + 1] == '/') {
					if (j == 0)
						fileAnalyseLine.file_detail.line_purecomment++;
					fileAnalyseLine.file_detail.line_comment++;
					flag_comment = DoubleLineSign;
				}
				else if (j < len - 1 && tmp_line[j] == '/' && tmp_line[j + 1] == '*') {
					fileAnalyseLine.file_detail.line_comment++;
					fileAnalyseLine.file_detail.char_comment += 4;
					// default a pair of comment sign, so there is no syntax error
					flag_comment = LineStarSign;
					j++;
				}
				else if (flag_comment != Norm && j < len - 1 && tmp_line[j] == '*' && tmp_line[j + 1] == '/') {
					if (j == len - 2)
						fileAnalyseLine.file_detail.line_purecomment++;
					flag_comment = Norm;
				}
				else if (tmp_line[j] != ' ' && tmp_line[j] != '\n' && tmp_line[j] != '\t') {
					if (flag_comment)
						fileAnalyseLine.file_detail.char_comment++;
					else
						fileAnalyseLine.file_detail.char_valid++;
				}
			}
			if (flag_comment == DoubleLineSign)
				flag_comment = Norm;
		}
	}

	fileAnalyseLine.file_detail.ratio = (double)(fileAnalyseLine.file_detail.char_valid) / \
		(fileAnalyseLine.file_detail.char_valid + fileAnalyseLine.file_detail.char_comment);
	return fileAnalyseLine;
}

int CountLine(FILE *fin)
{
	char tmp_line[300];
	int ctr;
	for (ctr = 0; !feof(fin); ctr++)
		fgets(tmp_line, 300, fin);
	return ctr;
}

void Solve(struct Student *head, char *class_no, char *order, int tag)
{
	FILE* fin;
	ErrorInfo err_num;
	char file_route[64] = "source\\";
	char file_person[64];

	strcat(file_route, class_no);

	for (struct Student* p = head->next; p; p = p->next) {
		err_num = 0;
		strcpy(file_person, file_route);
		strcat(file_person, "-");
		strcat(file_person, p->no);
		strcat(file_person, "\\");

		if (!strcmp(order, "all")) {

#if defined(_MSC_VER)

			struct _finddata_t fileinfo;
			for (int i = 0; i < 3; i++) {
				char file_each[64];
				strcpy(file_each, file_person);
				strcat(file_each, "*");
				strcat(file_each, suffix[i]);
				intptr_t file_handler = _findfirst(file_each, &fileinfo);
				if (file_handler == -1)
					continue;
				do {
					err_num = 0;
					char file_name[20];
					strcpy(file_name, fileinfo.name);

					strcpy(file_each, file_person);
					strcat(file_each, file_name);
					fin = fopen(file_each, "r");
					union FileInfo file_info;
					if (!fin)
						err_num = err_num | (1 << 5);
					else {
						if (tag == _checkTitle)
							CheckTitle(p, fin, &err_num);
						else if (tag == _countLine)
							file_info.line_num = CountLine(fin);
						else if (tag == _analyseLine)
							file_info = LineAnalyse(fin);
						fclose(fin);
					}
					PrintResult(err_num, p, file_name, tag, &file_info);
				} while (_findnext(file_handler, &fileinfo) != -1);
				_findclose(file_handler);
			}

#elif defined(__linux) || defined(__linux__)

			for (int i = 0; i < 3; i++) {
				char file_each[64];
				strcpy(file_each, file_person);
				strcat(file_each, "*");
				strcat(file_each, suffix[i]);

				DIR            *dir;
				struct dirent  *node;
				if ((dir = opendir(file_each)) == NULL)
					continue;
				/* ѭ��ɨ���Ŀ¼�µ������ļ� */
				while ((node = readdir(dir)) != NULL) {
					err_num = 0;
					char file_name[20];
					strcpy(file_name, node->d_name);

					strcpy(file_each, file_person);
					strcat(file_each, file_name);
					fin.open(file_each, ios::in);
					if (!fin.is_open())
						err_num = err_num | (1 << 5);
					else
						CheckTitle(p, &fin, &err_num);
					PrintResult(err_num, p, file_name);
					fin.close();
		}//end of whileɨ��
				closedir(dir);
				/* �ر� /etc Ŀ¼ */

#endif

		}
		else if(strstr(order, suffix[0]) || strstr(order, suffix[1]) || strstr(order, suffix[2])){
			strcat(file_person, order);
			fin = fopen(file_person, "r");
			union FileInfo file_info;
			if (!fin)
				err_num = err_num | (1 << 5);
			else {
				if (tag == _checkTitle)
					CheckTitle(p, fin, &err_num);
				else if (tag == _countLine)
					file_info.line_num = CountLine(fin);
				else if (tag == _analyseLine)
					file_info = LineAnalyse(fin);
				fclose(fin);
			}
			PrintResult(err_num, p, order, tag, &file_info);
		}
		else {
			printf("����Դ�����ļ���\n");
			break;
		}
	}
}

ErrorInfo GetMain(FILE *fin)
{
	char line[320];

	do {
		fgets(line, 320, fin);
		if (strstr(line, "int main()"))
			break;
	} while (!feof(fin));
	if (feof(fin))
		return ERROR;
	return OK;
}

ErrorInfo ana_list(FILE *fin, const char *argv, struct Student **head)
{
	char route[40] = "source\\";
	strcat(route, argv);
	strcat(route, ".dat\0");
	fin = fopen(route, "r");
	if (!fin) {
		printf("����Ŀγ����󣬸ÿγ̲����ڣ�\n");
		return ERROR;
	}

	*head = (struct Student*)malloc(sizeof(struct Student));
	if (!head) {
		printf("�ڴ治�㣡\n");
		fclose(fin);
		return ERROR;
	}
	(*head)->next = NULL;

	struct Student *p;
	char tmp[10], no_use[10];

	while (!feof(fin)) {
		p = (struct Student*)malloc(sizeof(struct Student));
		if (!p) {
			printf("�ڴ治��!\n");
			fclose(fin);
			return ERROR;
		}
		fscanf(fin, "%s%s%s%s", p->no, p->name, tmp, no_use);
		ana_class(tmp, &p->cls);
		if (!p->cls) {
			printf("���ݿ������..��\n");
			fclose(fin);
			return ERROR;
		}
		p->next = (*head)->next;
		(*head)->next = p;
	}
	return OK;
}

int main(int argc, char**argv)
{
	char tmp_argv[4][50];
	int tmp_argc;

	if (argc == 1) {
		scanf("%s", tmp_argv[1]);
		if (!strcmp(tmp_argv[1], "-checktitle"))
			tmp_argc = 4;
		else if (!strcmp(tmp_argv[1], "-linecount"))
			tmp_argc = 4;
		else if (!strcmp(tmp_argv[1], "-lineanalyse"))
			tmp_argc = 4;
		else {
			printf("�������!\n");
			return 0;
		}
		for (int i = 2; i < tmp_argc; i++)
			scanf("%s", tmp_argv[i]);
	}
	else {
		for (int i = 0; i < argc; i++)
			strcpy(tmp_argv[i], argv[i]);
		tmp_argc = argc;
		
	}

	FILE *stu_list = NULL;
	struct Student *head = NULL;
	if (ana_list(stu_list, tmp_argv[2], &head) != OK)
		return 0;

	if (!strcmp(tmp_argv[1], "-checktitle") && tmp_argc == 4)
		Solve(head, tmp_argv[2], tmp_argv[3], _checkTitle);
	else if (!strcmp(tmp_argv[1], "-linecount") && tmp_argc == 4)
		Solve(head, tmp_argv[2], tmp_argv[3], _countLine);
	else if (!strcmp(tmp_argv[1], "-lineanalyse") && tmp_argc == 4)
		Solve(head, tmp_argv[2], tmp_argv[3], _analyseLine);
	else
		printf("�����ʽ����ȷ��\n");

	DeleteHead(&head);
	return 0;
}

#if defined(__linux) || defined(__linux__)

#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
using namespace std;

int main()
{
	DIR            *dir;
	struct dirent  *node;

	/* ��Linux�� /etc Ŀ¼ */
	if ((dir = opendir("/etc")) == NULL)
		return -1;

	/* ѭ��ɨ���Ŀ¼�µ������ļ� */
	while ((node = readdir(dir)) != NULL) {
		cout << node->d_name << endl;
	}//end of whileɨ��

	 /* �ر� /etc Ŀ¼ */
	closedir(dir);

	return 0;
}

#endif