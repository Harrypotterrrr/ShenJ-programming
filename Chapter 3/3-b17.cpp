/*1�� 1651574 �����*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;
int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&fc_begin);	//��ó�ʼӲ����ʱ������

										/* �˴�����ĳ���ʼ */
	int n = 0;
	for (int i1 = 1; i1 <= 5; i1++) {
		for (int i4 = 5; i4 <= 8; i4++) {
			if (i4 == i1)
				continue;
			for (int i7 = 7; i7 <= 9; i7++) {
				if (i7 <= i4)
					continue;
				for (int i2 = 1; i2 <= 9; i2++) {
					if (i2 == i1 || i2 == i4 || i2 == i7)
						continue;
					for (int i3 = 1; i3 <= 9; i3++) {
						if (i3 == i2 || i3 == i1 || i3 == i4 || i3 == i7)
							continue;
						for (int i5 = 1; i5 <= 9; i5++) {
							if (i5 == i1 || i5 == i2 || i5 == i3 || i5 == i4 || i5 == i7)
								continue;
							for (int i6 = 1; i6 <= 9; i6++) {
								if (i6 == i1 || i6 == i2 || i6 == i3 || i6 == i4 || i6 == i5 || i6 == i7)
									continue;
								for (int i8 = 1; i8 <= 9; i8++) {
									if (i8 == i1 || i8 == i2 || i8 == i3 || i8 == i4 || i8 == i5 || i8 == i6 || i8 == i7)
										continue;
									for (int i9 = 1; i9 <= 9; i9++) {
										if (i9 == i1 || i9 == i2 || i9 == i3 || i9 == i4 || i9 == i5 || i9 == i6 || i9 == i7 || i9 == i8)
											continue;
										if (100 * (i1 + i4 + i7) + 10 * (i2 + i5 + i8) + i3 + i6 + i9 == 1953) {
											n++;
											cout << "No." << n << " : ";
											cout << i1 << i2 << i3 << "+" << i4 << i5 << i6 << "+" << i7 << i8 << i9 << "=1953\n";
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
	cout << "total=" << n << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&fc_end);//�����ֹӲ����ʱ������
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "ʱ��Ƶ�ʣ�" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "ʱ�Ӽ�����" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "��" << endl;

	return 0;
}
