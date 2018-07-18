/* 1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString
{
private:
	char *content;
	int len;
public:
	TString(const char *p = NULL);
	TString(const TString &);
	~TString();

	char* c_str() const;
	int length() const;

	TString& operator=(const TString &);
	TString& operator=(const char*);
	TString& operator+=(const TString &);
	TString& operator+=(const char );
	TString& operator-=(const TString &);
	TString& operator-=(const char);
	TString& operator*=(const int);
	char& operator[](int n);

	friend istream& operator >>(istream &, TString &);
	friend ostream& operator <<(ostream &, const TString &);

	friend TString operator+(const TString &, const char*);
	friend TString operator+(const char*, const TString &);
	friend TString operator+(const TString &, const TString &);

	friend TString operator+(const TString &, const char &);
	friend TString operator+(const char &, const TString &);

	friend TString operator-(const TString &, const char*);
	friend TString operator-(const char*, const TString &);
	friend TString operator-(const TString &, const TString &);

	friend TString operator-(const TString &, const char &);
	friend TString operator-(const char &, const TString &);

	friend TString operator*(const TString &, const int);
	friend TString operator!(const TString &);

	friend bool operator>(const TString &, const TString &);
	friend bool operator>(const TString &, const char *);
	friend bool operator>(const char *, const TString &);

	friend bool operator>=(const TString &, const TString &);
	friend bool operator>=(const TString &, const char *);
	friend bool operator>=(const char *, const TString &);

	friend bool operator<(const TString &, const TString &);
	friend bool operator<(const TString &, const char *);
	friend bool operator<(const char *, const TString &);

	friend bool operator<=(const TString &, const TString &);
	friend bool operator<=(const TString &, const char *);
	friend bool operator<=(const char *, const TString &);

	friend bool operator==(const TString &, const TString &);
	friend bool operator==(const TString &, const char *);
	friend bool operator==(const char *, const TString &);

	friend bool operator!=(const TString &, const TString &);
	friend bool operator!=(const TString &, const char *);
	friend bool operator!=(const char *, const TString &);


	friend int TStringLen(const TString &);
};



/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */

/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
