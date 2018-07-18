/*1651574 1班 贾昊霖*/
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
	cout <<setiosflags(ios::fixed)<< setprecision(2);   //格式控制
	cout << "圆周长为： " << roundCircum << endl           //输出
		<< "圆面积为： " << roundSquare << endl
		<< "圆球表面积为： " << sphereSquare << endl
		<< "圆球体积为： " << sphereVolume << endl
		<< "圆柱体积为： " << cylinVolume << endl;
	return 0;
}
