/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
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
	if (a9 == 1)
		cout << "Ҽʰ";
	else if (a9 == 2)
		cout << "��ʰ";
	else if (a9 == 3)
		cout << "��ʰ";
	else if (a9 == 4)
		cout << "��ʰ";
	else if (a9 == 5)
		cout << "��ʰ";
	else if (a9 == 6)
		cout << "½ʰ";
	else if (a9 == 7)
		cout << "��ʰ";
	else if (a9 == 8)
		cout << "��ʰ";
	else if (a9 == 9)
		cout << "��ʰ";
	//==============��==============//
	if (a8 == 0 && a9 != 0)
		cout << "��";
	else if (a8 == 1)
		cout << "Ҽ��";
	else if (a8 == 2)
		cout << "����";
	else if (a8 == 3)
		cout << "����";
	else if (a8 == 4)
		cout << "����";
	else if (a8 == 5)
		cout << "����";
	else if (a8 == 6)
		cout << "½��";
	else if (a8 == 7)
		cout << "����";
	else if (a8 == 8)
		cout << "����";
	else if (a8 == 9)
		cout << "����";
	//==============ǧ��==============//
	if (a7 == 0 && (a9 + a8) && (a6 + a5 + a4))
		cout << "��";
	else if (a7 == 1)
		cout << "ҼǪ";
	else if (a7 == 2)
		cout << "��Ǫ";
	else if (a7 == 3)
		cout << "��Ǫ";
	else if (a7 == 4)
		cout << "��Ǫ";
	else if (a7 == 5)
		cout << "��Ǫ";
	else if (a7 == 6)
		cout << "½Ǫ";
	else if (a7 == 7)
		cout << "��Ǫ";
	else if (a7 == 8)
		cout << "��Ǫ";
	else if (a7 == 9)
		cout << "��Ǫ";
	//==============����==============//
	if (a6 == 0 && a7 && (a4 + a5))
		cout << "��";
	else if (a6 == 1)
		cout << "Ҽ��";
	else if (a6 == 2)
		cout << "����";
	else if (a6 == 3)
		cout << "����";
	else if (a6 == 4)
		cout << "����";
	else if (a6 == 5)
		cout << "���";
	else if (a6 == 6)
		cout << "½��";
	else if (a6 == 7)
		cout << "���";
	else if (a6 == 8)
		cout << "�ư�";
	else if (a6 == 9)
		cout << "����";
	//==============ʮ��==============//
	if (a5 == 0 && a6 && a4)
		cout << "��";
	else if (a5 == 1)
		cout << "Ҽʰ";
	else if (a5 == 2)
		cout << "��ʰ";
	else if (a5 == 3)
		cout << "��ʰ";
	else if (a5 == 4)
		cout << "��ʰ";
	else if (a5 == 5)
		cout << "��ʰ";
	else if (a5 == 6)
		cout << "½ʰ";
	else if (a5 == 7)
		cout << "��ʰ";
	else if (a5 == 8)
		cout << "��ʰ";
	else if (a5 == 9)
		cout << "��ʰ";
	//==============��==============//
	if (a4 == 0 && (a7 + a6 + a5))
		cout << "��";
	else if (a4 == 1)
		cout << "Ҽ��";
	else if (a4 == 2)
		cout << "����";
	else if (a4 == 3)
		cout << "����";
	else if (a4 == 4)
		cout << "����";
	else if (a4 == 5)
		cout << "����";
	else if (a4 == 6)
		cout << "½��";
	else if (a4 == 7)
		cout << "����";
	else if (a4 == 8)
		cout << "����";
	else if (a4 == 9)
		cout << "����";
	//==============ǧ==============//
	if (a3 == 0 && (a9 + a8 + a7 + a6 + a5 + a4) && (a2 + a1 + a0))
		cout << "��";
	else if (a3 == 1)
		cout << "ҼǪ";
	else if (a3 == 2)
		cout << "��Ǫ";
	else if (a3 == 3)
		cout << "��Ǫ";
	else if (a3 == 4)
		cout << "��Ǫ";
	else if (a3 == 5)
		cout << "��Ǫ";
	else if (a3 == 6)
		cout << "½Ǫ";
	else if (a3 == 7)
		cout << "��Ǫ";
	else if (a3 == 8)
		cout << "��Ǫ";
	else if (a3 == 9)
		cout << "��Ǫ";
	//==============��==============//
	if (a2 == 0 && a3 && (a1 + a0))
		cout << "��";
	else if (a2 == 1)
		cout << "Ҽ��";
	else if (a2 == 2)
		cout << "����";
	else if (a2 == 3)
		cout << "����";
	else if (a2 == 4)
		cout << "����";
	else if (a2 == 5)
		cout << "���";
	else if (a2 == 6)
		cout << "½��";
	else if (a2 == 7)
		cout << "���";
	else if (a2 == 8)
		cout << "�ư�";
	else if (a2 == 9)
		cout << "����";
	//==============ʮ==============//
	if (a1 == 0 && a2 && a0)
		cout << "��";
	else if (a1 == 1)
		cout << "Ҽʰ";
	else if (a1 == 2)
		cout << "��ʰ";
	else if (a1 == 3)
		cout << "��ʰ";
	else if (a1 == 4)
		cout << "��ʰ";
	else if (a1 == 5)
		cout << "��ʰ";
	else if (a1 == 6)
		cout << "½ʰ";
	else if (a1 == 7)
		cout << "��ʰ";
	else if (a1 == 8)
		cout << "��ʰ";
	else if (a1 == 9)
		cout << "��ʰ";
	//==============��==============//
	if (a0 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1))
		cout << "Բ";
	else if (a0 == 1)
		cout << "ҼԲ";
	else if (a0 == 2)
		cout << "��Բ";
	else if (a0 == 3)
		cout << "��Բ";
	else if (a0 == 4)
		cout << "��Բ";
	else if (a0 == 5)
		cout << "��Բ";
	else if (a0 == 6)
		cout << "½Բ";
	else if (a0 == 7)
		cout << "��Բ";
	else if (a0 == 8)
		cout << "��Բ";
	else if (a0 == 9)
		cout << "��Բ";
	if (!a_1 && !a_2) {
		cout << "��\n";
		return 0;
	}
	//=============��==============//
	if (a_1 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0))
		cout << "��";
	else if (a_1 == 1)
		cout << "Ҽ��";
	else if (a_1 == 2)
		cout << "����";
	else if (a_1 == 3)
		cout << "����";
	else if (a_1 == 4)
		cout << "����";
	else if (a_1 == 5)
		cout << "���";
	else if (a_1 == 6)
		cout << "½��";
	else if (a_1 == 7)
		cout << "���";
	else if (a_1 == 8)
		cout << "�ƽ�";
	else if (a_1 == 9)
		cout << "����";
	//===========��==============//	
	if (a_2 == 0)
		cout << "��\n";
	if (a_2 == 1)
		cout << "Ҽ��\n";
	else if (a_2 == 2)
		cout << "����\n";
	else if (a_2 == 3)
		cout << "����\n";
	else if (a_2 == 4)
		cout << "����\n";
	else if (a_2 == 5)
		cout << "���\n";
	else if (a_2 == 6)
		cout << "½��\n";
	else if (a_2 == 7)
		cout << "���\n";
	else if (a_2 == 8)
		cout << "�Ʒ�\n";
	else if (a_2 == 9)
		cout << "����\n";
	return 0;
}
