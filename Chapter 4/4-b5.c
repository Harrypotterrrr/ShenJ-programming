/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	void Print(int);
	int n;
	printf("������һ������:\n");
	scanf("%d", &n);
	if (n < 0)
		Print(-n);
	else
		Print(n);
	if (n < 0)
		putchar('-');
	putchar('\n');
	return 0;
}
void Print(int num)
{
	if (!num)
		return;
	printf("%d ", num % 10);
	Print(num / 10);
}