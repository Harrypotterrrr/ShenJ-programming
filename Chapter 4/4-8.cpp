/*1651574 1∞‡ º÷Íª¡ÿ*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	double Legendre(double, int);
	double x;
	int n;
	while (true) {
		cout << "¿¥¡Ω∏ˆ ˝◊÷∞…∏Á:\n";
		cin >> x >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}			
		if (n >= 0)
			break;
	}

	cout << "legendre["<<n<<"]("<<x<<")=" << Legendre(x, n) << endl;
}
double Legendre(double x,int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	double tmp;
	tmp = ((2 * n - 1)*x*Legendre(x, n - 1) - (n - 1)*Legendre(x, n - 2)) * 1.0 / n;
	return tmp;
}
