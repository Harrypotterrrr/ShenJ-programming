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
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void to_be_continued(const char *prompt, const int X=0, const int Y=22)
{
	setcolor(); //恢复缺省颜色
	gotoxy(X, Y);

	if (prompt) 
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	system("cls"); //调用系统命令清除屏幕
}

/***************************************************************************
  函数名称：
  功    能：在指定位置，用指定颜色，显示一个字符若干次
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	if (1) {
		int x, y;

		/* 显示16*16的配色框，每个字符之间加一个空格 */
		for (y = 0; y<16; y++) {
			for (x = 0; x<16; x++)
				showch(x * 2, y, 'x', y, x, 2);	//在xy位置显示x，用x坐标的值做前景色，y坐标的值做背景色（显示两个x是为了使比例协调，可以换成一个x后观察效果）
			cout << endl; //16个前景色变换完成后，换一行
			Sleep(100);  //延时0.1秒（以毫秒为单位，1000=1秒）
			} //end of for

		to_be_continued("配色显示演示完成");
		}

	if (1) {
		const int MAX_X = 50;
		const int Y = 2;
		const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
		const int fg_color = COLOR_HBLUE;		//前景为亮蓝色
		const char ch = '*';        //字符为*(注意：如果是空格，则前景色无法显示)
		const int LENGTH = 10;
		int x;

		/* 将一串字符从左向右移动 */
		for (x = 0; x<MAX_X; x++) {
			/* 在坐标(x,2)位置处连续打印10个字符 */
			showch(x, Y, ch, bg_color, fg_color, LENGTH);

			/* 延时0.1秒 */
			Sleep(100);

			if (x<MAX_X - 1) {
				/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
				showch(x, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
				}
			} //end of for

		to_be_continued("右移特效完成");
		}

	if (1) {
		const int MAX_Y = 12;
		const int X = 2;
		const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
		const int fg_color = COLOR_HBLUE;	//前景为亮蓝色
		const char ch = '*';        //字符为*(注意：如果是空格，则前景色无法显示)
		const int LENGTH = 10;
		int y;

		/* 将一串字符从上向下移动 */
		for (y = 2; y<MAX_Y; y++) {
			/* 在坐标(x,2)位置处连续打印10个字符 */
			showch(X, y, ch, bg_color, fg_color, LENGTH);

			/* 延时0.3秒 */
			Sleep(300);

			if (y<MAX_Y - 1) {
				/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
				showch(X, y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
				}
			} //end of for

		to_be_continued("下移特效完成");
		}

	if (1) {
		/* 在屏幕的[0,0]-[60,20]区域内随机显示100个字符，值随机，颜色随机
		说明：未判断位置重复，可能最终字符数少于100
		未判断前景色/背景色重复，可能某些位置只看到颜色，看不到字符 */
		const int MAX_X = 60, MAX_Y = 20;
		int x, y, fg_color, bg_color, num;
		char ch;

		srand((unsigned int)(time(0))); //生成种子

		for (num = 0; num<100; num++) {
			x = rand() % (MAX_X + 1);
			y = rand() % (MAX_Y + 1);
			fg_color = rand() % 16;
			bg_color = rand() % 16;
			ch = 33 + rand() % 94;   //ASCII码表中33-126为可见图形字符

									 /* 显示一个1 */
			showch(x, y, ch, bg_color, fg_color, 1);

			/* 延时0.05秒 */
			Sleep(50);
			}  //end of for

		to_be_continued("随机字符演示完成");
		}

	if (1) {
		setcursor(CURSOR_VISIBLE_FULL);
		to_be_continued("光标显示为全高色块", 0, 2);

		setcursor(CURSOR_VISIBLE_HALF);
		to_be_continued("光标显示为半高色块", 0, 4);

		setcursor(CURSOR_INVISIBLE);
		to_be_continued("关闭光标显示", 0, 6);

		setcursor(CURSOR_VISIBLE_NORMAL);
		to_be_continued("光标显示为正常", 0, 8);

		to_be_continued("光标形状演示完成");
		}

	return 0;
}
