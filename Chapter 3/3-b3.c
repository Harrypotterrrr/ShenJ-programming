/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	//while(1) {
	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	printf("输入一个0~100亿的浮点数：\n");
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
	//四舍五入
	printf("十亿位：%d\n", a9);
	printf("亿位：%d\n", a8);
	printf("千万位：%d\n", a7);
	printf("百万位：%d\n", a6);
	printf("十万位：%d\n", a5);
	printf("万位：%d\n", a4);
	printf("千位：%d\n", a3);
	printf("百位：%d\n", a2);
	printf("十位：%d\n", a1);
	printf("个亿位：%d\n", a0);
	printf("十分位：%d\n", a_1);
	printf("百分位：%d\n", a_2);
	//}
	return 0;
}