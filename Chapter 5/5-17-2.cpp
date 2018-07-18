/*1班 贾昊霖 1651574*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include <cmath>
#define MAX_NUM 1000
#define MAX_LENGTH 15
#define N 10
using namespace std;

int main()
{
	string name[MAX_NUM];
	string num[MAX_NUM];
	int grade[MAX_LENGTH];
	for (int i = 0; i < N; i++) {
		while (true) {
			cout << "请输入第" << i + 1 << "个人的姓名、学号、成绩\n";
			cin >> name[i] >> num[i] >> grade[i];
			if (cin.good())
				break;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	cout << "不及格名单\n";
	for (int i = 0; i < N; i++) {
		if (grade[i] < 60) {
			cout << name[i] << " "
				<< num[i] << " "
				<< grade[i] << endl;
		}
	}
	return 0;
}
