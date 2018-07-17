/* 1651574 贾昊霖 1班*/
#include "90-b2.h"

void DrawBox(int x, int y)
{
	gotoxy(x, y);
	cout << "╔═╗";
	gotoxy(x, y + 1);
	cout << "║★║";
	gotoxy(x, y + 2);
	cout << "╚═╝";
}

void initGame(TetrisData *dataSet, TetrisCondition *controlPanel) {
	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };
	HANDLE g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);
	SetConsoleTitleA("Tetris Game~");
	restartGame(dataSet, controlPanel);
}

void restartGame(TetrisData *dataSet, TetrisCondition *controlPanel, bool flag) {
	memset(dataSet, 0, sizeof(TetrisData)); 
	memcpy(dataSet->pool, modelPatternTable, sizeof(uint16_t[ARRAY]));
	srand((unsigned)time(NULL));

	if (flag) {
		ifstream fin;
		fin.open("tetris.txt", ios::in);
		if (!fin.is_open()){
			//cout << "无法打开文件" << endl;
			//return -1;
		}
		//懒得做了....一个道理...
	}
	dataSet->type[1] = rand() % 10;
	dataSet->ori[1] = rand() & 3;

	dataSet->type[2] = rand() % 10;
	dataSet->ori[2] = rand() & 3;

	memset(controlPanel, 0, sizeof(TetrisCondition));

	giveTetris(dataSet, controlPanel);
	setPoolColor(dataSet, controlPanel);
}

void giveTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	uint64_t tetris;

	dataSet->type[0] = dataSet->type[1];
	dataSet->ori[0] = dataSet->ori[1];
	dataSet->type[1] = dataSet->type[2];
	dataSet->ori[1] = dataSet->ori[2];
	dataSet->type[2] = rand() % 7;
	dataSet->ori[2] = rand() & 3;
	tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];
	dataSet->y = 0;
	dataSet->x = 6;
	if (checkCollision(dataSet)) {
		dataSet->dead = true;
		printCurrentTetris(dataSet, controlPanel);
	}
	else 
		insertTetris(dataSet);
	dataSet->tetrisTotal++;
	dataSet->tetrisCount[dataSet->type[0]]++;
	printNextTetris(dataSet, controlPanel);
	printScore(dataSet);
}

bool checkCollision(const TetrisData *dataSet) {

	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];
	uint64_t judge = 0;

	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		int tmp = dataSet->x;
		if (dataSet->y >= 14)
			return true;

		for (int i = 0; i < 3 ; i++)
			judge |= (unsigned(( (dataSet->pool[dataSet->y + i] >> (11 - tmp)) & (0x1F)) << (0x10 - 8 * i)));
	}
	else {
		if (dataSet->y >= 12)
			return true;
		int tmp = dataSet->x;
		for (int i = 0; i < 5; i++)
			judge |= unsigned(((dataSet->pool[dataSet->y + i] >> (13 - tmp)) & (0x7F)) << (0x20 - 8 * i));
	}
	return ((judge & tetris) != 0);
}