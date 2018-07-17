/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <math.h>
const char chistr[] = "零壹贰叁肆伍陆柒捌玖";
char result[256] = { '\0' };

void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				strncat(result, chistr, 2);
			break;
		case 1:
			strncat(result, chistr + 1 * 2, 2);
			break;
		case 2:
			strncat(result, chistr + 2 * 2, 2);
			break;
		case 3:
			strncat(result, chistr + 3 * 2, 2);
			break;
		case 4:
			strncat(result, chistr + 4 * 2, 2);
			break;
		case 5:
			strncat(result, chistr + 5 * 2, 2);
			break;
		case 6:
			strncat(result, chistr + 6 * 2, 2);
			break;
		case 7:
			strncat(result, chistr + 7 * 2, 2);
			break;
		case 8:
			strncat(result, chistr + 8 * 2, 2);
			break;
		case 9:
			strncat(result, chistr + 9 * 2, 2);
			break;
		default:
			printf("error\n");   
			break;
	}
}

/* 可根据需要自定义其它函数 */
void PrintSelect(int x)
{
	if (x == 1)
		daxie(1, 1);
	else if (x == 2)
		daxie(2, 1);
	else if (x == 3)
		daxie(3, 1);
	else if (x == 4)
		daxie(4, 1);
	else if (x == 5)
		daxie(5, 1);
	else if (x == 6)
		daxie(6, 1);
	else if (x == 7)
		daxie(7, 1);
	else if (x == 8)
		daxie(8, 1);
	else if (x == 9)
		daxie(9, 1);
}
/* 根据需要完成main函数 */
int main()
{
	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	while (1) {
		printf("输入一个0~100亿的浮点数：\n");
		if (scanf("%lf", &a))
			break;
		rewind(stdin);
	}
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
	a0 = (int)(temp);		//整数部分 即个位
	temp2 = temp - a0;	//小数部分
	temp2 += 0.005;
	a_1 = (int)(floor(temp2 * 10));
	a_2 = (int)(floor(temp2 * 100)) % 10;
	printf("大写结果是：\n");
	if (!(a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0 + a_1 + a_2)) {
		daxie(0, 1);
		strcat(result, "圆整");
		printf("%s\n",result);
		return 0;
	}
	//==============十亿==============//
	PrintSelect(a9);
	if (a9)
		strcat(result, "拾");
	//==============亿==============//
	if (a8 == 0 && a9 != 0)
		strcat(result, "亿");
	else if (a8)
		PrintSelect(a8);
	if (a8)
		strcat(result, "亿");
	//==============千万==============//
	if (a7 == 0 && (a9 + a8) && (a6 + a5 + a4))
		daxie(0, 1);
	else if (a7) {
		PrintSelect(a7);
		strcat(result, "仟");
	}
	//==============百万==============//
	if (a6 == 0 && a7 && (a4 + a5))
		daxie(0, 1);
	else if (a6) {
		PrintSelect(a6);
		strcat(result, "佰");
	}
	//==============十万==============//
	if (a5 == 0 && a6 && a4)
		daxie(0, 1);
	else if (a5) {
		PrintSelect(a5);
		strcat(result, "拾");
	}
	//==============万==============//
	if (a4 == 0 && (a7 + a6 + a5))
		strcat(result, "万");
	else if (a4) {
		PrintSelect(a4);
		strcat(result, "万");
	}
	//==============千==============//
	if (a3 == 0 && (a9 + a8 + a7 + a6 + a5 + a4) && (a2 + a1 + a0))
		daxie(0, 1);
	else if (a3) {
		PrintSelect(a3);
		strcat(result, "仟");
	}
	//==============百==============//
	if (a2 == 0 && a3 && (a1 + a0))
		daxie(0, 1);
	else if (a2) {
		PrintSelect(a2);
		strcat(result, "佰");
	}
	//==============十==============//
	if (a1 == 0 && a2 && a0)
		daxie(0, 1);
	else if (a1) {
		PrintSelect(a1);
		strcat(result, "拾");
	}
	//==============个==============//
	if (a0 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1))
		strcat(result, "圆");
	else if (a0) {
		PrintSelect(a0);
		strcat(result, "圆");
	}
	if (!a_1 && !a_2) {
		strcat(result, "整");
		printf("%s\n", result);
		return 0;
	}
	//=============角==============//
	if (a_1 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0))
		daxie(0, 1);
	else if (a_1) {
		PrintSelect(a_1);
		strcat(result, "角");
	}
	//=============分==============//	
	if (a_2 == 0)
		strcat(result, "整");
	else {
		PrintSelect(a_2);
		strcat(result, "分");
	}
	result[strlen(result)] = '\0';
	printf("%s\n", result);
	return 0;
}