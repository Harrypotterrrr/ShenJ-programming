/* 1班 贾昊霖 1651574 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
void merge(int *list_a, int *list_b, int *list_c)
{
	int *p = list_a, *q = list_b, *r = list_c;
	while (*p != -1 && *q != -1) {
		if (*p > *q)
			*r++ = *p++;
		else
			*r++ = *q++;
		while (*p == *(r - 1))
			p++;
		while (*q == *(r - 1))
			q++;
	}
	while (*p != -1) {
		*r++ = *p++;
		while (*p == *(r - 1))
			p++;
	}
	while (*q != -1) {
		*r++ = *q++;
		while (*q == *(r - 1))
			q++;
	}
	*r = -1;
}
int main()
{
	int num1[25], *p = num1;
	int num2[25], *q = num2;
	int num3[55], *r = num3, tmp;
	printf("请输入第一个数组:\n");
	while (scanf("%d",&tmp)) {
		*p++ = tmp;
		if (tmp == -1)
			break;
	}
	printf("请输入第二个数组:\n");
	while (scanf("%d", &tmp)) {
		*q++ = tmp;
		if (tmp == -1)
			break;
	}
	printf("输入的第一个整数序列为：\n");
	for (p = num1; *p != -1; )
		printf("%d ", *p++);
	putchar('\n');
	printf("输入的第二个整数序列为：\n");
	for (q = num2; *q != -1; )
		printf("%d ", *q++);
	putchar('\n');

	merge(num1, num2, num3);

	printf("合并后的数组为：\n");
	for (r = num3; *r != -1;)
		printf("%d ", *r++);
	putchar('\n');
	return 0;
}