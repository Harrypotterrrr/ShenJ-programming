/* 1651574 ����� 1 �� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ���
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/* ������ƶ���ָ��λ�� */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* ��ָ��λ�ô���ӡһ��ָ�����ַ� */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

int main()
{

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int    i;

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ע�⣺������bug���������ѭ�����ɵ�XY����ǡ����ȫ��ͬ������ĸ�����᲻��20������˵��������Ҫ�����bug�� */
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	
	/* �ڴ˴�������Ҫ�Ĵ���-begin */
	//getchar(); //�˾��ɾ��
	int cur_x = MAX_X / 2 + 1, cur_y = MAX_Y / 2 + 1;
	unsigned short _char;
	gotoxy(hout, cur_x, cur_y);

	while (true) {
		_char = _getch();
		if (_char == 0x51 || _char == 0x71)
			break;
		else if (_char == 0x20) {
			putchar(' ');
			gotoxy(hout, cur_x, cur_y);
		}
		else if (_char != 0xe0)
			continue;
		else {
			_char = _getch();
			if (_char == 0x4b && cur_x > 1)			//��
				gotoxy(hout, --cur_x, cur_y);
			else if (_char == 0x50 && cur_y < MAX_Y)	//��
				gotoxy(hout, cur_x, ++cur_y);
			else if (_char == 0x4d && cur_x < MAX_X)	//��
				gotoxy(hout, ++cur_x, cur_y);
			else if (_char == 0x48 && cur_y > 1)		//��
				gotoxy(hout, cur_x, --cur_y);
		}
	}
	/* �ڴ˴�������Ҫ�Ĵ���-end */

	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س����˳�." << endl;
	getchar();

	return 0;
}