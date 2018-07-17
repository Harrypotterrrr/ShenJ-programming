/* 1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
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



/* 如果有其它全局函数需要声明，写于此处 */

/* 如果有需要的宏定义、只读全局变量等，写于此处 */
