/* 1651574 ����� 1�� */
//#include<cmath>
#include<iostream>
#pragma once
using namespace std;

class double1
{
protected:
	double x;
public:
	double1(const double a = 0);//����
	bool operator==(const double1 &d1);//==����
	bool operator!=(const double1 &d1);//!=����
	friend ostream& operator<<(ostream& out, const double1 &d1);//cout ����
	friend istream& operator>>(istream& in, double1 &d1);//cin ����
	double1(const int a);//int ת double1

};