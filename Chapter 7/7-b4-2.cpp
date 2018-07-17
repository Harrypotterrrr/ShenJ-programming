/*1651574 贾昊霖 1班*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#define OK 1
#define Error 0
using namespace std;

typedef int Status;
struct student
{
	int *no;
	char *name;
	int *score;
	struct student *next;
};
typedef student* Stulist;

Status input(ifstream &fin)
{
	fin.open("list.txt", ios::in);
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
		return Error;
	}
	return OK;
}

Status AppendList(Stulist& head, ifstream& fin)
{
	int no;
	char name[12];
	head = new student;
	head->name = new char;
	head->no = new int;
	head->score = new int;
	if (!head)
		return Error;
	student *q = head;
	q->next = NULL;
	while (fin >> no, no != 9999999) {
		student* p = new(nothrow) student;
		p->no = new int;
		if (!p->no)
			return Error;
		*(p->no) = no;
		fin >> name;
		p->name = new char[strlen(name) + 1];
		if (!p->name)
			return Error;
		strcpy(p->name, name);
		p->score = new int;
		if (!p->score)
			return Error;
		fin >> *(p->score);
		p->next = NULL;

		q->next = p;
		q = q->next;
	}
	fin.close();
	return OK;
}

void PrintList(Stulist head)
{
	student *p = head->next;
	while (p != NULL) {
		cout << *(p->no) << " " << p->name << " " << *(p->score) << endl;
		p = p->next;
	}
}

void DeleteList(Stulist head)
{
	student *p, *q;
	p = head;
	while (p != NULL) {
		q = p->next;
		delete p->name;
		delete p->no;
		delete p->score;
		delete p;
		p = q;
	}
}

int main()
{
	Stulist head = NULL;
	ifstream fin;

	if (!input(fin))
		return Error;

	if (!AppendList(head, fin))
		return Error;
	PrintList(head);
	DeleteList(head);

	return 0;
}