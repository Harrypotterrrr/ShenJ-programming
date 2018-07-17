#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <fstream>
#include "..\common\cmd_console_tools.h"

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