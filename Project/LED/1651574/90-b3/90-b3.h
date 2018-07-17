#pragma once
/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <Windows.h>
#include <strstream>
#include <io.h>
#include <experimental/filesystem>

using namespace std;

enum ITEM_TYPE { TYPE_INT = 0, TYPE_DOUBLE, TYPE_STRING, TYPE_CHARACTER, TYPE_NULL };

#define OPEN_OPT_RDONLY		0	//��ֻ����ʽ�򿪣��򲻿��򷵻�ʧ�ܣ�
#define OPEN_OPT_RDWR		1	//�Զ�д��ʽ�򿪣��򲻿��ļ��򴴽���
#define OK 1
#define ERROR 0

/* �������λ�ã��������һ�С��������һ�����С����������һ��Ŀ�ʼ�� */
enum INSERT_POS_TYPE { FIRST_LINE_AFTER_GROUP = 0, FIRST_SPACE_LINE_AFTER_GROUP, BEFORE_NEXT_GROUP };

const char filename[200] = "test.ini";

struct Text
{
	char *content;
	Text* next;
};

//ifstream &open_cfg(const char *, int);

int open_cfgfile(fstream &, const char*, const int);

void close_cfgfile(fstream &);

bool isBlankLine(const char *content);

void DestroyLink(Text* &);

int _length(fstream &);

//int _resize(const char *, fstream &, int);

int InsertText(Text *, Text *, const char *, const void *, const enum ITEM_TYPE );

void PrintFile(fstream &, const char *, Text *);

Text* ScanFile(fstream &);

int group_del(fstream &, const char *, const char *);

int group_add(fstream &, const char *, const char *);

int item_add(fstream &, const char *, const char *, const char *, const void *, const enum ITEM_TYPE );

int item_del(fstream &, const char* , const char *, const char *);

int item_update(fstream &, const char* , const char *, const char *, const void *, const enum ITEM_TYPE );

int item_get_value(fstream &, const char *, const char *, const char *, void *, const enum ITEM_TYPE );