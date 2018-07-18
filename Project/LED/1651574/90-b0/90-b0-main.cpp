/*1651574 1班 贾昊霖*/
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
		std::cout << "1.命令行找出可合成项并标识（非递归）" << endl;
		std::cout << "2.命令行找出可合成项并标识（递归）" << endl;
		std::cout << "3.命令行完成一次合成（分步骤显示）" << endl;
		std::cout << "4.命令行完整版（分步骤显示）" << endl;
		std::cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
		std::cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
		std::cout << "7.伪图形界面下用箭头键选择当前色块" << endl;
		std::cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
		std::cout << "9.伪图形界面完整版" << endl;
		std::cout << "0.退出" << endl;
		std::cout << "-----------------------------------" << endl;
		std::cout << "[请选择0-9]";
		
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
