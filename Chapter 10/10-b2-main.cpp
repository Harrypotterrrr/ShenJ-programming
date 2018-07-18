/* 学号 姓名 班级 */
#include <iostream>
#include <cstdio>
#include "10-b2.h"
using namespace std;

#if defined(__linux) || defined(__linux__)
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}
#else
#include <conio.h>
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}
#endif

/* ----main函数不准动，也不需要提交，检查时会替换（细节可能有错，如果发现请及时提出）---- */
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2018,5,23);	//2018.5.23

		cout << "测试初始化，完全正确的赋值" << endl;

		cout << "d1应该是2000.1.1， 实际为：";
		d1.show();
		cout << "d2应该是2018.5.23，实际为：";
		d2.show();

		wait_for_enter();
		}

	if (1) {
		Date d1(1870,3,15);  //2000.3.15
		Date d2(2112,3,4);   //2000.3.4
		Date d3(2005,13,15); //2005.1.15
		Date d4(2018,5,32);  //2018.5.1

		cout << "测试初始化，年、月、日非法" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2018.5.1， 实际为：";
		d4.show();

		wait_for_enter();
		}

	if (1) {
		Date d1(2018,2,29);   //2018.2.1
	    Date d2(2016,2,29);   //2016.2.29

		cout << "测试初始化，闰年" << endl;

		cout << "d1应该是2018.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2016.2.29，实际为：";
		d2.show();

		wait_for_enter();
		}

	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		d1.set(2018,5,23);	//2018.5.23
		d2.set(2018,5);		//2018.5.1
		d3.set(2018);		//2018.1.1

		cout << "d1应该是2018.5.23，实际为：";
		d1.show();
		cout << "d2应该是2018.5.1， 实际为：";
		d2.show();
		cout << "d3应该是2018.1.1， 实际为：";
		d3.show();

		wait_for_enter();
		}

	if (1) {
		Date d1(2018,5,23);
		Date d2(2018,5,23);
		Date d3(2018,5,23);

		cout << "测试set，部分不变" << endl;

		d1.set(2007,0,0);   //2007.5.23
		d2.set(0, 3, 18);   //2018.3.18
		d3.set(0, 0, 28);   //2018.5.28

		cout << "d1应该是2007.5.23，实际为：";
		d1.show();
		cout << "d2应该是2018.3.18，实际为：";
		d2.show();
		cout << "d3应该是2018.5.28，实际为：";
		d3.show();

		wait_for_enter();
		}

	if (1) {
		Date d1(2016,4,28);
		Date d2(2007,5,20);
		Date d3(2016,4,28);
		Date d4(2018,5,23);

		cout << "测试set，年、月、日非法" << endl;

		d1.set(2112,1,0);     //2000.1.28
		d2.set(2017, 2, 29);  //2017.2.1
		d3.set(2016, 5, 32);  //2016.5.1
		d4.set(2018, 13, 12); //2018.1.12

		cout << "d1应该是2000.1.28，实际为：";
		d1.show();
		cout << "d2应该是2017.2.1， 实际为：";
		d2.show();
		cout << "d3应该是2016.5.1， 实际为：";
		d3.show();
		cout << "d4应该是2018.1.12，实际为：";
		d4.show();

		wait_for_enter();
		}

	if (1) {
		Date d1(2018,5,23);
		int y,m,d;

		cout << "测试get" << endl;
		d1.get(y, m, d);

		cout << "应该y=2018,m=5,d=23，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
		}

	if (1) {
		Date d1(2018,5,23);
		Date d2;

		cout << "测试cout" << endl;
		cout << "d1应该是2018.5.23，实际为："<< d1 << endl;
		cout << "d2应该是2000.1.1， 实际为："<< d2 << endl;

		wait_for_enter();
		}

	if (0) {
		Date d1;

		cout << "测试cin/cout" << endl;

		cout << "请输入2018 5 23" << endl;
		cin  >> d1;
		cout << "d1应该是2018.5.23，实际为："<< d1 << endl;

		cout << "请输入2016 2 29" << endl;
		cin  >> d1;
		cout << "d1应该是2016.2.29，实际为："<< d1 << endl;

		cout << "请输入2018 2 29" << endl;
		cin  >> d1;
		cout << "d1应该是2018.2.1，实际为："<< d1 << endl;

		cout << "请输入1899 4 10" << endl;
		cin  >> d1;
		cout << "d1应该是2000.4.10，实际为："<< d1 << endl;

		cout << "请输入2018 13 10" << endl;
		cin  >> d1;
		cout << "d1应该是2018.1.10，实际为："<< d1 << endl;

		cout << "请输入2018 4 31" << endl;
		cin  >> d1;
		cout << "d1应该是2018.4.1，实际为："<< d1 << endl;

		cout << "请输入2112 15 34" << endl;
		cin  >> d1;
		cout << "d1应该是2000.1.1，实际为："<< d1 << endl;

		wait_for_enter();
		}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31

		cout << "转换构造函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();

		d1 = 30000;
		cout << "d1应该是1982.2.19， 实际为：";
		d1.show();

		d2 = 43242;
		cout << "d2应该是2018.5.23， 实际为：";
		d2.show();

		wait_for_enter();
		}

	if (1) {
		Date d1(1900,1,1);
		Date d2(2099,12,31);
		Date d3(1982,2,19);
		Date d4(2018,5,23);

		cout << "类型转换函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1，     实际为：" << int(d1) << endl;
		cout << "d2应该是73049， 实际为：" << int(d2) << endl;
		cout << "d3应该是30000， 实际为：" << int(d3) << endl;
		cout << "d4应该是43242， 实际为：" << int(d4) << endl;

		wait_for_enter();
		}

	if (1) {
		Date d1(2018, 5, 23);
		Date d2;

		cout << "测试+/- n" << endl;

		d2 = d1+39;
		cout << "d2应该是2018.7.1，    实际为："<< d2 << endl;

		d2 = 39+d1;
		cout << "d2应该是2018.7.1，    实际为："<< d2 << endl;

		d2 = d1-7;
		cout << "d2应该是2018.5.16，   实际为："<< d2 << endl;

		d1.set(2016,2,28);
		d2 = d1+3;
		cout << "d2应该是2016.3.2，    实际为："<< d2 << endl;

		d1.set(2018,2,28);
		d2 = d1+3;
		cout << "d2应该是2018.3.3，    实际为："<< d2 << endl;

		d1.set(2010,12,28);
		d2 = d1+5;
		cout << "d2应该是2011.1.2，    实际为："<< d2 << endl;

		d1.set(2011,1,1);
		d2 = d1-5;
		cout << "d2应该是2010.12.27，  实际为："<< d2 << endl;

		d1.set(2009,12,31);
		d2 = d1+366;
		cout << "d2应该是2011.1.1，    实际为："<< d2 << endl;

		d1.set(2009,1,1);
		d2 = d1-367;
		cout << "d2应该是2007.12.31，  实际为："<< d2 << endl;

		d1.set(1900,1,2);
		d2 = d1-10;
		cout << "d2应该是1900.1.1，    实际为："<< d2 << endl;

		d1.set(2099,12,30);
		d2 = d1+5;
		cout << "d2应该是2099.12.31，  实际为："<< d2 << endl;

		d1.set(2018,5,23);
		d2.set(2018,4,21);
		cout << "d1-d2应该是32，实际为："<< d1-d2 << endl;

		d1.set(2016,4,28);
		d2.set(2015,4,28);
		cout << "d1-d2应该是366，实际为："<< d1-d2 << endl;

		d1.set(2018,5,18);
		d2.set(2017,5,18);
		cout << "d1-d2应该是365，实际为："<< d1-d2 << endl;

		d1.set(2018,5,23);

		cout << "d1+9应该是2018.6.1， 实际为：" << d1 + 9  << endl;
		cout << "9+d1应该是2018.6.1， 实际为：" << 9  + d1 << endl;
		cout << "d1-3应该是2018.5.20，实际为：" << d1 - 3  << endl;

		wait_for_enter();
		}

	if (1) {
		Date d1(2018,5,1);
		Date d2(2018,3,11);

		cout << "测试-date" << endl;
		cout << "日期差值应为51， 实际为：" << d1-d2 << endl;

		d2.set(2018, 5, 23);
		cout << "日期差值应为-22，实际为：" << d1-d2 << endl;

		d1.set(2016, 3, 2);
		d2.set(2016, 2, 27);
		cout << "日期差值应为4，  实际为：" << d1-d2 << endl;

		d1.set(2018, 3, 2);
		d2.set(2018, 2, 27);
		cout << "日期差值应为3，  实际为：" << d1-d2 << endl;

		d1.set(2018, 1, 2);
		d2.set(2017, 12, 27);
		cout << "日期差值应为6，  实际为：" << d1-d2 << endl;

		d1.set(2015, 1, 1);
		d2.set(2013, 12, 31);
		cout << "日期差值应为366，实际为：" << d1-d2 << endl;

		d1.set(2017, 1, 1);
		d2.set(2015, 12, 31);
		cout << "日期差值应为367，实际为：" << d1-d2 << endl;

		wait_for_enter();
		}

	if (1) {
		Date d1, d2;

		cout << "测试++/--" << endl;

		d1.set(2018,5,23);
		d2 = d1++;
		cout << "d1应该是2018.5.24，  实际为：" << d1 << endl;
		cout << "d2应该是2018.5.23，  实际为：" << d2 << endl;

		d1.set(2018,5,23);
		d2 = ++d1;
		cout << "d1应该是2018.5.24，  实际为：" << d1 << endl;
		cout << "d2应该是2018.5.24，  实际为：" << d2 << endl;

		d1.set(2018,5,1);
		d2 = d1--;
		cout << "d1应该是2018.4.30， 实际为：" << d1 << endl;
		cout << "d2应该是2018.5.1，  实际为：" << d2 << endl;

		d1.set(2018,5,1);
		d2 = --d1;
		cout << "d1应该是2018.4.30， 实际为：" << d1 << endl;
		cout << "d2应该是2018.4.30， 实际为：" << d2 << endl;

		d1.set(2017,12,31);
		d2 = d1++;
		cout << "d1应该是2018.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是2017.12.31，实际为：" << d2 << endl;

		d1.set(2018,1,1);
		d2 = d1--;
		cout << "d1应该是2017.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2018.1.1，  实际为：" << d2 << endl;

		d1.set(2016,2,28);
		d2 = d1++;
		cout << "d1应该是2016.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2016.2.28， 实际为：" << d2 << endl;

		d1.set(2018,2,28);
		d2 = d1++;
		cout << "d1应该是2018.3.1，  实际为：" << d1 << endl;
		cout << "d2应该是2018.2.28， 实际为：" << d2 << endl;

		d1.set(2016,3,1);
		d2 = d1--;
		cout << "d1应该是2016.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2016.3.1，  实际为：" << d2 << endl;

		d1.set(2018,3,1);
		d2 = d1--;
		cout << "d1应该是2018.2.28， 实际为：" << d1 << endl;
		cout << "d2应该是2018.3.1，  实际为：" << d2 << endl;

		d1.set(2099,12,31);
		d2 = d1++;
		cout << "d1应该是2099.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2099.12.31，实际为：" << d2 << endl;

		d1.set(1900,1,1);
		d2 = d1--;
		cout << "d1应该是1900.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是1900.1.1，  实际为：" << d2 << endl;

		wait_for_enter();
		}


	if (1) {
		/* 测试比较运算符 */
		Date d1(2018,5,23);
		Date d2(2018,5,23);
		Date d3(2018,4,27);

		cout << "测试比较运算符" << endl;

		cout << "比较结果应为0，实际为：" << (d1 >  d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <  d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 <= d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 == d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 != d2) << endl;

		cout << "比较结果应为1，实际为：" << (d1 >  d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <  d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 == d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 != d3) << endl;

		wait_for_enter();
		}

	return 0;
}
