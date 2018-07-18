/*1651574 1�� �����*/
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#define eps 1e-8

/* ������ɫ���ú궨��ȡ������,������䣩 */
#define _COLOR 0
#define COLOR_BLACK		0	//��
#define COLOR_BLUE		1	//��
#define COLOR_GREEN		2	//��
#define COLOR_CYAN		3	//��
#define COLOR_RED		4	//��
#define COLOR_PINK		5	//��
#define COLOR_YELLOW	6	//��
#define COLOR_WHITE		7	//��
#define COLOR_HBLACK	8	//����
#define COLOR_HBLUE		9	//����
#define COLOR_HGREEN	10	//����
#define COLOR_HCYAN		11	//����
#define COLOR_HRED		12	//����
#define COLOR_HPINK		13	//����
#define COLOR_HYELLOW	14	//����
#define COLOR_HWHITE	15	//����
/* �������ɫ˳�� */
#ifndef _COLOR
#define COLOR_BLACK		0	//��
#define COLOR_BLUE		1	//��
#define COLOR_CYAN		3	//��
#define COLOR_HBLUE		9	//����
#define COLOR_GREEN		2	//��
#define COLOR_HCYAN		11	//����
#define COLOR_HGREEN	10	//����
#define COLOR_HYELLOW	14	//����
#define COLOR_HRED		12	//����
#define COLOR_HPINK		13	//����
#define COLOR_YELLOW	6	//��
#define COLOR_RED		4	//��
#define COLOR_PINK		5	//��
#define COLOR_WHITE		7	//��
#define COLOR_HWHITE	15	//����
#define COLOR_HBLACK	8	//����
#endif
/* ���������̬ */
#define CURSOR_VISIBLE_FULL			0	//�����ʾ,ȫ��ɫ��
#define CURSOR_VISIBLE_HALF			1	//�����ʾ,���ɫ��
#define CURSOR_VISIBLE_NORMAL		2	//�����ʾ,���ߣ�ȱʡΪ�˷�ʽ��
#define CURSOR_INVISIBLE			3	//��겻��ʾ
/* ����̨����� */
#define COLUMN 100
#define ARRAY 40
#define START 1
#define DEPTH 33
const char space1[] = "            ";
const char space2[] = "     ";
const char space3[] = "    ";
const char space4[] = "  ";//���Ԥ���ռ�
const char Line[] = " �������������������������������������������������������������������������������������������������� ";
const int ColorNumber[] = { 0,1,3,9,2,11,10,14,12,13,6,4,5,7,15,8 };//�������ɫ˳��
const int INC_XY[][2] = { {0,2},{1,0},{0,-2},{-1,0} };
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}
void setcolor(const HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}
void SwitchColor(int n, bool tag)
{
	if (tag)
		n *= 10;
	switch (n) {
		case(8):
			setcolor(hout, COLOR_HWHITE, COLOR_HBLACK);
			break;
		case(7):
			setcolor(hout, COLOR_HWHITE, COLOR_RED);
			break;
		case(6):
			setcolor(hout, COLOR_HWHITE, COLOR_PINK);
			break;
		case(70):
			setcolor(hout, COLOR_HWHITE, COLOR_HRED);
			break;
		case(60):
			setcolor(hout, COLOR_HWHITE, COLOR_GREEN);
			break;
		case(1):
			setcolor(hout, COLOR_HWHITE, COLOR_BLUE);
			break;
		default:
			setcolor(hout, COLOR_HWHITE, COLOR_HBLUE);
	}
}
/**
*�������������� ����       ����+ +
*�������������������ߩ����������������ߩ� + +
*���������������������������� ��
*�������������������������������� ++ + + +++
*������������ ����������������������  ��+
*���������������������������� �� +
*�����������������������ߡ�������
*���������������������������� �� + ++ +
*���������������������������� ������
*                ������  ��
*������������������������  �� + + + ++
*������������������������������
*���������������������������� +
*����������������������������   +
*��������������������������������+
*���������������������� �� ���������� + ++
*�������������������� �����������ǩ�
*�������������������� ��������������
*���������������������������������ש����� + + + ++   +   +
*������������������ ���ϩϡ� ���ϩ�
*������������������ ���ߩ��� ���ߩ�+ + + + +  +  +
*	��ʦ������������...���ִӿ�ѧ�����ڵ�zeller��ʽȫ���ô���.........
*				֪���ղŲŷ���......( >�n<��)~
*/

int Zeller(int year, int month, int day)
{
	int century, week;
	year %= 100;
	century = year / 100;
	if (month < 3) {
		month += 12;
		year --;
	}
	week = year + year / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10 + day - 1;
	return (week + 6) % 7 + 1;
}
int PrintCalendar(int M[], int year, int month)
{
	for (int i = 0; i < 3; i++) {
		cout << space4;
		cout << space1;
		SwitchColor(8, false);
		cout << month + i << "��";
		if (i != 2)
			cout << space1 << space2;
	}
	putchar('\n');
	for (int i = 1; i <= 3; i++) {
		cout << space4;
		SwitchColor(1, false);
		cout << "Mon Tue Wed Thu Fri";
		SwitchColor(6, false);
		cout << " Sat";
		SwitchColor(7, false);
		cout << " Sun";
		cout << space2;
	}
	putchar('\n');
	int day[3] = { 1,1,1 }, num;
	cout << setiosflags(ios::left);
	/*				Initial				*/
	for (int i = 0; i < 3; i++) {
		cout << space4;
		int space = Zeller(year, month + i, 1) - 1;
		num = 0;					//ATTENTION!
		for (int j = 1; j <= space; j++) {
			cout << setw(4) << " ";
			num++;
		}
		while ((num % 7) || !num) {
			SwitchColor(num + 1, true);
			cout << setw(4) << day[i]++;
			num++;
		}
		cout << space3;
	}
	putchar('\n');
	/*				Left				*/
	int line = 4;
	while (true) {
		for (int i = 0; i < 3; i++) {
			cout << space4;
			num = 0;			//ATTENTION!
			while ((num % 7) || !num) {
				if (day[i] <= M[month + i]) {
					SwitchColor(num + 1, true);
					cout << setw(4) << day[i]++;
				}
				else
					cout << setw(4) << " ";
				num++;
			}
			cout << space3;
		}
		line ++;
		putchar('\n');
		if (day[0] == M[month] + 1 && day[1] == M[month + 1] + 1 \
			&& day[2] == M[month + 2] + 1)
			break;
		//Sleep(100);
	}
	return line;
}
void PrintLight(int line[])
{
	int x = START, y = 0;
	int x_inc = INC_XY[0][0], y_inc = INC_XY[0][1];
	int i = 0, j = 0;
	while (true) {
		gotoxy(hout, y, x);
		setcolor(hout, COLOR_HWHITE, ColorNumber[(i++) % 16]);
		Sleep(10);
		cout << "��";
		x += x_inc;
		y += y_inc;
		if ((x == START && y == 0)
			|| (x == START && y == 3 * DEPTH-1)
			|| (x == START + line[4] && y == 0)
			|| (x == START + line[4] && y == 3 * DEPTH-1)) {
			j++;
			x_inc = INC_XY[j % 4][0];
			y_inc = INC_XY[j % 4][1];
		}
	}
}
void PrintDecoration(int line[])
{
	setcolor(hout, COLOR_HWHITE, COLOR_YELLOW);
	for (int i = 0; i <= 4; i++) {
		if (i)
			line[i] += line[i - 1];
		gotoxy(hout, 0, START + line[i]);
		cout << Line;
	}
	for (int i = START + 1; i < START + line[4]; i++)
		for (int j = 0; j <= 3; j++) {
			gotoxy(hout,  j * DEPTH, i);
			cout << "|";
		}
}
void AddLeapYear(int M[], int year)
{
	bool leap = (!(year % 4) && (year % 100) || !(year % 400));
	M[2] += leap;
}
int main()
{
	/* ���ÿ���̨����� */
	system("mode con cols=115 lines=40");
	/* ���ÿ���̨����ǰ��ɫ */
	system("color F0");
	int M[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int countLine[5] = { 0 };	//��¼ÿ�����µ��������
	int year;
	while (true) {
		cout << "���������(1900-2100)��";
		cin >> year;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (year <= 2100 && year >= 1900)
			break;
	}
	system("cls");
	AddLeapYear(M, year);
	cout << year << "���������\n\n";

	for (int i = 1; i <= 4; i++) {
		countLine[i] = PrintCalendar(M, year, i * 3 - 2);
		putchar('\n');
	}
	putchar('\n');

	PrintDecoration(countLine);
	Sleep(100);
	PrintLight(countLine);
	gotoxy(hout, 0, ARRAY - 1);
	return 0;
}
