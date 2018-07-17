/*1651574 1班 贾昊霖*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double Fah, Cen;
	cout << "请输入一个华氏温度" << endl;
	cin >> Fah;
	Cen = 5. / 9. * (Fah - 32);
	cout << setiosflags(ios::fixed) << setprecision(2)
		<< "对应的摄氏度为： " << Cen << endl;
	return 0;
}