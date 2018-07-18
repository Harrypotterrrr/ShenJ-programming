/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int Factorial(int);
	int sum = 0, a, b, c;
	while (1) {
		printf("来三个数字吧哥:\n");
		if (scanf("%d", &a) && scanf("%d", &b) && scanf("%d", &c))
			break;
		rewind(stdin);
	}
	sum += Factorial(a) + Factorial(b) + Factorial(c);
	printf("%d!+%d!+%d!=%d\n", a, b, c, sum);
	return 0;
}
int Factorial(int x)
{
	int ans = 1;
	int i;
	for (i = 1; i <= x; i++)
		ans *= i;
	return ans;
}
