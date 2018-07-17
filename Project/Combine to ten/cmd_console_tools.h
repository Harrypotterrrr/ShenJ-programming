#pragma once

#include <Windows.h>

/* ������ɫ���ú궨��ȡ�����֣�������䣩 */
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

/* ���������̬ */
#define CURSOR_VISIBLE_FULL			0	//�����ʾ��ȫ��ɫ��
#define CURSOR_VISIBLE_HALF			1	//�����ʾ�����ɫ��
#define CURSOR_VISIBLE_NORMAL		2	//�����ʾ�����ߣ�ȱʡΪ�˷�ʽ��
#define CURSOR_INVISIBLE				3	//��겻��ʾ

/* cmd_console_tools�µĺ������� */
void setcolor        (const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE);
void getcolor        (int &bg_color, int &fg_color);
void gotoxy          (const int X, const int Y);
void getxy           (int &x, int &y);
void setcursor       (const int options);
void showch          (const int X, const int Y, const char ch, const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE, const int n = 1);
void showstr         (const int X, const int Y, const char *str, const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE);
void setconsoleborder(const int cols, const int lines);
