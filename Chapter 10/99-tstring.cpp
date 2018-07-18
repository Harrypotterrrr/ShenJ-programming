/* ѧ�� ���� �༶ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define strcat MyStrcat
using namespace std;

/* �ڴ˴�������Ķ��弰ʵ�� */

class TString
{
private:
	char *content;
	int len;
	TString* next;
	TString* tail;
public:
	TString(const char *p = NULL);
	~TString();

	int length() const;

	TString& operator+=(const char *);
	
	friend bool operator!=(const TString &, const char *);
};

int TString::length() const
{
	int sum = this->len;
	const TString *p = this->next;
	while (p){
		sum += p->len;
		p = p->next;
	}
	return sum;
}

TString& TString::operator+=(const char *s)
{

	if (this->len == 0) {
		this->len += strlen(s);
		this->content = new char [this->len + 1];
		this->next = NULL;
		this->tail = this;
		strcpy(this->content, s);
		return *this;
	}

	this->tail->next = new TString(s);
	this->tail = this->tail->next;
	return *this;
}

bool operator!=(const TString &ts, const char *s)
{
	return true;
}


TString::TString(const char *p)
{
	if (p) {
		this->content = (char*)malloc(strlen(p) + 1);
		strcpy(content, p);
		this->len = strlen(p);
	}
	else {
		this->len = 0;
		this->content = NULL;
	}
	next = NULL;
	tail = NULL;
}

TString::~TString()
{
	delete this->content;
	content = NULL;
}	

void MyStrcat(char *s, char* str)
{

}

/* ����Ĺ��ߺ�����main������Ķ� */

#if defined(__linux) || defined(__linux__)
#include <sys/time.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
long get_cur_msec(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;  //΢��ת����
}

#else
#include <Windows.h>
#include <conio.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
long get_cur_msec(void)
{
	return GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ����
}

#endif

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int memory_speed_test(void)
{
	const int MAX_BYTES = 100 * 1024 * 1024;

	TString s1;
	int     total, len, i;
	int     MB_count, MB_prev_count;
	char    temp[65536];
	long    t_start, t_end, t_cur, t_prev;
	char   *crc_str;

	cout << "�ڴ����ܲ���(s1+=str��ʽ)" << endl;
	wait_for_enter();

	crc_str = new(nothrow) char[MAX_BYTES + 65536]; //���루100MB+64KB���ռ�
	if (crc_str == NULL) {
		cout << "�޷�����" << MAX_BYTES + 65536 << "�ֽڵ�У��ռ䣬������ֹ��������ٴ�����" << endl;
		return -1;
	}
	*crc_str = 0; //��Ϊ�մ�

	t_prev = t_start = get_cur_msec(); //ȡ��ǰϵͳʱ�䣬��λ����
	MB_prev_count = 0;
	srand((unsigned int)time(0));
	total = 0;
	while (1) {
		len = 32768 + rand() % 32768;

		for (i = 0; i<len; i++)
			temp[i] = ' ' + rand() % 95;	//����������ַ����
		temp[len] = 0;
		total += len;
		s1 += temp;

		strcat(crc_str, temp);

		MB_count = s1.length() / (1024 * 1024);
		if (MB_count - MB_prev_count >= 1) {
			MB_prev_count = MB_count;

			t_cur = get_cur_msec();   //ȡ��ǰϵͳʱ��

			cout << "s1���г��ȣ�" << setw(10) << s1.length() / (1024.0 * 1024) << " MB�ֽڣ��������� " << setw(5) << len << " �ֽڣ�����ʱ"
				<< setw(10) << (t_cur - t_start) / 1000.0 << "�룬����1MB��ʱ" << setw(10) << (t_cur - t_prev) / 1000.0 << "��" << endl;
			t_prev = t_cur;
		}
		else
			cout << "s1���г��ȣ�" << setw(10) << s1.length() / (1024.0 * 1024) << " MB�ֽڣ��������� " << setw(5) << len << " �ֽ�" << endl;

		if (s1.length() == 0 || s1.length() > MAX_BYTES)	//��100MB���ڴ�ľ������
			break;
	}//end of while (1)

	t_end = get_cur_msec();   //ȡ��ǰϵͳʱ��

	cout << "time=" << (t_end - t_start) / 1000.0 << endl;

	if (s1.length() == 0) {
		cout << "�ڴ���䵽�� " << total / (1024 * 1024) << " MB�ֽں��ڴ�ľ�����������еĴ���" << endl;

#if !(defined(__linux) || defined(__linux__))
		cout << endl << "�۲�����������б�������ڴ�ռ�����..." << endl;
		wait_for_enter();
#endif
		exit(-1);
	}
	else
		cout << "�ڴ���䵽����100MB�����Խ���" << endl;

	int check1 = (s1 != crc_str);			//TString��ʽ�Ƚ������Ƿ����
	delete[]crc_str; //�ͷ�У�鴮

	if (check1)
		cout << "s1�ۼ���֤������������ʵ�ֲ���" << endl;
	else {
		cout << "    ���β��Ժ�ʱ " << (t_end - t_start) / 1000.0 << "��" << endl;
#if !(defined(__linux) || defined(__linux__))
		cout << endl << "�۲�����������б�������ڴ�ռ�����(��������115MB)..." << endl;
#endif
		wait_for_enter();
	}

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	memory_speed_test();

#if !(defined(__linux) || defined(__linux__))
	system("pause");
#endif

	return 0;
}
