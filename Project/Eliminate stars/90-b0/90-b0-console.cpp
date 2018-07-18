#include "90-b0.h"
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
/*		  Execute order according to the cursor		*/
bool GameType(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
	//cout << "箭头键移动并取消选择，回车键合成\n";
	int x, y;
	MarkTable[DT[Orig_y]][DT[Orig_x]] = SIGNED;
	for (int i = 0; i < 4; i++) {
		DT[Tmp_y] = DT[Orig_y] + MOVE_XY[i][0];
		DT[Tmp_x] = DT[Orig_x] + MOVE_XY[i][1];
		DFS_recursion(Table, MarkTable, DT);
	}
	if (!DT[Count]) {
		setcolor(COLOR_BLACK, COLOR_HYELLOW);
		std::cout << "周围无相同值!";
		setcolor(COLOR_BLACK, COLOR_HWHITE);
		std::cout << "请重新输入\n";
		MarkTable[DT[Orig_y]][DT[Orig_x]] = UNSIGNED;
		return false;
	}
	ComplementBox(Table, MarkTable, DT, false);

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
/*					Game Controler					*/
bool GameControl(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag = true)
{
	char c;
	if (!GameType(Table, MarkTable, DT))
		return true;
	UpdateDrawing(Table, MarkTable, DT, flag);
	GenerateTable(Table, DT);

	ComplementBox(Table, MarkTable, DT, true);
	if (DT[Choice] == 8 || DT[DataSet::Level] - 1 == DT[DataSet::Goal])
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

/*		previous operation before choose box		*/
void PreChooseBox(int(*Table)[10], int *DT, bool flag, bool tag, int arr, int col, int x, int y)
{
	if (flag) {
		DrawBox(x, y, Table[arr][col], 1);
		showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		setcolor(COLOR_BLACK, COLOR_HWHITE);
		gotoxy(0, DT[Bottom] - 1);
		if (tag)
			cout << "[鼠标位置]:";
		else
			cout << "[键盘位置]";
		cout << char('A' + arr) << col + 1;
	}
	else {
		DrawBox(x, y, Table[arr][col], 0);
		showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		setcolor(COLOR_BLACK, COLOR_HYELLOW);
		gotoxy(0, DT[Bottom] - 1);
		cout << "[鼠标位置]:位置非法";
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
/*				Choose Box by cursor key			*/
void ChooseBox(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int col = 0, arr = 0, x = 2, y = 2; // arr col begin from 0 !
	int X, Y, maction, keycode1, keycode2;
	bool flag = true, tag = false, pre_singleClick = false;
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
				if (tmp_col < 0 || tmp_col >= DT[Column] || tmp_arr < 0 || tmp_arr >= DT[Array])
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
					CalcScore(DT, Table[DT[Orig_x]][DT[Orig_y]], DT[Count]);
					memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
					pre_singleClick = false;
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
					arr = (arr + 1 + DT[Array]) % DT[Array];
				else if (keycode2 == KB_ARROW_LEFT)
					col = (col - 1 + DT[Column]) % DT[Column];
				else if (keycode2 == KB_ARROW_RIGHT)
					col = (col + 1 + DT[Column]) % DT[Column];
				else if (keycode2 == KB_ARROW_UP)
					arr = (arr - 1 + DT[Array]) % DT[Array];
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
					CalcScore(DT, Table[DT[Orig_x]][DT[Orig_y]], DT[Count]);
					memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
				}
			}
			tag = false;
		}
		if(!pre_singleClick)
			PreChooseBox(Table, DT, flag, tag, arr, col, x, y);
	}
	disable_mouse();
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
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
	cout << "屏幕当前设置为:" << Boarder_y + 5 << "行" << Boarder_x + 2 << "列" << endl;
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