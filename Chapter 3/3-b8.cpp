/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double a, b, c, delta, pre, rear;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:\n";
	cin >> a >> b >> c;
	if (!a) {
		cout << "����һԪ���η���\n";
		return 0;
	}
	delta = b * b - 4 * a * c;
	pre = -b / (2 * a);
	if (delta < 0) {
		rear = sqrt(-delta) / (2 * a);
		cout<< "�����������\n"
			<<"x1="<< pre << "+" << rear << "i\n"
			<<"x2="<< pre << "-" << rear << "i\n";
	}
	else{
		rear = sqrt(delta) / (2 * a);
		if (!delta)
			cout << "���������ʵ��:\nx1=x2=" << pre + rear << endl;
		else 
			cout<< "����������ʵ����\n"
				<<"x1="<< pre +rear << "\n"
				<<"x2="<< pre -rear << "\n";
	}
	return 0;
}
