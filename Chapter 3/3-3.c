/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double Fah, Cen;
	printf("请输入一个华氏温度：\n");
	scanf("%lf", &Fah);
	Cen = 5. / 9. * (Fah - 32);
	printf("\n对应的摄氏度为： %.2lf\n", Cen);
	return 0;
}