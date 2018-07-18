/*1651574 1班 贾昊霖*/
#include "90-b3.h"

int open_cfgfile(fstream &file, const char* filename, const int opt)
{
	if (opt == OPEN_OPT_RDWR)
		file.open(filename, ios::in | ios::out | ios::trunc);
	else if (opt == OPEN_OPT_RDONLY)
		file.open(filename, ios::in | ios::out | ios::_Nocreate);
	if(!file. is_open())
		return ERROR;
	return OK;
}

void close_cfgfile(fstream &file)
{
	file.close();
}

int file_length(fstream &fp)
{
	int file_len, now_pos;

	/* 当前为错误状态则返回-1 */
	if (fp.fail())
		return -1;

	/* 取fp当前指针位置 */
	now_pos = int(fp.tellg());

	/* 将文件指针移动到最后，此时tellp的结果就是文件大小 */
	fp.seekg(0, ios::end);
	file_len = int(fp.tellp());

	/* 指针移动回函数调用前的原位置 */
	fp.seekg(now_pos, ios::beg);

	return file_len;
}

int file_resize(const char *filename, fstream &fp, int newsize)
{
	int now_pos;

	/* 当前为错误状态则返回-1 */
	if (fp.fail())
		return -1;

	/* 取fp当前指针位置 */
	now_pos = int(fp.tellg());

	/* 如果大小是负数则直接返回-1 */
	if (newsize < 0)
		return -1;

	experimental::filesystem::resize_file(filename, newsize);

	/* 如果当前文件指针超过了文件大小，则回到文件头 */
	if (now_pos > newsize)
		fp.seekg(0, ios::beg);

	return 0;
}

bool  isBlankLine(const char *content)
{
	size_t len = strlen(content);
	for (size_t i = 0; i < len; i++) {
		if (content[i] != ' ' && content[i] != '\t' && content[i] != '\n')
			return false;
	}
	return true;
}

void DestroyLink(Text* &head)
{
	Text* p = head->next, *q;
	while (p) {
		delete p->content;
		q = p->next;
		delete p;
		p = q;
	}
	delete head;
}

int InsertText(Text *begin, Text *end, const char *item_char, const void *item_item_intue, const enum ITEM_TYPE item_type)
{
	Text *addLine = new(nothrow) Text;
	if (!addLine) {
		cerr << "内存不足\n";
		return ERROR;
	}
	begin->next = addLine;
	addLine->next = end;

	char tmp_line[300];
	ostrstream str(tmp_line, 300);
	//ostrstream str;

	if (item_type == TYPE_INT)
		str << *(int*)item_item_intue;
	else if (item_type == TYPE_DOUBLE)
		str << *(double*)item_item_intue;
	else if (item_type == TYPE_STRING)
		str << (char*)item_item_intue;
	else if (item_type == TYPE_CHARACTER)
		str << *(char*)item_item_intue;
	str << ends;//转化为字符串
	//str.write(tmp_line, strlen(tmp_line));

	addLine->content = new(nothrow) char[strlen(item_char) + strlen(tmp_line) + 2];
	if (addLine->content == NULL) {
		cerr << "内存不足\n";
		return ERROR;
	}
	strcpy(addLine->content, item_char);
	strcat(addLine->content, "=");
	strcat(addLine->content, tmp_line);
	return OK;
}

void PrintFile(fstream &file, const char *filename, Text *head)
{
	file.clear();
	file.seekp(0, ios::beg);
	Text *tail = head->next;
	bool flag = true;
	while (tail) {
		if (tail->content[0] == '[') {
			if (flag)
				flag = false;
			else
				file << endl;
		}
		file << tail->content << endl;
		tail = tail->next;
	}
	file << endl;
	int length = int(file.tellp());
	//int length2 = int(file.tellg());
	//cout << length <<endl<< length2 <<endl<< file_length(file)<<endl;
	experimental::filesystem::resize_file(filename, length);
}

Text* ScanFile(fstream &file)
{
	char tmp_line[300];
	int flag = 1;
	Text *head = new Text, *tail = head;
	head->next = NULL;
	while (!file.eof()) {
		file.getline(tmp_line, 300, '\n');
		if ( isBlankLine(tmp_line))
			continue;
		Text *p = new(nothrow) Text;
		if (!p) {
			cerr << "内存不足" << endl;
			DestroyLink(head);
			return NULL;
		}
		p->content = new(nothrow) char[strlen(tmp_line) + 1];
		if (!p->content) {
			cerr << "内存不足" << endl;
			DestroyLink(head);
			return NULL;
		}
		strcpy(p->content, tmp_line);

		tail->next = p;
		tail = tail->next;
	}
	tail->next = NULL;
	return head;
}

Text* FindGroup(Text* head, const char *property5)
{
	Text* p;
	for (p = head->next; p; p = p->next) {
		if (p->content[0] == '[' && p->content[strlen(p->content) - 1] == ']') {
			if (!strncmp(p->content + 1, property5, strlen(property5)))
				break;
		}
	}
	return p;
}

int group_del(fstream &file, const char *filename, const char *group_name)
{
	file.clear();
	file.seekg(0, ios::beg);
	Text *head = ScanFile(file);
	Text *p = FindGroup(head, group_name);
	if (!p) {
		DestroyLink(head);
		return ERROR;
	}

	Text* begin = head, *end;
	while (begin->next != p)
		begin = begin->next;
	end = begin->next;
	do {
		Text* tmp = end->next;
		delete end->content;
		delete end;
		end = tmp;
	} while (end && end->content[0] != '[');

	begin->next = end;

	PrintFile(file, filename, head);
	DestroyLink(head);
	return OK;
}

int group_add(fstream &file, const char *filename, const char *group_name)
{
	file.seekg(0, ios::beg);
	Text *head = ScanFile(file);
	Text *p = FindGroup(head, group_name);
	if (!p) {
		file.clear();
		file.seekp(0, ios::end);
		file << '[' << group_name << ']' << endl;
		experimental::filesystem::resize_file(filename, file_length(file));
		DestroyLink(head);
		return OK;
	}
	else {
		DestroyLink(head);
		return ERROR;
	}
}

int item_add(fstream &file, const char *filename, const char *group_name, const char *item_char, const void *item_item_intue, const enum ITEM_TYPE item_type)
{
	file.clear();
	file.seekg(0, ios::beg);
	Text *head = ScanFile(file);
	Text *p = FindGroup(head, group_name), *q;
	if (!p) {
		DestroyLink(head);
		return ERROR;
	}
	for (q = p->next; q && q->content[0] != '['; q = q->next) {
		char tmp_line[300], *pos;
		strcpy(tmp_line, q->content);
		pos = strchr(tmp_line, '=');
		if (!pos)
			continue;
		*pos = '\0';
		if (!strcmp(tmp_line, item_char)) {
			DestroyLink(head);
			return ERROR;
		}
	}
	while (p->next != q)
		p = p->next;

	if (InsertText(p, q, item_char, item_item_intue, item_type) == ERROR) {
		DestroyLink(head);
		return ERROR;
	}
	else {
		PrintFile(file, filename, head);
		DestroyLink(head);
		return OK;
	}
}

int item_del(fstream &file, const char* filename, const char *group_name, const char *item_char)
{
	file.clear();
	file.seekg(0, ios::beg);
	Text *head = ScanFile(file);
	Text *p = FindGroup(head, group_name), *q;
	if (!p) {
		DestroyLink(head);
		return ERROR;
	}
	for (q = p->next; q && q->content[0] != '['; q = q->next) {//found item
		char tmp_line[300], *pt;
		strcpy(tmp_line, q->content);
		pt = strchr(tmp_line, '=');
		if (pt == NULL)
			continue;
		*pt = '\0';
		if (!strcmp(tmp_line, item_char))
			break;
	}
	if (!q || q->content[0] == '[') {
		DestroyLink(head);
		return ERROR;
	}//not found

	for (; p->next != q; p = p->next)
		;
	p->next = q->next;
	delete q->content;
	delete q;
	PrintFile(file, filename, head);
	return OK;
}

int item_update(fstream &file, const char* filename, const char *group_name, const char *item_char, const void *item_item_intue, const enum ITEM_TYPE item_type)
{
	file.clear();
	file.seekg(0, ios::beg);
	Text *head = ScanFile(file);
	Text *p = FindGroup(head, group_name), *q;
	if (!p) {
		DestroyLink(head);
		return 0;
	}
	for (q = p->next; q && q->content[0] != '['; q = q->next) {
		char tmp_line[300], *pt;
		strcpy(tmp_line, q->content);
		pt = strchr(tmp_line, '=');
		if (!pt)
			continue;
		*pt = '\0';
		if (strcmp(tmp_line, item_char) == 0)
			break;
	}
	if (!q || q->content[0] == '[') {
		DestroyLink(head);
		return ERROR;
	}//not found
	Text *begin;
	for (begin = p; begin->next != q; begin = begin->next)
		;
	begin->next = q->next;	//delete q
	delete q->content;
	delete q;
	q = begin->next;

	if (InsertText(begin, q, item_char, item_item_intue, item_type) == ERROR) {
		DestroyLink(head);
		return ERROR;
	}
	else {
		PrintFile(file, filename, head);
		DestroyLink(head);
		return OK;
	}
}

int item_get_value(fstream &file, const char *filename, const char *group_name, const char *item_char, void *item_item_intue, const enum ITEM_TYPE item_type)
{
	file.clear();
	file.seekg(0, ios::beg);
	Text *head = ScanFile(file);
	Text *p = FindGroup(head, group_name), *q;
	if (!p) {
		DestroyLink(head);
		return 0;
	}
	char tmp_line[300], *pt;
	for (q = p->next; q && q->content[0] != '['; q = q->next) {
		strcpy(tmp_line, q->content);
		pt = strchr(tmp_line, '=');
		if (pt == NULL)
			continue;
		*pt = '\0';
		if (!strcmp(tmp_line, item_char))
			break;
	}
	if (!q || q->content[0] == '[') {
		DestroyLink(head);
		return 0;
	}
	char *begin = strchr(q->content, '=') + 1;
	 istrstream str(begin, int(strlen(begin) + 1));
	if (item_type == TYPE_INT)
		str >> *(int*)item_item_intue;
	else if (item_type == TYPE_DOUBLE)
		str >> *(double*)item_item_intue;
	else if (item_type == TYPE_STRING)
		str >> (char*)item_item_intue;
	else if (item_type == TYPE_CHARACTER)
		str >> *(char*)item_item_intue;
	DestroyLink(head);
	return 1;
}

int main()
{
	cout << "仿照上学期小作业做的...太忙没时间..以后有时间再补..\n";
	cout << "核心文件读写 UPDATE 工具以及链表的建立删除以及 UPDATE 全部完成\n";
	cout << "剩下涉及到90-b0 90-b1 90-b2 部分实在没时间读并 UPDATE 曾经的程序了..\n";
	cout << "C语言版涉及到fscanf与fprintf 以及与strstream 对应的sscanf与sprintf";
	cout << "等对应的函数也没时间改了..\n连着一周多3,4点睡了，等期中考试完再返回来补上吧\n";
	int resultTag;
	int item_int;
	double item_double;
	char item_char[80];
	fstream file;
	bool tag = open_cfgfile(file, filename, OPEN_OPT_RDWR);
	if (tag) {

		cout << "group_addtest：" << endl;
		resultTag = group_add(file, filename, "Group1");
		if (resultTag)
			cout << "add group" << "Group1" << " Success！" << endl;
		else
			cout << "add group" << "Group1" << " Fail！" << endl;
		resultTag = group_add(file, filename, "Group2");
		if (resultTag)
			cout << "add group" << "Group2" << " Success！" << endl;
		else
			cout << "add group" << "Group2" << " Fail！" << endl;
		cout << endl;


		cout << "item_addtest：" << endl;
		strcpy(item_char, "artillery");
		resultTag = item_add(file, filename, "Group2", "property1", item_char, TYPE_STRING);
		if (resultTag)
			cout << "Group2:" << "property1" << " ADD " << item_char << " Success！" << endl;
		else
			cout << "Group2:" << "property1" << " ADD " << item_char << " Fail！" << endl;
		strcpy(item_char, "123123123");
		resultTag = item_add(file, filename, "Group1", "property5", item_char, TYPE_STRING);
		if (resultTag)
			cout << "Group1:" << "property5" << " ADD " << item_char << " Success！" << endl;
		else
			cout << "Group1:" << "property5" << " ADD " << item_char << " Fail！" << endl;
		item_double = 1.33;
		resultTag = item_add(file, filename, "Group2", "property2", &item_double, TYPE_DOUBLE);
		if (resultTag)
			cout << "Group2:" << "property2" << " ADD " << item_double << " Success！" << endl;
		else
			cout << "Group2:" << "property2" << " ADD " << item_double << " Fail！" << endl;
		item_char[0] = 'Y';
		resultTag = item_add(file, filename, "Group2", "property3", item_char, TYPE_CHARACTER);
		if (resultTag)
			cout << "Group2" << "property3" << " ADD " << item_char[0] << " Success！" << endl;
		else
			cout << "Group2" << "property3" << " ADD " << item_char[0] << " Fail！" << endl;
		resultTag = item_add(file, filename, "Group2", "property4", NULL, TYPE_NULL);
		if (resultTag)
			cout << "Group2" << "property4" << " ADD " << "NULL" << " Success！" << endl;
		else
			cout << "Group2" << "property4" << " ADD " << "NULL" << " Fail！" << endl;
		cout << endl;
		item_char[0] = 'Y';
		resultTag = item_add(file, filename, "Group3", "property3", item_char, TYPE_CHARACTER);
		if (resultTag)
			cout << "Group3" << "property3" << " ADD " << item_char[0] << " Success！" << endl;
		else
			cout << "Group3" << "property3" << " ADD " << item_char[0] << " Fail！" << endl;
		cout << endl;


		cout << "item_updatetest：" << endl;
		item_int = 4;
		resultTag = item_update(file, filename, "Group1", "property5", &item_int, TYPE_INT);
		if (resultTag)
			cout << "Group1:" << "property5" << " UPDATE " << item_int << " Success！" << endl;
		else
			cout << "Group1:" << "property5" << " UPDATE " << item_int << " Fail！" << endl;
		strcpy(item_char, "property7");
		resultTag = item_update(file, filename, "Group2", "property1", item_char, TYPE_STRING);
		if (resultTag)
			cout << "Group2:" << "property1" << " UPDATE " << item_char << " Success！" << endl;
		else
			cout << "Group2:" << "property1" << " UPDATE " << item_char << " Fail！" << endl;
		resultTag = item_update(file, filename, "Group3", "property1", item_char, TYPE_STRING);
		if (resultTag)
			cout << "Group3:" << "property1" << " UPDATE " << item_char << " Success！" << endl;
		else
			cout << "Group3:" << "property1" << " UPDATE " << item_char << " Fail！" << endl;
		cout << endl;


		cout << "item_get_valuetest：" << endl;
		item_int = 0;
		resultTag = item_get_value(file, filename, "Group1", "property5", &item_int, TYPE_INT);
		if (resultTag)
			cout << "Group1:" << "property5" << " is " << item_int << endl;
		else
			cout << "Group1:" << "property5" << " is Fail！" << endl;
		item_int = 0;
		resultTag = item_get_value(file, filename, "Group1", "property5", &item_int, TYPE_NULL);
		if (resultTag)
			if (item_int == 0)
				cout << "property5 exists, but argument is null" << endl;
			else
				cout << " Fail!" << endl;
		else
			cout << "Group1:" << "property5" << " is Fail !" << endl;
		item_double = 0;
		resultTag = item_get_value(file, filename, "Group6", "property6", &item_double, TYPE_DOUBLE);
		if (resultTag)
			cout << "Group6:" << "property6" << " is " << item_double << endl;
		else
			cout << "Group6:" << "property6" << " is Fail！" << endl;
		item_char[0] = '\0';
		resultTag = item_get_value(file, filename, "Group2", "property1", item_char, TYPE_STRING);
		if (resultTag)
			cout << "Group2:" << "property1" << " is " << item_char << endl;
		else
			cout << "Group2:" << "property1" << " iS Fail！" << endl;
		item_char[0] = '\0';
		resultTag = item_get_value(file, filename, "Group2", "property3", item_char, TYPE_CHARACTER);
		if (resultTag)
			cout << "Group2:" << "property3" << " is " << item_char[0] << endl;
		else
			cout << "Group2:" << "property3" << " is Fail！" << endl;
		item_double = 0;
		resultTag = item_get_value(file, filename, "Group2", "property2", &item_double, TYPE_DOUBLE);
		if (resultTag)
			cout << "Group2:" << "property2" << " is " << item_int << endl;
		else
			cout << "Group2:" << "property2" << " is Fail !" << endl;
		cout << endl;



		cout << "group_deltest：" << endl;
		resultTag = group_del(file, filename, "Group1");
		if (resultTag)
			cout << "delete group" << "Group1" << " Success！" << endl;
		else
			cout << "delete group" << "Group1" << " Fail！" << endl;
		resultTag = group_del(file, filename, "Group3");
		if (resultTag)
			cout << "delete group" << "Group3" << " Success！" << endl;
		else
			cout << "delete group" << "Group3" << " Fail！" << endl;
		cout << endl;



		cout << "item_deltest：" << endl;
		resultTag = item_del(file, filename, "Group6", "property4");
		if (resultTag)
			cout << "delete " << "property4" << " Success！" << endl;
		else
			cout << "delete " << "property4" << " Fail！" << endl;
		resultTag = item_del(file, filename, "Group2", "property3");
		if (resultTag)
			cout << "delete " << "property3" << " Success！" << endl;
		else
			cout << "delete " << "property2" << " Fail！" << endl;
		resultTag = item_del(file, filename, "Group2", "property4");
		if (resultTag)
			cout << "delete " << "property4" << " Success！" << endl;
		else
			cout << "delete " << "property4" << " Fail！" << endl;
		cout << endl;

		close_cfgfile(file);
	}
	return 0;
}