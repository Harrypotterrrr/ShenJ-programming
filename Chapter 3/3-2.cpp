/*1651574 1�� �����*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define pai 2*asin(1)
using namespace std;
int main()
{
	double r = 1.5, h = 3;
	double roundCircum, roundSquare, sphereSquare, \
		sphereVolume,cylinVolume;
	roundCircum = 2 * pai*r;
	roundSquare = pai * r * r;
	sphereSquare = 4 * pai*r*r;
	sphereVolume = 4. / 3.*pai*r*r*r;
	cylinVolume = roundCircum*h;
	cout <<setiosflags(ios::fixed)<< setprecision(2);   //��ʽ����
	cout << "Բ�ܳ�Ϊ�� " << roundCircum << endl           //���
		<< "Բ���Ϊ�� " << roundSquare << endl
		<< "Բ������Ϊ�� " << sphereSquare << endl
		<< "Բ�����Ϊ�� " << sphereVolume << endl
		<< "Բ�����Ϊ�� " << cylinVolume << endl;
	return 0;
}
