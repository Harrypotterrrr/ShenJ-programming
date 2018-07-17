/* 1651574 ¼Öê»ÁØ 1°à*/
#include "90-b4.h"

PolyNode::PolyNode(int coe, int exp, PolyNode* next)
{
	this->coe = coe;
	this->exp = exp;
	this->next = next;
}

void Polynomial::GetHeadCoe()
{
	head_coe = this->next->coe;
}

void Polynomial::Append(PolyList &node)
{
	PolyList p = this->next, q = NULL;
	while (p && p->exp > node->exp) {
		q = p;
		p = p->next;
	}
	if (p == this->next) {
		this->next = node;
		node->next = p;
	}
	else {
		q->next = node;
		node->next = p;
	}
}

void Polynomial::Append(PolyNode &node)
{
	PolyList p = this->next;
	while (p && p->exp > node.exp) {
		p = p->next;
	}
	node.next = p->next;
	p->next = &node;
}

void Polynomial::MulPoly(int n)
{
	PolyList p = this->next;
	while (p) {
		p->coe += n;
		p->coe %= 255;
		p = p->next;
	}
}

void Polynomial::DivPoly(int n)
{
	PolyList p = this->next;
	while (p) {
		p->coe += 255;
		p->coe -= n;
		p->coe %= 255;
		p = p->next;
	}
}

void Polynomial::XorPoly(const Polynomial &L)
{
	PolyList p = L.next, q = this->next;
	if (!p || !q)
		return;
	this->next = q->next;
	delete q;

	q = this->next;
	p = p->next;

	while (p && q) {
		q->coe ^= p->coe;
		q = q->next;
		p = p->next;
	}
}

void Polynomial::ConvertAlpha2N()
{
	PolyList p = this->next;
	while (p) {
		p->coe = alpha2n[p->coe];
		p = p->next;
	}
}

void Polynomial::ConvertN2Alpha()
{
	PolyList p = this->next;
	while (p) {
		p->coe = n2alpha[p->coe];
		p = p->next;
	}
}

void Polynomial::PrintPoly()
{
	PolyList p = this->next;
	while (p) {
		cout << "coeffcient:" << p->coe << endl;
		cout << "exponent:" << p->exp << endl;
		p = p->next;
	}
}



QRcode::QRcode(char* str)
{
	if (!str) {
		cout << "input:\n";
		cin >> origin_content;
	}
	else
		strcpy(origin_content, str);
	strcpy(mode_indicator, "0100");
}

QRcode::~QRcode()
{
	cout << "the end of the program";
}

void QRcode::DecideVersion()
{
	int i;
	for (i = 0; i < sizeof(data_capacity) / sizeof(int); i++) {
		if (len_origin <= data_capacity[i])
			break;
	}
	version = i;
}

void QRcode::AddTerminator()
{
	if (len_origin < data_capacity[version]) {
		strcat(data_encoding, "0000");
		len_data_encoding += 4;
	}
}

void QRcode::AddPadding()
{
	const char str[][9] = { "11101100" ,"00010001" };
	data_final[0] = '\0';
	strcpy(data_final, data_encoding);
	len_final = len_data_encoding;
	//the process of adding '0' is unneccessary  due to the solution of 8-bits
	for (int i = 0; len_final < data_total[version] * 8; i ^= 1) {
		len_final += 8;
		strcat(data_final, str[i]);
	}
}

void QRcode::CorrectError(Polynomial &message_ply)
{
	Polynomial generate_ply;

	char tmp[10];
	int ctr = len_final / 8 - 1 + correction_number[version];		//important!

	for (char *p = data_final; p < data_final + len_final; p += 8) {
		strncpy(tmp, p, 8);
		tmp[8] = '\0';
		PolyList pl = new PolyNode(Str2Int(tmp), ctr--);
		message_ply.Append(pl);
	}
	for (int i = ctr; i >= 0; i--) {
		PolyList pl = new PolyNode(0, i);
		message_ply.Append(pl);
	}
	for (int i = 0; i <= correction_number[version]; i++) {			// attetion: <= 
		PolyList pl = new PolyNode(generator_polynomial[version][i][0], generator_polynomial[version][i][1]);
		generate_ply.Append(pl);
	}
	for (int i = 0; i < data_total[version]; i++) {
		message_ply.GetHeadCoe();
		int headcoe = message_ply.head_coe;
		int headcoe_alpha = n2alpha[headcoe];
		generate_ply.MulPoly(headcoe_alpha);
		generate_ply.ConvertAlpha2N();
		message_ply.XorPoly(generate_ply);
		generate_ply.ConvertN2Alpha();
		generate_ply.DivPoly(headcoe_alpha);
	}
	//setcolor(COLOR_BLACK);
	//message_ply.PrintPoly();
	//cout << "=========================\n";
	//generate_ply.PrintPoly();
}

void QRcode::PositionDetectPattern(int x, int y)
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			pattern[x + i][y + j] = BLACK;
	for (int i = 1; i < 6; i++) {
		pattern[x + i][y + 1] = pattern[x + i][y + 5] = WHITE;
		pattern[x + 1][y + i] = pattern[x + 5][y + i] = WHITE;
	}
}

void QRcode::SeperatorPattern()
{
	for (int i = 0; i <= 7; i++) {
		pattern[7][i] = pattern[pattern_size[version] - 8][i] = WHITE;
		pattern[i][7] = pattern[i][pattern_size[version] - 8] = WHITE;
	}
	for (int i = pattern_size[version] - 8; i <= pattern_size[version] - 1; i++) {
		pattern[i][7] = WHITE;
		pattern[7][i] = WHITE;
	}
}

void QRcode::TimingPattern()
{
	for (int i = 8; i <= pattern_size[version] - 9; i++)
		pattern[6][i] = pattern[i][6] = (i % 2) ? WHITE : BLACK;
}

void QRcode::AlignmentPattern()
{
	for (int i = 0; i <= 4; i++) {
		pattern[pattern_size[version] - 9 + i][pattern_size[version] - 9] =
			pattern[pattern_size[version] - 9][pattern_size[version] - 9 + i] = BLACK;
		pattern[pattern_size[version] - 9 + i][pattern_size[version] - 5] =
			pattern[pattern_size[version] - 5][pattern_size[version] - 9 + i] = BLACK;
	}
	setcolor(COLOR_BLACK);
	for (int i = 0; i <= 2; i++) {
		pattern[pattern_size[version] - 8 + i][pattern_size[version] - 8] =
			pattern[pattern_size[version] - 8][pattern_size[version] - 8 + i] = WHITE;
		pattern[pattern_size[version] - 8 + i][pattern_size[version] - 6] =
			pattern[pattern_size[version] - 6][pattern_size[version] - 8 + i] = WHITE;
	}
	setcolor(COLOR_BLACK);
	pattern[pattern_size[version] - 7][pattern_size[version] - 7] = BLACK;

}

void QRcode::AddFunctionPattern()
{
	PositionDetectPattern(0, 0);
	PositionDetectPattern(pattern_size[version] - 7, 0);
	PositionDetectPattern(0, pattern_size[version] - 7);
	SeperatorPattern();
	TimingPattern();
	if (version > 1)
		AlignmentPattern();
	// Dark Dot
	pattern[8][pattern_size[version] - 8] = BLACK;
}

void QRcode::FillingFormatInfo()
{
	//strcpy(correct_version, "01");
	//strcpy(mask_version, "100");
	mask_version = 7;
	strcpy(correct_str, mask_module[mask_version]);
	//strrev(correct_str);

	int p = strlen(correct_str) - 1;
	for (int i = 1; i <= 8; i++, p--)
		pattern[pattern_size[version] - i][8] = (correct_str[p] - '0') ? BLACK : WHITE;
	for (int i = 1; i <= 7; i++, p--)
		pattern[8][pattern_size[version] - 8 + i] = (correct_str[p] - '0') ? BLACK : WHITE;
	p = strlen(correct_str) - 1;
	for (int i = 0; i <= 5; i++, p--)
		pattern[8][i] = (correct_str[p] - '0') ? BLACK : WHITE;
	pattern[8][7] = (correct_str[p--] - '0') ? BLACK : WHITE;
	pattern[8][8] = (correct_str[p--] - '0') ? BLACK : WHITE;
	pattern[7][8] = (correct_str[p--] - '0') ? BLACK : WHITE;
	for (int i = 5; i >= 0; i--, p--)
		pattern[i][8] = (correct_str[p] - '0') ? BLACK : WHITE;
}

void QRcode::InitialPattern()
{
	pattern = new int*[pattern_size[version] + 1];
	for (int i = 0; i <= pattern_size[version]; i++) {
		pattern[i] = new int[pattern_size[version] + 1];
		memset(pattern[i], EMPTY, sizeof(int) * pattern_size[version]);
	}
}

void QRcode::DrawPattern()
{
	for (int i = 0; i < pattern_size[version]; i++) {
		for (int j = 0; j < pattern_size[version]; j++) {
			if (pattern[j][i] == BLACK)
				setcolor(COLOR_BLACK);
			else if (pattern[j][i] == WHITE)
				setcolor(COLOR_HWHITE);
			else
				setcolor(COLOR_WHITE);
			cout << "  ";
		}
		putchar('\n');
	}
}

void QRcode::PrintPattern()
{
	for (int i = 0; i < pattern_size[version]; i++) {
		for (int j = 0; j < pattern_size[version]; j++) {
			if (pattern[j][i] == BLACK)
				cout << BLACK;
			else if (pattern[j][i] == WHITE)
				cout << WHITE;
			else
				cout << '.';
		}
		putchar('\n');
	}
}

void QRcode::FillingData(Polynomial &message_ply)
{
	PolyList p = message_ply.next;
	//cout << "====================\n";
	//cout << data_final << endl;
	//cout << strlen(data_final) / 8 << endl;
	//cout << "====================\n";

	flag = new bool*[pattern_size[version] + 1];
	for (int i = 0; i <= pattern_size[version]; i++) {
		flag[i] = new bool[pattern_size[version] + 1];
		memset(flag[i], 0, sizeof(bool) * pattern_size[version]);
	}


	strcpy(data_correct_code, data_final);

	while (p) {
		int tmp_num = p->coe;
		char tmp_str[10];
		Int2Int_binary(tmp_num, tmp_str);
		strcat(data_correct_code, tmp_str);
		//cout << tmp_num << " " << tmp_str << endl;
		p = p->next;
	}

	int ctr = 0;
	for (int i = pattern_size[version] - 1, t = 1; i >= 0; i -= 2, t ^= 1) {
		if (i == 6)
			i--;

		if ((t && i > 6) || (!t && i < 6)) {
			for (int j = pattern_size[version] - 1; j >= 0; j--) {
				for (int k = 0; k >= -1; k--) {
					if (pattern[i + k][j] == EMPTY) {
						pattern[i + k][j] = (data_correct_code[ctr++] - '0') ? BLACK : WHITE;
						flag[i + k][j] = true;
					}
					//DrawPattern();
					//Sleep(70);
				}
			}
		}
		else {
			for (int j = 0; j <= pattern_size[version] - 1; j++) {
				for (int k = 0; k >= -1; k--) {
					if (pattern[i + k][j] == EMPTY) {
						pattern[i + k][j] = (data_correct_code[ctr++] - '0') ? BLACK : WHITE;
						flag[i + k][j] = true;
					}
					//DrawPattern();
					//Sleep(70);

				}
			}
		}
	}
}

void QRcode::MaskingPattern()
{
	cout << endl << endl << endl;
	for (int i = 0; i < pattern_size[version]; i++) {
		for (int j = 0; j < pattern_size[version]; j++) {
			if (flag[j][i])
				if ((((i + j) % 2) + ((i * j) % 3)) % 2 == 0)
					pattern[j][i] = !pattern[j][i];
		}
	}
}

void QRcode::Solve()
{
	DecideVersion();

	//Data analyse
	CountIndicator();
	GetDataStream();
	ConcatenateData();
	//if (!strcmp(data_encoding, "01000000110101001000011001010110110001101100011011110010110000100000011101110110111101110010011011000110010000100001"))
	//	cout << "yes\n";

	AddTerminator();

	//Padding add
	AddPadding();

	//Correct error
	Polynomial message_ply;
	CorrectError(message_ply);

	InitialPattern();
	AddFunctionPattern();
	FillingFormatInfo();


	FillingData(message_ply);

	MaskingPattern();

	//Draw pattern

	DrawPattern();

	//PrintPattern();
	//DrawPattern();
}

int QRcode::Str2Int(char *str)
{
	int len = strlen(str);
	int num = 0;
	for (int i = 0; i < len; i++) {
		num *= 2;
		num += str[i] - '0';
	}
	return num;
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
	length = CountNumLength - 1;
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
	len_origin = strlen(origin_content);
	Int2Int_binary(len_origin, count_indicator);
}

void QRcode::GetDataStream()
{
	char tmp_str[10];
	strcpy(data_bit_stream, "");
	for (int i = 0; i < len_origin; i++) {
		char tmp_ch = origin_content[i];
		char tmp_n = char(1);
		for (int j = 0; j < 8; j++)
			tmp_str[j] = ((tmp_ch >> (7 - j)) & tmp_n) + '0';
		tmp_str[8] = '\0';
		strcat(data_bit_stream, tmp_str);
	}
}

void QRcode::ConcatenateData()
{
	strcpy(data_encoding, mode_indicator);
	strcat(data_encoding, count_indicator);
	strcat(data_encoding, data_bit_stream);
	len_data_encoding = strlen(data_encoding);
}

void QRcode::print()
{
	setcolor(COLOR_BLACK);
	cout << "version:" << this->version << endl;
	cout << "origin_content:" << this->origin_content << endl;
	cout << "count_indicator:" << this->count_indicator << endl;
	cout << "data_bit_stream:" << this->data_bit_stream << endl;
	cout << "data_encoding:" << this->data_encoding << endl;
	cout << "len_data_encoding:" << this->len_data_encoding << endl;
	cout << "data_final:" << this->data_final << endl;
	cout << "len_final:" << this->len_final << endl;
}

void test()
{
	Polynomial pa, pb;
	/*int test[][2] = { 16,25,19,24,99,23,144,22,236,21,17,20,236,19,17,18,236,17,17,16,236,15,17,14,236,13,17,12,236,11,1,10,236,9,17,8,236,7,0,6,0,5,0,4,0,3,0,2,0,1,0,0 };
	int test2[][2] = { 0,7,87,6,229,5,146,4,149,3,238,2,102,1,21,0 };*/

	int test[][2] = { 32,25,91,24,11,23,120,22,209,21,114,20,220,19,77,18,67,17,64,16,236,15,17,14,236,13,17,12,236,11,17,10,0,9,0,8,0,7,0,6,0,5,0,4,0,3,0,2,0,1,0,0 };
	int test2[][2] = { 0,10,251,9,67,8,46,7,61,6,118,5,70,4,64,3,94,2,32,1,45,0 };

	//for (int i = 0; i < 19; i++) {
	//	PolyList pl = new PolyNode(16,25,NULL);
	//	//pa.Append(&PolyNode(16, 25, NULL));
	//	pa.Append(pl);
	//}

	for (int i = 0; i < sizeof(test) / sizeof(*test); i++) {
		PolyList pl = new PolyNode(test[i][0], test[i][1]);
		pa.Append(pl);
	}
	for (int i = 0; i < sizeof(test2) / sizeof(*test2); i++) {
		PolyList pl = new PolyNode(test2[i][0], test2[i][1]);
		//PolyList pl = new PolyNode(alpha2n[test2[i][0]], test[i][1]);
		pb.Append(pl);
	}
	cout << "==================\n";
	cout << "pa:\n";
	pa.PrintPoly();
	cout << "==================\n";
	cout << "pb:\n";
	pb.PrintPoly();

	for (int i = 0; i < 16; i++) {
		cout << "==================\n";
		pa.GetHeadCoe();
		int headcoe = pa.head_coe;
		int headcoe_alpha = n2alpha[headcoe];
		cout << "headcoe:" << headcoe << endl;
		cout << "headcoe_alpha:" << headcoe_alpha << endl;

		cout << "==================\n";
		cout << "after multiply, pb:\n";
		pb.MulPoly(headcoe_alpha);
		pb.PrintPoly();

		cout << "==================\n";
		cout << "after convert alpha to n, pb:\n";
		pb.ConvertAlpha2N();
		pb.PrintPoly();


		cout << "==================\n";
		cout << "after xor, pa:\n";
		pa.XorPoly(pb);
		pa.PrintPoly();

		cout << "==================\n";
		cout << "recover pb:\n";
		pb.ConvertN2Alpha();
		pb.DivPoly(headcoe_alpha);
		pb.PrintPoly();
	}

}