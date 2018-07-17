/* 1651574 1班 贾昊霖*/

/* 允许添加需要的头文件、宏定义等 */
#include "10-b3.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString(const char *p)
{
	if (p) {
		content = new(nothrow) char[strlen(p) + 1];
		if (!content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(content, p);
		this->len = strlen(p);
	}
	else {
		this->len = 0;
		//delete content;
		content = NULL;
	}
}
TString::TString(const TString &ts)
{
	if (ts.len) {
		content = new(nothrow) char[ts.len + 1];
		if (!content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		this->len = ts.len;
		strcpy(this->content, ts.content);
	}
	else {
		//delete content;
		this->content = NULL;
		this->len = 0;
	}
}
TString::~TString()
{
	delete content;
	content = NULL;
}

char* TString::c_str() const
{
	return this->content;
}

int TString::length() const
{
	return this->len;
}

TString& TString::operator=(const TString &ts)
{
	if (&ts == this)
		return *this;
	if (ts.len) {
		delete this->content;
		this->len = ts.len;
		content = new(nothrow) char[ts.len + 1];
		if (!content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(this->content, ts.content);
	}
	else {
		delete this->content;
		this->content = NULL;
		this->len = 0;
	}
	return *this;
}

TString& TString::operator=(const char* p)
{
	if (p) {
		this->len = strlen(p);
		delete this->content;
		content = new(nothrow) char[this->len + 1];
		if (!content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(this->content, p);
	}
	else {
		delete this->content;
		this->content = NULL;
		this->len = 0;
	}
	return *this;
}

char& TString::operator[](const int n)
{
	return this->content[n];
}

TString operator+(const TString &ts, const char* s)
{
	TString tmp;
	if (s) {
		tmp.len = ts.len + strlen(s);
		tmp.content = new(nothrow) char[tmp.len + 1];
		if (!tmp.content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		if (ts.content) {
			strcpy(tmp.content, ts.content);
			strcat(tmp.content, s);
		}
		else
			strcpy(tmp.content, s);
	}
	else {
		tmp.len = ts.len;
		tmp.content = new(nothrow) char[tmp.len + 1];
		if (!tmp.content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		if (ts.content)
			strcpy(tmp.content, ts.content);
	}
	return tmp;
}

TString operator+(const char* s, const TString &ts)
{
	TString tmp;
	if (s) {
		tmp.len = ts.len + strlen(s);
		tmp.content = new(nothrow) char[tmp.len + 1];
		if (!tmp.content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		if (s) {
			strcpy(tmp.content, s);
			if(ts.content)
				strcat(tmp.content, ts.content);
		}
		else if(ts.content)
			strcpy(tmp.content, ts.content);
	}
	else {
		tmp.len = ts.len;
		tmp.content = new(nothrow) char[tmp.len + 1];
		if (!tmp.content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		if (ts.content)
			strcpy(tmp.content, ts.content);
	}
	return tmp;
}

TString operator+(const TString &ts1, const TString &ts2)
{
	TString tmp;
	tmp.len = ts1.len + ts2.len;
	tmp.content = new(nothrow) char[tmp.len + 1];
	if (!tmp.content) {
		cout << "内存不足!\n";
		exit(-1);
	}
	if (ts1.len) {
		strcpy(tmp.content, ts1.content);
		if (ts2.len)
			strcat(tmp.content, ts2.content);
	}
	else if(ts2.len)
		strcpy(tmp.content, ts2.content);
	else {
		tmp.content = NULL;
		tmp.len = 0;
	}
	return tmp;
}

TString operator+(const TString &ts, const char& c)
{
	TString tmp;
	tmp.len = ts.len + 1;
	tmp.content = new(nothrow) char[tmp.len + 1];
	if (!tmp.content) {
		cout << "内存不足!\n";
		exit(-1);
	}
	strcpy(tmp.content, ts.content);
	tmp.content[tmp.len - 1] = c;
	tmp.content[tmp.len] = '\0';
	return tmp;
}

TString operator+(const char &c, const TString &ts)
{
	TString tmp;
	tmp.len = ts.len + 1;
	tmp.content = new(nothrow) char[tmp.len + 1];
	if (!tmp.content) {
		cout << "内存不足!\n";
		exit(-1);
	}
	tmp.content[0] = c;
	strcpy(tmp.content+1, ts.content);
	tmp.content[tmp.len] = '\0';
	return tmp;
}

TString operator-(const TString &ts, const char* s)
{
	TString tmp;
	char *p = strstr(ts.content, s);
	if (!p) {
		tmp.content = new (nothrow)char[ts.len + 1];
		if (!tmp.content) {
			cerr << "内存不足!\n";
			exit(-1);
		}
		strcpy(tmp.content, ts.content);
		tmp.len = ts.len;
		return ts;
		//cout << "没有找到字符串!\n";
		//exit(-1);
	}
	tmp.len = ts.len - strlen(s);
	tmp.content = new (nothrow)char[tmp.len + 1];
	if (!tmp.content) {
		cerr << "内存不足!\n";
		exit(-1);
	}
	strncpy(tmp.content, ts.content, p - ts.content);
	tmp.content[p - ts.content] = '\0';
	strcat(tmp.content, p + strlen(s));
	return tmp;
}

TString operator-(const char* s, const TString &ts)
{
	TString tmp;
	char *s_tmp = new (nothrow)char[ts.len + 1];
	if (!s_tmp) {
		cerr << "内存不足!\n";
		exit(-1);
	}
	strcpy(s_tmp, s);
	s_tmp[strlen(s_tmp)] = '\0';

	char *p = strstr(s_tmp, ts.content);
	if (!p) {
		tmp.len = strlen(s);
		strcpy(tmp.content, s);
		return tmp;
		//cout << "没有找到字符串!\n";
		//exit(-1);
	}

	tmp.len = strlen(s) - ts.len;
	tmp.content = new (nothrow)char[tmp.len + 1];
	if (!tmp.content) {
		cerr << "内存不足!\n";
		exit(-1);
	}

	strncpy(tmp.content, s, p - s_tmp);
	tmp.content[p - s_tmp] = '\0';
	strcat(tmp.content, p + strlen(tmp.content));

	delete s_tmp;
	return tmp;
}

TString operator-(const TString &ts1, const TString &ts2)
{
	TString tmp;
	char *p = strstr(ts1.content, ts2.content);
	if (!p) {
		tmp.content = new (nothrow)char[ts1.len + 1];
		if (!tmp.content) {
			cerr << "内存不足!\n";
			exit(-1);
		}
		strcpy(tmp.content, ts1.content);
		tmp.len = ts1.len;
		return ts1;
		//cout << "没有找到字符串!\n";
		//exit(-1);
	}
	tmp.len = ts1.len - ts2.len;
	tmp.content = new (nothrow)char[tmp.len + 1];
	if (!tmp.content) {
		cerr << "内存不足!\n";
		exit(-1);
	}
	strncpy(tmp.content, ts1.content, p - ts1.content);
	tmp.content[p - ts1.content] = '\0';
	strcat(tmp.content, p + ts2.len);
	return tmp;
}

TString operator-(const TString &ts, const char& c)
{
	TString tmp;
	tmp.len = ts.len + 1;
	tmp.content = new(nothrow) char[tmp.len + 1];
	if (!tmp.content) {
		cout << "内存不足!\n";
		exit(-1);
	}
	
	char *p = strchr(ts.content, c);
	if (!p) {
		strcpy(tmp.content, ts.content);
		tmp.len = ts.len;
		return tmp;
	}
	strncpy(tmp.content, ts.content,p-ts.content);
	tmp.content[p - ts.content] = '\0';
	strcat(tmp.content, p + 1);
	return tmp;
}

TString operator-(const char &c, const TString &ts)
{
	TString tmp;
	tmp.len = ts.len + 1;
	tmp.content = new(nothrow) char[tmp.len + 1];
	if (!tmp.content) {
		cout << "内存不足!\n";
		exit(-1);
	}
	strcpy(tmp.content, ts.content);
	tmp.content[tmp.len - 1] = c;
	tmp.content[tmp.len] = '\0';
	return tmp;
}

TString& TString::operator+=(const TString &ts)
{
	if (ts.len) {
		if (this->len) {
			char *tmp = new(nothrow) char[this->len + ts.len];
			if (!tmp) {
				cout << "内存不足!\n";
				exit(-1);
			}
			strcpy(tmp, this->content);

			delete this->content;
			this->len += ts.len;
			content = new(nothrow) char[this->len + ts.len];
			if (!content) {
				cout << "内存不足!\n";
				exit(-1);
			}
			strcpy(this->content, tmp);
			strcat(this->content, ts.content);
			delete tmp;
		}
		else {
			this->len = ts.len;
			content = new(nothrow) char[this->len + ts.len];
			if (!content) {
				cout << "内存不足!\n";
				exit(-1);
			}
			strcpy(this->content, ts.content);
		}
	}
	return *this;
}

TString& TString::operator+=(const char c)
{
	if (c) {
		if (this->len) {
			char *tmp = new(nothrow) char[this->len + 1];
			if (!tmp) {
				cout << "内存不足!\n";
				exit(-1);
			}
			strcpy(tmp, this->content);

			delete this->content;
			this->len += 1;
			content = new(nothrow) char[this->len + 1];
			if (!content) {
				cout << "内存不足!\n";
				exit(-1);
			}
			strcpy(this->content, tmp);
			this->content[this->len - 1] = c;
			this->content[this->len] = '\0';
			delete tmp;
		}
		else {
			this->len = 1;
			content = new(nothrow) char[this->len + 1];
			if (!content) {
				cout << "内存不足!\n";
				exit(-1);
			}
			this->content[0] = c;
			this->content[1] = '\0';
		}
	}
	return *this;
}

TString& TString::operator-=(const TString &ts)
{
	char *p = strstr(this->content, ts.content);
	if (p) {
		this->len -= ts.len;
		char *tmp = new(nothrow) char[this->len + 1];
		if (!tmp) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strncpy(tmp, this->content,p-this->content);
		tmp[p - this->content] = '\0';
		strcat(tmp, p + ts.len);

		delete this->content;

		this->content = new(nothrow) char[this->len + 1];
		if (!this->content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(this->content, tmp);
		delete tmp;
	}
	//else {
	//	cout << "没有找到该串!\n";
	//}

	return *this;
}

TString& TString::operator-=(const char c)
{
	if (c) {
		char *tmp = new(nothrow) char[this->len + 1];
		if (!this->content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(tmp, this->content);

		delete this->content;
		this->len -= 1;
		content = new(nothrow) char[this->len + 1];
		if (!content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		char *p = strchr(tmp, c);
		if (!p) {
			strcpy(this->content, tmp);
			this->len += 1;
			return *this;
		}
		strncpy(this->content, tmp, p - tmp);
		this->content[p - tmp] = '\0';
		strcat(this->content, p+1);
		delete tmp;
	}
	return *this;
}

TString& TString::operator*=(const int n)
{
	if (!this->len || n == 0) {
		delete this->content;
		this->content = NULL;
	}
	else {
		char *tmp = new(nothrow) char[this->len + 1];
		if (!tmp) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(tmp, this->content);

		this->len *= n;

		delete this->content;
		content = new(nothrow) char[this->len + 1];
		if (!content) {
			cout << "内存不足!\n";
			exit(-1);
		}
		strcpy(this->content, tmp);
		for (int i = 0; i < n - 1; i++)
			strcat(this->content, tmp);
		delete tmp;
	}
	return *this;
}

TString operator*(const TString &ts, const int n)
{
	TString tmp = ts;
	tmp *= n;
	return tmp;
}

TString operator!(const TString &ts)
{
	TString tmp = ts;
	for (int i = 0; i < tmp.len / 2; i++) {
		char c_tmp = tmp.content[i];
		tmp.content[i] = tmp.content[tmp.len - 1 - i];
		tmp.content[tmp.len - 1 - i] = c_tmp;
	}
	return tmp;
}

bool operator>(const TString &ts1, const TString &ts2)
{
	if (!ts1.content || !ts2.content)
		return false;
	int i;
	for (i = 0; i < ts1.len && i < ts2.len; i++) {
		if (ts1.content[i] != ts2.content[i])
			return ts1.content[i] > ts2.content[i];
	}

	return ts1.content[i] != '\0';
}

bool operator>(const TString &ts, const char *s)
{
	int i;
	if (!ts.content && !s)
		return false;
	if (!ts.content && strlen(s))
		return true;
	if (!ts.content && !strlen(s))
		return false;
	if (!s)
		return true;
	for (i = 0; i < (int)strlen(s) && i < ts.len; i++) {
		if (ts.content[i] != s[i])
			return ts.content[i] > s[i];
	}

	return ts.content[i] != '\0';
}

bool operator>(const char *s, const TString &ts)
{
	int i;
	for (i = 0; i < (int)strlen(s) && i < ts.len; i++) {
		if (ts.content[i] != s[i])
			return s[i] > ts.content[i];
	}

	return s[i] != '\0';
}

bool operator>=(const TString &ts1, const TString &ts2)
{
	if (!ts1.content || !ts2.content)
		return true;
	int i;
	for (i = 0; i < ts1.len && i < ts2.len; i++) {
		if (ts1.content[i] != ts2.content[i])
			return ts1.content[i] >= ts2.content[i];
	}
	if (i == ts1.len && i == ts2.len)
		return true;
	return ts1.content[i] != '\0';
}

bool operator>=(const TString &ts, const char *s)
{
	int i;
	if (!s || !strlen(s))
		return true;
	for (i = 0; i < (int)strlen(s) && i < ts.len; i++) {
		if (ts.content[i] != s[i])
			return ts.content[i] > s[i];
	}
	if (i == ts.len && i == strlen(s))
		return true;
	return ts.content[i] != '\0';
}

bool operator>=(const char *s, const TString &ts)
{
	int i;
	for (i = 0; i < (int)strlen(s) && i < ts.len; i++) {
		if (ts.content[i] != s[i])
			return s[i] > ts.content[i];
	}
	if (i == ts.len && i == strlen(s))
		return true;
	return s[i] != '\0';
}

bool operator<(const TString &ts1, const TString &ts2)
{
	if (!ts1.content || !ts2.content)
		return false;
	int i;
	for (i = 0; i < ts1.len && i < ts2.len; i++) {
		if (ts1.content[i] != ts2.content[i])
			return ts1.content[i] < ts2.content[i];
	}

	return ts1.content[i] == '\0';
}

bool operator<(const TString &ts, const char *s)
{
	int i;
	if (!s || !strlen(s))
		return false;
	int t = strcmp(ts.content, s);
	if (t < 0)
		return true;
	return false;
}

bool operator<(const char *s, const TString &ts)
{
	int i;
	for (i = 0; i < (int)strlen(s) && i < ts.len; i++) {
		if (ts.content[i] != s[i])
			return s[i] < ts.content[i];
	}

	return s[i] == '\0';
}

bool operator<=(const TString &ts1, const TString &ts2)
{
	if (!ts1.content || !ts2.content)
		return true;
	int i;
	for (i = 0; i < ts1.len && i < ts2.len; i++) {
		if (ts1.content[i] != ts2.content[i])
			return ts1.content[i] < ts2.content[i];
	}
	if (i == ts1.len && i == ts2.len)
		return true;
	return ts1.content[i] == '\0';
}

bool operator<=(const TString &ts, const char *s)
{
	int i;
	if (!ts.content && !s)
		return true;
	if (!s)
		return false;
	if (!ts.content && !strlen(s))
		return true;
	for (i = 0; i < ts.len && i < (int)strlen(s); i++) {
		if (ts.content[i] != s[i])
			return ts.content[i] <= s[i];
	}
	if (i == ts.len && i == strlen(s))
		return true;
	return ts.content[i] == '\0';
}

bool operator<=(const char *s, const TString &ts)
{
	int i;
	for (i = 0; i < ts.len && i < (int)strlen(s); i++) {
		if (ts.content[i] != s[i])
			return ts.content[i] <= s[i];
	}
	if (i == ts.len && i == strlen(s))
		return true;
	return ts.content[i] == '\0';
}

bool operator==(const TString &ts1, const TString &ts2)
{
	if (!ts1.content || !ts2.content)
		return true;
	int n = strcmp(ts1.content, ts2.content);
	return n == 0;
}

bool operator==(const TString &ts, const char *s)
{
	if (!ts.content)
		return true;
	if (!s)
		return false;
	if (!ts.content && !strlen(s))
		return true;
	int n = strcmp(ts.content, s);
	return n == 0;
}

bool operator==(const char *s, const TString &ts)
{
	if (!ts.content || !s)
		return false;
	int n = strcmp(ts.content, s);
	return n == 0;
}

bool operator!=(const TString &ts1, const TString &ts2)
{
	if (!ts1.content || !ts2.content)
		return false;
	int n = strcmp(ts1.content, ts2.content);
	return n != 0;
}

bool operator!=(const TString &ts, const char *s)
{
	if (!ts.content && !s)
		return false;
	if (!ts.content && s)
		return false;
	if (!s)
		return true;
	int n = strcmp(ts.content, s);
	return n != 0;
}

bool operator!=(const char *s, const TString &ts)
{
	if (!ts.content || !s)
		return true;
	int n = strcmp(ts.content, s);
	return n != 0;
}

istream& operator>>(istream &in, TString &ts)
{
	char s[1024];
	in >> s;
	if (!in.good()) {
		cerr << "输入有点问题啊..\n";
		exit(-1);
	}
	ts.len = strlen(s);
	ts.content = new(nothrow) char[ts.len + 1];
	strcpy(ts.content, s);
	return in;
}

ostream& operator<<(ostream &out, const TString &ts)
{
	if (ts.len)
		out << ts.content;
	else
		out << "<NULL>";
	return out;
}


/* 如果有需要的其它全局函数的实现，可以写于此处 */

int TStringLen(const TString &ts)
{
	return ts.length();
}