/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "..\common\cmd_console_tools.h"

#include "90-b0.h"
using namespace std;
/*					    main						*/
int main()
{
	int TotalGrade = 0;
	int Table[10][10];
	int MarkTable[10][10];
	int DataTable[20];

	srand(unsigned(time(NULL)));

	while (true) {
		setconsoleborder(INITIAL_Y, INITIAL_X);
		setcursor(CURSOR_VISIBLE_NORMAL);
		system("color 0F");
		memset(DataTable, 0, sizeof DataTable);

		std::cout << "-----------------------------------" << endl;
		std::cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
		std::cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
		std::cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
		std::cout << "4.�����������棨�ֲ�����ʾ��" << endl;
		std::cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
		std::cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
		std::cout << "7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��" << endl;
		std::cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
		std::cout << "9.αͼ�ν���������" << endl;
		std::cout << "0.�˳�" << endl;
		std::cout << "-----------------------------------" << endl;
		std::cout << "[��ѡ��0-9]";
		
		do {
			DataTable[Choice] = _getch();
			DataTable[Choice] -= '0';
		} while (DataTable[Choice] < 0 || DataTable[Choice] > 9);
		if (!DataTable[Choice])
			break;
		std::cout << DataTable[Choice] << endl;

		InitialSetting(Table, MarkTable, DataTable);
		Solve(Table, MarkTable, DataTable);
		system("cls");
	}
	gotoxy(0, INITIAL_X - 1);
	setconsoleborder(75, 50);
	system("color F0");
	setcolor(COLOR_HWHITE, COLOR_BLACK);
	PrintEasterEgg();
	return 0;
}
