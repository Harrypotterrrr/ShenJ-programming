/* 1651574 1�� �����*/
#include "90-b5.h"

int main(void)
{
	setfontsize("������",12,6);
	setcursor(CURSOR_INVISIBLE);
	setconsoleborder(32 * 7 + 3, 16 + 3, 32 * 7 + 3, 16 + 3);

	Led led;
	ifstream configFile;
	led.ReadConfig(configFile);

	led.AnalyseSentence();
	led.PrintSentence();
	return 0;

}


