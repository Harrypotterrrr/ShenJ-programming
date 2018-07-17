/*1651574 ����� 1��*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
using namespace std;

#if 0
struct _TIME_ZONE_INFORMATION {
	LONG Bias;					 //�Է���Ϊ��λ
	WCHAR StandardName[32];		 // ��׼ʱ�������
	SYSTEMTIME StandardDate;
	LONG StandardBias;
	WCHAR DaylightName[32];		 // ����ʱ������
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
