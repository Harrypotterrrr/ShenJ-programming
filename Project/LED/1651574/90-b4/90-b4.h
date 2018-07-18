/* 1651574 º÷Íª¡ÿ 1∞‡*/
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include "..\common\cmd_console_tools.h"


using namespace std;
typedef int Status;

//#define ERROR -1
#define OK 1
#define CountNumLength 8
#define BLACK 1
#define WHITE 0

#define EMPTY 0x3F3F3F3F

#define CalcSize(V) (((V-1)*4)+21)

#define DarkModule() ([£®4 * V£©+ 9],8)

const int n2alpha[] = { INT_MAX ,0 ,1 ,25 ,2 ,50 ,26 ,198 ,3 ,223 ,51 ,238 ,27 ,104 ,199 ,75 ,4 ,100 ,224 ,14 ,52 ,141 ,239 ,129 ,28 ,193 ,105 ,248 ,200 ,8 ,76 ,113 ,5 ,138 ,101 ,47 ,225 ,36 ,15 ,33 ,53 ,147 ,142 ,218 ,240 ,18 ,130 ,69 ,29 ,181 ,194 ,125 ,106 ,39 ,249 ,185 ,201 ,154 ,9 ,120 ,77 ,228 ,114 ,166 ,6 ,191 ,139 ,98 ,102 ,221 ,48 ,253 ,226 ,152 ,37 ,179 ,16 ,145 ,34 ,136 ,54 ,208 ,148 ,206 ,143 ,150 ,219 ,189 ,241 ,210 ,19 ,92 ,131 ,56 ,70 ,64 ,30 ,66 ,182 ,163 ,195 ,72 ,126 ,110 ,107 ,58 ,40 ,84 ,250 ,133 ,186 ,61 ,202 ,94 ,155 ,159 ,10 ,21 ,121 ,43 ,78 ,212 ,229 ,172 ,115 ,243 ,167 ,87 ,7 ,112 ,192 ,247 ,140 ,128 ,99 ,13 ,103 ,74 ,222 ,237 ,49 ,197 ,254 ,24 ,227 ,165 ,153 ,119 ,38 ,184 ,180 ,124 ,17 ,68 ,146 ,217 ,35 ,32 ,137 ,46 ,55 ,63 ,209 ,91 ,149 ,188 ,207 ,205 ,144 ,135 ,151 ,178 ,220 ,252 ,190 ,97 ,242 ,86 ,211 ,171 ,20 ,42 ,93 ,158 ,132 ,60 ,57 ,83 ,71 ,109 ,65 ,162 ,31 ,45 ,67 ,216 ,183 ,123 ,164 ,118 ,196 ,23 ,73 ,236 ,127 ,12 ,111 ,246 ,108 ,161 ,59 ,82 ,41 ,157 ,85 ,170 ,251 ,96 ,134 ,177 ,187 ,204 ,62 ,90 ,203 ,89 ,95 ,176 ,156 ,169 ,160 ,81 ,11 ,245 ,22 ,235 ,122 ,117 ,44 ,215 ,79 ,174 ,213 ,233 ,230 ,231 ,173 ,232 ,116 ,214 ,244 ,234 ,168 ,80 ,88 ,175 };
const int alpha2n[] = { 1 ,2 ,4 ,8 ,16 ,32 ,64 ,128 ,29 ,58 ,116 ,232 ,205 ,135 ,19 ,38 ,76 ,152 ,45 ,90 ,180 ,117 ,234 ,201 ,143 ,3 ,6 ,12 ,24 ,48 ,96 ,192 ,157 ,39 ,78 ,156 ,37 ,74 ,148 ,53 ,106 ,212 ,181 ,119 ,238 ,193 ,159 ,35 ,70 ,140 ,5 ,10 ,20 ,40 ,80 ,160 ,93 ,186 ,105 ,210 ,185 ,111 ,222 ,161 ,95 ,190 ,97 ,194 ,153 ,47 ,94 ,188 ,101 ,202 ,137 ,15 ,30 ,60 ,120 ,240 ,253 ,231 ,211 ,187 ,107 ,214 ,177 ,127 ,254 ,225 ,223 ,163 ,91 ,182 ,113 ,226 ,217 ,175 ,67 ,134 ,17 ,34 ,68 ,136 ,13 ,26 ,52 ,104 ,208 ,189 ,103 ,206 ,129 ,31 ,62 ,124 ,248 ,237 ,199 ,147 ,59 ,118 ,236 ,197 ,151 ,51 ,102 ,204 ,133 ,23 ,46 ,92 ,184 ,109 ,218 ,169 ,79 ,158 ,33 ,66 ,132 ,21 ,42 ,84 ,168 ,77 ,154 ,41 ,82 ,164 ,85 ,170 ,73 ,146 ,57 ,114 ,228 ,213 ,183 ,115 ,230 ,209 ,191 ,99 ,198 ,145 ,63 ,126 ,252 ,229 ,215 ,179 ,123 ,246 ,241 ,255 ,227 ,219 ,171 ,75 ,150 ,49 ,98 ,196 ,149 ,55 ,110 ,220 ,165 ,87 ,174 ,65 ,130 ,25 ,50 ,100 ,200 ,141 ,7 ,14 ,28 ,56 ,112 ,224 ,221 ,167 ,83 ,166 ,81 ,162 ,89 ,178 ,121 ,242 ,249 ,239 ,195 ,155 ,43 ,86 ,172 ,69 ,138 ,9 ,18 ,36 ,72 ,144 ,61 ,122 ,244 ,245 ,247 ,243 ,251 ,235 ,203 ,139 ,11 ,22 ,44 ,88 ,176 ,125 ,250 ,233 ,207 ,131 ,27 ,54 ,108 ,216 ,173 ,71 ,142 ,INT_MAX };

const int data_capacity[] = { 17,32,53,78,106 };
const int data_total[] = { 19,34,55,80,108 };
const int correction_number[] = { 7,10,15,20,26 };
const int generator_polynomial[][28][2] = {
	{ 0,7,87,6,229,5,146,4,149,3,238,2,102,1,21,0 },
{ 0,10,251,9,67,8,46,7,61,6,118,5,70,4,64,3,94,2,32,1,45,0 },
{ 0,15,8,14,183,13,61,12,91,11,202,10,37,9,51,8,58,7,58,6,237,5,140,4,124,3,5,2,99,1,105,0 },
{ 0,20,17,19,60,18,79,17,50,16,61,15,163,14,26,13,187,12,202,11,180,10,221,9,225,8,83,7,239,6,156,5,164,4,212,3,212,2,188,1,190,0 },
{ 0,26,173,25,125,24,158,23,2,22,103,21,182,20,118,19,17,18,145,17,201,16,111,15,28,14,165,13,53,12,161,11,21,10,245,9,142,8,13,7,102,6,48,5,227,4,153,3,145,2,218,1,70,0 }
};
const char correct_level[][3] = { "01","00","11","10" };
const char mask_module[][16] = { "111011111000100", "111001011110011", "111110110101010", "111100010011101", "110011000101111", "110001100011000","110110001000001","110100101110110" };
const int remain_bit[] = { 0,7,7,7,7 };
const int alignmentPattern_loc[][2] = { { 0,0 },{ 18,18 },{ 22,22 },{ 26,26 },{ 30,30 } };
const int pattern_size[] = { 21,25,29,33,37 };


class PolyNode {
public:
	int coe;	//coefficient
	int exp;	//exponent
	PolyNode* next;
	PolyNode(int = 0, int = 0, PolyNode* = NULL);
};

typedef PolyNode* PolyList;

class Polynomial {
public:
	int head_coe;
	PolyList next;
	Polynomial(PolyList = NULL) { next = NULL; }
	void Append(PolyNode &);
	void Append(PolyList &);
	void GetHeadCoe();
	void MulPoly(int n);
	void DivPoly(int n);
	void XorPoly(const Polynomial &);
	void ConvertAlpha2N();
	void ConvertN2Alpha();
	void PrintPoly();
};

class QRcode
{
private:
	char origin_content[105];
	char mode_indicator[8];
	char count_indicator[15];
	char data_bit_stream[1050];
	char data_encoding[1000];
	char data_final[1000];

	char data_correct_code[2000];
	int len_origin;
	int len_data_encoding;
	int len_final;
	int version;
	int mask_version;

	int cost[8][4];

	char correct_str[20] = "111101000110011";

public:
	QRcode(char* = NULL);
	~QRcode();

	int **pattern;
	bool **flag;

	void Solve();
	void DecideVersion();
	void CountIndicator();
	void GetDataStream();
	void ConcatenateData();
	void AddTerminator();
	void AddPadding();
	void CorrectError(Polynomial &);
	void InitialPattern();
	void AddFunctionPattern();
	void PositionDetectPattern(int, int);
	void SeperatorPattern();
	void PrintPattern();
	void DrawPattern();
	void AlignmentPattern();
	void TimingPattern();
	void FillingFormatInfo();
	void FillingData(Polynomial &);

	void MaskingPattern();

	int Str2Int(char*);
	int Str2Int_binary(char*);
	void Int2Int_binary(int, char *, int = 0);

	void print();
};