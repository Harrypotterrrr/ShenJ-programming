/*1651574 1�� �����*/
#include <iostream>
using namespace std;

class Rectangular
{
public:
	void CalcVolumn();
	void ShowVolumn();
	void Input();
private:
	int a, b, c;
	int V;
};

void Rectangular::CalcVolumn()
{
	this->V = a * b * c;
}
void Rectangular::Input()
{
	cout << "�����볤�������:\n";
	cin >> a >> b >> c;
}
void Rectangular::ShowVolumn()
{
	cout << "���Ϊ��" << this->V << endl;
}

int main()
{
	Rectangular r1, r2, r3;
	r1.Input();
	r2.Input();
	r3.Input();
	r1.CalcVolumn();
	r2.CalcVolumn();
	r3.CalcVolumn();
	cout << "��������������ֱ�Ϊ��\n";
	r1.ShowVolumn();
	r2.ShowVolumn();
	r3.ShowVolumn();
	return 0;
}