/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	void PrintNum(int);
	void PrintSelect(int);

	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	cout << "����һ��0~100�ڵĸ�������" << endl;
	cin >> a;
	a1 = int(a / 10) % 10;
	a2 = int(a / 100) % 10;
	a3 = int(a / 1000) % 10;
	a4 = int(a / 10000) % 10;
	a5 = int(a / 100000) % 10;
	a6 = int(a / 1000000) % 10;
	a7 = int(a / 10000000) % 10;
	a8 = int(a / 100000000) % 10;
	a9 = int(a / 1000000000) % 10;
	temp = a - 1000000000. * a9 - 100000000. * \
		a8 - 10000000. * a7 - 1000000. * a6 - \
		100000. * a5 - 10000. * a4 - 1000. * a3 \
		- 100. * a2 - 10. * a1;
	a0 = int(temp);		//�������� ����λ
	temp2 = temp - a0;	//С������
	temp2 += 0.005;
	a_1 = int(floor(temp2 * 10));
	a_2 = int(floor(temp2 * 100)) % 10;//�ϴ���ҵ�����Բ���..д���е�����.....
	cout << "��д����ǣ�\n";
	if (!(a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0 + a_1 + a_2)) {
		cout << "��Բ��\n";
		return 0;
	}
	//==============ʮ��==============//
	PrintSelect(a9);
	if (a9)
		cout << "ʰ";
	//==============��==============//
	if (a8 == 0 && a9 != 0)
		cout << "��";
	else if (a8)
		PrintSelect(a8);
	if (a8)
		cout << "��";
	//==============ǧ��==============//
	if (a7 == 0 && (a9 + a8) && (a6 + a5 + a4))
		PrintNum(0);
	else if (a7) {
		PrintSelect(a7);
		cout << "Ǫ";
	}
	//==============����==============//
	if (a6 == 0 && a7 && (a4 + a5))
		PrintNum(0);
	else if (a6) {
		PrintSelect(a6);
		cout << "��";
	}
	//==============ʮ��==============//
	if (a5 == 0 && a6 && a4)
		PrintNum(0);
	else if (a5) {
		PrintSelect(a5);
		cout << "ʰ";
	}
	//==============��==============//
	if (a4 == 0 && (a7 + a6 + a5))
		cout << "��";
	else if (a4) {
		PrintSelect(a4);
		cout << "��";
	}
	//==============ǧ==============//
	if (a3 == 0 && (a9 + a8 + a7 + a6 + a5 + a4) && (a2 + a1 + a0))
		PrintNum(0);
	else if (a3) {
		PrintSelect(a3);
		cout << "Ǫ";
	}
	//==============��==============//
	if (a2 == 0 && a3 && (a1 + a0))
		PrintNum(0);
	else if (a2) {
		PrintSelect(a2);
		cout << "��";
	}
	//==============ʮ==============//
	if (a1 == 0 && a2 && a0)
		PrintNum(0);
	else if (a1) {
		PrintSelect(a1);
		cout << "ʰ";
	}
	//==============��==============//
	if (a0 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1))
		cout << "Բ";
	else if (a0) {
		PrintSelect(a0);
		cout << "Բ";
	}
	if (!a_1 && !a_2) {
		cout << "��\n";
		return 0;
	}
	//=============��==============//
	if (a_1 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0))
		PrintNum(0);
	else if(a_1){
		PrintSelect(a_1);
		cout << "��";
	}
	//=============��==============//	
	if (a_2 == 0)
		cout << "��\n";
	else {
		PrintSelect(a_2);
		cout << "��\n";
	}
	return 0;
}
void PrintNum(int n)
{
	switch (n) {
		case(1):
			cout << "Ҽ";
			break;
		case(2):
			cout << "��";
			break;
		case(3):
			cout << "��";
			break;
		case(4):
			cout << "��";
			break;
		case(5):
			cout << "��";
			break;
		case(6):
			cout << "½";
			break;
		case(7):
			cout << "��";
			break;
		case(8):
			cout << "��";
			break;
		case(9):
			cout << "��";
			break;
		default:
			cout << "��";
	}
}
void PrintSelect(int x)
{
	if (x == 1)
		PrintNum(1);
	else if (x == 2)
		PrintNum(2);
	else if (x == 3)
		PrintNum(3);
	else if (x == 4)
		PrintNum(4);
	else if (x == 5)
		PrintNum(5);
	else if (x == 6)
		PrintNum(6);
	else if (x == 7)
		PrintNum(7);
	else if (x == 8)
		PrintNum(8);
	else if (x == 9)
		PrintNum(9);
}