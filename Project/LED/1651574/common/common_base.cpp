#include "common.h"
/*						DFS_recursion				*/
void DFS_recursion(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int x = DT[Tmp_x], y = DT[Tmp_y];
	if ((x < 0 || x >= DT[Column] || y < 0 || y >= DT[Array]))
		return;
	//if (Table[x][y] == 0)	//	means to be (x<1 || x>Array || y<1 || y>Column)
	//	return;
	if (Table[DT[Orig_y]][DT[Orig_x]] != Table[y][x] || MarkTable[y][x] != UNSIGNED)
		return;
	MarkTable[y][x] = SIGNED;
	DT[Count]++;						//	counter
	for (int i = 0; i < 4; i++) {
		DT[Tmp_y] += MOVE_XY[i][0];
		DT[Tmp_x] += MOVE_XY[i][1];
		DFS_recursion(Table, MarkTable, DT);
		DT[Tmp_y] -= MOVE_XY[i][0];
		DT[Tmp_x] -= MOVE_XY[i][1];		//	important!
	}
	return;
}

/*choose the solutions according to the main function*/
void Solve(int(*Table)[10], int(*MarkTable)[10], int *DataTable)
{
	int *&DT = DataTable;
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	switch (DT[Choice]) {
	case(1):case(2):
		setconsoleborder(INITIAL_Y, INITIAL_X);
		GenerateTable(Table, DT);
		PrintTable(Table, MarkTable, DT, 1);
		ExecuteCommand(Table, MarkTable, DT);
		PrintTable(Table, MarkTable, DT, 2);
		PrintTable(Table, MarkTable, DT, 3);
		break;
	case(3):case(4):
		setconsoleborder(INITIAL_Y, INITIAL_X);
		GenerateTable(Table, DT);
		do {
			PrintTable(Table, MarkTable, DT, 1);
			ExecuteCommand(Table, MarkTable, DT);
			PrintTable(Table, MarkTable, DT, 2);
			PrintTable(Table, MarkTable, DT, 3);
		} while (CombineNumber(Table, MarkTable, DT));
		break;
	case(5):
		GenerateTable(Table, DT);
		DrawFigure(Table, MarkTable, DT, false);
		break;
	case(6):
		GenerateTable(Table, DT);
		DrawFigure(Table, MarkTable, DT, true);
		break;
	case(7):
		GenerateTable(Table, DT);
		DrawFigure(Table, MarkTable, DT, true);
		ChooseBox(Table, MarkTable, DT);
		break;
	case(8):case(9):
		GenerateTable(Table, DT);
		DrawFigure(Table, MarkTable, DT, true);
		ChooseBox(Table, MarkTable, DT);
	}
	EnterEnd();
}

/*				Draw the Boarder of the graph 		*/
void DrawBoarder(int x, int y, int col, int arr, int interval, bool flag)
{
	setcolor(COLOR_HWHITE, COLOR_BLACK);
	gotoxy(x, y);
	int end_i = 2 + 3 * arr + flag * (arr - 1);
	int end_j = 2 + 3 * col + flag * (col - 1);
	int t = interval;
	for (int i = 1; i <= end_i; i++) {
		for (int j = 1; j <= end_j; j++) {
			if (i == 1 && j == 1)
				cout << "�X";
			else if (i == 1 && j == end_j)
				cout << "�[";
			else if (i == end_i && j == 1)
				cout << "�^";
			else if (i == end_i && j == end_j)
				cout << "�a";
			else if (i == 1) {
				if (flag && j % t == 1)
					cout << "�h";
				else
					cout << "�T";
			}
			else if (j == 1) {
				if (flag && i % t == 1)
					cout << "�c";
				else
					cout << "�U";
			}
			else if (j == end_j) {
				if (flag && i % t == 1)
					cout << "�f";
				else
					cout << "�U";
			}
			else if (i == end_i) {
				if (flag && j % t == 1)
					cout << "�k";
				else
					cout << "�T";
			}
			else if (flag && j % t == 1 && i % t == 1)
				cout << "��";
			else if (flag && i % t == 1)
				cout << "��";
			else if (flag && j % t == 1)
				cout << "��";
			else
				cout << "  ";
		}
		putchar('\n');
		Sleep(30);
	}
}

/*				 Falling Movement of Box			*/
void UpdateDrawing(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag = true)
{
	int X = DT[Orig_x], Y = DT[Orig_y];
	int x, y;
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
	showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);//clear
	for (int i = 0; i < DT[Array]; i++) {
		for (int j = 0; j < DT[Column]; j++) {
			if (MarkTable[i][j] == SIGNED) {
				CalcCoord(x, y, j, i);
				Table[i][j] = 0;
				DrawBox(x, y, 0, 9);
			}
		}
	}
	Sleep(20);
	UpdateTable(Table, MarkTable, DT, flag);
}

/*				Falling Movement of Box				*/
void FallingMovement(int(*Table)[10], int *DT, int i, int j, int k)
{
	int x = 2 + i * 6 + 2 * i;
	int y = 2 + k * 3 + k;
	int end = 2 + j * 3 + j;
	int counter = 0;
	while (y < end) {
		counter++;
		DrawBox(x, y, Table[k][i], 9);
		if (!(counter % 4)) {
			showstr(x, y, "������", COLOR_HWHITE, COLOR_BLACK);
		}
		y++;
		DrawBox(x, y, Table[k][i], 0);
	}
}

/*		Print Table according to the option			*/
void PrintTable(int(*Table)[10], int(*MarkTable)[10], int *DT, int option)
{
	if (option == 1)
		std::cout << "��ǰ���飺\n";
	else if (option == 2)
		std::cout << "Ѱ�ҽ�����飺\n";
	else if (option == 3)
		std::cout << "��ǰ����(��ͬɫ��ʶ)��\n";
	else if (option == 4)
		std::cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��\n";
	else if (option == 5)
		std::cout << "��0�������(��ͬɫ��ʶ)��\n";
	else if (option == 6)
		std::cout << "��ֵ���������(��ͬɫ��ʶ)��\n";

	std::cout << "  |";
	for (int i = 0; i < DT[Column]; i++)
		std::cout << " " << i << " ";
	std::cout << "\n--+";
	for (int i = 0; i < DT[Column]; i++)
		std::cout << "---";
	putchar('\n');
	for (int i = 0; i < DT[Array]; i++) {
		std::cout << char('A' + i) << " |";
		for (int j = 0; j < DT[Column]; j++) {
			if (option == 1)
				std::cout << " " << Table[i][j] << " ";
			else if (option == 2) {
				if (MarkTable[i][j] == SIGNED)
					std::cout << " * ";
				else
					std::cout << " 0 ";
			}
			else if (option == 3 || option == 6) {
				if (MarkTable[i][j] == SIGNED) {
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					std::cout << " " << Table[i][j] << " ";
					setcolor(COLOR_BLACK, COLOR_HWHITE);
				}
				else
					std::cout << " " << Table[i][j] << " ";
			}
			else if (option == 4) {
				if (MarkTable[i][j] == SIGNED) {
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					if (i == DT[Orig_y] && j == DT[Orig_x])
						std::cout << " " << Table[i][j] << " ";
					else
						std::cout << " 0 ";
					setcolor(COLOR_BLACK, COLOR_HWHITE);
				}
				else
					std::cout << " " << Table[i][j] << " ";
			}
			else if (option == 5) {
				if (MarkTable[i][j] == SIGNED) {
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					std::cout << " 0 ";
					setcolor(COLOR_BLACK, COLOR_HWHITE);
				}
				else
					std::cout << " " << Table[i][j] << " ";
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

/*		Check whether there is box to eliminate		*/
bool CheckContinue(int(*Table)[10], int * DT)
{
	int n = 0;
	int Mark[10][10];
	memset(Mark, UNSIGNED, sizeof(int) * 10 * 10);
	for (int i = 0; i < DT[Array]; i++) {
		for (int j = 0; j < DT[Column]; j++) {
			DT[Tmp_y] = i;
			DT[Tmp_x] = j;
			DFS_recursion(Table, Mark, DT);
			n += DT[Count];
		}
	}
	if (n)
		return true;
	cout << "��Ϸ����������";
	return false;
}

/*		previous operation before choose box		*/
void PreChooseBox(int(*Table)[10], int *DT, bool flag, bool tag, int arr, int col, int x, int y)
{
	if (flag) {
		DrawBox(x, y, Table[arr][col], 1);
		showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		setcolor(COLOR_BLACK, COLOR_HWHITE);
		gotoxy(0, DT[Bottom] - 1);
		if (tag)
			cout << "[���λ��]:";
		else
			cout << "[����λ��]";
		cout << char('A' + arr) << col + 1;
	}
	else {
		DrawBox(x, y, Table[arr][col], 0);
		showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		setcolor(COLOR_BLACK, COLOR_HYELLOW);
		gotoxy(0, DT[Bottom] - 1);
		cout << "[���λ��]:λ�÷Ƿ�";
	}
}

/*				choice == 1 0r 2 Command			*/
void ExecuteCommand(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int cur_x, cur_y;
	char command[10];
	while (true) {
		std::cout << "������ĸ+������ʽ[����c1]����������꣺";
		getxy(cur_x, cur_y);
		while (true) {
			std::cin >> command;
			if (JudgeCommand(Table, command, DT))
				break;
			showstr(cur_x, cur_y, "      ", COLOR_BLACK, COLOR_HWHITE);
			std::cout << "\n������Ч��Χ��ѡ��!";
			gotoxy(cur_x, cur_y);
		}
		showch(0, cur_y + 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		gotoxy(0, cur_y + 1);
		std::cout << "����Ϊ" << command[0] << "��" << command[1] << "��\n";
		DT[Orig_y] = command[0] - 'A';
		DT[Orig_x] = command[1] - '0';
		DT[Count] = 0;
		MarkTable[DT[Orig_y]][DT[Orig_x]] = SIGNED;
		for (int i = 0; i < 4; i++) {
			DT[Tmp_y] = DT[Orig_y] + MOVE_XY[i][0];
			DT[Tmp_x] = DT[Orig_x] + MOVE_XY[i][1];
			DFS_recursion(Table, MarkTable, DT);
		}
		if (DT[Count])
			break;
		MarkTable[DT[Orig_y]][DT[Orig_x]] = UNSIGNED;
		std::cout << "����ľ�������λ�ô���������ֵͬ������������\n";
	}
	putchar('\n');
}

/*		  Execute order according to the cursor		*/
bool GameType(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
	//cout << "��ͷ���ƶ���ȡ��ѡ�񣬻س����ϳ�\n";
	int x, y;
	MarkTable[DT[Orig_y]][DT[Orig_x]] = SIGNED;
	for (int i = 0; i < 4; i++) {
		DT[Tmp_y] = DT[Orig_y] + MOVE_XY[i][0];
		DT[Tmp_x] = DT[Orig_x] + MOVE_XY[i][1];
		DFS_recursion(Table, MarkTable, DT);
	}
	if (!DT[Count]) {
		setcolor(COLOR_BLACK, COLOR_HYELLOW);
		std::cout << "��Χ����ֵͬ!";
		setcolor(COLOR_BLACK, COLOR_HWHITE);
		std::cout << "����������\n";
		MarkTable[DT[Orig_y]][DT[Orig_x]] = UNSIGNED;
		return false;
	}
	ComplementBox(Table, MarkTable, DT, false);	//	mark the signed box

												/*sparkle*/
	CalcCoord(x, y, DT[Orig_x], DT[Orig_y]);
	for (int i = 1; i <= TIMES; i++) {
		DrawBox(x, y, Table[DT[Orig_y]][DT[Orig_x]], 2);
		Sleep(5);
		DrawBox(x, y, Table[DT[Orig_y]][DT[Orig_x]], 3);
		Sleep(5);
	}
	return true;
}


/*					Draw the figure					*/
void DrawFigure(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag)
{
	int arr = DT[Array], col = DT[Column];
	int Boarder_x = 4 + col * 2 * 3 + flag * (col - 1) * 2;
	int Boarder_y = 3 + arr * 3 + flag * (arr - 1);
	int cur_x, cur_y;
	setconsoleborder(Boarder_x + 1, Boarder_y + 5);
	setcursor(CURSOR_INVISIBLE);
	cout << "��Ļ��ǰ����Ϊ:" << Boarder_y + 5 << "��" << Boarder_x + 2 << "��" << endl;
	DrawBoarder(0, 1, col, arr, 4, flag);
	for (int i = 0; i < arr; i++) {
		for (int j = 0; j < col; j++) {
			cur_x = 2 + j * 3 * 2 + flag * j * 2;
			cur_y = 2 + i * 3 + flag * i;
			DrawBox(cur_x, cur_y, Table[i][j], 0);
		}
	}
	DT[Bottom] = Boarder_y + 3;
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, Boarder_y + 2);
}


void DrawBox(int x, int y)
{
	gotoxy(x, y);
	cout << "�X�T�[";
	gotoxy(x, y + 1);
	cout << "�U��U";
	gotoxy(x, y + 2);
	cout << "�^�T�a";
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
		if (!fin.is_open()) {
			//cout << "�޷����ļ�" << endl;
			//return -1;
		}
		//��������....һ������...
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

		for (int i = 0; i < 3; i++)
			judge |= (unsigned(((dataSet->pool[dataSet->y + i] >> (11 - tmp)) & (0x1F)) << (0x10 - 8 * i)));
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
	cout << "Score��" << dataSet->score;

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
	cout << "Control Panel��";
	gotoxy(90, 37);
	cout << "Move left��				�� A 4";
	gotoxy(90, 38);
	cout << "Move right��				�� D 6";
	gotoxy(90, 39);
	cout << "Move downfoward��			�� S 2";
	gotoxy(90, 40);
	cout << "Clockwise rotation��			�� W 8";
	gotoxy(90, 41);
	cout << "Anti-clockwise rotation��		0";
	gotoxy(90, 42);
	cout << "Drop to the ground:			space";
	gotoxy(90, 43);
	cout << "Pause��				enter";
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
	cout << "PRESS 'Y' TO TRY AGAIN!��THEN PRESS 'N' TO END";

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
