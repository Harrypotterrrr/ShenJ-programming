/*1班 贾昊霖 1651574*/
/*已验证 1652571 袁小丁 1651025 汪涵 1550276 马跃泷 1653733 卢依雯 1553449 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define ROW 10
#define COLUMN 26
#define NUM_BOMB 50
const int MOVE[][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int CheckNum(char map[][COLUMN + 5], int x, int  y)
{
	int count = 0;
	int i;
	for (i = 0; i < 8; i++) {
		int X = x + MOVE[i][0];
		int Y = y + MOVE[i][1];
		if (X >= 1 && X <= ROW && Y >= 1 && Y <= COLUMN)
			if (map[X][Y] == '*')
				count++;
	}
	return count;
}
void ReadMap(char map[][COLUMN + 5])
{
	int i, j;
	char tmp;
	for (i = 1; i <= ROW; i++) {
		for (j = 1; j <= COLUMN; j++) {
			tmp = getchar();
			while (tmp == ' ' || tmp == '\n' || tmp == '\0')
				tmp = getchar();
			map[i][j] = tmp;
		}
	}
}
int CheckMap(char map[][COLUMN + 5])
{
	int num = 0;
	int i,j;
	for (i = 1; i <= ROW; i++) {
		for (j = 1; j <= COLUMN; j++) {
			if (map[i][j] == '*')
				num++;
			else if (map[i][j] - '0' != CheckNum(map, i, j))
				return NUM_BOMB - 1;
		}
	}
	return num;
}
int main()
{
	char map[ROW + 5][COLUMN + 5];
	ReadMap(map);
	if (CheckMap(map) == NUM_BOMB)
		printf("正确\n");
		//cout << "正确\n";
	else
		printf("错误\n");
		//cout << "错误\n";
	return 0;
}
