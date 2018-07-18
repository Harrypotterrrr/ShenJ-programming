/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pai 2*asin(1)
int main()
{
	int a, b, ang;
	double sq;
	printf("请分别输入三角形的两个边和中间的夹角，其中数字均为正整数：\n");
	scanf("%d%d%d", &a, &b, &ang);
	sq = 0.5 * a * b * sin(ang * pai / 180.0);
	printf("三角形的面积为：%.3lf\n", sq);
	return 0;
}