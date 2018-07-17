/* 1651574 1班 贾昊霖 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请给出一个不多于五位的正整数：\n");
	int num, num_1, num_2, num_3, num_4, num_5;
	scanf("%d",&num);
	num_1 = num / 1 % 10;
	num_2 = num / 10 % 10;
	num_3 = num / 100 % 10;
	num_4 = num / 1000 % 10;
	num_5 = num / 10000 % 10;
	if (num_5)
		printf("5位数\n此数正序为：\n%d %d %d %d %d\n此数逆序为：%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else if (num_4)
		printf("4位数\n此数正序为：\n%d %d %d %d %d\n此数逆序为：%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else if (num_3)
		printf("3位数\n此数正序为：\n%d %d %d %d %d\n此数逆序为：%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else if (num_2)
		printf("2位数\n此数正序为：\n%d %d %d %d %d\n此数逆序为：%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else
		printf("1位数\n此数正序为：\n%d %d %d %d %d\n此数逆序为：%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	//显得很蠢..但是为了赶时间啊啊啊啊！！[哭][哭][哭]
	return 0;
}
