/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>
#define OK 1
#define Error 0
using namespace std;
typedef int Status;
struct Student
{
	int num;
	char name[12];
	char school[10];
	struct Student *next;
};
typedef Student* Stulist;


Status input(ifstream &fin)
{
	fin.open("stulist.txt", ios::in);
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
		return Error;
	}
	return OK;
}

Status AppendList(Stulist& head, int& n,int& m)
{
	ifstream fin;
	input(fin);
	head = new Student;
	if (!head)
		return Error;
	Student *q = head;
	q->next = NULL;
	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		Student *p = new(nothrow)Student;
		if (!p)
			return Error;
		fin >> p->num >> p->name >> p->school;
		p->next = NULL;
		q->next = p;
		q = q->next;
	}
	fin.close();
	return OK;
}
void DeleteNode(Student *p, Student *q)
{
	q->next = p->next;
	delete p;
}

Status PrintList(Stulist& head, int& n, int& m)
{
	ofstream fout;
	fout.open("result.txt", ios::out);
	if (!fout.is_open()){
		cout << "打开输出文件失败" << endl;
		return Error;
	}
	srand(unsigned(time(0)));
	for (int i = 0; i < n; i++) {
		int t = rand() % (m-i) + 1;
		Student *p = head;
		for (int j = 0; j < t-1; j++)
			p = p->next;
		Student *q = p;
		p = p->next;
		fout << "第" << i + 1 <<setw(3)<< "个选中的人： ";
		fout << p->num << setw(13) << p->name << setw(11) << p->school << endl;
		DeleteNode(p, q);
	}
	
	fout.close();
	cout << "result.txt已生成" << endl;
	return OK;
}

void ReleaseList(Stulist& head)
{
	Student *p, *q;
	p = head;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
}

int main()
{
	Stulist head;
	int n, m;
	AppendList(head, n, m);
	PrintList(head, n, m);
	ReleaseList(head);
	return 0;
}