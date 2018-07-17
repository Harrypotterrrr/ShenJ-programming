/* 1651574 贾昊霖 1班 */
#pragma once
#include<string>
#include<iostream>
using namespace std;


class student
{
protected:
	int   num;
	string  name;
	char  sex;
	float score;
	string  addr;
public:
	student(const int n = 0, const string nam = "jack", const char s = 'm', const float sc = 0, const string ad = "China");//构造函数
	bool operator==(const student &s1);//== 重载
	bool operator!=(const student &s1);//!= 重载
	student& operator=(const student &s1);//= 重载
	friend ostream& operator<<(ostream& out, const student &s1);//cout 重载
	friend istream& operator>>(istream& in,  student &s1);//cin 重载
};