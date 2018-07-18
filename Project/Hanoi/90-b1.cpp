/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include "cmd_console_tools.h"
#define UNCOLOR_BASE_X 12
#define UNCOLOR_PILLAR_Y 9
#define COLOR_PILLAR_Y 12
#define CHOICE4_X 17
#define CHOICE89_X 30
#define BASE_X 16
#define BASE_Y 1
#define BASE_LENGTH 23
#define BASE_HALF 11
#define BASE_TOP 3
#define BASE_INTERVAL 9
#define MOVESPEED 5

#define END12_X	25
#define END12_Y 60
#define END37_X 30
#define END37_Y 100
#define END89_X 40
#define END89_Y 100

#define QUIT 0
#define OK 1
#ifdef _WINGDI_
#define ERROR -1
#endif
using namespace std;
const int PILLAR_INTERVAL = BASE_LENGTH + BASE_INTERVAL - 1;
const int PILLAR_START = BASE_Y + BASE_HALF;
const int CHOICE8_BASE = BASE_X + 12;
const int CHOICE9_BASE = CHOICE8_BASE + 7;
const int ColorNumber[] = { 1,9,3,2,11,10,14,12,13,4,5,7,15,8 };//�������ɫ˳��
const char tips[] = "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
const int LEN_TIPS = strlen(tips);
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
typedef int Status;
void PrintEasterEgg();

int Plate[3][15];
int p[3], n, step;
/*				�ӳ�ʱ������					*/
inline void SleepTime(int delay)
{
	switch (delay) {
		case(0):
			while (_getch() != '\r')
				;	//���»س����ܼ���
			break;
		case(1):
			Sleep(1000);
			break;
		case(2):
			Sleep(500);
			break;
		case(3):
			Sleep(200);
			break;
		case(4):
			Sleep(80);
			break;
		case(5):
			Sleep(20);
			break;
		default:
			Sleep(MOVESPEED);
	}
}
/*				�ȴ�����ȷ��					*/
void pause()
{
	cout << "���س�������\n";
	while (_getch() != '\r')
		;
}
/*			    ��ʼ��ջ��Ԫ��				*/
void InitPlates(char Start, char End)
{
	p[0] = p[1] = p[2] = 1;
	if (Start == 'A') {
		for (int i = 1; i <= n; i++)
			Plate[0][i] = n - i + 1;
		p[0] = n + 1;
	}
	else if (Start == 'B') {
		for (int i = 1; i <= n; i++)
			Plate[1][i] = n - i + 1;
		p[1] = n + 1;
	}
	else {
		for (int i = 1; i <= n; i++)
			Plate[2][i] = n - i + 1;
		p[2] = n + 1;
	}
}
/*			����ջ��ָ��ı�ջ��Ԫ��			*/
void MovePlate(char from, char to)
{
	int tmp;
	switch (from) {
		case('A'):
			tmp = Plate[0][--p[0]];
			break;
		case('B'):
			tmp = Plate[1][--p[1]];
			break;
		default:
			tmp = Plate[2][--p[2]];
	}
	switch (to) {
		case('A'):
			Plate[0][p[0]++] = tmp;
			break;
		case('B'):
			Plate[1][p[1]++] = tmp;
			break;
		default:
			Plate[2][p[2]++] = tmp;
	}
}
/*			  ��ӡ����ŵ��					*/
void PrintVertical(int choice)
{
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	for (int j = 0; j < 3; j++) {
		for (int i = 10; i >= 1; i--) {
			if (choice == 8 || choice == 9)
				gotoxy(hout, UNCOLOR_PILLAR_Y + 2 + 10 * j, CHOICE8_BASE - i);
			else
				gotoxy(hout, UNCOLOR_PILLAR_Y + 2 + 10 * j, UNCOLOR_BASE_X - i);
			if (i >= p[j])
				cout << ' ';
			else
				cout << Plate[j][i];
		}
	}
}
/*	choice == 3 or 4 or 8 or 9 ��ӡ����ŵ��	*/
void PrintTransversal(int choice, char from, char to)
{
	if (choice == 8 || choice == 9)
		gotoxy(hout, 0, CHOICE89_X);
	else if (choice == 4)
		gotoxy(hout, 0, CHOICE4_X);
	if (step == 0)
		cout << "��ʼ�� ";
	else {
		cout << "��" << setw(4) << step << " ��(";
		cout << setw(2) << step << "#: ";
		cout << from << "-->" << to << ")";
	}
	cout << "A:";
	for (int i = 1; i <= 10; i++) {
		if (i < p[0])
			cout << setw(2) << Plate[0][i];
		else
			cout << "  ";
	}
	cout << " B:";
	for (int i = 1; i <= 10; i++) {
		if (i < p[1])
			cout << setw(2) << Plate[1][i];
		else
			cout << "  ";
	}
	cout << " C:";
	for (int i = 1; i <= 10; i++) {
		if (i < p[2])
			cout << setw(2) << Plate[2][i];
		else
			cout << "  ";
	}
	//gotoxy(hout, 0, 17);
	putchar('\n');
}
/*			   ����ɫ������					*/
void DrawColorPlates()
{
	int x, y, pillar, length;
	for (int i = 0; i < 3; i++) {
		gotoxy(hout, COLOR_PILLAR_Y + i * PILLAR_INTERVAL, BASE_X);
		x = COLOR_PILLAR_Y + i * PILLAR_INTERVAL;
		y = BASE_X - 1;
		pillar = p[i];
		length = --pillar;
		for (int i = 0; i < pillar; i++) {
			showch(hout, x - length, y - i, ' ', ColorNumber[i], ColorNumber[i], 2 * length + 1);
			length--;
		}
	}
	SleepTime(3);
}
/*				 ������						*/
void DrawColorPillar()
{
	for (int i = 0; i < 3; i++)
		showch(hout, BASE_Y + PILLAR_INTERVAL * i, BASE_X, ' ', COLOR_HYELLOW, COLOR_HYELLOW, BASE_LENGTH);

	for (int i = 0; i < 3; i++)
		for (int j = BASE_TOP; j < BASE_X; j++)
			showch(hout, PILLAR_START + i * PILLAR_INTERVAL, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	SleepTime(5);
}
/*		  choice == 1 or 2 ʱ�����			*/
void PrintPrimaryHanoi(int choice, int num, int step, char from, char to)
{
	if (choice == 1) {
		cout << "#" << num << " " << from << "---->" << to << endl;
	}
	else {
		cout << "��" << setw(4) << step << " ��( ";
		cout << setw(2) << num << "#: ";
		cout << from << "-->" << to << ")\n";
	}
}
/*				��ӡ��ʼ��Ԫ��				*/
void PrintInitial(int choice, char Start, char End, int delay)
{
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	gotoxy(hout, 0, 0);
	cout << "�� " << Start << " �ƶ��� " << End << "���� " << p[0] + p[1] + p[2] - 3
		<< " ��";
	if (choice == 6 || choice == 7)
		return;
	if (choice != 9)
		cout << ",��ʱ����Ϊ " << delay;
	if (choice == 8 || choice == 9)
		gotoxy(hout, UNCOLOR_PILLAR_Y, CHOICE8_BASE);
	else
		gotoxy(hout, UNCOLOR_PILLAR_Y, UNCOLOR_BASE_X);
	cout << "=========================";
	if (choice == 8 || choice == 9)
		gotoxy(hout, UNCOLOR_PILLAR_Y, CHOICE8_BASE + 1);
	else
		gotoxy(hout, UNCOLOR_PILLAR_Y, UNCOLOR_BASE_X + 1);
	cout << "  A         B         C";
	PrintTransversal(choice, Start, End);
	SleepTime(delay);
	PrintVertical(choice);
	SleepTime(delay);
}
/*			 ������ʾ�����ƶ�����				*/
void SolveMovement(char from, char to)
{
	int start = from - 'A';
	int end = to - 'A';
	int inc = (from > to) ? -1 : 1;

	int PillarStart = p[start];//���ϵ����
	int PillarEnd = p[end];//���ϵ����
	int InfoStart = Plate[start][PillarStart - 1];//���Ӻ�

	int y = PILLAR_START + start * PILLAR_INTERVAL;
	int x = BASE_X - PillarStart + 1;
	int tmp_color = ColorNumber[n - InfoStart];//��Ӧ����ɫ
	/*			�����ƶ�				 */
	while (x != 1) {
		/*		 ɾ������ 	*/
		showch(hout, y - InfoStart, x, ' ', COLOR_BLACK, COLOR_BLACK, InfoStart);
		if (x >= 3)
			showch(hout, y, x, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		else
			showch(hout, y, x, ' ', COLOR_BLACK, COLOR_BLACK, 1);
		showch(hout, y + 1, x, ' ', COLOR_BLACK, COLOR_BLACK, InfoStart);
		x--;
		SleepTime(5);
		/*		��������		*/
		showch(hout, y - InfoStart, x, ' ', tmp_color, tmp_color, 2 * InfoStart + 1);
		SleepTime(5);
	}
	/*			����or���ƶ�			*/
	int Destination_y = PILLAR_START + end * PILLAR_INTERVAL;
	while (y != Destination_y) {
		showch(hout, y - InfoStart, x, ' ', COLOR_BLACK, COLOR_BLACK, 2 * InfoStart + 1);
		y += inc;
		SleepTime(5);
		showch(hout, y - InfoStart, x, ' ', tmp_color, tmp_color, 2 * InfoStart + 1);
		SleepTime(5);
	}
	/*			�����ƶ�				*/
	int Destination_x = BASE_X - PillarEnd;
	while (x != Destination_x) {
		/*		 ɾ������ 	*/
		showch(hout, y - InfoStart, x, ' ', COLOR_BLACK, COLOR_BLACK, InfoStart);
		if (x >= 3)
			showch(hout, y, x, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		else
			showch(hout, y, x, ' ', COLOR_BLACK, COLOR_BLACK, 1);
		showch(hout, y + 1, x, ' ', COLOR_BLACK, COLOR_BLACK, InfoStart);
		x++;
		SleepTime(5);
		/*		��������		*/
		showch(hout, y - InfoStart, x, ' ', tmp_color, tmp_color, 2 * InfoStart + 1);
		SleepTime(5);
	}
}
/*		 �ݹ��и���choiceѡ��������			*/
void SwitchSolutions(int choice, int num, int delay, char from, char to)
{
	switch (choice) {
		case(1):case(2):
			PrintPrimaryHanoi(choice, num, step, from, to);
			break;
		case(3):
			MovePlate(from, to);
			PrintTransversal(choice, from, to);
			break;
		case(4):
			MovePlate(from, to);
			PrintTransversal(4, from, to);
			SleepTime(delay);
			PrintVertical(choice);
			SleepTime(delay);
			break;
		case(7):
			if (step >= 2)
				return;
			SolveMovement(from, to);
			break;
		case(8):
			SolveMovement(from, to);
			MovePlate(from, to);
			setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
			PrintTransversal(8, from, to);
			SleepTime(delay);
			PrintVertical(choice);
			SleepTime(delay);
			break;
	}
}
/*				hanoi���������				*/
void Hanoi(int num, char from, char to, char by, int choice, int delay)
{
	if (num == 1) {
		step++;
		SwitchSolutions(choice, num, delay, from, to);
		return;
	}
	Hanoi(num - 1, from, by, to, choice, delay);
	step++;
	SwitchSolutions(choice, num, delay, from, to);
	Hanoi(num - 1, by, to, from, choice, delay);
}
/*				�ж��ַ��Ϸ���				*/
bool JudgeChar(char c)
{
	if (c <= 'C' && c >= 'A')
		return true;
	else if (c <= 'c' && c >= 'a')
		return true;
	return false;
}
/*            �ж�����������Ƿ�Ϸ�			*/
Status JudgeValidity(char *str)
{
	int start, end;
	int StartPlate, EndPlate;
	if (strlen(str) > 2)
		return ERROR;
	if (strlen(str) == 1 && str[0] == 'Q' || str[0] == 'q') {
		gotoxy(hout, 0, CHOICE9_BASE + 1);
		cout << "��Ϸ��ֹ!!!!!";
		SleepTime(0);
		return QUIT;
	}
	for (int i = 0; i < 2; i++)
		if (!JudgeChar(str[i]))
			return ERROR;
	if (str[0] > 'C') {
		str[0] -= 32;
		start = str[0] - 'A';
	}
	else
		start = str[0] - 'A';
	if (str[1] > 'C') {
		str[1] -= 32;
		end = str[1] - 'A';
	}
	else
		end = str[1] - 'A';
	if (start == end)
		return ERROR;
	StartPlate = Plate[start][p[start] - 1];
	EndPlate = Plate[end][p[end] - 1];
	if (p[start] == 1) {
		gotoxy(hout, 0, CHOICE9_BASE + 1);
		cout << "Դ��Ϊ��!";
		SleepTime(1);
		showch(hout, 0, CHOICE9_BASE + 1, ' ', COLOR_BLACK, COLOR_BLACK, strlen("Դ��Ϊ��!"));
		return ERROR;
	}
	if (StartPlate > EndPlate && p[end] > 1) {
		gotoxy(hout, 0, CHOICE9_BASE + 1);
		cout << "����ѹС�̣��Ƿ��ƶ�!";
		SleepTime(1);
		showch(hout, 0, CHOICE9_BASE + 1, ' ', COLOR_BLACK, COLOR_BLACK, strlen("����ѹС�̣��Ƿ��ƶ�!"));
		return ERROR;
	}
	return OK;
}
/* 				��ŵ����Ϸ					*/
void PlayGame(char from, char to)
{
	char command[20];
	int flag;
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	gotoxy(hout, 0, CHOICE9_BASE);
	cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
	while (true) {
		gotoxy(hout, LEN_TIPS, CHOICE9_BASE);
		setcursor(hout, CURSOR_VISIBLE_NORMAL);
		cin >> command;
		setcursor(hout, CURSOR_INVISIBLE);
		flag = JudgeValidity(command);
		if (flag == OK) {
			step++;
			SolveMovement(command[0], command[1]);
			MovePlate(command[0], command[1]);
			setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
			PrintTransversal(8, command[0], command[1]);
			SleepTime(4);
			PrintVertical(9);
			SleepTime(4);
			/*��Ϸ�ɹ�*/
			if (p[to - 'A'] == n + 1) {
				gotoxy(hout, 0, CHOICE9_BASE + 1);
				cout << "��Ϸ����!!!!!";
				return;
			}
		}
		else if (flag == QUIT)
			return;
		/*��������*/

		showch(hout, LEN_TIPS, CHOICE9_BASE, ' ', COLOR_BLACK, COLOR_HWHITE, strlen(command));
	}
}
/*				��ʼ������					*/
void InitialSetting(int choice, int*delay, char *Start, char*End)
{
	while (true) {
		cout << "�����뺺ŵ������(1-10):\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n > 0 && n < 11)
			break;
	}
	while (true) {
		cout << "��������ʼ��(A-C) \n";
		cin >> *Start;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (JudgeChar(*Start))
			break;
	}
	while (true) {
		cout << "������Ŀ����(A-C) \n";
		cin >> *End;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (*End == *Start || labs(*End - *Start) == 32) {
			cout << "Ŀ����(" << End << ")��������ʼ��(" << *Start << ")��ͬ" << endl;
			continue;
		}
		if (JudgeChar(*End))
			break;
	}
	if (*Start > 'C')
		*Start -= 32;
	if (*End > 'C')
		*End -= 32;
	/*			�ӳ�			*/
	if (choice == 4 || choice == 8)
		while (true) {
			cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���)\n";
			cin >> *delay;
			if (!cin.good()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if (*delay >= 0 && *delay <= 5)
				break;
		}

}
/*		 �������и���choiceѡ��������		*/
void Solve(int choice, char Start, char End, int delay)
{
	step = 0;
	switch (choice) {
		case(1):case(2):
			break;
		case(3):
			InitPlates(Start, End);
			break;
		case(4):
			InitPlates(Start, End);
			PrintInitial(choice, Start, End, delay);
			break;
		case(5):
			DrawColorPillar();
			return;						//ATTENTION!!!!!
		case(6):
			InitPlates(Start, End);
			PrintInitial(choice, Start, End, delay);
			DrawColorPillar();
			DrawColorPlates();
			return;						//ATTENTION!!!!!
		case(7):
			InitPlates(Start, End);
			PrintInitial(choice, Start, End, delay);
			DrawColorPillar();
			DrawColorPlates();
			break;
		case(8):
			InitPlates(Start, End);
			PrintInitial(choice, Start, End, delay);
			DrawColorPillar();
			DrawColorPlates();
			break;
		case(9):
			InitPlates(Start, End);
			PrintInitial(choice, Start, End, delay);
			DrawColorPillar();
			DrawColorPlates();
			PlayGame(Start, End);
	}
	Hanoi(n, Start, End, char(3 * 'B' - Start - End), choice, delay);
}
/*				  main						*/
int main()
{
	int choice, delay;
	char Start, End;
	while (true) {
		setconsoleborder(hout, END12_Y, END12_X);
		setcursor(hout, CURSOR_VISIBLE_NORMAL);
		system("color 0F");
		cout << "-----------------------" << endl;
		cout << "1.������" << endl;
		cout << "2.������(������¼)" << endl;
		cout << "3.�ڲ�������ʾ(����)" << endl;
		cout << "4.�ڲ�������ʾ(����+����)" << endl;
		cout << "5.ͼ�ν�-Ԥ��-������Բ��" << endl;
		cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������" << endl;
		cout << "7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
		cout << "8.ͼ�ν�-�Զ��ƶ��汾" << endl;
		cout << "9.ͼ�ν�-��Ϸ��" << endl;
		cout << "0.�˳�" << endl;
		cout << "----------------------" << endl;
		cout << "[��ѡ��0-9]";

		do {
			choice = _getch();
			choice -= '0';
		} while (choice < 0 || choice > 9);
		if (!choice)
			break;
		cout << choice << endl;

		if (choice != 5)
			InitialSetting(choice, &delay, &Start, &End);
		else {
			delay = 0;
			Start = End = 'a';
		}
		if (choice >= 3 && choice <= 7)
			setconsoleborder(hout, END37_Y, END37_X);
		else if (choice >= 8)
			setconsoleborder(hout, END89_Y, END89_X);

		setcursor(hout, CURSOR_INVISIBLE);
		Solve(choice, Start, End, delay);
		setcolor(hout, COLOR_BLACK, COLOR_HWHITE);

		if (choice == 3)
			putchar('\n');
		if (choice >= 4 && choice <= 7)
			gotoxy(hout, 0, END37_X - 2);
		else if (choice >= 8)
			gotoxy(hout, 0, END89_X - 2);
		pause();
		system("cls");
	}
	gotoxy(hout, 0, END12_X - 1);
	setconsoleborder(hout, 75, 50);
	system("color F0");
	setcolor(hout, COLOR_HWHITE, COLOR_BLACK);
	PrintEasterEgg();
	return 0;
}
/*				 Easter Egg				    */
void PrintEasterEgg()
{
	printf("::\n                      :;J7, :,                   \
     ::;7:\n                      ,ivYi, ,                       ;\
LLLFS:\n                      :iv7Yi                       :7ri;j5\
PL\n                     ,:ivYLvr                    ,ivrrirrY2X,\n\
                     :;r@Wwz.7r:                :ivu@kexianli.\n   \
                 :iL7::,:::iiirii:ii;::::,,irvF7rvvLujL7ur\n       \
            ri::,:,::i:iiiiiii:i:irrv177JX7rYXqZEkvv17\n           \
     ;i:, , ::::iirrririi:i:::iiir2XXvii;L8OGJr71i\n              :\
,, ,,:   ,::ir@mingyi.irii:i:::j1jri7ZBOS7ivv,\n                 ,:\
:,    ::rv77iiiriii:iii:i::,rvLq@huhao.Li\n             ,,      ,, \
,:ir7ir::,:::i;ir:::i:i::rSGGYri712:\n           :::  ,v7r:: ::rrv7\
7:, ,, ,:i7rrii:::::, ir7ri7Lri\n          ,     2OBBOi,iiir;r::   \
     ,irriiii::,, ,iv7Luur:\n        ,,     i78MBBi,:,:::,:,  :7FSL\
: ,iriii:::i::,,:rLqXv::\n        :      iuMMP: :,:::,:ii;2GY7OBB0v\
iiii:i:iii:i:::iJqL;::\n       ,     ::::i   ,,,,, ::LuBBu BBBBBEri\
i:i:i:i:i:i:i:r77ii\n      ,       :       , ,,:::rruBZ1MBBqi, :,,,\
:::,::::::iiriri:\n     ,               ,,,,::::i:  @arqiao.       \
,:,, ,:::ii;i7:\n    :,       rjujLYLi   ,,:::::,:::::::::,,   ,:i,\
:,,,,,::i:iii\n    ::      BBBBBBBBB0,    ,,::: , ,:::::: ,      ,,\
,, ,,:::::::\n    i,  ,  ,8BMMBBBBBBi     ,,:,,     ,,, , ,   , , ,\
 :,::ii::i::\n    :      iZMOMOMBBM2::::::::::,,,,     ,,,,,,:,,,::\
::i:irr:i:::,\n    i   ,,:;u0MBMOG1L:::i::::::  ,,,::,   ,,, ::::::\
i:i:iirii:i:i:\n    :    ,iuUuuXUkFu7i:iii:i:::, :,:,: ::::::::i:i:\
::::iirr7iiri::\n    :     :rk@Yizero.i:::::, ,:ii:::::::i:::::i::,\
::::iirrriiiri::,\n     :      5BMBBBBBBSr:,::rv2kuii:::iii::,:i:,,\
 , ,,:,:i@petermu.,\n          , :r50EZ8MBBBBGOBBBZP7::::i::,:::::,\
: :,:,::i;rrririiii::\n              :jujYY7LS0ujJL7r::,::i::,:::::\
:::::::::iirirrrrrrr:ii:\n           ,:  :@kevensun.:,:,,,::::i:i::\
:::,,::::::iir;ii;7v77;ii;i,\n           ,,,     ,,:,::::::i:iiiii:\
i::::,, ::::iiiir@xingjief.r;7:i,\n        , , ,,,:,,::::::::iiiiii\
iiii:,:,:::::::::iiir;ri7vL77rrirri::\n         :,, , ::::::::i:::i\
:::i:i::,,,,,:,::i:i:::iir;@Secbone.ii:::\n");
	cout << "����������..��������..����һ��΢Ц..\n";
}