/*1651574 1�� �����*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double Fah, Cen;
	cout << "������һ�������¶�" << endl;
	cin >> Fah;
	Cen = 5. / 9. * (Fah - 32);
	cout << setiosflags(ios::fixed) << setprecision(2)
		<< "��Ӧ�����϶�Ϊ�� " << Cen << endl;
	return 0;
}