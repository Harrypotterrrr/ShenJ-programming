/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <math.h>
const char chistr[] = "��Ҽ��������½��ƾ�";
char result[256] = { '\0' };

void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
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

/* �ɸ�����Ҫ�Զ����������� */
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
/* ������Ҫ���main���� */
int main()
{
	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	while (1) {
		printf("����һ��0~100�ڵĸ�������\n");
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
	a0 = (int)(temp);		//�������� ����λ
	temp2 = temp - a0;	//С������
	temp2 += 0.005;
	a_1 = (int)(floor(temp2 * 10));
	a_2 = (int)(floor(temp2 * 100)) % 10;
	printf("��д����ǣ�\n");
	if (!(a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0 + a_1 + a_2)) {
		daxie(0, 1);
		strcat(result, "Բ��");
		printf("%s\n",result);
		return 0;
	}
	//==============ʮ��==============//
	PrintSelect(a9);
	if (a9)
		strcat(result, "ʰ");
	//==============��==============//
	if (a8 == 0 && a9 != 0)
		strcat(result, "��");
	else if (a8)
		PrintSelect(a8);
	if (a8)
		strcat(result, "��");
	//==============ǧ��==============//
	if (a7 == 0 && (a9 + a8) && (a6 + a5 + a4))
		daxie(0, 1);
	else if (a7) {
		PrintSelect(a7);
		strcat(result, "Ǫ");
	}
	//==============����==============//
	if (a6 == 0 && a7 && (a4 + a5))
		daxie(0, 1);
	else if (a6) {
		PrintSelect(a6);
		strcat(result, "��");
	}
	//==============ʮ��==============//
	if (a5 == 0 && a6 && a4)
		daxie(0, 1);
	else if (a5) {
		PrintSelect(a5);
		strcat(result, "ʰ");
	}
	//==============��==============//
	if (a4 == 0 && (a7 + a6 + a5))
		strcat(result, "��");
	else if (a4) {
		PrintSelect(a4);
		strcat(result, "��");
	}
	//==============ǧ==============//
	if (a3 == 0 && (a9 + a8 + a7 + a6 + a5 + a4) && (a2 + a1 + a0))
		daxie(0, 1);
	else if (a3) {
		PrintSelect(a3);
		strcat(result, "Ǫ");
	}
	//==============��==============//
	if (a2 == 0 && a3 && (a1 + a0))
		daxie(0, 1);
	else if (a2) {
		PrintSelect(a2);
		strcat(result, "��");
	}
	//==============ʮ==============//
	if (a1 == 0 && a2 && a0)
		daxie(0, 1);
	else if (a1) {
		PrintSelect(a1);
		strcat(result, "ʰ");
	}
	//==============��==============//
	if (a0 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1))
		strcat(result, "Բ");
	else if (a0) {
		PrintSelect(a0);
		strcat(result, "Բ");
	}
	if (!a_1 && !a_2) {
		strcat(result, "��");
		printf("%s\n", result);
		return 0;
	}
	//=============��==============//
	if (a_1 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0))
		daxie(0, 1);
	else if (a_1) {
		PrintSelect(a_1);
		strcat(result, "��");
	}
	//=============��==============//	
	if (a_2 == 0)
		strcat(result, "��");
	else {
		PrintSelect(a_2);
		strcat(result, "��");
	}
	result[strlen(result)] = '\0';
	printf("%s\n", result);
	return 0;
}