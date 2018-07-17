/*1∞‡ º÷Íª¡ÿ 1651574*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define COLUMN 26
#define NUM_BOMB 50
using namespace std;
const int MOVE[][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
void CreateBomb(char map[][COLUMN + 5])
{
	int x, y;
	memset(map, '\0', sizeof map);
	srand(unsigned(time(NULL)));
	for (int i = 0; i < NUM_BOMB; i++) {
		x = rand() % ROW + 1;
		y = rand() % COLUMN + 1;
		if (map[x][y] == '*')
			i--;
		map[x][y] = '*';
	}
}
void AddNum(char map[][COLUMN + 5], int x, int  y)
{
	int count = 0;
	for (int i = 0; i < 8; i++) {
		int X = x + MOVE[i][0];
		int Y = y + MOVE[i][1];
		if (X >= 1 && X <= ROW && Y >= 1 && Y <= COLUMN)
			if (map[X][Y] == '*')
				count++;
	}
	map[x][y] = count + '0';
}
void CompleteMap(char map[][COLUMN + 5])
{
	for (int i = 1; i <= ROW; i++)
		for (int j = 1; j <= COLUMN; j++) {
			if (map[i][j] != '*')
				AddNum(map, i, j);
		}
}
void PrintMap(char map[][COLUMN + 5])
{
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j < COLUMN; j++)
			cout << map[i][j] << " ";
		cout << map[i][COLUMN];
		putchar('\n');
	}
}
int main()
{
	char map[ROW + 5][COLUMN + 5];
	CreateBomb(map);
	CompleteMap(map);
	PrintMap(map);
	return 0;
}
