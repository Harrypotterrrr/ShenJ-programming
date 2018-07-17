/*1651574 1班 贾昊霖*/
#if defined(_MSC_VER)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <strstream>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <io.h>

#elif defined(__linux) || defined(__linux__)

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
using namespace std;
const char suffix[3][6] = { ".cpp",".c",".h" };
enum OrderType {_checkTitle, _countLine, _analyseLine};

struct Student {
	char no[10];
	char name[10];
	int cls;
	Student* next;
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
	FileDetail file_detail;
};

void DeleteHead(Student *&head)
{
	Student *p = head;
	while (p) {
		head = head->next;
		delete p;
		p = head;
	}
}

void PrintResult(ErrorInfo err_num, Student *stu, char *file_name, int tag = _checkTitle, FileInfo *info = NULL)
{
	cout << stu->name << " : " << file_name << " : ";
	if (err_num & (1 << 5)) {
		cout << "未提交\n";
		return;
	}
	if (tag == _checkTitle) {
		if (err_num & (1 << 0))
			cout << "未获取到首行信息！\n";
		else if (err_num & (1 << 1))
			cout << "首行信息不全！\n";
		else if (err_num) {
			if (err_num & (1 << 2))
				cout << "学号不匹配 ";
			if (err_num & (1 << 3))
				cout << "姓名不匹配 ";
			if (err_num & (1 << 4))
				cout << "班级不匹配";
			putchar('\n');
		}
		else
			cout << "通过\n";
	}
	else if(tag == _countLine)
		cout << "共" << info->line_num << "行\n";
	else if(tag == _analyseLine){
		cout << "有效行-" << info->file_detail.line_valid << " "
			<< "纯注释行-" << info->file_detail.line_purecomment << " "
			<< "注释行-" << info->file_detail.line_comment << " "
			<< "有效字符-" << info->file_detail.char_valid << " "
			<< "注释字符-" << info->file_detail.char_comment << " "
			<< "比例-" << setprecision(4) << info->file_detail.ratio * 100 << "%\n";
	}
	//cout << "=========================\n";
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

ErrorInfo JudgeTitle(ifstream *fin, ErrorInfo *err_num, char(*info)[25])
{
	char str[64], *p, *q, c;

	while ((c = fin->peek()) == '\n' || (c = fin->peek()) == '\t' || (c = fin->peek()) == ' ')
		fin->ignore();
	fin->getline(str, 64);

	//int len;
	//len = strlen(str);
	//for (i = 0; len > 4 && i < len; i++)		//attention to  useless 4...
	//	if (str[i] != ' ' && str[i] != '\t')
	//		break;

	if (fin->eof() || str[0] != '/' || (str[0] != '/' && str[1] != '*')) {
		*err_num = *err_num | (1 << 0);
		return ERROR;
	}
	if (str[1] == '*' && !(q = strstr(str, "*/"))) {
		*err_num = *err_num | (1 << 0);
		return ERROR;
	}
	p = str + 2;
	if (str[1] == '*')
		q = p + strlen(str) - 4;
	else
		q = p + strlen(str) - 2;
	istrstream line(p, int(q - p));

	for (int i = 0; i < 3; i++) {
		if (!(line >> info[i])) {
			*err_num = *err_num | (1 << 1);
			return ERROR;
		}
	}
	return OK;
}

void CheckTitle(Student *student, ifstream *fin, ErrorInfo *err_num)
{
	Student test = { "","",0,NULL };
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

FileInfo LineAnalyse(ifstream *fin)
{
	enum CommentSign { Norm, DoubleLineSign, LineStarSign };
	FileInfo fileAnalyseLine;
	FileInfo &f = fileAnalyseLine;
	f.file_detail = { 0,0,0,0,0 };
	char tmp_line[300];
	int len, i;
	int flag_comment = Norm; //	stack/**/
	for (f.file_detail.line_valid = 0; !fin->eof(); f.file_detail.line_valid++) {
		fin->getline(tmp_line, 300, '\n');
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
			f.file_detail.line_valid--;
		else {
			for (int j = 0; j < len; j++) {
				if (j < len - 1 && tmp_line[j] == '/' && tmp_line[j + 1] == '/') {
					if (j == 0)
						f.file_detail.line_purecomment++;
					f.file_detail.line_comment++;
					flag_comment = DoubleLineSign;
				}
				else if (j < len - 1 && tmp_line[j] == '/' && tmp_line[j + 1] == '*') {
					f.file_detail.line_comment++;
					f.file_detail.char_comment += 4;
					// default a pair of comment sign, so there is no syntax error
					flag_comment = LineStarSign;
					j++;
				}
				else if (flag_comment != Norm && j < len - 1 && tmp_line[j] == '*' && tmp_line[j + 1] == '/') {
					if (j == len - 2)
						f.file_detail.line_purecomment++;
					flag_comment = Norm;
				}
				else if (tmp_line[j] != ' ' && tmp_line[j] != '\n' && tmp_line[j] != '\t') {
					if (flag_comment)
						f.file_detail.char_comment++;
					else
						f.file_detail.char_valid++;
				}
			}
			if (flag_comment == DoubleLineSign)
				flag_comment = Norm;
		}
	}

	f.file_detail.ratio = double(f.file_detail.char_valid) / \
		(f.file_detail.char_valid + f.file_detail.char_comment);
	return f;
}

int CountLine(ifstream *fin)
{
	char tmp_line[300];
	int ctr;
	for (ctr = 0; !fin->eof(); ctr++)
		fin->getline(tmp_line, 300, '\n');
	return ctr;
}

void Solve(Student *head, char *class_no, char *order, int tag)
{
	ifstream fin;
	ErrorInfo err_num;
	char file_route[64] = "source\\";
	char file_person[64];

	strcat(file_route, class_no);

	for (Student* p = head->next; p; p = p->next) {
		err_num = 0;
		strcpy(file_person, file_route);
		strcat(file_person, "-");
		strcat(file_person, p->no);
		strcat(file_person, "\\");

		if (!strcmp(order, "all")) {

#if defined(_MSC_VER)

			_finddata_t fileinfo;
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
					fin.open(file_each, ios::in);
					FileInfo file_info;
					if (!fin.is_open())
						err_num = err_num | (1 << 5);
					else {
						if (tag == _checkTitle)
							CheckTitle(p, &fin, &err_num);
						else if (tag == _countLine)
							file_info.line_num = CountLine(&fin);
						else if (tag == _analyseLine)
							file_info = LineAnalyse(&fin);
						fin.close();
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
			fin.open(file_person, ios::in);
			FileInfo file_info;
			if (!fin.is_open())
				err_num = err_num | (1 << 5);
			else {
				if (tag == _checkTitle)
					CheckTitle(p, &fin, &err_num);
				else if (tag == _countLine)
					file_info.line_num = CountLine(&fin);
				else if (tag == _analyseLine)
					file_info = LineAnalyse(&fin);
				fin.close();
			}
			PrintResult(err_num, p, order, tag, &file_info);
		}
		else {
			cout << "不是源程序文件！\n";
			break;
		}
	}
}

ErrorInfo GetMain(fstream *file)
{
	char line[320];
	do {
		file->getline(line, 320);
		if (strstr(line, "int main()"))
			break;
	} while (!file->eof());
	if (file->eof())
		return ERROR;
	return OK;
}

ErrorInfo ana_list(ifstream *fin, const char *argv, Student *&head)
{
	char route[40] = "source\\";
	strcat(route, argv);
	strcat(route, ".dat\0");
	fin->open(route, ios::in);
	if (!fin->is_open()) {
		cout << "输入的课程有误，该课程不存在！\n";
		return ERROR;
	}

	head = new(nothrow) Student;
	if (!head) {
		cout << "内存不足！\n";
		fin->close();
		return ERROR;
	}
	head->next = NULL;

	Student *p;
	char tmp[10], no_use[10];
	while (!fin->eof()) {
		p = new(nothrow)Student;
		if (!p) {
			cout << "内存不足！\n";
			fin->close();
			return ERROR;
		}
		*fin >> p->no >> p->name >> tmp >> no_use;
		ana_class(tmp, &p->cls);
		if (!p->cls) {
			cout << "数据库出错了..哥\n";
			fin->close();
			return ERROR;
		}
		p->next = head->next;
		head->next = p;
	}
	return OK;
}

int main(int argc, char**argv)
{
	char tmp_argv[4][50];
	int tmp_argc;

	if (argc == 1) {
		cin >> tmp_argv[1];
		if (!strcmp(tmp_argv[1], "-checktitle"))
			tmp_argc = 4;
		else if (!strcmp(tmp_argv[1], "-linecount"))
			tmp_argc = 4;
		else if (!strcmp(tmp_argv[1], "-lineanalyse"))
			tmp_argc = 4;
		else {
			cout << "命令错误！\n";
			return 0;
		}
		for (int i = 2; i < tmp_argc; i++)
			cin >> tmp_argv[i];
	}
	else {
		for (int i = 0; i < argc; i++)
			strcpy(tmp_argv[i], argv[i]);
		tmp_argc = argc;
		
	}
	ifstream stu_list;
	Student *head = NULL;
	if (ana_list(&stu_list, tmp_argv[2], head) != OK)
		return 0;

	if (!strcmp(tmp_argv[1], "-checktitle") && tmp_argc == 4)
		Solve(head, tmp_argv[2], tmp_argv[3], _checkTitle);
	else if (!strcmp(tmp_argv[1], "-linecount") && tmp_argc == 4)
		Solve(head, tmp_argv[2], tmp_argv[3], _countLine);
	else if (!strcmp(tmp_argv[1], "-lineanalyse") && tmp_argc == 4)
		Solve(head, tmp_argv[2], tmp_argv[3], _analyseLine);
	else
		cout << "命令格式不正确！\n";

	DeleteHead(head);
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