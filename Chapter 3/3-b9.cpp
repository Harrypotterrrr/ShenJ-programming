/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	int y, m, d, sum = 0;
	cout << "��ֱ������ꡢ�¡��յ�ֵ:\n";
	cin >> y >> m >> d;
	if(m>12 || m<1){
		cout<<"�������-�·ݲ���ȷ\n";
		return 0;
	}
	bool leap = (!(y % 4) && (y % 100) || !(y % 400));
	bool flag = (((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) && (d <= 31))
		|| (((m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d <= 30))
		|| ((m == 2) && (d <= 28 + leap));
	if (!flag) {
		cout << "�������-�����µĹ�ϵ�Ƿ�\n";
		return 0;
	}
	sum += d;
	if (m > 1) {
		sum += 31;
		if (m > 2) {
			sum += 28 + leap;
			if (m > 3) {
				sum += 31;
				if (m > 4) {
					sum += 30;
					if (m > 5) {
						sum += 31;
						if (m > 6) {
							sum += 30;
							if (m > 7) {
								sum += 31;
								if (m > 8) {
									sum += 31;
									if (m > 9) {
										sum += 30;
										if (m > 10) {
											sum += 31;
											if (m > 11)
												sum += 30;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	// ���ص�   { ... } emoji.jpg
	// ������ȥ��Щ����..����˼·���Ǻ������..���������Խ�����ȫ�������������...
	cout << y<<"-"<<m<<"-"<<d<<"��"<<y<<"��ĵ�"<<sum<<"��\n";
	return 0;
}
