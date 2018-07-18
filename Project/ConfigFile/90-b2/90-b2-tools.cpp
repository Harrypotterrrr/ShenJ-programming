#include "90-b2.h"

void insertTetris(TetrisData *dataSet) {
	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];


	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		for (int i = 0; i < 3; i++)
			dataSet->pool[dataSet->y + 2 - i] |= (((tetris >> (0x00 + 8 * i)) & 0x1F) << (11 - dataSet->x));
	}
	else {
		for (int i = 0; i < 5; i++)
			dataSet->pool[dataSet->y + 4 - i] |= (((tetris >> (0x00 + 8 * i)) & 0x07) << (13 - dataSet->x));
	}
}

void removeTetris(TetrisData *dataSet) {
	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];

	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		for (int i = 0; i < 3; i++)
			dataSet->pool[dataSet->y + 2 - i] &= ~(((tetris >> (0x00 + i * 8)) & 0x001F) << (11 - dataSet->x));
	}
	else {
		for (int i = 0; i < 5; i++)
			dataSet->pool[dataSet->y + 4 - i] &= ~(((tetris >> (0x00 + i * 8)) & 0x007) << (13 - dataSet->x));
	}

}

void setPoolColor(const TetrisData *dataSet, TetrisCondition *controlPanel) {


	int num, posx, posy;
	bool flag = false;

	uint64_t tetris = numPatternTable[dataSet->type[0]][dataSet->ori[0]];
	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3) {
		for (int i = 0; i < 3; i++) {
			num = (tetris >> (0x00 + 8 * i) & 0x001F);
			posy = dataSet->y + 2 - i;
			for (int j = 0; j < 5; j++) {
				posx = dataSet->x + j;
				if (((num >> (4 - j)) & 1))
					controlPanel->color[posy][posx] = (dataSet->type[0] | 8);
			}
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			num = (tetris >> (0x00 + 8 * i) & 0x0007);
			posy = dataSet->y + 4 - i;
			for (int j = 0; j < 3; j++) {
				posx = dataSet->x + j;
				if (((num >> (2 - j)) & 1))
					controlPanel->color[posy][posx] = (dataSet->type[0] | 8);
			}
		}
	}
}

void rotateTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	int8_t ori = dataSet->ori[0];

	removeTetris(dataSet);

	int orix = dataSet->x;
	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3)
		dataSet->x++;
	else
		dataSet->x--;
	dataSet->ori[0] = (controlPanel->clockwise) ? ((ori + 1) & 3) : ((ori + 3) & 3);

	if (checkCollision(dataSet))
	{
		dataSet->x = orix;
		dataSet->ori[0] = ori;
		insertTetris(dataSet);
	}
	else {
		insertTetris(dataSet);
		setPoolColor(dataSet, controlPanel);
		printCurrentTetris(dataSet, controlPanel);
	}
}


void horzMoveTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	int x = dataSet->x;

	removeTetris(dataSet);
	controlPanel->direction == 0 ? (--dataSet->x) : (++dataSet->x);

	if (checkCollision(dataSet)) {
		dataSet->x = x;
		insertTetris(dataSet);
	}
	else {
		insertTetris(dataSet);
		setPoolColor(dataSet, controlPanel);
		printCurrentTetris(dataSet, controlPanel);
	}
}

void moveDownTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	int8_t y = dataSet->y;
	removeTetris(dataSet);
	++dataSet->y;

	if (checkCollision(dataSet)) {
		dataSet->y = y;
		insertTetris(dataSet);
		if (checkErasing(dataSet, controlPanel))
			printTetrisPool(dataSet, controlPanel);
	}
	else {
		insertTetris(dataSet);
		setPoolColor(dataSet, controlPanel);
		printCurrentTetris(dataSet, controlPanel);
	}
}

void dropDownTetris(TetrisData *dataSet, TetrisCondition *controlPanel) {
	removeTetris(dataSet);
	for (; dataSet->y < ROW_END; ++dataSet->y)
		if (checkCollision(dataSet))
			break;
	--dataSet->y;

	insertTetris(dataSet);
	setPoolColor(dataSet, controlPanel);

	checkErasing(dataSet, controlPanel);
	printTetrisPool(dataSet, controlPanel);
}

bool checkErasing(TetrisData *dataSet, TetrisCondition *controlPanel) {
	static const unsigned scores[5] = { 0, 10, 30, 90, 150 };
	int8_t count = 0;
	int8_t k = 0, y;
	if (dataSet->ori[0] == 1 || dataSet->ori[0] == 3)
		y = dataSet->y + 2;
	else
		y = dataSet->y + 4;

	do {
		if (y < ARRAY && dataSet->pool[y] == 0xFFFFU) {
			++count;
			memmove(dataSet->pool + 1, dataSet->pool, sizeof(uint16_t) * y);
			memmove(controlPanel->color[1], controlPanel->color[0],
				sizeof(int8_t[16]) * y);
		}
		else {
			--y;
			++k;
		}
	} while (y >= dataSet->y && k < 4);
	//dataSet->erasedTotal += count; 
	dataSet->score += scores[count];
	if (count > 0)
		dataSet->erasedCount[count - 1]++;
	giveTetris(dataSet, controlPanel);
	setPoolColor(dataSet, controlPanel);
	return (count > 0);
}

void keydownControl(TetrisData *dataSet, TetrisCondition *controlPanel, int key) {
	if (key == 13)  // pause
		controlPanel->pause = !controlPanel->pause;

	if (controlPanel->pause)  // pause state
		return;

	switch (key) {
	case 'w':
	case 'W':
	case '8':
	case 72:  //up
		controlPanel->clockwise = true;  // rotate
		rotateTetris(dataSet, controlPanel);
		break;
	case 'a':
	case 'A':
	case '4':
	case 75:  // left
		controlPanel->direction = 0;
		horzMoveTetris(dataSet, controlPanel);
		break;
	case 'd':
	case 'D':
	case '6':
	case 77:  // right
		controlPanel->direction = 1;  // right
		horzMoveTetris(dataSet, controlPanel);
		break;
	case 's':
	case 'S':
	case '2':
	case 80:  // down
		moveDownTetris(dataSet, controlPanel);
		break;
	case ' ':  // speed up
		dropDownTetris(dataSet, controlPanel);
		break;
	case '0':  // reverse
		controlPanel->clockwise = false;
		rotateTetris(dataSet, controlPanel);
		break;
	default:
		break;
	}
}
