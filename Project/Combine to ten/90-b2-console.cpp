#include "90-b2.h"
/*			 Filling the blank of whole Table		*/
void ComplementBox(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag)
{
	int x, y;
	for (int i = 0; i < DT[Array]; i++)
		for (int j = 0; j < DT[Column]; j++)
			if (MarkTable[i][j] == SIGNED) {
				x = 2 + j * 6 + 2 * j;
				y = 2 + i * 3 + i;
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
	cout << "箭头键移动并取消选择，回车键合成\n";
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
		return false;
	}
	ComplementBox(Table, MarkTable, DT, false);

	/*sparkle*/
	x = 2 + DT[Orig_x] * 6 + 2 * DT[Orig_x];
	y = 2 + DT[Orig_y] * 3 + DT[Orig_y];
	for (int i = 1; i <= TIMES; i++) {
		DrawBox(x, y, Table[DT[Orig_y]][DT[Orig_x]], 2);
		Sleep(5);
		DrawBox(x, y, Table[DT[Orig_y]][DT[Orig_x]], 3);
		Sleep(5);
	}
	return true;
}
/*					Game Controler					*/
bool GameControl(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	char c;
	if (!GameType(Table, MarkTable, DT))
		return true;
	UpdateDrawing(Table, MarkTable, DT);
	GenerateTable(Table, DT);

	ComplementBox(Table, MarkTable, DT, true);
	if (DT[Choice] == 8)
		return false;
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
	cout << "本次合成结束,按Q退出游戏\n";
	while (true) {
		c = _getch();
		if (c == 'q' || c == 'Q')
			return false;
		return true;
	}
}
/*				Choose Box by cursor key			*/
void ChooseBox(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int End_col = DT[Column], End_arr = DT[Array];
	int col = 0, arr = 0, x = 2, y = 2;
	unsigned short _char;
	setcursor(CURSOR_INVISIBLE);
	while (true) {
		DrawBox(x, y, Table[arr][col], 1);
		showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		setcolor(COLOR_BLACK, COLOR_HWHITE);
		gotoxy(0, DT[Bottom] - 1);
		cout << "方向键控制移动，回车确定\n";
		_char = _getch();
		if (_char == 0xd) {
			if (DT[Choice] == 7)
				break;
			DT[Orig_x] = col;
			DT[Orig_y] = arr;
			DT[Count] = 0;
			if (!GameControl(Table, MarkTable, DT))
				break;
			memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);		//important!
		}
		else if (_char != 0xe0)
			continue;
		else {
			_char = _getch();
			DrawBox(x, y, Table[arr][col], 0);
			if (_char == 0x4b && col > 0)//left
				col--;
			else if (_char == 0x50 && arr < End_arr - 1)//down
				arr++;
			else if (_char == 0x4d && col < End_col - 1)//right
				col++;
			else if (_char == 0x48 && arr > 0)//up
				arr--;
			x = 2 + col * 6 + 2 * col;
			y = 2 + arr * 3 + arr;
			DrawBox(x, y, Table[arr][col], 1);
		}
	}
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