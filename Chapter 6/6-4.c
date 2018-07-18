/* 1班 贾昊霖 1651574 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void MoveArray(int *num, int n, int m)
{
	int tmp, *p, i;
	for (i = 1; i <= m; i++) {
		tmp = *(num + n - 1);
		for (p=num+n-1; p >=num; p--)
			*p = *(p-1);
		*num = tmp;
	}
}
int main()
{
	int num[25];
	int n, m, *p;
	while (1) {
		printf("请输入整数的数量n(10-20):\n");
		while (!scanf("%d", &n)) {
			rewind(stdin);
			continue;
		}
		if (n >= 10 && n <= 20)
			break;
	}
	printf("请输入%d个整数：\n", n);
	for (p = num; p < num + n; p++)
		scanf("%d", p);
	printf("输入的整数序列为：\n");
	for (p = num; p < num + n; p++)
		printf("%d ", *p);
	putchar('\n');
	printf("请输入向后移动的位置m(≥1)\n");
	scanf("%d", &m);
	m %= 17;
	MoveArray(num, n, m);
	printf("移动后的序列为\n");
	for (p = num; p < num + n; p++)
		printf("%d ", *p);
	putchar('\n');
	return 0;
}