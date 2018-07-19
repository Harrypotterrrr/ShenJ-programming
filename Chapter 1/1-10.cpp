/*1651574 计1 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);
	return 0;
}
void sort(int x, int y, int z)
{
	int temp;
	if (x > y) { temp = x;x = y;y = temp; }
	if (z < x) cout << z << ',' << x << ',' << y << endl;
	else if (z < y) cout << x << ',' << z << ',' << y << endl;
	else cout << x << ',' << y << ',' << z << endl;
}
/*
	功能：
		程序按照从小到大对输入的三个整数排序之间用逗号隔开。

	前三次输出：
		3,6,10
	第四次输出：
		Visual studio :
			-858993460,-858993460,10
		Dev C++ :
			0,0,10
        Code::Blocks ：
            0,10,4310000
*/
