/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	//while(1) {
	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	printf("����һ��0~100�ڵĸ�������\n");
	scanf("%lf", &a);
	a1 = (int)(a / 10) % 10;
	a2 = (int)(a / 100) % 10;
	a3 = (int)(a / 1000) % 10;
	a4 = (int)(a / 10000) % 10;
	a5 = (int)(a / 100000) % 10;
	a6 = (int)(a / 1000000) % 10;
	a7 = (int)(a / 10000000) % 10;
	a8 = (int)(a / 100000000) % 10;
	a9 = (int)(a / 1000000000) % 10;
	temp = a - 1000000000. * a9 - 100000000. * \
		a8 - 10000000. * a7 - 1000000. * a6 - \
		100000. * a5 - 10000. * a4 - 1000. * a3 \
		- 100. * a2 - 10. * a1;
	a0 = (int)(temp);
	temp2 = a - floor(a);
	a_1 = (int)(floor(temp2 * 10));
	a_2 = (int)(floor(temp2 * 100 + 0.005)) % 10;
	//��������
	printf("ʮ��λ��%d\n", a9);
	printf("��λ��%d\n", a8);
	printf("ǧ��λ��%d\n", a7);
	printf("����λ��%d\n", a6);
	printf("ʮ��λ��%d\n", a5);
	printf("��λ��%d\n", a4);
	printf("ǧλ��%d\n", a3);
	printf("��λ��%d\n", a2);
	printf("ʮλ��%d\n", a1);
	printf("����λ��%d\n", a0);
	printf("ʮ��λ��%d\n", a_1);
	printf("�ٷ�λ��%d\n", a_2);
	//}
	return 0;
}