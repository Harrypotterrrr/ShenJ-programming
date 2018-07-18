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
#include "..\common\cmd_console_tools.h"

using namespace std;
#define INITIAL_X 25
#define INITIAL_Y 50
#define UNSIGNED 0	//unchecked
#define SIGNED 1	//checked
#define TIMES 4
#define CLEAR 42

const int MOVE_XY[4][2] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };
const int ColorNumber[] = { 1,9,3,2,11,10,12,13,4,5,8,7,15 };//the order of colors
enum DataSet { Choice, Array, Column, Goal, TotalGrade, Level, Tmp_x, Tmp_y, Count, Orig_x, Orig_y, Bottom, Score };
/*						input Enter					*/
void InputEnter(int x);
/*calculate the coordination according to col & arr */
void CalcCoord(int &, int &, const int, const int);
/*					generate random numer			*/
int GenerateRandom(int MaxNum);
/*				Calculate the Score					*/
void CalcScore(int *DT, int k, int N);
/*					end sentences					*/
void EnterEnd();
/*					DFS_recursion					*/
void DFS_recursion(int(*Table)[10], int(*MarkTable)[10], int *DT);
/*			judge the validity of character			*/
bool JudgeCommand(char *command, int *DT);
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
/*		previous operation before choose box		*/
void PreChooseBox(int(*)[10], int *, bool, bool, int, int, int, int);
/*				Falling Movement of Box				*/
void FallingMovement(int(*Table)[10], int *DT, int i, int j, int k);
/*						UpdateTable					*/
void UpdateTable(int(*Table)[10], int(*MarkTable)[10], int *DT, bool);
/*			      Update the table				    */
void UpdateTable(int(*Table)[10], int(*MarkTable)[10], int *DT, bool);
/*				 Falling Movement of Box			*/
void UpdateDrawing(int(*Table)[10], int(*MarkTable)[10], int *DT, bool);
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
void PrintEasterEgg();