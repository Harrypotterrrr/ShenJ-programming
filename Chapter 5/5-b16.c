/*1�� ����� 1651574*/
/*����֤ 1652571 ԬС�� 1651025 ���� 1550276 ��Ծ�� 1653733 ¬���� 1553449 ��־ҵ*/
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
			break;	//������strlen��Ҳ�����ΰ�...
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
		printf("����\n");
		return 0;
	}
	int i;
	for (i = Uppercase; i <= Other; i++) {
		scanf("%d", &LimitNum[i]);
		if (LimitNum[i] < 2) {
			printf("����\n");
			return 0;
		}
	}
	for (i = 1; i <= 10; i++) {
		scanf("%s", code);
		if (!CheckCode(code, n, LimitNum)) {
			printf("����\n");
			return 0;
		}
	}
	printf("��ȷ\n");
	return 0;
}
