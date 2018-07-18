/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long Convert(char *str)
{
	int len = strlen(str);
	long long ans = 0;
	char *tag = str + len;
	for ( ; str<tag; str++) {
		ans *= 2;
		ans += *str - '0';
	}
	return ans;
}
int main()
{

	char str[1000];
	cout << "请输入一个0/1组成的字符串，长度不超过32\n";
	cin>>str;
	cout<<Convert(str)<<endl;
	return 0;
}