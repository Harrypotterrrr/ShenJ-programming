/*1651574 ��1 �����*/
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
	���ܣ�
		�����մ�С����������������������֮���ö��Ÿ�����

	ǰ���������
		3,6,10
	���Ĵ������
		Visual studio :
			-858993460,-858993460,10
		Dev C++ :
			0,0,10
        Code::Blocks ��
            0,10,4310000
*/
