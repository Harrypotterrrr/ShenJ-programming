/* 1651574 ����� 1��*/
#include <stdio.h>
#include <time.h>
int main()
{
	struct tm *local, *utc;
	time_t nwTime = time(NULL);
	struct tm *tmpTime = gmtime(&nwTime);

	int zone = nwTime - mktime(tmpTime) / 3600;
	printf("UTF %d\n", zone);
	//input_time += timezone; 
	return 0;
}