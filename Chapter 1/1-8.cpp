/*1651574 计1 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << "a+b=" << c << endl;
	return 0;
}
/*
错误1：没有预处理指令，即没有添加头文件与命名空间
错误2：没有定义变量c
错误3：cout后面错用>>
错误4：没有return 0
*/