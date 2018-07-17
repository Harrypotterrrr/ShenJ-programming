/*1651574 1班 贾昊霖*/
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

struct Student {
	char no[10];
	char name[10];
	int cls;
	struct Student* next;
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

void PrintResult(ErrorInfo err_num, struct Student *stu, char *file_name)
{
	printf("%s的%s结果：\n",stu->name,file_name);
	if (err_num & (1 << 5))
		printf("该学生的作业未提交\n");
	else if (err_num & (1 << 0))
		printf("未获取到首行信息！\n");
	else if (err_num & (1 << 1))
		printf("首行信息不全！\n");
	else if (err_num) {
		if (err_num & (1 << 2))
			printf("学号不匹配\n");
		if (err_num & (1 << 3))
			printf("姓名不匹配\n");
		if (err_num & (1 << 4))
			printf("班级不匹配\n");
	}
	else
		printf("通过\n");

	printf("=========================\n");
}

void ana_class(char *str, int *cls)
{
	if (strstr(str, "1班") || strstr(str, "一") || strstr(str, "计1"))
		*cls = 1;
	else if (strstr(str, "2班") || strstr(str, "二") || strstr(str, "计2"))
		*cls = 2;
	else if (strstr(str, "3班") || strstr(str, "三") || strstr(str, "计3"))
		*cls = 3;
	else if (strstr(str, "数强") || strstr(str, "数理强化"))
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

void Check(struct Student *head, char *class_no, char *order)
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
					if (!fin)
						err_num = err_num | (1 << 5);
					else
						CheckTitle(p, fin, &err_num);
					PrintResult(err_num, p, file_name);
					fclose(fin);
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
				/* 循环扫描该目录下的所有文件 */
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
		}//end of while扫描
				closedir(dir);
				/* 关闭 /etc 目录 */

#endif

		}
		else if(strstr(order, suffix[0]) || strstr(order, suffix[1]) || strstr(order, suffix[2])){
			strcat(file_person, order);
			fin = fopen(file_person, "r");
			if (!fin)
				err_num = err_num | (1 << 5);
			else
				CheckTitle(p, fin, &err_num);
			PrintResult(err_num, p, order);
			fclose(fin);
		}
		else {
			printf("不是源程序文件！\n");
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
		printf("输入的课程有误，该课程不存在！\n");
		return ERROR;
	}

	*head = (struct Student*)malloc(sizeof(struct Student));
	if (!head) {
		printf("内存不足！\n");
		fclose(fin);
		return ERROR;
	}
	(*head)->next = NULL;

	struct Student *p;
	char tmp[10], no_use[10];

	while (!feof(fin)) {
		p = (struct Student*)malloc(sizeof(struct Student));
		if (!p) {
			printf("内存不足!\n");
			fclose(fin);
			return ERROR;
		}
		fscanf(fin, "%s%s%s%s", p->no, p->name, tmp, no_use);
		ana_class(tmp, &p->cls);
		if (!p->cls) {
			printf("数据库出错了..哥\n");
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
		scanf("%s", tmp_argv[0]);
		if (!strcmp(tmp_argv[0], "-checktitle"))
			tmp_argc = 3;
		else {
			printf("命令错误!\n");
			return 0;
		}
		for (int i = 1; i < tmp_argc; i++)
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
		Check(head, tmp_argv[2], tmp_argv[3]);
	else
		printf("命令格式不正确！\n");

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

	/* 打开Linux的 /etc 目录 */
	if ((dir = opendir("/etc")) == NULL)
		return -1;

	/* 循环扫描该目录下的所有文件 */
	while ((node = readdir(dir)) != NULL) {
		cout << node->d_name << endl;
	}//end of while扫描

	 /* 关闭 /etc 目录 */
	closedir(dir);

	return 0;
}

#endif