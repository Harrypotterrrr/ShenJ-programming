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
