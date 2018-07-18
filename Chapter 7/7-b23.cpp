/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h>

#define OK 1
#define ERROR 0
#define QUIT -1
#define INPUTERROR 2
using namespace std;

typedef int Status;
typedef long long ll;

const char* attrName[] = { "����ǳ�" ,"����ֵ" , "����" ,"����" ,"����ֵ","��Ǯ",
"����" ,"����ֵ" ,"����", "�ƶ��ٶ�" ,"�����ٶ�" ,"������Χ" , "������" ,"������" ,
"���ݶ�ֵ" ,"����" ,"����ֵ" , "�ȼ�" ,"ħ��ֵ" ,"ħ��������" , "ħ���˺���" ,
"������" ,"ħ��������" ,"������" , "����" ,NULL };

const ll maxAttr[] = { 0,10000,10000,8192,1024,100000000,1000000,1000000,100000000000,100,100,100,2000,2000,100,100,100,100,10000,100,100,100,100,100,100,-1 };

const int addByte[] = { 0,16,18,20,22,24,28,32,36,44,45,46,48,50,52,53,54,55,56,58,59,60,61,62,63,-1 };

const int attrType[] = { 3,1,1,1,1,2,2,2,4,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0 };

const char fileName[20] = "game1.dat";

/*
char		0
short		1
int			2
char*		3
long long	4
*/

struct Attribute
{
	char name[16];
	short HP;						//health point
	short str;						//strength
	short cor;						//corporeity
	short agi;						//agile
	int GP;							//gold point
	int fame;
	int charm;
	char ReserveValue[8];
	//ll ReserveValue;				//PAY ATTENTION!! byte stuffing��
	char moveSpeed;
	char attackSpeed;
	char attackRange;
	char ReserveValue2;
	short ATK;						//attack
	short DEF;						//defend
	char DEX;						//dexterousness
	char INT;						//intelligence
	char exp;						//experience
	char level;
	short MP;						//mana point
	char mCost;
	char mAtk;
	char hitRate;
	char mDef;
	char CRI;		//critical chance
	char STA;		//stamina
};

Status Input(Attribute &info)
{
	ifstream fin;
	fin.open(fileName, ios::in | ios::binary);
	if (!fin.is_open()) {
		cerr << "�ļ�������!\n";
		return ERROR;
	}
	if (!fin.read((char*)&info, sizeof(info))) {
		cerr << "�ļ���С�����������ֽ�����ƥ�䣡\n";
		return ERROR;
	}
	fin.close();
	return OK;
}

ll stoi(char* str)
{
	int len = strlen(str);
	ll num = 0;
	for (int i = 0; i < len; i++) {
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}

Status ModifyAttr(Attribute &info)
{
	char ch;
	cout << "�������޸���ţ���0�˳��޸�:\n";
	ch = _getche();
	putchar('\n');
	if (ch == '0')
		return QUIT;
	if (ch >= 'a' && ch <= 'z')
		ch -= 32;
	if (ch <'A' || ch >= 'A' + sizeof(addByte) / sizeof(int) - 1)
		return INPUTERROR;

	int k = ch - 'A';
	char tmp[36];
	cout << "�������޸ĵ���ֵ�� ";
	cin >> tmp;
	if (attrType[k] == 3) {
		if (strlen(tmp) > 16)
			return INPUTERROR;
		strcpy((char*)&info + addByte[k], tmp);
	}
	else {
		ll num = stoi(tmp);
		if (attrType[k] == 4)
			num -= 100000000000;
		if (num > maxAttr[k] || num < 0)
			return INPUTERROR;
		if (attrType[k] == 0)
			*((char*)&info + addByte[k]) = char(num);
		else if (attrType[k] == 1)
			*(short*)((char*)&info + addByte[k]) = short(num);
		else if (attrType[k] == 2)
			*(int*)((char*)&info + addByte[k]) = int(num);
		else if (attrType[k] == 4)
			*(ll*)((char*)&info + addByte[k]) = ll(num + 100000000000);
		//VERY IMPORTANT!!!!!
	}

	ofstream fout(fileName, ios::out | ios::binary); //ios::out is also right!
	if (!fout.is_open()) {
		cerr << "�ļ�δ�ܴ򿪣�\n";
		return ERROR;
	}
	fout.write((char*)&info, sizeof(info));
	return OK;
}

void PrintAttr(const Attribute &info)
{
	for (int i = 0; attrName[i]; i++) {
		cout << char(i + 'A') << '.' << attrName[i] << (strlen(attrName[i]) < 6 ? "\t" : "") << "\t:";
		if (attrType[i] == 3)
			cout << ((char*)&info + addByte[i]);
		else if (attrType[i] == 0)
			cout << (int)*((char*)&info + addByte[i]);
		else if (attrType[i] == 1)
			cout << (short)*(short*)((char*)&info + addByte[i]);
		else if (attrType[i] == 2)
			cout << (int)*(int*)((char*)&info + addByte[i]);
		else if (attrType[i] == 4)
			cout << (ll)*(ll*)((char*)&info + addByte[i]);
		//VERY IMPORTANT!!!!!!!!
		putchar('\n');
	}
}

int main()
{
	Attribute info;
	if (!Input(info))
		return 0;
	PrintAttr(info);
	while (true) {
		Status tag = ModifyAttr(info);
		if (tag == QUIT || tag == ERROR) {
			cout << "�޸Ľ�����\n";
			break;
		}
		if (tag == INPUTERROR)
			cout << "��������������ֵ��Χ����ȷ�����������룡\n";
		else if (tag == OK) {
			system("cls");
			PrintAttr(info);
		}
	}
	return 0;
}