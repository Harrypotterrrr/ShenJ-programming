/* 1651574 贾昊霖 1班 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <time.h>
/* 如果有需要，此处可以添加头文件 */

/* 允许定义常变量/宏定义，但不允许定义全局变量 */
const char playerName[4][10] = { "甲","乙","丙" };
const char cardPattern[4] = { 5,4,3,6 };
const char cardPattern2[2][5] = { "BJ", "RJ" };
const char cardNumber[15] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
/* 可以添加自己需要的函数 */
void PrintCard(const unsigned long long *player)
{
	long long tmp_player;
	int n, k;
	for (int i = 0; i < 3; i++) {
		tmp_player = player[i];
		std::cout << playerName[i] << "的牌：";
		for (int j = 0; j < 64; j++, tmp_player >>= 1) {
			if(!(tmp_player & 1))
				continue;
			n = j / 4;
			k = j % 4;
			if (n < 13)
				std::cout << char(cardPattern[k]) << char(cardNumber[n]) << " ";
			else
				std::cout << cardPattern2[k] << " ";
		}
		std::cout << std::endl;
	}
}


/* 打印某个玩家的牌面信息，如果是地主，后面加标记 */
int print(const char *prompt, const int landlord, const unsigned long long player)
{
	/* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	std::cout << prompt;
	long long tmp_player = player;
	int n, k;
	for (int j = 0; j < 64; j++, tmp_player >>= 1) {
		if (!(tmp_player & 1))
			continue;
		n = j / 4;
		k = j % 4;
		if (n < 13)
			std::cout << char(cardPattern[k]) << char(cardNumber[n]) << " ";
		else
			std::cout << cardPattern2[k] << " ";
	}
	std::cout << ((landlord) ? "(地主)" : " ") << std::endl;
	return 0;
}

int deal(unsigned long long *player)
{
	/* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	srand(unsigned(time(NULL)));
	long long card = -1;
	int k, landlord;
	for (int i = 1; i <= 17; i++) {
		for (int j = 0; j < 3; j++) {
			do {
				k = rand() % 54;
			} while (!(card & (long long (1) << k)));
			card &= ~(long long(1) << k);
			player[j] |= (long long (1) << k);
		}
		std::cout << "第" << i << "轮结束：\n";
		PrintCard(player);
	}
	do {
		std::cout << "请选择一个地主[0-2]:\n";
		std::cin >> landlord;
	} while (landlord < 0 || landlord>2);
	for (int t = 0; t < 54; t++) {
		if (card & (long long(1) << t)) {
			card &= ~(long long(1) << t);
			player[landlord] |= (long long(1) << t);
		}
	}
	return landlord; //此处修改为选定的地主(0-2)
}
/* main函数，不准修改 */
int main()
{
	unsigned long long player[3] = { 0 }; //存放三个玩家的发牌信息
	int landlord; //返回0-2表示哪个玩家是地主

	std::cout << "按回车键开始发牌";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("甲的牌：", landlord == 0, player[0]);
	print("乙的牌：", landlord == 1, player[1]);
	print("丙的牌：", landlord == 2, player[2]);

	return 0;
}
