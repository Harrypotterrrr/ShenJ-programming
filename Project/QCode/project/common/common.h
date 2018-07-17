#pragma once
/*1651574 1∞‡ º÷Íª¡ÿ*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include "cmd_console_tools.h"
using namespace std;
#define INITIAL_X 25
#define INITIAL_Y 50
#define UNSIGNED 0	//unchecked
#define SIGNED 1	//checked
#define TIMES 4
#define CLEAR 42

const int MOVE_XY[4][2] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };
const int ColorNumber[] = { /*1,9,3,2,11,*/10,12,13,4,5,8,7,15 };//the order of colors
enum DataSet { Choice, Array, Column, Tmp_x, Tmp_y, Count, Orig_x, Orig_y, Bottom, Score };
/*						input Enter					*/
void InputEnter(int x);
/*calculate the coordination according to col & arr */
void CalcCoord(int &, int &, const int, const int);
/*				Calculate the Score					*/
void CalcScore(int *DT, int N);
/*					end sentences					*/
void EnterEnd();
/*					DFS_recursion					*/
void DFS_recursion(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*			judge the validity of character			*/
bool JudgeCommand(int(*Table)[10], char *command, int *DT);
/*				Falling Movement of Box				*/
void FallingMovement(int(*Table)[10], int *DT, int i, int j, int k);
/*				choice == 1 0r 2 Command			*/
void ExecuteCommand(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*		Print Table according to the option			*/
void PrintTable(int(*Table)[10], int(*MarkTable)[10], int *DT, int option); 
/*					Generate one Table				*/
void GenerateTable(int(*Table)[10], int *DT);
/*	Calculate TotalGrade accroding to the command	*/
bool CombineNumber(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*				Draw the Boarder of the graph 		*/
void DrawBoarder(int x, int y, int col, int arr, int interval, bool flag);
/*				Draw or change the figure			*/
void DrawBox(int x, int y, int num, int flag);
/*		Check whether there is box to eliminate		*/
bool CheckContinue(int(*)[10], int *);
/*		previous operation before choose box		*/
void PreChooseBox(int(*)[10], int *, bool, bool, int, int, int, int);
/*			      Restore the Table                 */
void RestoreTable(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*				Falling Movement of Box				*/
void UpdateTable(int(*Table)[10], int(*MarkTable)[10], int *DT, bool);
/*				 Falling Movement of Box			*/
void UpdateDrawing(int(*Table)[10], int(*MarkTable)[10], int *DT, bool);
/*		Move the column to the black place			*/
void MoveColumn(int(*Table)[10], int j, int *DT);
/*			 Filling the blank of whole Table		*/
void ComplementBox(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag);
/*		  Execute order according to the cursor		*/
bool GameType(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*					Game Controler					*/
bool GameControl(int(*Table)[10], int(*MarkTable)[10], int *DT, bool);
/*				Choose Box by cursor key			*/
void ChooseBox(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*					Draw the figure					*/
void DrawFigure(int(*Table)[10], int(*MarkTable)[10], int *DT, bool flag);
/*choose the solutions according to the main function*/;
/*				  Initial Settings					*/
void InitialSetting(int(*Table)[10], int(*MarkTable)[10], int *DataTable);
/*choose the solutions according to the main function*/
void Solve(int(*Table)[10], int(*MarkTable)[10], int *DataTable);
/*					  Easter Egg				    */


using namespace std;
#define ARRAY 17
#define COLUMN 14

#define COL_BEGIN 0
#define COL_END 14
#define ROW_BEGIN 1
#define ROW_END 40

static const uint64_t numPatternTable[10][4] = {
	{ 0x0000000705050507U, 0x00000000001F111FU, 0x0000000705050507U, 0x00000000001F111FU },			// 0
{ 0x0000000202020202U, 0x0000000000001F00U, 0x0000000202020202U, 0x0000000000001F00U },			// 1
{ 0x0000000701070407U, 0x00000000001D1517U, 0x0000000701070407U, 0x00000000001D1517U },			// 2
{ 0x0000000701070107U, 0x000000000015151FU, 0x0000000704070407U, 0x00000000001F1515U },			// 3
{ 0x0000000505070101U, 0x000000000007041FU, 0x0000000404070505U, 0x00000000001F041CU },			// 4
{ 0x0000000704070107U, 0x000000000017151DU, 0x0000000704070107U, 0x000000000017151DU },			// 5
{ 0x0000000704070507U, 0x00000000001F151DU, 0x0000000705070107U, 0x000000000017151FU },			// 6
{ 0x0000000701010101U, 0x000000000001011FU, 0x0000000404040407U, 0x00000000001F1010U },			// 7
{ 0x0000000705070507U, 0x00000000001F151FU, 0x0000000705070507U, 0x00000000001F151FU },			// 8
{ 0x0000000705070107U, 0x000000000017151FU, 0x0000000704070507U, 0x00000000001F151DU }			// 9
};

static const uint16_t modelPatternTable[ARRAY] = {
	0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U,
	0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U, 0x8001U,
	0xFFFFU
};


struct TetrisData
{
	uint16_t pool[ARRAY];
	int x;
	int y;
	int type[3];
	int ori[3];
	unsigned score;
	unsigned erasedCount[4];
	unsigned erasedTotal;
	unsigned tetrisCount[10];
	unsigned tetrisTotal;
	bool dead;
};

struct TetrisCondition
{
	bool pause;
	bool clockwise;
	int8_t direction;
	int16_t color[ARRAY][16];
};

void initGame(TetrisData *, TetrisCondition *);
void restartGame(TetrisData *, TetrisCondition *, bool flag = false);
void giveTetris(TetrisData *, TetrisCondition *);
bool checkCollision(const TetrisData *);
void insertTetris(TetrisData *);
void removeTetris(TetrisData *);
void horzMoveTetris(TetrisData *, TetrisCondition *);
void moveDownTetris(TetrisData *, TetrisCondition *);
void rotateTetris(TetrisData *, TetrisCondition *);
void dropDownTetris(TetrisData *, TetrisCondition *);
bool checkErasing(TetrisData *, TetrisCondition *);
void keydownControl(TetrisData *, TetrisCondition *, int);
void setPoolColor(const TetrisData *, TetrisCondition *);
void printPoolBorder();
void printTetrisPool(const TetrisData *, const TetrisCondition *);
void printCurrentTetris(const TetrisData *, const TetrisCondition *);
void printNextTetris(const TetrisData *, const TetrisCondition *);
void printScore(const TetrisData *);
void runGame(TetrisData *, TetrisCondition *);
void printHint();
bool ifPlayAgain();
void DrawBox(int, int);