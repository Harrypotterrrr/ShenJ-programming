/* 1651574 1∞‡ º÷Íª¡ÿ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <stdint.h>
#include "../common/cmd_console_tools.h"


#define BOARD_COL (32*6 +3)
#define MAX_TIME 1000
#define MAX_LEN (len * 16)
#define Empty -1
#define Simple 0
#define Traditional 1

using namespace std;

typedef unsigned char byte;
const int sleepTime[] = { 1000,500,300,100,50,20 };

class Led
{
protected:
	byte * sentence;
	int len;
	byte(*buffer)[35];
	bool(*charPattern)[16];
	static const byte key[8];

	int opt_content;
	int type_char;
	int type_effect;
	int bg_color;
	int char_color;
	int sleep_time;

public:

	Led(byte* = NULL);
	~Led();
	void ReadConfig(ifstream&);
	void SetSentence(byte*);
	void AnalyseSentence();
	void LoadBuffer();
	void PrintSentence_Type0();
	void PrintSentence_Type1();
	void PrintSentence_Type2();
	void PrintSentence_Type3();
	void PrintSentence();
	void SetColor(bool = true);
};

