/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1-8
using namespace std;
double Average(int(*Grade)[4])
{
	double sum = 0;
	for (int *p = *Grade + 0; p < *Grade + 4; p++)
		sum += *p;
	return sum / 4;
}
void FindFail(int(*Grade)[4])
{
	double sum;
	int num;
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		sum = num = 0;
		for (int(*p)[4] = Grade; p < Grade + 5; p++) {
			sum += *(*p + i);
			if (*(*p + i) < 60)
				num++;
		}
		if (num > 1) {
			if (!flag) {
				flag = true;
				cout << "2门以上不及格的学生：\n";
			}
			cout << "No." << i + 1 << " ";
			for (int(*p)[4] = Grade; p < Grade + 5; p++)
				cout << *(*p + i) << " ";
			cout << "平均：" << sum / 5;
			putchar('\n');
		}
	}
}

void SearchExcellent(int(*Grade)[4])
{
	double sum, average;
	int num;
	bool flag = false, tag = false;
	for (int i = 0; i < 4; i++) {
		sum = num = 0;
		for (int(*p)[4] = Grade; p < Grade + 5; p++) {
			sum += *(*p + i);
			if (*(*p + i) < 85)
				tag = true;
		}
		average = sum / 5;
		if (average > 85 || !tag) {
			if (!flag) {
				flag = true;
				cout << "平均90以上或全部85以上的学生\n";
			}
			cout << "No." << i + 1 << " ";
			for (int(*p)[4] = Grade; p < Grade + 5; p++)
				cout << *(*p + i) << " ";
			cout << "平均：" << average;
			putchar('\n');
		}
	}
}

int main()
{
	int Grade[5][4] = { { 91,92,93,97 },  //第1-4个学生的第1门课成绩
						{ 81,82,83,85 },  //第1-4个学生的第2门课成绩
						{ 71,72,99,87 },  //第1-4个学生的第3门课成绩
						{ 61,32,80,91 },  //第1-4个学生的第4门课成绩
						{ 51,52,95,88 } };//第1-4个学生的第5门课成绩
	cout << "初始信息:\n";
	for (int i = 0; i < 5; i++) {
		cout << "No.1-4学生的第" << i + 1 << "门课的成绩：";
		for (int *p = *(Grade + i); p < *(Grade + i) + 4; p++)
			cout << *p << " ";
		putchar('\n');
	}
	putchar('\n');
	cout << "第1门课平均分：" << Average(Grade) << endl;
	putchar('\n');
	FindFail(Grade);
	putchar('\n');
	SearchExcellent(Grade);
	return 0;
}