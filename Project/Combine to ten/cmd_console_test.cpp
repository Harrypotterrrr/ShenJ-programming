#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void to_be_continued(const char *prompt, const int X=0, const int Y=22)
{
	setcolor(); //�ָ�ȱʡ��ɫ
	gotoxy(X, Y);

	if (prompt) 
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;

	system("cls"); //����ϵͳ���������Ļ
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ָ��λ�ã���ָ����ɫ����ʾһ���ַ����ɴ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	if (1) {
		int x, y;

		/* ��ʾ16*16����ɫ��ÿ���ַ�֮���һ���ո� */
		for (y = 0; y<16; y++) {
			for (x = 0; x<16; x++)
				showch(x * 2, y, 'x', y, x, 2);	//��xyλ����ʾx����x�����ֵ��ǰ��ɫ��y�����ֵ������ɫ����ʾ����x��Ϊ��ʹ����Э�������Ի���һ��x��۲�Ч����
			cout << endl; //16��ǰ��ɫ�任��ɺ󣬻�һ��
			Sleep(100);  //��ʱ0.1�루�Ժ���Ϊ��λ��1000=1�룩
			} //end of for

		to_be_continued("��ɫ��ʾ��ʾ���");
		}

	if (1) {
		const int MAX_X = 50;
		const int Y = 2;
		const int bg_color = COLOR_HYELLOW;	//����Ϊ����ɫ
		const int fg_color = COLOR_HBLUE;		//ǰ��Ϊ����ɫ
		const char ch = '*';        //�ַ�Ϊ*(ע�⣺����ǿո���ǰ��ɫ�޷���ʾ)
		const int LENGTH = 10;
		int x;

		/* ��һ���ַ����������ƶ� */
		for (x = 0; x<MAX_X; x++) {
			/* ������(x,2)λ�ô�������ӡ10���ַ� */
			showch(x, Y, ch, bg_color, fg_color, LENGTH);

			/* ��ʱ0.1�� */
			Sleep(100);

			if (x<MAX_X - 1) {
				/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
				showch(x, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
				}
			} //end of for

		to_be_continued("������Ч���");
		}

	if (1) {
		const int MAX_Y = 12;
		const int X = 2;
		const int bg_color = COLOR_HYELLOW;	//����Ϊ����ɫ
		const int fg_color = COLOR_HBLUE;	//ǰ��Ϊ����ɫ
		const char ch = '*';        //�ַ�Ϊ*(ע�⣺����ǿո���ǰ��ɫ�޷���ʾ)
		const int LENGTH = 10;
		int y;

		/* ��һ���ַ����������ƶ� */
		for (y = 2; y<MAX_Y; y++) {
			/* ������(x,2)λ�ô�������ӡ10���ַ� */
			showch(X, y, ch, bg_color, fg_color, LENGTH);

			/* ��ʱ0.3�� */
			Sleep(300);

			if (y<MAX_Y - 1) {
				/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
				showch(X, y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
				}
			} //end of for

		to_be_continued("������Ч���");
		}

	if (1) {
		/* ����Ļ��[0,0]-[60,20]�����������ʾ100���ַ���ֵ�������ɫ���
		˵����δ�ж�λ���ظ������������ַ�������100
		δ�ж�ǰ��ɫ/����ɫ�ظ�������ĳЩλ��ֻ������ɫ���������ַ� */
		const int MAX_X = 60, MAX_Y = 20;
		int x, y, fg_color, bg_color, num;
		char ch;

		srand((unsigned int)(time(0))); //��������

		for (num = 0; num<100; num++) {
			x = rand() % (MAX_X + 1);
			y = rand() % (MAX_Y + 1);
			fg_color = rand() % 16;
			bg_color = rand() % 16;
			ch = 33 + rand() % 94;   //ASCII�����33-126Ϊ�ɼ�ͼ���ַ�

									 /* ��ʾһ��1 */
			showch(x, y, ch, bg_color, fg_color, 1);

			/* ��ʱ0.05�� */
			Sleep(50);
			}  //end of for

		to_be_continued("����ַ���ʾ���");
		}

	if (1) {
		setcursor(CURSOR_VISIBLE_FULL);
		to_be_continued("�����ʾΪȫ��ɫ��", 0, 2);

		setcursor(CURSOR_VISIBLE_HALF);
		to_be_continued("�����ʾΪ���ɫ��", 0, 4);

		setcursor(CURSOR_INVISIBLE);
		to_be_continued("�رչ����ʾ", 0, 6);

		setcursor(CURSOR_VISIBLE_NORMAL);
		to_be_continued("�����ʾΪ����", 0, 8);

		to_be_continued("�����״��ʾ���");
		}

	return 0;
}
