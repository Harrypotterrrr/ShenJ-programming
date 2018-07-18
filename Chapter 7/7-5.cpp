/* 1651574 贾昊霖 1班*/
#include<iostream>
#include<iomanip>
#include <cstring>
#include<cmath>
#define N 10
using namespace std;

struct Student
{
	int no;
	char name[9];
	float score[3];
	float var;
};

void input(Student st[N])
{
	int i, j;
	for (i = 0; i < N; i++) {
		cout << "请输入第" << setw(2) << i + 1 << "个学生的信息：";
		cin >> st[i].no >> st[i].name;
		for (j = 0; j < 3; j++)
			cin >> st[i].score[j];
	}
}

void output_var(Student st[N])
{
	int i;
	cout << "10个同学的平均成绩依次为：" << endl;
	cout << setiosflags(ios::left) << setw(4) << "序号" << " "
		<< setw(8) << "学号" << " "
		<< setw(8) << "姓名" << " "
		<< setw(15) << "三门课成绩"
		<< "平均成绩\n";
	cout << "===========================================\n";
	for (i = 0; i < N; i++)
		
	cout << endl;
}

float cal(Student st[N])
{
	float max = 0, temp;
	for (int i = 0; i < N; i++) {
		temp = 0;
		for (int j = 0; j < 3; j++)
			temp += st[i].score[j];
		st[i].var = temp / 3;
		if (st[i].var > max)
			max = st[i].var;
	}
	return max;
}

void output_max(Student st[N], float max)
{
	cout << "最高分学生为：" << endl;
	cout << setiosflags(ios::left) << setw(4) << "序号" << " "
		<< setw(8) << "学号" << " "
		<< setw(8) << "姓名" << " "
		<< setw(15) << "三门课成绩"
		<< "平均成绩\n";
	cout << "===========================================\n";
	for (int i = 0; i < N; i++)
		if (fabs(st[i].var - max) < 10e-4)
			cout << resetiosflags(ios::fixed) << setprecision(0)
			<< setw(4) << i + 1 << " "
			<< setiosflags(ios::left) << setw(8) << st[i].no << " "
			<< setw(8) << st[i].name << " "
			<< setw(4) << st[i].score[0] << " "
			<< setw(4) << st[i].score[1] << " "
			<< setw(4) << st[i].score[2] << " "
			<< setiosflags(ios::fixed) << setprecision(2) << setw(4) << st[i].var << endl;
}

int main()
{
	Student st[N];
	float max;

	input(st);
	max = cal(st);

	output_var(st);
	output_max(st, max);

	return 0;
}
