/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double Fah, Cen;
	printf("������һ�������¶ȣ�\n");
	scanf("%lf", &Fah);
	Cen = 5. / 9. * (Fah - 32);
	printf("\n��Ӧ�����϶�Ϊ�� %.2lf\n", Cen);
	return 0;
}