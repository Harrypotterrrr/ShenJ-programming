/* 1�� ����� 1651574 */
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
				cout << "2�����ϲ������ѧ����\n";
			}
			cout << "No." << i + 1<<" ";
			for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++)
				cout << *p << " ";
			cout << "ƽ����" << sum / 5;
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
				cout << "ƽ��90���ϻ�ȫ��85���ϵ�ѧ��\n";
			}
			cout << "No." << i + 1 << " ";
			for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++)
				cout << *p << " ";
			cout << "ƽ����" << average;
			putchar('\n');
		}
	}
}

int main()
{
	int Grade[4][5] = { { 91, 81, 71, 61, 51 },	//��1��ѧ����1-5�ſεĳɼ�
						{ 92, 82, 72, 32, 52 },		//��2��ѧ����1-5�ſεĳɼ�
						{ 93, 83, 99, 80, 95 },		//��3��ѧ����1-5�ſεĳɼ�
						{ 97, 85, 87, 91, 88 } };	//��4��ѧ����1-5�ſεĳɼ�	
	cout << "��ʼ��Ϣ:\n";
	for (int i = 0; i < 4; i++) {
		cout << "No." << i + 1 << "��1-5�ſγɼ���";
		for (int *p = *(Grade + i); p < *(Grade + i) + 5; p++)
			cout << *p << " ";
		putchar('\n');
	}
	putchar('\n');
	cout << "��1�ſ�ƽ���֣�"<<Average(Grade)<<endl;
	putchar('\n');
	FindFail(Grade);
	putchar('\n');
	SearchExcellent(Grade);
	return 0;
}