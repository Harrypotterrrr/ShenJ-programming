/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, a0, a1, a2, a3, a4;
	printf("������һ��������30000����������\n");
	scanf("%d",&a);
	a0 = a % 10;
	a1 = (a / 10) % 10;
	a2 = (a / 100) % 10;
	a3 = (a / 1000) % 10;
	a4 = (a / 10000) % 10;
	printf("��λ��%d\n", a4);
	printf("ǧλ��%d\n", a3);
	printf("��λ��%d\n", a2);
	printf("ʮλ��%d\n", a1);
	printf("��λ��%d\n", a0);
	return 0;
}