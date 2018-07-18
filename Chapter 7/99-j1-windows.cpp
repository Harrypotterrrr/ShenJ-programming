/*1651574 贾昊霖 1班*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
using namespace std;

#if 0
struct _TIME_ZONE_INFORMATION {
	LONG Bias;					 //以分钟为单位
	WCHAR StandardName[32];		 // 标准时间的名称
	SYSTEMTIME StandardDate;
	LONG StandardBias;
	WCHAR DaylightName[32];		 // 夏令时的名称
	SYSTEMTIME DaylightDate;
	LONG DaylightBias;
}
#endif

int main(void)
{
	/*UTC: Universal Time Coordinated*/
	TIME_ZONE_INFORMATION timeInfo;
	GetTimeZoneInformation(&timeInfo);
	int bias = timeInfo.Bias / - 60;
	cout << "UTC" << (bias > 0 ? '+' : '-') << bias << endl;
	return 1;
}
