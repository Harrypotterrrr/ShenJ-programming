#include "common.h"
/*						input Enter					*/
void InputEnter(int x)
{
	switch (x) {
		case(0):
			std::cout << "\n按回车键继续\n";
			break;
		case(1):
			cout << "按回车键或者鼠标点击进行数组下落除0操作..." << endl;
			break;
		case(5):
			cout << "按回车键或者鼠标点击进行新值填充..." << endl;
			break;
		case(8):
			cout << "本次合成结束，按回车键继续新一次的合成..." << endl;
			break;
	}
	while (_getch() != '\r')
		;
}

/*calculate the coordination according to the column and array  */
void CalcCoord(int &x, int &y, const int col, const int arr)
{
	x = 2 + col * 8;
	y = 2 + arr * 4;
}

/*			judge the validity of character			*/
bool JudgeCommand(int(*Table)[10], char *command, int *DT)
{
	if (strlen(command) < 2)
		return false;
	if (command[0] >= 'a' && command[0] <= 'a' + DT[Array] - 1)
		command[0] -= 32;
	int y = command[0] - 'A', x = command[1] - '0';
	if (y < 0 || y > DT[Array] - 1)
		return false;
	if (x < 0 || x > DT[Column] - 1)
		return false;
	if (!Table[y][x])
		return false;
	return true;
}

/*	Calculate TotalGrade accroding to the command	*/
bool CombineNumber(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int X = DT[Orig_x], Y = DT[Orig_y], tmp = 0;
	char c;
	cout << "请确认是否把相邻的相同值合并到A2中(Y/N/Q)：";
	while (true) {
		c = _getch();
		if (c == 'Y' || c == 'y') {
			cout << c << endl;
			for (int i = 0; i < DT[Array]; i++)
				for (int j = 0; j < DT[Column]; j++)
					if (MarkTable[i][j] == SIGNED) {
						tmp += 3 * Table[i][j];
						/*				if (i == Y && j == X)
						Table[Y][X]++;
						else*/
						Table[i][j] = 0;
					}
			DT[Score] += tmp;
			PrintTable(Table, MarkTable, DT, 4);
			cout << "本次得分：" << tmp << " 总得分：" << DT[Score] << endl;
			putchar('\n');
			UpdateTable(Table, MarkTable, DT, true);
			PrintTable(Table, MarkTable, DT, 5);
			InputEnter(5);
			//GenerateTable(Table, DT);
			PrintTable(Table, MarkTable, DT, 6);
			if (DT[Choice] == 3)
				return false;
			InputEnter(8);
			memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
			return true;
		}
		else if (c == 'n' || c == 'N') {
			cout << c << endl;
			if (DT[Choice] == 3)
				return false;
			PrintTable(Table, MarkTable, DT, 1);
		}
		else if (c == 'q' || c == 'Q') {
			cout << c << endl;
			return false;
		}
	}
}


/*			 Filling the blank of whole Table		*/
void ComplementBox(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag)
{
	int x, y;
	for (int i = 0; i < DT[Array]; i++)
		for (int j = 0; j < DT[Column]; j++)
			if (MarkTable[i][j] == SIGNED) {
				CalcCoord(x, y, j, i);
				if (flag)
					DrawBox(x, y, Table[i][j], 0);
				else if (i == DT[Orig_y] && j == DT[Orig_x])
					DrawBox(x, y, Table[i][j], 2);
				else
					DrawBox(x, y, Table[i][j], 1);
			}
}

/*			      Restore the Table                 */
void RestoreTable(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int x, y;
	for (int i = 0; i < DT[Array]; i++)
		for (int j = 0; j < DT[Column]; j++)
			if (MarkTable[i][j] == SIGNED) {
				CalcCoord(x, y, j, i);
				DrawBox(x, y, Table[i][j], 0);
				MarkTable[i][j] = UNSIGNED;
			}
}

/*				Draw or change the figure			*/
void DrawBox(int x, int y, int num, int flag)
{
	if (flag == 0)
		setcolor(ColorNumber[num], COLOR_BLACK);
	else if (flag == 1)
		setcolor(COLOR_HYELLOW, COLOR_HRED);
	else if (flag == 2)
		setcolor(COLOR_HYELLOW, COLOR_HBLUE);
	else if (flag == 3)
		setcolor(COLOR_YELLOW, COLOR_BLACK);
	else if (flag = 9)
		setcolor(COLOR_HWHITE, COLOR_HWHITE);
	if (!num && flag != 9)
		return;
	gotoxy(x, y);
	cout << "╔═╗";
	gotoxy(x, y + 1);
	cout << "║★║";
	gotoxy(x, y + 2);
	cout << "╚═╝";
	Sleep(30);
}

/*						UpdateTable					*/
void UpdateTable(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag = true)
{
	gotoxy(0, DT[Bottom] - 2);
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	if (flag)
		InputEnter(1);
	int k;
	for (int i = 0; i < DT[Column]; i++)
		for (int j = DT[Array] - 1; j >= 1; j--) {
			if (MarkTable[j][i] == SIGNED) {
				for (k = j - 1; k >= 0; k--) {
					if (MarkTable[k][i] == UNSIGNED && Table[k][i]) {
						Table[j][i] = Table[k][i];
						MarkTable[j][i] = UNSIGNED;
						if (DT[Choice] == 8 || DT[Choice] == 9)
							FallingMovement(Table, DT, i, j, k);
						MarkTable[k][i] = SIGNED;
						Table[k][i] = 0;
						break;
					}
				}
				if (k < 0) {
					if (j == DT[Array])
						MoveColumn(Table, j, DT);
					Table[k][i] = 0;
					MarkTable[j][i] = SIGNED;
				}
			}
		}
}

/*					Generate one Table				*/
void GenerateTable(int(*Table)[10], int *DT)
{
	for (int i = 0; i < DT[Array]; i++)
		for (int j = 0; j < DT[Column]; j++)
			if (!Table[i][j])
				Table[i][j] = rand() % 6 + 1;
}

/*		Move the column to the black place			*/
void MoveColumn(int(*Table)[10], int j, int *DT)
{
	for (int i = j + 1; i < DT[Column]; i++)
		for (int k = 0; k < DT[Array]; k++)
			Table[k][i - 1] = Table[k][i];
	for (int i = 0; i < DT[Array]; i++)
		Table[i][DT[Column] - 1] = 0;
}

/*					Game Controler					*/
bool GameControl(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag = true)
{
	char c;
	if (!GameType(Table, MarkTable, DT))
		return true;
	UpdateDrawing(Table, MarkTable, DT, flag);
	if (DT[Choice] == 8 || false)
		return false;
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
	cout << "本次合成结束,按Q退出游戏\n";
	while (flag) {
		c = _getch();
		if (c == 'q' || c == 'Q')
			return false;
		return true;
	}
	return true;
}

/*					end sentences					*/
void EnterEnd()
{
	int cur_x, cur_y;
	char tmp[20];
	std::cout << "本小题结束，请输入End继续...";
	getxy(cur_x, cur_y);
	while (true) {
		cin >> tmp;
		if (strlen(tmp) == 3 && (tmp[0] == 'e' || tmp[0] == 'E')\
			&& (tmp[1] == 'n' || tmp[1] == 'N')\
			&& (tmp[2] == 'd' || tmp[2] == 'D'))
			break;
		showstr(cur_x, cur_y, "         ", COLOR_BLACK, COLOR_HWHITE);
		std::cout << "\n输入错误，请重新输入.";
		gotoxy(cur_x, cur_y);
	}
	showch(0, cur_y + 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
}

/*				Calculate the Score					*/
void CalcScore(int *DT, int N)
{
	gotoxy(0, 0);
	DT[Score] += N * 5;
	cout << "本次得分：" << N * 5 << " 总得分为：" << DT[Score];
}


/*				  Initial Settings					*/
void InitialSetting(int(*Table)[10], int(*MarkTable)[10], int *DataTable)
{
	int cur_x, cur_y;
	std::cout << "请输入行数(8-10)：";
	while (true) {
		getxy(cur_x, cur_y);
		std::cin >> DataTable[Array];
		if (std::cin.good() && DataTable[Array] >= 8 && DataTable[Array] <= 10)
			break;
		showstr(cur_x, cur_y, "      ", COLOR_BLACK, COLOR_HWHITE);
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "\n输入不合法，请重新输入\n";
		gotoxy(cur_x, cur_y);
	}
	getxy(cur_x, cur_y);
	showch(cur_x, cur_y, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
	gotoxy(cur_x, cur_y);
	std::cout << "请输入列数(8-10)：";
	while (true) {
		getxy(cur_x, cur_y);
		std::cin >> DataTable[Column];
		if (std::cin.good() && DataTable[Column] >= 8 && DataTable[Column] <= 10)
			break;
		showstr(cur_x, cur_y, "      ", COLOR_BLACK, COLOR_HWHITE);
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "\n输入不合法，请重新输入\n";
		gotoxy(cur_x, cur_y);
	}
	getxy(cur_x, cur_y);
	showch(cur_x, cur_y, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
	gotoxy(cur_x, cur_y);

	
	memset(Table, 0, sizeof(int) * 10 * 10);
	memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);
	DataTable[Score] = 0;
}

/*				Choose Box by cursor key			*/
void ChooseBox(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int col = 0, arr = 0, x = 2, y = 2; // arr col begin from 0 !
	int X, Y, maction, keycode1, keycode2;
	bool flag = true, tag = false, pre_singleClick = false;
	int ctr = Array * Column;
	setcursor(CURSOR_INVISIBLE);

	enable_mouse();
	PreChooseBox(Table, DT, flag, tag, arr, col, x, y);
	while (true) {
		int ret = read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		int tmp_arr = -1, tmp_col = -1;
		if (ret == CCT_MOUSE_EVENT) {						//鼠标操作
			tmp_col = (X - 2) / 8;
			tmp_arr = (Y - 2) / 4;
			if (maction == MOUSE_ONLY_MOVED) {
				if (tmp_col == col && tmp_arr == arr)
					continue;
				if (pre_singleClick) {
					RestoreTable(Table, MarkTable, DT);
					pre_singleClick = false;
				}
				if (!Table[tmp_arr][tmp_col] || tmp_col < 0 || tmp_col >= DT[Column] || tmp_arr < 0 || tmp_arr >= DT[Array])
					flag = false;
				else {
					CalcCoord(x, y, col, arr);
					DrawBox(x, y, Table[arr][col], 0);
					arr = tmp_arr;
					col = tmp_col;
					CalcCoord(x, y, col, arr);
					DrawBox(x, y, Table[arr][col], 1);
					flag = true;
				}
			}
			else if (maction == MOUSE_LEFT_BUTTON_CLICK) {
				if (DT[Choice] == 7)
					break;
				DT[Orig_x] = col;
				DT[Orig_y] = arr;
				DT[Count] = 0;
				if (col == tmp_col && arr == tmp_arr && pre_singleClick) {
					memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
					if (!GameControl(Table, MarkTable, DT, false))
						break;
					CalcScore(DT, DT[Count]);
					memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
					pre_singleClick = false;
					ctr -= DT[Count];
					if (ctr < 10 && !CheckContinue(Table, DT))
						break;
				}
				else {
					if (!GameType(Table, MarkTable, DT))
						continue;
					gotoxy(0, DT[Bottom] - 1);
					setcolor(COLOR_BLACK, COLOR_HWHITE);
					cout << "移动鼠标或者键盘选择，取消本次操作";
					pre_singleClick = true;
				}
			}
			tag = true;
		}
		else if (ret == CCT_KEYBOARD_EVENT) {				//键盘操作
			if (keycode1 == 0xe0) {
				if (tmp_col != col || tmp_arr != arr)
					if (pre_singleClick) {
						RestoreTable(Table, MarkTable, DT);
						pre_singleClick = false;
					}
				DrawBox(x, y, Table[arr][col], 0);
				tmp_col = col;
				tmp_arr = arr;
				if (keycode2 == KB_ARROW_DOWN)
					do {
						arr = (arr + 1 + DT[Array]) % DT[Array];
					} while (!Table[arr][col]);
				else if (keycode2 == KB_ARROW_LEFT)
					do {
						col = (col - 1 + DT[Column]) % DT[Column];
					} while (!Table[arr][col]);
				else if (keycode2 == KB_ARROW_RIGHT)
					do {
						col = (col + 1 + DT[Column]) % DT[Column];
					} while (!Table[arr][col]);
				else if (keycode2 == KB_ARROW_UP)
					do {
						arr = (arr - 1 + DT[Array]) % DT[Array];
					} while (!Table[arr][col]);
					CalcCoord(x, y, col, arr);
					DrawBox(x, y, Table[arr][col], 1);
			}
			else if (keycode1 == 0x0d) {
				if (DT[Choice] == 7)
					break;
				else {
					DT[Orig_x] = col;
					DT[Orig_y] = arr;
					DT[Count] = 0;
					if (!GameControl(Table, MarkTable, DT))
						break;
					CalcScore(DT, DT[Count]);
					memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
				}
			}
			tag = false;
		}
		if (!pre_singleClick)
			PreChooseBox(Table, DT, flag, tag, arr, col, x, y);
	}
	disable_mouse();
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
}


void insertTetris(TetrisData *dataSet) {
	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];


	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		for (int i = 0; i < 3; i++)
			dataSet->pool[dataSet->y + 2 - i] |= (((tetris >> (0x00 + 8 * i)) & 0x1F) << (11 - dataSet->x));
	}
	else {
		for (int i = 0; i < 5; i++)
			dataSet->pool[dataSet->y + 4 - i] |= (((tetris >> (0x00 + 8 * i)) & 0x07) << (13 - dataSet->x));
	}
}

void removeTetris(TetrisData *dataSet) {
	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];

	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		for (int i = 0; i < 3; i++)
			dataSet->pool[dataSet->y + 2 - i] &= ~(((tetris >> (0x00 + i * 8)) & 0x001F) << (11 - dataSet->x));
	}
	else {
		for (int i = 0; i < 5; i++)
			dataSet->pool[dataSet->y + 4 - i] &= ~(((tetris >> (0x00 + i * 8)) & 0x007) << (13 - dataSet->x));
	}

}

void setPoolColor(const TetrisData *dataSet, TetrisCondition *controlPanel) {


	int num, posx, posy;
	bool flag = false;

	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];
	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		for (int i = 0; i < 3; i++) {
			num = (tetris >> (0x00 + 8 * i) & 0x001F);
			posy = dataSet->y + 2 - i;
			for (int j = 0; j < 5; j++) {
				posx = dataSet->x + j;
				if (((num >> (4 - j)) & 1))
					controlPanel->color[posy][posx] = (dataSet->type[0] | 8);
			}
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			num = (tetris >> (0x00 + 8 * i) & 0x0007);
			posy = dataSet->y + 4 - i;
			for (int j = 0; j < 3; j++) {
				posx = dataSet->x + j;
				if (((num >> (2 - j)) & 1))
					controlPanel->color[posy][posx] = (dataSet->type[0] | 8);
			}
		}
	}
}

void rotateTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	int8_t ori = dataSet->ori[0];

	removeTetris(dataSet);

	int orix = dataSet->x;
	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3)
		dataSet->x++;
	else
		dataSet->x--;
	dataSet->ori[0] = (controlPanel->clockwise) ? ((ori + 1) & 3) : ((ori + 3) & 3);

	if (checkCollision(dataSet))
	{
		dataSet->x = orix;
		dataSet->ori[0] = ori;
		insertTetris(dataSet);
	}
	else {
		insertTetris(dataSet);
		setPoolColor(dataSet, controlPanel);
		printCurrentTetris(dataSet, controlPanel);
	}
}


void horzMoveTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	int x = dataSet->x;

	removeTetris(dataSet);
	controlPanel->direction == 0 ? (--dataSet->x) : (++dataSet->x);

	if (checkCollision(dataSet)) {
		dataSet->x = x;
		insertTetris(dataSet);
	}
	else {
		insertTetris(dataSet);
		setPoolColor(dataSet, controlPanel);
		printCurrentTetris(dataSet, controlPanel);
	}
}

void moveDownTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	int8_t y = dataSet->y;
	removeTetris(dataSet);
	++dataSet->y;

	if (checkCollision(dataSet)) {
		dataSet->y = y;
		insertTetris(dataSet);
		if (checkErasing(dataSet, controlPanel))
			printTetrisPool(dataSet, controlPanel);
	}
	else {
		insertTetris(dataSet);
		setPoolColor(dataSet, controlPanel);
		printCurrentTetris(dataSet, controlPanel);
	}
}

void dropDownTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	removeTetris(dataSet);
	for (; dataSet->y < ROW_END; ++dataSet->y)
		if (checkCollision(dataSet))
			break;
	--dataSet->y;

	insertTetris(dataSet);
	setPoolColor(dataSet, controlPanel);

	checkErasing(dataSet, controlPanel);
	printTetrisPool(dataSet, controlPanel);
}

bool checkErasing(TetrisData *dataSet, TetrisCondition *controlPanel) {
	static const unsigned scores[5] = { 0, 10, 30, 90, 150 };
	int8_t count = 0;
	int8_t k = 0, y;
	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3)
		y = dataSet->y + 2;
	else
		y = dataSet->y + 4;

	do {
		if (y < ARRAY && dataSet->pool[y] == 0xFFFFU) {
			++count;
			memmove(dataSet->pool + 1, dataSet->pool, sizeof(uint16_t) * y);
			memmove(controlPanel->color[1], controlPanel->color[0],
				sizeof(int8_t[16]) * y);
		}
		else {
			--y;
			++k;
		}
	} while (y >= dataSet->y && k < 4);
	//dataSet->erasedTotal += count; 
	dataSet->score += scores[count];
	if (count > 0)
		dataSet->erasedCount[count - 1]++;
	giveTetris(dataSet, controlPanel);
	setPoolColor(dataSet, controlPanel);
	return (count > 0);
}

void keydownControl(TetrisData *dataSet, TetrisCondition *controlPanel, int key) {
	if (key == 13)  // pause
		controlPanel->pause = !controlPanel->pause;

	if (controlPanel->pause)  // pause state
		return;

	switch (key) {
	case 'w':
	case 'W':
	case '8':
	case 72:  //up
		controlPanel->clockwise = true;  // rotate
		rotateTetris(dataSet, controlPanel);
		break;
	case 'a':
	case 'A':
	case '4':
	case 75:  // left
		controlPanel->direction = 0;
		horzMoveTetris(dataSet, controlPanel);
		break;
	case 'd':
	case 'D':
	case '6':
	case 77:  // right
		controlPanel->direction = 1;  // right
		horzMoveTetris(dataSet, controlPanel);
		break;
	case 's':
	case 'S':
	case '2':
	case 80:  // down
		moveDownTetris(dataSet, controlPanel);
		break;
	case ' ':  // speed up
		dropDownTetris(dataSet, controlPanel);
		break;
	case '0':  // reverse
		controlPanel->clockwise = false;
		rotateTetris(dataSet, controlPanel);
		break;
	default:
		break;
	}
}
