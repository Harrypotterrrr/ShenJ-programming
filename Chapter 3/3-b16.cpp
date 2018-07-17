/*1�� 1651574 �����*/
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
		cout<<"���������(2000-2030)���·�(1-12) :";
		cin>>year>>month;
		if(year<2000 || year>2030){
			cout<<"����������\n";
			continue;
		}
		if(month >=1 && month <=12)
			break;
		else
			cout<<"����������\n";
	}
	leap =(!(year % 4) && !(year % 100) || (year % 400));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		day = 31;
	else if(month!=2)
		day = 30;
	else
		day = 28 + leap;
	cout<<"������"<<year<<"��"<<month<<"��1�յ�����(0-6��ʾ������-������) :"<<endl;
	cin>>week;
	while(week<0 || week > 6){
		cout<<"������������\n";
		cin>>week;
	}
	cout<<year<<"��"<<month<<"�µ�����Ϊ��\n";
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������\n";
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
