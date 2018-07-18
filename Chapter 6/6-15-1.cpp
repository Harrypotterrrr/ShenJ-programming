/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1-8
using namespace std;
double Average(int (*Grade)[5])
{
	double sum = 0;
	for (int(*p)[5] = Grade; p < Grade + 4; p++)
		sum += **p;
	return sum / 4;
}
void FindFail(int(*Grade)[5])
{
	double sum;
	int num;
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		sum = num = 0;
		for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++) {
			sum += *p;
			if (*p < 60)
				num++;
		}
		if (num > 1) {
			if (!flag) {
				flag = true;
				cout << "2门以上不及格的学生：\n";
			}
			cout << "No." << i + 1<<" ";
			for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++)
				cout << *p << " ";
			cout << "平均：" << sum / 5;
			putchar('\n');
		}
	}
}

void SearchExcellent(int(*Grade)[5])
{
	double sum, average;
	int num;
	bool flag = false, tag = false;
	for (int i = 0; i < 4; i++) {
		sum = num = 0;
		for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++) {
			sum += *p;
			if (*p < 85)
				tag = true;
		}
		average = sum / 5;
		if (average > 85 || !tag) {
			if (!flag) {
				flag = true;
				cout << "平均90以上或全部85以上的学生\n";
			}
			cout << "No." << i + 1 << " ";
			for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++)
				cout << *p << " ";
			cout << "平均：" << average;
			putchar('\n');
		}
	}
}

int main()
{
	int Grade[4][5] = { { 91, 81, 71, 61, 51 },	//第1个学生的1-5门课的成绩
						{ 92, 82, 72, 32, 52 },		//第2个学生的1-5门课的成绩
						{ 93, 83, 99, 80, 95 },		//第3个学生的1-5门课的成绩
						{ 97, 85, 87, 91, 88 } };	//第4个学生的1-5门课的成绩	
	cout << "初始信息:\n";
	for (int i = 0; i < 4; i++) {
		cout << "No." << i + 1 << "的1-5门课成绩：";
		for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++)
			cout << *p << " ";
		putchar('\n');
	}
	putchar('\n');
	cout << "第1门课平均分："<<Average(Grade)<<endl;
	putchar('\n');
	FindFail(Grade);
	putchar('\n');
	SearchExcellent(Grade);
	return 0;
}