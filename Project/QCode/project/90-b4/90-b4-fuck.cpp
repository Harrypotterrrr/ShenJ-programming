/*1651574 1∞‡ º÷Íª¡ÿ*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef int Status;
#define ERROR -1
#define OK 1

class QRcode
{
private:
	char origin_content[105];
	char mode_indicator[8];
	char count_indicator[15];
	char data_bit_stream[105];
	char data_encoding[1000];
	int origin_len;
public:
	QRcode(char* = NULL);
	~QRcode();

	void Solve();
	void CountIndicator();
	void GetDataStream();
	void ConcatenateData();


	int Str2Int_binary(char*);
	void Int2Int_binary(int, char *, int = 0);

	void print();
};

QRcode::QRcode(char* str)
{
	if (!str) {
		cout << "input:\n";
		cin >> origin_content;
	}
	strcpy(mode_indicator, "0001");
}

QRcode::~QRcode()
{
	cout << "the end of the program";
}

void QRcode::Solve()
{
	//Data analyse
	CountIndicator();
	GetDataStream();
	ConcatenateData();
	//***terminator
}

int QRcode::Str2Int_binary(char *str)
{
	int len = strlen(str), num = 0;
	char *p = str;
	for (; p < str + len; p++)
		if (*p != '0')
			break;
	for (; p < str + len; p++) {
		num *= 10;
		num += *p - '0';
	}
	return num;
}

void QRcode::Int2Int_binary(int n, char *str, int length)
{
	int num = 0;
	length = 10 - 1;////
	int tmp_2pow = int(pow(2, length));
	char *p = str;

	while (tmp_2pow) {
		*p++ = n / tmp_2pow + '0';
		n %= tmp_2pow;
		tmp_2pow /= 2;
	}
	*p = '\0';
}

void QRcode::CountIndicator()
{
	origin_len = strlen(origin_content);
	Int2Int_binary(origin_len, count_indicator);
}

void QRcode::GetDataStream()
{
	char *tmp_str;
	tmp_str = new(nothrow) char[1000];
	if (!tmp_str) {
		cerr << "No more space!\n";
		exit(ERROR);
	}

	char *q = data_bit_stream;
	for (char *p = origin_content; p < origin_content + origin_len; p += 3) {
		strncpy(tmp_str, p, 3);
		tmp_str[p - origin_content + 3] = '\0';
		int tmp_len = strlen(tmp_str);
		int tmp_num = Str2Int_binary(tmp_str);

		int tmp_2pow;
		if (tmp_len == 3)
			tmp_2pow = int(pow(2, 9));
		else if (tmp_len == 2)
			tmp_2pow = int(pow(2, 6));
		else if (tmp_len == 1)
			tmp_2pow = int(pow(2, 3));

		while (tmp_2pow) {
			*q++ = tmp_num / tmp_2pow + '0';
			tmp_num %= tmp_2pow;
			tmp_2pow /= 2;
		}
	}
	*q = '\0';

}

void QRcode::ConcatenateData()
{
	strcpy(data_encoding, mode_indicator);
	strcat(data_encoding, count_indicator);
	strcat(data_encoding, data_bit_stream);

}

void QRcode::print()
{
	cout << "origin_content:"<<this->origin_content << endl;
	cout << "count_indicator:"<< this->count_indicator << endl;
	cout << "data_bit_stream:"<< this->data_bit_stream << endl;
	cout << "data_encoding:"<< this->data_encoding << endl;
}

int main()
{
	QRcode qr;
	qr.Solve();

	qr.print();
	return 0;
}



