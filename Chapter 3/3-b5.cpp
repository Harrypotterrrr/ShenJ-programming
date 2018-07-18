/*1651574 1班 贾昊霖*/
#include <iostream>
#define eps 1e-8
using namespace std;
int main()
{
	double x, y;
	int h;
	cout << "请输入一个点的坐标(x,y):\n";
	cin >> x >> y;
	if (x > eps && y > eps && y + x - 3 <= 0)
		h = 1;
	else if (x < -eps && y >  eps && y - x - 3 <= 0)
		h = 2;
	else if (x < -eps && y < -eps && y + x + 3 >= 0)
		h = 3;	
	else if (x >  eps && y < -eps && y - x + 3 >= 0)
		h = 4;
	else
		h = 0;
	cout << "该坐标海拔为：\n" << h << "\n";
}
