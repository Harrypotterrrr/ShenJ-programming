/*1班 1651574 贾昊霖*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define eps 1e-6
using namespace std;
int main()
{
	int year,month,week,day;
	bool leap;
	while(true){
		cout<<"请输入年份(2000-2030)和月份(1-12) :";
		cin>>year>>month;
		if(year<2000 || year>2030){
			cout<<"年输入有误\n";
			continue;
		}
		if(month >=1 && month <=12)
			break;
		else
			cout<<"月输入有误\n";
	}
	leap =(!(year % 4) && !(year % 100) || (year % 400));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		day = 31;
	else if(month!=2)
		day = 30;
	else
		day = 28 + leap;
	cout<<"请输入"<<year<<"年"<<month<<"月1日的星期(0-6表示星期日-星期六) :"<<endl;
	cin>>week;
	while(week<0 || week > 6){
		cout<<"星期输入有误\n";
		cin>>week;
	}
	cout<<year<<"年"<<month<<"月的月历为：\n";
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六\n";
	week %= 7;
	int chg=0;
	for(int i=0 ; i<week ; i++,chg++){
		if(!i)
			cout<<setw(6)<<" ";
		else
			cout<<setw(8)<<" ";
	}
	for(int i=1 ; i<=day ; i++,chg++,chg%=7){
		if(!chg && i != 1)
			putchar('\n');
		if(!chg)
			cout<<setw(4)<<i<<"  ";
		else
			cout<<setw(6)<<i<<"  ";
	}
	putchar('\n');
	return 0;
}
