/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pai 2*asin(1)
int main()
{
	int a, b, ang;
	double sq;
	printf("��ֱ����������ε������ߺ��м�ļнǣ��������־�Ϊ��������\n");
	scanf("%d%d%d", &a, &b, &ang);
	sq = 0.5 * a * b * sin(ang * pai / 180.0);
	printf("�����ε����Ϊ��%.3lf\n", sq);
	return 0;
}