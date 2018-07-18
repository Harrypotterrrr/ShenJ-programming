/* 1651574 贾昊霖 1班 */
//#include<cmath>
#include<iostream>
#pragma once
using namespace std;

class double1
{
protected:
	double x;
public:
	double1(const double a = 0);//构造
	bool operator==(const double1 &d1);//==重载
	bool operator!=(const double1 &d1);//!=重载
	friend ostream& operator<<(ostream& out, const double1 &d1);//cout 重载
	friend istream& operator>>(istream& in, double1 &d1);//cin 重载
	double1(const int a);//int 转 double1

};