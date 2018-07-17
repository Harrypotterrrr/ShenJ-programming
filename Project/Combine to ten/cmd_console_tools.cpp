#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

/* ��̬ȫ�֣�ֻ�ڱ�Դ�����ļ�����Ч��Ϊ��ֹͬ������̬ȫ��һ�㽨���__��Ϊ��������ʼ�� */
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);	//ȡ��׼����豸��Ӧ�ľ��
static const HANDLE __hin  = GetStdHandle(STD_INPUT_HANDLE);		//ȡ��׼�����豸��Ӧ�ľ��

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ָ������ɫ
  ���������const int bg_color ������ɫ��0-15��
            const int fg_color ��ǰ��ɫ��0-15��
  �� �� ֵ��
  ˵    ������ɫ��ȡֵ�ɱ���ɫ+ǰ��ɫ��ɣ���16��
            fg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
                      8-15 ���� ���� ���� ���� ���� ���� ���� ����
            bg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
                      8-15 ���� ���� ���� ���� ���� ���� ���� ����
            ���յ���ɫΪ ����ɫ*16+ǰ��ɫ
***************************************************************************/
void setcolor(const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(__hout, bg_color * 16 + fg_color);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������һ��setcolor��ǰ��ɫ�ͱ���ɫ
  ���������int &bg_color      �����صı���ɫ��0-15��
            int &fg_color      �����ص�ǰ��ɫ��0-15��
  �� �� ֵ��
  ˵    �����β��е�&��ʾ���ã������»ὲ���������βε�ֵ���Է��ظ�ʵ��
***************************************************************************/
void getcolor(int &bg_color, int &fg_color)
{
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(__hout, &binfo);

	bg_color = binfo.wAttributes / 16;
	fg_color = binfo.wAttributes % 16;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ƶ���ָ��λ��
  ���������const int X       ��X�����꣨�У�
            const int Y       ��Y�����꣨�У�
  �� �� ֵ��
  ˵    ������Ļ���Ͻ�����Ϊ(0,0)����cmd���ڵĴ�Сδ������������£�Win10Ϊ��
            ����x�ᣬ��Ӧ��(0-119)
            ����y�ᣬ��Ӧ��(0-29)
***************************************************************************/
void gotoxy(const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(__hout, coord);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�ȡ��ǰ�������λ�õ�����ֵ
  ���������int &x            ��ȡ�õ�X�����꣨�У�
            int &y            ��ȡ�õ�Y�����꣨�У�
  �� �� ֵ��
  ˵    �����β��е�&��ʾ���ã������»ὲ���������βε�ֵ���Է��ظ�ʵ��
***************************************************************************/
void getxy(int &x, int &y)
{
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(__hout, &binfo);

	x = binfo.dwCursorPosition.X;
	y = binfo.dwCursorPosition.Y;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ù��״̬����ʾ/����ʾ/ȫ��/���/���ߵȣ�
  ���������const int option��Ҫ���õĹ��״̬
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setcursor(const int options)
{
	CONSOLE_CURSOR_INFO cursor_info;

	switch (options) {
		case CURSOR_VISIBLE_FULL:
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 100;
			break;
		case CURSOR_VISIBLE_HALF:
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 50;
			break;
		case CURSOR_INVISIBLE:
			cursor_info.bVisible = 0;
			cursor_info.dwSize = 1;
			break;
		case CURSOR_VISIBLE_NORMAL:
		default: //ȱʡ��ʾ��꣬����
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 25;
			break;
		}
	SetConsoleCursorInfo(__hout, &cursor_info);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ָ��λ�ã���ָ����ɫ����ʾһ���ַ����ɴ�
  ���������const int X       ��X�����꣨�У�
		   const int Y       ��Y�����꣨�У�
		   const char ch     ��Ҫ������ַ�ֵ
		   const int bg_color������ɫ��ȱʡΪCOLOR_BLACK��
		   const int fg_color������ɫ��ȱʡΪCOLOR_WHITE��
		   cinst int n       ���ظ�������ȱʡΪ1��
  �� �� ֵ��
  ˵    ����X��Y�ķ�Χ�μ�gotoxy������˵��
***************************************************************************/
void showch(const int X, const int Y, const char ch, const int bg_color, const int fg_color, const int n)
{
	int i;

	gotoxy(X, Y);
	setcolor(bg_color, fg_color);

	/* ѭ��n�Σ���ӡ�ַ�ch */
	for (i=0; i<n; i++)
		putchar(ch);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ָ��λ�ã���ָ����ɫ����ʾһ���ַ���
  ���������const int X       ��X�����꣨�У�
		   const int Y       ��Y�����꣨�У�
		   const char *str   ��Ҫ������ַ���
		   const int bg_color������ɫ��ȱʡΪCOLOR_BLACK��
		   const int fg_color������ɫ��ȱʡΪCOLOR_WHITE��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void showstr(const int X, const int Y, const char *str, const int bg_color, const int fg_color)
{
	const char *p;

	gotoxy(X, Y);
	setcolor(bg_color, fg_color);
	for (p = str; *p; p++)
		putchar(*p);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ı�cmd���ڵĴ�С
  ���������const int cols ���µ�����
		   const int lines���µ�����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setconsoleborder(const int cols, const int lines)
{
	char cmd[80];

	/* �ָ�Ϊ����ɫCOLOR_BLACK��ǰ��ɫCOLOR_WHITE��cmd���ڵ�ȱʡֵ��*/
	setcolor();
	system("cls");	//����

	sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
	system(cmd); //�����µĴ�С

	/* ������Ļ�������Ĵ�С�����һ����������Ϊ��Ļ�߶ȵ�10����*/
	COORD cr;
	cr.X = cols;
	cr.Y = lines*10;
	SetConsoleScreenBufferSize(__hout, cr); //����cmd���ڵ���Ļ�������Ĵ�С
}
