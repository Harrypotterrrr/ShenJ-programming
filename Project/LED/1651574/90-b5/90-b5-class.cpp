/* 1651574 1班 贾昊霖*/
#include "90-b5.h"

const byte Led::key[8] = {
	0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
};

Led::Led(byte* str)
{
	if (!str)
		return;
	len = strlen((char*)str) / 2;
	sentence = new(nothrow) byte[len * 2 + 1];
	if (!sentence) {
		cerr << "内存不足！\n";
		exit(ERROR);
	}
	strcpy((char*)sentence, (char*)str);
}

Led::~Led()
{
	if (!sentence)
		return;
	len = 0;
	delete sentence;
}

void Led::SetSentence(byte *str)
{
	if (len) {
		len = 0;
		delete sentence;
	}

	len = strlen((char*)str) / 2;
	sentence = new(nothrow) byte[len * 2 + 1];
	if (!sentence) {
		cerr << "内存不足！\n";
		exit(ERROR);
	}
	strcpy((char*)sentence, (char*)str);
}

void Led::PrintSentence_Type0()
{
	int cur_x, cur_y;
	bool flag;
	getxy(cur_x, cur_y);

	for (int l = 0; l < 7; l++) {
		int tmp_x = cur_x + 32 * l;
		for (int k = 0; k < 16; k++) {
			gotoxy(tmp_x, cur_y + k);
			for (int j = 0; j < 2; j++) {
				for (int i = 0; i < 8; i++) {
					flag = buffer[l][k * 2 + j] & key[i];//
					cout << (flag ? "●" : "  ");
				}
			}
		}
	}
	gotoxy(cur_x, cur_y + 16);
}
void Led::PrintSentence_Type1()
{
	int cur_x, cur_y;
	SetColor();
	getxy(cur_x, cur_y);
	int start_x = 0, times = -1;
	while (times++ < MAX_TIME) {
		const int max_j = 6 * 16;
		start_x = (start_x + 1) % MAX_LEN;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < max_j; j++) {

				cout << (charPattern[(j + start_x) % (len * 16)][i] ? "●" : "  ");
			}
			putchar('\n');
		}
		gotoxy(cur_x, cur_y);
		Sleep(sleepTime[sleep_time]);
	}
	gotoxy(cur_x, cur_y + 16);
}

void Led::PrintSentence_Type2()
{
	int cur_x, cur_y;
	SetColor();
	getxy(cur_x, cur_y);
	int start_x = 0, times = -1;
	while (times++ < MAX_TIME) {
		const int max_j = 6 * 16;
		start_x = (start_x - 1 + MAX_LEN) % MAX_LEN;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < max_j; j++) {

				cout << (charPattern[(start_x + j) % (MAX_LEN)][i] ? "●" : "  ");
			}
			putchar('\n');
		}
		gotoxy(cur_x, cur_y);
		Sleep(sleepTime[sleep_time]);
	}
	gotoxy(cur_x, cur_y + 16);
}

void Led::PrintSentence_Type3()
{
	int cur_x, cur_y;

	getxy(cur_x, cur_y);
	int start_x = 0, times = -1;
	while (times++ < MAX_TIME) {
		const int max_j = 6 * 16;
		start_x = (start_x - 1 + max_j) % MAX_LEN;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < max_j; j++) {

				cout << (charPattern[(start_x + j + len * 16) % (len * 16)][i] ? "●" : "  ");
			}
			putchar('\n');
		}
		gotoxy(cur_x, cur_y);
		Sleep(sleepTime[sleep_time]);
		SetColor(false);
	}
	gotoxy(cur_x, cur_y + 16);
}

void Led::PrintSentence()
{
	LoadBuffer();
	switch (type_effect) {
		case(0):
			PrintSentence_Type0();
			break;
		case(1):
			PrintSentence_Type1();
			break;
		case(2):
			PrintSentence_Type2();
			break;
		case(3):
			PrintSentence_Type3();
			break;
	}
}

void Led::SetColor(bool flag)
{
	static int color = 0;
	if (!flag) {
		setcolor(color, color + 7);
		color = (color + 1) % 15;
		return;
	}
	int _bg, _char;
	if (bg_color == -1)
		_bg = rand() % 15;
	else
		_bg = bg_color;
	if (char_color == -1)
		_char = rand() % 15;
	else
		_char = char_color;
	setcolor(_bg, _char);
}

void Led::AnalyseSentence()
{
	ifstream charSetBase;

	if (type_char == Simple)
		charSetBase.open("HZK16", ios::in | ios::binary);
	else
		charSetBase.open("HZK16F", ios::in | ios::binary);

	if (!charSetBase.is_open()) {
		cerr << "未找到点阵字库，请检查目录\n";
		exit(ERROR);
	}

	buffer = new(nothrow)byte[len][35];

	for (int i = 0; i < len; i++) {
		int offset = (94 * (unsigned int)(sentence[i << 1] - 0xA0 - 1) + (sentence[(i << 1) + 1] - 0xA0 - 1)) * 32;
		charSetBase.seekg(offset, ios::beg);
		charSetBase.read((char*)buffer[i], 32);
		buffer[i][32] = '\0';
	}
	charSetBase.close();
}

void Led::LoadBuffer()
{
	charPattern = new(nothrow) bool[len * 16][16];
	if (!charPattern) {
		cerr << "内存不足！\n";
		exit(ERROR);
	}

	for (int l = 0; l < len; l++) {

		int tmp_add_l = l * 16;
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 8; i++) {
				int tmp_add_ij = tmp_add_l + j * 8 + i;
				for (int k = 0; k < 16; k++) {
					charPattern[tmp_add_ij][k] = buffer[l][k * 2 + j] & key[i];
				}
			}
		}
	}
}

void Led::ReadConfig(ifstream &file)
{
	file.open("led（请修改此配置文件）.cfg", ios::in);
	if (!file.is_open()) {
		cerr << "未找到配置文件，请检查目录\n";
		exit(ERROR);
	}
	char line[1024], *p = NULL;
	while (!file.eof()) {
		file.getline(line, 1024);
		if (p = strstr(line, "背景色")) {
			p = strchr(line, '=');
			if (*(p + 1) == 'x')
				bg_color = -1;
			else
				bg_color = *(p + 1) - '0';
		}
		else if (p = strstr(line, "字体颜色")) {
			p = strchr(line, '=');
			if (*(p + 1) == 'x')
				char_color = -1;
			else
				char_color = *(p + 1) - '0';
		}
		else if (p = strstr(line, "特效")) {
			p = strchr(line, '=');
			type_effect = *(p + 1) - '0';
		}
		else if (p = strstr(line, "屏延时")) {
			p = strchr(line, '=');
			sleep_time = *(p + 1) - '0';
		}
		else if (p = strstr(line, "字库")) {
			if (p = strstr(line, "HZK16F"))
				type_char = Traditional;
			else if (p = strstr(line, "HZK16"))
				type_char = Simple;
		}
		else if (p = strstr(line, "内容")) {
			p = strchr(line, '=');
			opt_content = *(p + 1) - '0';
			char findStr[10] = "item";
			findStr[4] = opt_content + '0';
			findStr[5] = '\0';
			while (!file.eof()) {
				file.getline(line, 1024);
				if (p = strstr(line, findStr)) {
					p = strchr(line, '=');
					SetSentence((byte*)(p + 1));
					return;
				}
			}
		}
	}
	cerr << "config文件有误,请按照程序目录下的config修改！\n";
	exit(ERROR);
}