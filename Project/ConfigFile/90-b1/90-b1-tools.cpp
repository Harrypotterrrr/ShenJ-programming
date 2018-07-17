#include "90-b1.h"
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
			DFS_recursion(Table,Mark,DT);
			n += DT[Count];
		}
	}
	if (n)
		return true;
	cout << "游戏结束！！！";
	return false;
}

/*				Calculate the Score					*/
void CalcScore(int *DT, int N)
{
	gotoxy(0, 0);
	DT[Score] += N * 5;
	cout << "本次得分：" << N * 5 << " 总得分为：" << DT[Score];
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
