/*1651574 1班 贾昊霖*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cmath>
using namespace std;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
int A[15] = { 0 }, B[15] = { 0 }, C[15] = { 0 };
int pa = 1, pb = 1, pc = 1, delay;
char Start,End;
bool display;
/*				延迟时间						*/		
inline void SleepTime(int delay)
{
	switch (delay) {
		case(0):
			while (_getch() != '\r')
				;	//按下回车才能继续
			break;
		case(1):
			Sleep(1000);
			break;
		case(2):
			Sleep(500);
			break;
		case(3):
			Sleep(300);
			break;
		case(4):
			Sleep(100);
			break;
		default:
			Sleep(10);
			break;
	}
}
/*				定位							*/
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}
/*				初始化栈中元素				*/
void InitPlates(int n, char Start, char End)
{
	if (Start == 'A') {
		for (int i = 1; i <= n; i++)
			A[i] = n - i + 1;
		pa = n + 1;
	}
	else if (Start == 'B') {
		for (int i = 1; i <= n; i++)
			B[i] = n - i + 1;
		pb = n + 1;
	}
	else {
		for (int i = 1; i <= n; i++)
			C[i] = n - i + 1;
		pc = n + 1;
	}
}
/*			操作栈顶指针改变栈中元素			*/
void MovePlate(char from, char to)
{
	int tmp;
	switch (from) {
		case('A'):
			tmp = A[--pa];
			break;
		case('B'):
			tmp = B[--pb];
			break;
		default:
			tmp = C[--pc];
	}
	switch (to) {
		case('A'):
			A[pa++] = tmp;
			break;
		case('B'):
			B[pb++] = tmp;
			break;
		default:
			C[pc++] = tmp;
	}
}
/*				打印纵向汉诺塔				*/
void PrintPlates()
{
	for (int i = 10; i >=1; i--) {
		gotoxy(hout, 11, 12 - i);
		if (i >= pa)
			cout << ' ';
		else
			cout << A[i];
	}
	for (int i = 10; i >= 1; i--) {
		gotoxy(hout, 21, 12 - i);
		if (i >= pb)
			cout << ' ';
		else
			cout << B[i];
	}
	for (int i = 10; i >= 1; i--) {
		gotoxy(hout, 31, 12 - i);
		if (i >= pc)
			cout << ' ';
		else
			cout << C[i];
	}
}
/*				打印横向汉诺塔				*/
void PrintStack(int step, int num, char from, char to)
{
	gotoxy(hout, 0, 17);
	if (step == 1)
		cout << "初始： ";
	else
		cout << "第" << setw(4) << step << "步(" << num << "#: "
		<< from << "-->" << to << ")  ";
	if (!display)
		return;
	cout << "A:";
	for (int i = 1; i <= 10; i++) {
		if (i < pa)
			cout << setw(2) << A[i];
		else
			cout << "  ";
	}
	cout << " B:";
	for (int i = 1; i <= 10; i++) {
		if (i < pb)
			cout << setw(2) << B[i];
		else
			cout << "  ";
	}
	cout << " C:";
	for (int i = 1; i <= 10; i++) {
		if (i < pc)
			cout << setw(2) << C[i];
		else
			cout << "  ";
	}
}
/*				打印初始化元素				*/
void PrintInitial()
{
	gotoxy(hout, 0, 0);
	cout << "从 " << Start << " 移动到 " << End << "，共 " << pa + pb + pc - 3
		<< " 层，延时设置为 " << delay << "， ";
	if (!delay)
		cout << "不";
	cout << "显示内部数组值";
	gotoxy(hout, 9, 12);
	cout << "=========================";
	gotoxy(hout, 9, 13);
	cout << "  A         B         C";
	PrintStack(1, 1, Start, End);
	SleepTime(delay);
	PrintPlates();
	SleepTime(delay);
}
/*				hanoi主解决函数				*/
void Hanoi(int num, char from, char to, char by)
{
	static int step = 0;
	if (num == 1) {
		MovePlate(from, to);
		PrintStack(++step, num, from, to);
		SleepTime(delay);
		PrintPlates();
		SleepTime(delay);
		return;
	}
	Hanoi(num - 1, from, by, to);

	MovePlate(from, to);
	PrintStack(++step, num, from, to);
	SleepTime(delay);
	PrintPlates();
	SleepTime(delay);
	Hanoi(num - 1, by, to, from);
}
/*				判断字符合法性				*/
bool JudgeChar(char c)
{
	if (c <= 'C' && c >= 'A')
		return true;
	else if (c <= 'c' && c >= 'a')
		return true;
	return false;
}
/*				初始化设置					*/
int InitialSetting()
{
	int n;
	while (true) {
		cout << "请输入汉诺塔层数(1-10):";
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
		cout << "请输入起始柱(A-C) ";
		cin >> Start;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (JudgeChar(Start))
			break;
	}
	while (true) {
		cout << "请输入目标柱(A-C) ";
		cin >> End;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (End == Start || labs(End - Start) == 32) {
			cout << "目标柱(" << End << ")不能与起始柱(" << Start << ")相同" << endl;
			continue;
		}
		if (JudgeChar(End))
			break;
	}
	if (Start > 'C')
		Start -= 32;
	if (End > 'C')
		End -= 32;
	/*			延迟			*/
	while (true) {
		cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短) ";
		cin >> delay;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (delay >= 0 && delay <= 5)
			break;
	}
	/*			显示			*/
	while (true) {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示) ";
		cin >> display;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return n;
}
/*				main						*/
int main()
{
	int n;
	system("mode con cols=100 lines=30");
	n = InitialSetting();

	system("cls");

	InitPlates(n, Start, End);
	PrintInitial();

	Hanoi(n, Start, End, char(3 * 'B' - Start - End));

	gotoxy(hout, 0, 18);
	//cout << "累死了.....\n";
	return 0;
}