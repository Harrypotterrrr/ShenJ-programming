/*1班 贾昊霖 1651574*/
/*已验证 1652571 袁小丁 1651025 汪涵 1550276 马跃泷 1653733 卢依雯 1553449 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LENGTH 1000
enum LetterType { Uppercase, Lowercase, Number, Other };

void Count(char code[], int num[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (code[i] == '\0')
			break;	//不让用strlen我也很无奈啊...
		if (code[i] <= 'Z' && code[i] >= 'A')
			num[Uppercase]++;
		else if (code[i] <= 'z' && code[i] >= 'a')
			num[Lowercase]++;
		else if (code[i] <= '9' && code[i] >= '0')
			num[Number]++;
		else
			num[Other]++;
	}
}
int CheckCode(char code[], int n, int LimitNum[])
{
	int num[5] = { 0 }, sum = 0, i;
	Count(code, num, n);
	for (i = Uppercase; i <= Other; i++)
		if (LimitNum[i] > num[i])
			return 0;
	return 1;
}
int main()
{
	char code[MAX_LENGTH];
	int n, LimitNum[5];
	scanf("%d",&n);
	if (n < 12 && n > 16) {
		printf("错误\n");
		return 0;
	}
	int i;
	for (i = Uppercase; i <= Other; i++) {
		scanf("%d", &LimitNum[i]);
		if (LimitNum[i] < 2) {
			printf("错误\n");
			return 0;
		}
	}
	for (i = 1; i <= 10; i++) {
		scanf("%s", code);
		if (!CheckCode(code, n, LimitNum)) {
			printf("错误\n");
			return 0;
		}
	}
	printf("正确\n");
	return 0;
}
