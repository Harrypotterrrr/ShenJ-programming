#include "90-b2.h"
/*						input Enter					*/
void InputEnter(int x)
{
	switch (x) {
		case(0):
			std::cout << "\n按回车键继续\n";
			break;
		case(1):
			cout << "按回车键进行数组下落除0操作..." << endl;
			break;
		case(5):
			cout << "按回车键进行新值填充..." << endl;
			break;
		case(8):
			cout << "本次合成结束，按回车键继续新一次的合成..." << endl;
			break;
	}
	while (_getch() != '\r')
		;
}
/*					generate random numer			*/
int GenerateRandom(int MaxNum)
{
	int tmp = rand() % (20) + 1;
	switch (MaxNum) {
		case(1):case(2):case(3):
			return rand() % 3 + 1;
		case(4):
			for (int i = 1; i <= 3; i++)
				if (tmp <= i * 6)
					return i;
			return 4;
		case(5):
			for (int i = 1; i <= 4; i++)
				if (tmp <= i * 5)
					return i;
			if (tmp <= 18)
				return 4;
			return 5;
		case(6):
			for (int i = 1; i <= 4; i++)
				if (tmp <= i * 4)
					return i;
			if (tmp <= 19)
				return 5;
			return 6;
		default:
			for (int i = 1; i <= MaxNum - 3; i++)
				if (tmp <= i * 16 / (MaxNum - 3))
					return i;
			if (tmp <= 18)
				return MaxNum - 2;
			if (tmp <= 19)
				return MaxNum - 1;
			return MaxNum;
	}
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
	std::cout << "请输入行数(5-8)：";
	while (true) {
		getxy(cur_x, cur_y);
		std::cin >> DataTable[Array];
		if (std::cin.good() && DataTable[Array] >= 5 && DataTable[Array] <= 8)
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
	std::cout << "请输入列数(5-10)：";
	while (true) {
		getxy(cur_x, cur_y);
		std::cin >> DataTable[Column];
		if (std::cin.good() && DataTable[Column] >= 5 && DataTable[Column] <= 10)
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
	std::cout << "请输入合成目标(5-20)：";
	if (DataTable[Choice] != 1 && DataTable[Choice] != 5 && DataTable[Choice] != 6)
		while (true) {
			getxy(cur_x, cur_y);
			std::cin >> DataTable[Goal];
			if (std::cin.good() && DataTable[Goal] >= 5 && DataTable[Goal] <= 20)
				break;
			showstr(cur_x, cur_y, "      ", COLOR_BLACK, COLOR_HWHITE);
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "\n输入不合法，请重新输入\n";
			gotoxy(cur_x, cur_y);
		}
	memset(Table, 0, sizeof(int) * 10 * 10);
	memset(MarkTable, UNSIGNED, sizeof(int) * 10 * 10);
	DataTable[Level] = 3;
}
/*					  Easter Egg				    */
void PrintEasterEgg()
{
	printf("::\n                      :;J7, :,                   \
     ::;7:\n                      ,ivYi, ,                       ;\
LLLFS:\n                      :iv7Yi                       :7ri;j5\
PL\n                     ,:ivYLvr                    ,ivrrirrY2X,\n\
                     :;r@Wwz.7r:                :ivu@kexianli.\n   \
                 :iL7::,:::iiirii:ii;::::,,irvF7rvvLujL7ur\n       \
            ri::,:,::i:iiiiiii:i:irrv177JX7rYXqZEkvv17\n           \
     ;i:, , ::::iirrririi:i:::iiir2XXvii;L8OGJr71i\n              :\
,, ,,:   ,::ir@mingyi.irii:i:::j1jri7ZBOS7ivv,\n                 ,:\
:,    ::rv77iiiriii:iii:i::,rvLq@huhao.Li\n             ,,      ,, \
,:ir7ir::,:::i;ir:::i:i::rSGGYri712:\n           :::  ,v7r:: ::rrv7\
7:, ,, ,:i7rrii:::::, ir7ri7Lri\n          ,     2OBBOi,iiir;r::   \
     ,irriiii::,, ,iv7Luur:\n        ,,     i78MBBi,:,:::,:,  :7FSL\
: ,iriii:::i::,,:rLqXv::\n        :      iuMMP: :,:::,:ii;2GY7OBB0v\
iiii:i:iii:i:::iJqL;::\n       ,     ::::i   ,,,,, ::LuBBu BBBBBEri\
i:i:i:i:i:i:i:r77ii\n      ,       :       , ,,:::rruBZ1MBBqi, :,,,\
:::,::::::iiriri:\n     ,               ,,,,::::i:  @arqiao.       \
,:,, ,:::ii;i7:\n    :,       rjujLYLi   ,,:::::,:::::::::,,   ,:i,\
:,,,,,::i:iii\n    ::      BBBBBBBBB0,    ,,::: , ,:::::: ,      ,,\
,, ,,:::::::\n    i,  ,  ,8BMMBBBBBBi     ,,:,,     ,,, , ,   , , ,\
 :,::ii::i::\n    :      iZMOMOMBBM2::::::::::,,,,     ,,,,,,:,,,::\
::i:irr:i:::,\n    i   ,,:;u0MBMOG1L:::i::::::  ,,,::,   ,,, ::::::\
i:i:iirii:i:i:\n    :    ,iuUuuXUkFu7i:iii:i:::, :,:,: ::::::::i:i:\
::::iirr7iiri::\n    :     :rk@Yizero.i:::::, ,:ii:::::::i:::::i::,\
::::iirrriiiri::,\n     :      5BMBBBBBBSr:,::rv2kuii:::iii::,:i:,,\
 , ,,:,:i@petermu.,\n          , :r50EZ8MBBBBGOBBBZP7::::i::,:::::,\
: :,:,::i;rrririiii::\n              :jujYY7LS0ujJL7r::,::i::,:::::\
:::::::::iirirrrrrrr:ii:\n           ,:  :@kevensun.:,:,,,::::i:i::\
:::,,::::::iir;ii;7v77;ii;i,\n           ,,,     ,,:,::::::i:iiiii:\
i::::,, ::::iiiir@xingjief.r;7:i,\n        , , ,,,:,,::::::::iiiiii\
iiii:,:,:::::::::iiir;ri7vL77rrirri::\n         :,, , ::::::::i:::i\
:::i:i::,,,,,:,::i:i:::iir;@Secbone.ii:::\n");
	std::cout << "再次把纯洁、爽朗而又不失礼节的笑容送给您\n";
}