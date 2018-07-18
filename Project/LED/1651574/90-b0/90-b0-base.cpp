#include "90-b0.h"
/*			judge the validity of character			*/
bool JudgeCommand(char *command, int *DT)
{
	if (strlen(command) < 2)
		return false;
	if (command[0] >= 'a' && command[0] <= 'a' + DT[Array] - 1)
		command[0] -= 32;
	if (command[0] < 'A' || command[0] > 'A' + DT[Array] - 1)
		return false;
	if (command[1] < '0' || command[1] > '0' + DT[Column] - 1)
		return false;
	return true;
}
/*				choice == 1 0r 2 Command			*/
void ExecuteCommand(int(*Table)[10], int(*MarkTable)[10], int *DT)
{
	int cur_x, cur_y;
	char command[10];
	while (true) {
		std::cout << "请以字母+数字形式[例：c1]输入矩阵坐标：";
		getxy(cur_x, cur_y);
		while (true) {
			std::cin >> command;
			if (JudgeCommand(command, DT))
				break;
			showstr(cur_x, cur_y, "      ", COLOR_BLACK, COLOR_HWHITE);
			std::cout << "\n输入错误，请重新输入.";
			gotoxy(cur_x, cur_y);
		}
		showch(0, cur_y + 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);
		gotoxy(0, cur_y + 1);
		std::cout << "输入为" << command[0] << "行" << command[1] << "列\n";
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
		std::cout << "输入的矩阵坐标位置处无连续相同值，请重新输入\n";
	}
	putchar('\n');
}
/*		Print Table according to the option			*/
void PrintTable(int(*Table)[10], int(*MarkTable)[10], int *DT, int option)
{
	if (option == 1)
		std::cout << "当前数组：\n";
	else if (option == 2)
		std::cout << "寻找结果数组：\n";
	else if (option == 3)
		std::cout << "当前数组(不同色标识)：\n";
	else if (option == 4)
		std::cout << "相同值归并后的数组(不同色标识)：\n";
	else if (option == 5)
		std::cout << "除0后的数组(不同色标识)：\n";
	else if (option == 6)
		std::cout << "新值填充后的数组(不同色标识)：\n";

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
/*					Generate one Table				*/
void GenerateTable(int(*Table)[10], int *DT)
{
	for (int i = 0; i < DT[Array]; i++)
		for (int j = 0; j < DT[Column]; j++)
			if (!Table[i][j])
				Table[i][j] = GenerateRandom(DT[Level]);
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
						if (i == Y && j == X)
							Table[Y][X]++;
						else
							Table[i][j] = 0;
					}
			DT[TotalGrade] += tmp;
			PrintTable(Table, MarkTable, DT, 4);
			cout << "本次得分：" << tmp << " 总得分：" << DT[TotalGrade] << " 合成目标：" << DT[Goal] << endl;
			putchar('\n');
			UpdateTable(Table, MarkTable, DT, true);
			PrintTable(Table, MarkTable, DT, 5);
			InputEnter(5);
			GenerateTable(Table, DT);
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
				cout << "╔";
			else if (i == 1 && j == end_j)
				cout << "╗";
			else if (i == end_i && j == 1)
				cout << "╚";
			else if (i == end_i && j == end_j)
				cout << "╝";
			else if (i == 1) {
				if (flag && j % t == 1)
					cout << "╤";
				else
					cout << "═";
			}
			else if (j == 1) {
				if (flag && i % t == 1)
					cout << "╟";
				else
					cout << "║";
			}
			else if (j == end_j) {
				if (flag && i % t == 1)
					cout << "╢";
				else
					cout << "║";
			}
			else if (i == end_i) {
				if (flag && j % t == 1)
					cout << "╧";
				else
					cout << "═";
			}
			else if (flag && j % t == 1 && i % t == 1)
				cout << "┼";
			else if (flag && i % t == 1)
				cout << "─";
			else if (flag && j % t == 1)
				cout << "│";
			else
				cout << "  ";
		}
		putchar('\n');
		Sleep(30);
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
	gotoxy(x, y);
	cout << "╔═╗";
	gotoxy(x, y + 1);
	cout << "║" << setw(2) << num << "║";
	gotoxy(x, y + 2);
	cout << "╚═╝";
	Sleep(30);
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
			showstr(x, y, "───", COLOR_HWHITE, COLOR_BLACK);
		}
		y++;
		DrawBox(x, y, Table[k][i], 0);
	}
}
/*						UpdateTable					*/
void UpdateTable(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag = true)
{
	gotoxy(0, DT[Bottom] - 2);
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	if(flag)
		InputEnter(1);
	int k;
	MarkTable[DT[Orig_y]][DT[Orig_x]] = UNSIGNED;
	if (Table[DT[Orig_y]][DT[Orig_x]] == DT[Level])
		DT[Level]++;								//upgrade
	for (int i = 0; i < DT[Column]; i++)
		for (int j = DT[Array] - 1; j >= 1; j--) {
			if (MarkTable[j][i] == SIGNED) {
				for (k = j - 1; k >= 0; k--) {
					//if (Table[k][i]) {
					if (MarkTable[k][i] == UNSIGNED) {
						Table[j][i] = Table[k][i];
						MarkTable[j][i] = MarkTable[k][i];
						if (DT[Choice] == 8 || DT[Choice] == 9)
							FallingMovement(Table, DT, i, j, k);
						//Table[k][i] = 0;
						MarkTable[k][i] = SIGNED;
						break;
					}
				}
				if (k < 0) {
					Table[k][i] = 0;
					MarkTable[j][i] = SIGNED;
				}
			}
		}
}
/*				 Falling Movement of Box			*/
void UpdateDrawing(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag = true)
{
	int X = DT[Orig_x], Y = DT[Orig_y], tmp = 0;
	int x, y;
	setcolor(COLOR_BLACK, COLOR_HWHITE);
	gotoxy(0, DT[Bottom] - 1);
	showch(0, DT[Bottom] - 1, ' ', COLOR_BLACK, COLOR_HWHITE, CLEAR);//clear
	for (int i = 0; i < DT[Array]; i++) {
		for (int j = 0; j < DT[Column]; j++) {
			if (MarkTable[i][j] == SIGNED) {
				tmp += 3 * Table[i][j];
				CalcCoord(x, y, j, i);
				if (i == Y && j == X) {
					Table[Y][X]++;
					DrawBox(x, y, Table[Y][X], 0);
				}
				else {
					Table[i][j] = 0;
					DrawBox(x, y, 0, 9);
				}
			}
		}
	}
	Sleep(20);
	UpdateTable(Table, MarkTable, DT, flag);
}