/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, a0, a1, a2, a3, a4;
	printf("请输入一个不大于30000的正整数：\n");
	scanf("%d",&a);
	a0 = a % 10;
	a1 = (a / 10) % 10;
	a2 = (a / 100) % 10;
	a3 = (a / 1000) % 10;
	a4 = (a / 10000) % 10;
	printf("万位：%d\n", a4);
	printf("千位：%d\n", a3);
	printf("百位：%d\n", a2);
	printf("十位：%d\n", a1);
	printf("个位：%d\n", a0);
	return 0;
}