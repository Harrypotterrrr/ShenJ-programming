/* 1651574 º÷Íª¡ÿ 1∞‡*/
#include "90-b2.h"

int main() 
{
	TetrisData tetrisDataSet;
	TetrisCondition tetrisControl;
	setfontsize("µ„’Û◊÷ÃÂ", 20);
	setconsoleborder(165, 200, 150, 200);
	initGame(&tetrisDataSet, &tetrisControl);
	do {
		printHint();
		printPoolBorder();
		runGame(&tetrisDataSet, &tetrisControl);
		if (ifPlayAgain()){
			setcolor(COLOR_BLACK, COLOR_HWHITE);
			system("cls"); 
			restartGame(&tetrisDataSet, &tetrisControl); 
		}
		else
			break;
	} while (true);

	return 0;
}