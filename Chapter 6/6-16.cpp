/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 10
using namespace std;
int main()
{
	char str[80], *p=NULL;
	int  a[N] = { 0 }, *pnum=NULL, *pa=NULL;
	bool is_num=true, is_minus=true;
	//....
	int num[1000], q = 0;
	cout << "请输入字符串:\n";
	gets_s(str);

	int len = strlen(str),tmp=0;
	for (int i = 0; i < len; i++) {
		if (*(str+i) <= '9'&&*(str+i) >= '0') {
			if (tmp == -1)
				tmp = 0;
			tmp *= 10;
			tmp += *(str+i) - '0';
		}
		else if (tmp >= 0) {
			*(num+q++) = tmp;
			tmp = -1;
		}
	}
	if (tmp >= 0)
		*(num+q++) = tmp;
	cout << "总共有" << q << "个整数" << endl;
	for (int i = 0; i < q; i++) {
		cout << *(num+i) << " ";
	}
	putchar('\n');
	return 0;
}