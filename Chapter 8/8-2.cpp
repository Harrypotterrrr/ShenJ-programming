/*1651574 1∞‡ º÷Íª¡ÿ*/
#include <iostream>
using namespace std;

class Time
{
public://
	void set_time()//int set_time(void)
	{
		cin >> hour;//cin>>t.hour;
		cin >> minute;//cin>>t.minute;
		cin >> sec;//cin>>t.sec;
	}
	void show_time()//int show_time(void)
	{
		cout << hour << ":" << minute << ":" << sec << endl;//cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
	}
private://
	int hour;
	int minute;
	int sec;
};

int main()
{
	Time t1;
	t1.set_time();//set_time();
	t1.show_time();//show_time();
	return 0;
}



