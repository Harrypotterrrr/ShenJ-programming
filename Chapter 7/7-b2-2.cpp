/*1651574 1班 贾昊霖*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student
{
	int num;
	int score;
	int rank;
	char name[9];
};

void swap(Student& a, Student& b) {
	Student tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	Student *head;
	ifstream fin;
	int n;
	fin.open("student.txt", ios::in);
	if (!fin.is_open()){
		cout << "打开文件失败" << endl;
		return -1;
	}
	fin >> n;
	head = new(nothrow) Student[n];
	if (head == NULL)
		return -1;

	for (int i = 0; i < n; i++){
		fin >> head[i].num >> head[i].name >> head[i].score;
		//insert sort
		for (int j = i; j > 0; j--)
			if (head[j].score > head[j - 1].score)
				swap(head[j], head[j - 1]);
			else if (head[j].score == head[j - 1].score)
				if (head[j].num < head[j - 1].num)
					swap(head[j], head[j - 1]);
	}

	head[0].rank = 1;
	for (int i = 1; i < n; i++){
		if (head[i].score == head[i - 1].score)
			head[i].rank = head[i - 1].rank;
		else
			head[i].rank = i + 1;
	}

	for (int i = 0; i < n; i++)
		cout << head[i].num << setw(10) << head[i].name << setw(4) << head[i].score << setw(4) << head[i].rank << endl;
	delete head;
	return 0;
}