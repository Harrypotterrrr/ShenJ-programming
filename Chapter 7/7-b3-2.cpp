/*1651574 贾昊霖 1班*/
#include <iostream>
#include <fstream>
#include <cstring>
#define OK 1
#define Error 0
using namespace std;

typedef int Status;
struct student
{
	int no;
	char name[9];
	int score;
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
	head = new(nothrow) student;
	if (!head)
		return Error;
	student *q = head;
	q->next = NULL;

	while (fin >> no, no != 9999999) {
		student* p = new(nothrow) student;
		p->no = no;
		fin >> p->name;
		fin >> p->score;
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
		cout << p->no << " " << p->name << " " << p->score << endl;
		p = p->next;
	}
}

void DeleteList(Stulist head)
{
	student *p, *q;
	p = head;
	while (p != NULL) {
		q = p->next;
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