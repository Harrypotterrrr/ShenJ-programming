/* 1651574 1�� ����� */
#include <iostream>
using namespace std;
int main()
{
	cout << "�����һ����������λ����������\n";
	int num, num_1, num_2, num_3, num_4, num_5;
	cin >> num;
	num_1 = num / 1 % 10;
	num_2 = num / 10 % 10;
	num_3 = num / 100 % 10;
	num_4 = num / 1000 % 10;
	num_5 = num / 10000 % 10;
	if (num_5)
	{
		cout << "5λ��\n"
			 << "��������Ϊ��\n" << num_5 << ' ' << num_4 << ' ' << num_3 << ' ' << num_2 << ' ' << num_1 << endl
		     << "��������Ϊ��\n" << num_1 << ' ' << num_2 << ' ' << num_3 << ' ' << num_4 << ' ' << num_5 << endl;
	}
	else if (num_4)
	{
		cout << "4λ��\n"
			 << "��������Ϊ��\n" << num_4 << ' ' << num_3 << ' ' << num_2 << ' ' << num_1 << endl
			 << "��������Ϊ��\n" << num_1 << ' ' << num_2 << ' ' << num_3 << ' ' << num_4 << endl;
	}
	else if (num_3)
	{
		cout << "3λ��\n"
			 << "��������Ϊ��\n" << num_3 << ' ' << num_2 << ' ' << num_1 << endl
			 << "��������Ϊ��\n" << num_1 << ' ' << num_2 << ' ' << num_3 << endl;
	}
	else if (num_2)
	{
		cout << "2λ��\n"
			 << "��������Ϊ��\n" << num_2 << ' ' << num_1 << endl
			 << "��������Ϊ��\n" << num_1 << ' ' << num_2 << endl;
	}
	else
	{
		cout << "1λ��\n"
			 << "��������Ϊ��\n" << num_1 << endl
			 << "��������Ϊ��\n" << num_1 << endl;
	}
	return 0;
}
