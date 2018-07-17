/*1651574 1°à ¼Öê»ÁØ*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	cout << "ÊäÈëÒ»¸ö0~100ÒÚµÄ¸¡µãÊı£º" << endl;
	cin >> a;
	a1 = int(a / 10) % 10;
	a2 = int(a / 100) % 10;
	a3 = int(a / 1000) % 10;
	a4 = int(a / 10000) % 10;
	a5 = int(a / 100000) % 10;
	a6 = int(a / 1000000) % 10;
	a7 = int(a / 10000000) % 10;
	a8 = int(a / 100000000) % 10;
	a9 = int(a / 1000000000) % 10;
	temp = a - 1000000000. * a9 - 100000000. * \
		a8 - 10000000. * a7 - 1000000. * a6 - \
		100000. * a5 - 10000. * a4 - 1000. * a3 \
		- 100. * a2 - 10. * a1;
	a0 = int(temp);		//ÕûÊı²¿·Ö ¼´¸öÎ»
	temp2 = temp - a0;	//Ğ¡Êı²¿·Ö
	temp2 += 0.005;
	a_1 = int(floor(temp2 * 10));
	a_2 = int(floor(temp2 * 100)) % 10;//ÉÏ´Î×÷ÒµÕâÀïÄÔ²ĞÁË..Ğ´µÃÓĞµãÎÊÌâ.....
	cout << "´óĞ´½á¹ûÊÇ£º\n";
	if (!(a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0 + a_1 + a_2)) {
		cout << "ÁãÔ²Õû\n";
		return 0;
	}
	//==============Ê®ÒÚ==============//
	if (a9 == 1)
		cout << "Ò¼Ê°";
	else if (a9 == 2)
		cout << "·¡Ê°";
	else if (a9 == 3)
		cout << "ÈşÊ°";
	else if (a9 == 4)
		cout << "ËÁÊ°";
	else if (a9 == 5)
		cout << "ÎéÊ°";
	else if (a9 == 6)
		cout << "Â½Ê°";
	else if (a9 == 7)
		cout << "ÆâÊ°";
	else if (a9 == 8)
		cout << "°ÆÊ°";
	else if (a9 == 9)
		cout << "¾ÁÊ°";
	//==============ÒÚ==============//
	if (a8 == 0 && a9 != 0)
		cout << "ÒÚ";
	else if (a8 == 1)
		cout << "Ò¼ÒÚ";
	else if (a8 == 2)
		cout << "·¡ÒÚ";
	else if (a8 == 3)
		cout << "ÈşÒÚ";
	else if (a8 == 4)
		cout << "ËÁÒÚ";
	else if (a8 == 5)
		cout << "ÎéÒÚ";
	else if (a8 == 6)
		cout << "Â½ÒÚ";
	else if (a8 == 7)
		cout << "ÆâÒÚ";
	else if (a8 == 8)
		cout << "°ÆÒÚ";
	else if (a8 == 9)
		cout << "¾ÁÒÚ";
	//==============Ç§Íò==============//
	if (a7 == 0 && (a9 + a8) && (a6 + a5 + a4))
		cout << "Áã";
	else if (a7 == 1)
		cout << "Ò¼Çª";
	else if (a7 == 2)
		cout << "·¡Çª";
	else if (a7 == 3)
		cout << "ÈşÇª";
	else if (a7 == 4)
		cout << "ËÁÇª";
	else if (a7 == 5)
		cout << "ÎéÇª";
	else if (a7 == 6)
		cout << "Â½Çª";
	else if (a7 == 7)
		cout << "ÆâÇª";
	else if (a7 == 8)
		cout << "°ÆÇª";
	else if (a7 == 9)
		cout << "¾ÁÇª";
	//==============°ÙÍò==============//
	if (a6 == 0 && a7 && (a4 + a5))
		cout << "Áã";
	else if (a6 == 1)
		cout << "Ò¼°Û";
	else if (a6 == 2)
		cout << "·¡°Û";
	else if (a6 == 3)
		cout << "Èş°Û";
	else if (a6 == 4)
		cout << "ËÁ°Û";
	else if (a6 == 5)
		cout << "Îé°Û";
	else if (a6 == 6)
		cout << "Â½°Û";
	else if (a6 == 7)
		cout << "Æâ°Û";
	else if (a6 == 8)
		cout << "°Æ°Û";
	else if (a6 == 9)
		cout << "¾Á°Û";
	//==============Ê®Íò==============//
	if (a5 == 0 && a6 && a4)
		cout << "Áã";
	else if (a5 == 1)
		cout << "Ò¼Ê°";
	else if (a5 == 2)
		cout << "·¡Ê°";
	else if (a5 == 3)
		cout << "ÈşÊ°";
	else if (a5 == 4)
		cout << "ËÁÊ°";
	else if (a5 == 5)
		cout << "ÎéÊ°";
	else if (a5 == 6)
		cout << "Â½Ê°";
	else if (a5 == 7)
		cout << "ÆâÊ°";
	else if (a5 == 8)
		cout << "°ÆÊ°";
	else if (a5 == 9)
		cout << "¾ÁÊ°";
	//==============Íò==============//
	if (a4 == 0 && (a7 + a6 + a5))
		cout << "Íò";
	else if (a4 == 1)
		cout << "Ò¼Íò";
	else if (a4 == 2)
		cout << "·¡Íò";
	else if (a4 == 3)
		cout << "ÈşÍò";
	else if (a4 == 4)
		cout << "ËÁÍò";
	else if (a4 == 5)
		cout << "ÎéÍò";
	else if (a4 == 6)
		cout << "Â½Íò";
	else if (a4 == 7)
		cout << "ÆâÍò";
	else if (a4 == 8)
		cout << "°ÆÍò";
	else if (a4 == 9)
		cout << "¾ÁÍò";
	//==============Ç§==============//
	if (a3 == 0 && (a9 + a8 + a7 + a6 + a5 + a4) && (a2 + a1 + a0))
		cout << "Áã";
	else if (a3 == 1)
		cout << "Ò¼Çª";
	else if (a3 == 2)
		cout << "·¡Çª";
	else if (a3 == 3)
		cout << "ÈşÇª";
	else if (a3 == 4)
		cout << "ËÁÇª";
	else if (a3 == 5)
		cout << "ÎéÇª";
	else if (a3 == 6)
		cout << "Â½Çª";
	else if (a3 == 7)
		cout << "ÆâÇª";
	else if (a3 == 8)
		cout << "°ÆÇª";
	else if (a3 == 9)
		cout << "¾ÁÇª";
	//==============°Ù==============//
	if (a2 == 0 && a3 && (a1 + a0))
		cout << "Áã";
	else if (a2 == 1)
		cout << "Ò¼°Û";
	else if (a2 == 2)
		cout << "·¡°Û";
	else if (a2 == 3)
		cout << "Èş°Û";
	else if (a2 == 4)
		cout << "ËÁ°Û";
	else if (a2 == 5)
		cout << "Îé°Û";
	else if (a2 == 6)
		cout << "Â½°Û";
	else if (a2 == 7)
		cout << "Æâ°Û";
	else if (a2 == 8)
		cout << "°Æ°Û";
	else if (a2 == 9)
		cout << "¾Á°Û";
	//==============Ê®==============//
	if (a1 == 0 && a2 && a0)
		cout << "Áã";
	else if (a1 == 1)
		cout << "Ò¼Ê°";
	else if (a1 == 2)
		cout << "·¡Ê°";
	else if (a1 == 3)
		cout << "ÈşÊ°";
	else if (a1 == 4)
		cout << "ËÁÊ°";
	else if (a1 == 5)
		cout << "ÎéÊ°";
	else if (a1 == 6)
		cout << "Â½Ê°";
	else if (a1 == 7)
		cout << "ÆâÊ°";
	else if (a1 == 8)
		cout << "°ÆÊ°";
	else if (a1 == 9)
		cout << "¾ÁÊ°";
	//==============¸ö==============//
	if (a0 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1))
		cout << "Ô²";
	else if (a0 == 1)
		cout << "Ò¼Ô²";
	else if (a0 == 2)
		cout << "·¡Ô²";
	else if (a0 == 3)
		cout << "ÈşÔ²";
	else if (a0 == 4)
		cout << "ËÁÔ²";
	else if (a0 == 5)
		cout << "ÎéÔ²";
	else if (a0 == 6)
		cout << "Â½Ô²";
	else if (a0 == 7)
		cout << "ÆâÔ²";
	else if (a0 == 8)
		cout << "°ÆÔ²";
	else if (a0 == 9)
		cout << "¾ÁÔ²";
	if (!a_1 && !a_2) {
		cout << "Õû\n";
		return 0;
	}
	//=============½Ç==============//
	if (a_1 == 0 && (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0))
		cout << "Áã";
	else if (a_1 == 1)
		cout << "Ò¼½Ç";
	else if (a_1 == 2)
		cout << "·¡½Ç";
	else if (a_1 == 3)
		cout << "Èş½Ç";
	else if (a_1 == 4)
		cout << "ËÁ½Ç";
	else if (a_1 == 5)
		cout << "Îé½Ç";
	else if (a_1 == 6)
		cout << "Â½½Ç";
	else if (a_1 == 7)
		cout << "Æâ½Ç";
	else if (a_1 == 8)
		cout << "°Æ½Ç";
	else if (a_1 == 9)
		cout << "¾Á½Ç";
	//===========·Ö==============//	
	if (a_2 == 0)
		cout << "Õû\n";
	if (a_2 == 1)
		cout << "Ò¼·Ö\n";
	else if (a_2 == 2)
		cout << "·¡·Ö\n";
	else if (a_2 == 3)
		cout << "Èş·Ö\n";
	else if (a_2 == 4)
		cout << "ËÁ·Ö\n";
	else if (a_2 == 5)
		cout << "Îé·Ö\n";
	else if (a_2 == 6)
		cout << "Â½·Ö\n";
	else if (a_2 == 7)
		cout << "Æâ·Ö\n";
	else if (a_2 == 8)
		cout << "°Æ·Ö\n";
	else if (a_2 == 9)
		cout << "¾Á·Ö\n";
	return 0;
}
