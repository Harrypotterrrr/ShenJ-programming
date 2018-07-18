/* 1�� ����� 1651574 */
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
				cout << "2�����ϲ������ѧ����\n";
			}
			cout << "No." << i + 1 << " ";
			for (int(*p)[4] = Grade; p < Grade + 5; p++)
				cout << *(*p + i) << " ";
			cout << "ƽ����" << sum / 5;
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
				cout << "ƽ��90���ϻ�ȫ��85���ϵ�ѧ��\n";
			}
			cout << "No." << i + 1 << " ";
			for (int(*p)[4] = Grade; p < Grade + 5; p++)
				cout << *(*p + i) << " ";
			cout << "ƽ����" << average;
			putchar('\n');
		}
	}
}

int main()
{
	int Grade[5][4] = { { 91,92,93,97 },  //��1-4��ѧ���ĵ�1�ſγɼ�
						{ 81,82,83,85 },  //��1-4��ѧ���ĵ�2�ſγɼ�
						{ 71,72,99,87 },  //��1-4��ѧ���ĵ�3�ſγɼ�
						{ 61,32,80,91 },  //��1-4��ѧ���ĵ�4�ſγɼ�
						{ 51,52,95,88 } };//��1-4��ѧ���ĵ�5�ſγɼ�
	cout << "��ʼ��Ϣ:\n";
	for (int i = 0; i < 5; i++) {
		cout << "No.1-4ѧ���ĵ�" << i + 1 << "�ſεĳɼ���";
		for (int *p = *(Grade + i); p < *(Grade + i) + 4; p++)
			cout << *p << " ";
		putchar('\n');
	}
	putchar('\n');
	cout << "��1�ſ�ƽ���֣�" << Average(Grade) << endl;
	putchar('\n');
	FindFail(Grade);
	putchar('\n');
	SearchExcellent(Grade);
	return 0;
}