/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
#include <conio.h>
#include "11-b1-datetime.h"
using namespace std;

void wait_to_enter()
{
	cout << "«Î ‰»Îªÿ≥µºÃ–¯\n";
	char c;
	while ((c = _getch()) != '\r' )
		;
}

int main()
{
	if (false) {
		DateTime date_time_0(1999, 1, 1, 9, 19, 29);
		cout << "≥ı º◊¥Ã¨£∫" << endl;
		cout << date_time_0;
		cout << " ‰»Îyyyy-mm-dd hh:mm:ss :";
		cin >> date_time_0;
		cout << date_time_0;
		wait_to_enter();
		cout<<"========================\n";
	}

	if (true) {
		DateTime date_time_0,date_time_1(1400,3,2,1,6,0), date_time_2(2018,2,39,2,3,4);
		cout << date_time_0;
		cout << date_time_1;
		cout << date_time_2;
		wait_to_enter();
		cout<<"========================\n";
	}

	if (true) {
		DateTime date_time_1(2018,3,4,25,59,50), date_time_2(2032,3,32,23,333,222),date_time_3(2018,6,30,2,3,9);
		cout << date_time_1 + 1;
		cout << date_time_2 + 9999;
		cout << date_time_3 + INT_MAX;
		wait_to_enter();
		cout<<"========================\n";
	}

	if (true) {
		DateTime date_time_1(2018,1,1,0,6,8), date_time_2(2018,1,1,1,6,7), date_time_3(2018,1,1,1,6,9);
		cout << date_time_1 - 1;
		cout << date_time_2 - INT_MAX;
		cout << date_time_3 - 423513;
		cout << date_time_2 - date_time_1 << endl;
		cout << date_time_3 - date_time_2 << endl;
		wait_to_enter();
		cout<<"========================\n";
	}

	if (true) {
		DateTime date_time_0,date_time_1(2018,12,31,23,59,59), date_time_2(2018,6,8,23,23,23), date_time_3(2018,1,1,0,0,0);
		date_time_0 = ++date_time_1;
		cout << date_time_0;
		date_time_0 = date_time_2++;
		cout << date_time_0;
		date_time_0 = --date_time_3;
		cout << date_time_0;
		wait_to_enter();
		cout<<"========================\n";
	}

	if (true) {
		DateTime date_time_1(2018, 6, 8, 23, 23, 23), date_time_2(2019, 6, 8, 23, 23, 23), date_time_3(2017, 6, 8, 23, 23, 23);
		cout << (date_time_1 > date_time_2) << (date_time_1 >= date_time_2) << (date_time_1 < date_time_2) << (date_time_1 <= date_time_2) << (date_time_1 == date_time_2) << (date_time_1 != date_time_2) << endl;
		cout << (date_time_1 > date_time_3) << (date_time_1 >= date_time_3) << (date_time_1 < date_time_3) << (date_time_1 <= date_time_3) << (date_time_1 == date_time_3) << (date_time_1 != date_time_3) << endl;
		wait_to_enter();
	}
	return 0;
}
