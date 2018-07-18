/* 1651574 º÷Íª¡ÿ 1∞‡*/
#include "90-b2.h"

void printPoolBorder() {
	int8_t y;

	int endx = 2 + COLUMN * 6, endy = ROW_BEGIN + (ARRAY - 1) * 3;
	setcolor(COLOR_HWHITE, COLOR_HWHITE);
	for (y = ROW_BEGIN; y < endy; ++y)
	{
		gotoxy(COL_BEGIN, y);
		cout << "  ";
		gotoxy(endx, y);
		cout << "  ";
	}
	gotoxy(0, y);
	cout << setw(88) << " ";
}

void printTetrisPool(const TetrisData *dataSet, const TetrisCondition *controlPanel)
{
	int x, y;

	for (y = 0; y < ARRAY - 1; ++y) {
		for (x = 1; x <= COLUMN; ++x) {
			int posx = x * 6 - 4, posy = 1 + y * 3;
			if ((dataSet->pool[y] >> (COLUMN + 1 - x)) & 1) {
				setcolor(COLOR_BLACK, controlPanel->color[y][x]);
				DrawBox(posx, posy);
			}
			else {
				setcolor(COLOR_BLACK, COLOR_BLACK);
				DrawBox(posx, posy);
			}
		}
	}
}

void printCurrentTetris(const TetrisData *dataSet, const TetrisCondition *controlPanel) {
	int x, y, posx, posy;
	y = (dataSet->y > 0) ? (dataSet->y - 1) : 0;
	for (; y < ARRAY - 1 && y < dataSet->y + 6; y++) {
		x = (dataSet->x > 1) ? (dataSet->x - 1) : 1;
		for (; x < COLUMN + 1 && x < dataSet->x + 6; x++) {
			posx = x * 6 - 4;
			posy = 1 + y * 3;
			if ((dataSet->pool[y] >> (COLUMN + 1 - x)) & 1) {
				setcolor(COLOR_BLACK, controlPanel->color[y][x]);
				DrawBox(posx, posy);
			}
			else  if (y < ARRAY) {
				setcolor(COLOR_BLACK, COLOR_BLACK);
				DrawBox(posx, posy);
			}
		}
	}

}

void printNextTetris(const TetrisData *dataSet, const TetrisCondition *controlPanel) {
	setcolor(COLOR_BLACK, COLOR_HCYAN);
	gotoxy(90, 13);
	cout << "Next Number is :		Next Next Number is :";
	int type = dataSet->type[1], ori = dataSet->ori[1];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int tmp = (((numPatternTable[type][ori] >> (0x00 + 8 * i)) >> j) & 1);
			int posx = 6 * (4 - j), posy = 3 * (4 - i);
			if (tmp) {
				setcolor(COLOR_BLACK, dataSet->type[1] | 8);
				DrawBox(90 + posx, 15 + posy);
			}
			else {
				setcolor(COLOR_BLACK, COLOR_BLACK);
				DrawBox(90 + posx, 15 + posy);
			}
		}
	}
	type = dataSet->type[2];
	ori = dataSet->ori[2];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int tmp = (((numPatternTable[type][ori] >> (0x00 + 8 * i)) >> j) & 1);
			int posx = 6 * (4 - j), posy = 3 * (4 - i);
			if (tmp) {
				setcolor(COLOR_BLACK, dataSet->type[2] | 8);
				DrawBox(125 + posx, 15 + posy);
			}
			else {
				setcolor(COLOR_BLACK, COLOR_BLACK);
				DrawBox(125 + posx, 15 + posy);
			}
		}
	}
}

void printScore(const TetrisData *dataSet) {
	static const char *tetrisName = "ITLJZSO";

	setcolor(COLOR_BLACK, COLOR_HGREEN);

	gotoxy(90, 1);
	cout << "Score£∫" << dataSet->score;

	gotoxy(90, 2);
	cout << "Total times:	" << dataSet->erasedTotal;
	for (int i = 0; i < 9; i++) {
		gotoxy(90, 3 + i);
		cout << i << " times" << ":		" << dataSet->erasedCount[i];
	}
}

void printHint() {
	setcolor(COLOR_BLACK, COLOR_HYELLOW);
	gotoxy(90, 36);
	cout << "Control Panel£∫";
	gotoxy(90, 37);
	cout << "Move left£∫				°˚ A 4";
	gotoxy(90, 38);
	cout << "Move right£∫				°˙ D 6";
	gotoxy(90, 39);
	cout << "Move downfoward£∫			°˝ S 2";
	gotoxy(90, 40);
	cout << "Clockwise rotation£∫			°¸ W 8";
	gotoxy(90, 41);
	cout << "Anti-clockwise rotation£∫		0";
	gotoxy(90, 42);
	cout << "Drop to the ground:			space";
	gotoxy(90, 43);
	cout << "Pause£∫				enter";
	gotoxy(90, 44);
}

void runGame(TetrisData *dataSet, TetrisCondition *controlPanel) {
	clock_t clockLast, clockNow;

	clockLast = clock();
	printTetrisPool(dataSet, controlPanel);

	while (!dataSet->dead)
	{
		while (_kbhit())
		{
			keydownControl(dataSet, controlPanel, _getch());
		}

		if (!controlPanel->pause)
		{
			clockNow = clock();

			if (clockNow - clockLast > 0.85F * CLOCKS_PER_SEC) {
				clockLast = clockNow;
				keydownControl(dataSet, controlPanel, 80);
			}
		}
	}
}

bool ifPlayAgain() {
	int ch;

	setcolor(COLOR_HWHITE, COLOR_HRED);
	gotoxy(40, 25);
	cout << "GAME OVER";
	gotoxy(22, 26);
	cout << "PRESS 'Y' TO TRY AGAIN!£¨THEN PRESS 'N' TO END";

	do {
		ch = _getch();
		if (ch == 'Y' || ch == 'y') {
			return true;
		}
		else if (ch == 'N' || ch == 'n') {
			setcolor(COLOR_BLACK, COLOR_BLACK);
			gotoxy(0, 0);
			return false;
		}
	} while (1);
}
