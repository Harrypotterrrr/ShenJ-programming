/*1�� ����� 1651574*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_NUM 1000
#define MAX_LENGTH 15
#define N 10
int main()
{
	char name[MAX_NUM][MAX_LENGTH];
	char num[MAX_NUM][MAX_LENGTH];
	int grade[MAX_LENGTH];
	int i;
	for (i = 0; i < N; i++) {
		while (1) {
			printf("�������%d���˵�������ѧ�š��ɼ�\n", i + 1);
			if (!scanf("%s", name+i) || !scanf("%s", num+i)){
				rewind(stdin);		//ָ��ָ���ļ���ʼ
			  //fflush(stdin);	//��ջ�����
				continue;
			}
			if (!scanf("%d", &grade[i])){
				rewind(stdin);
				continue;
			}
			break;
		}
	}
	printf("����������\n");
	for (i = 0; i < N; i++) {
		if (grade[i] < 60) {
			printf("%s %s %d\n", name[i], num[i], grade[i]);
		}
	}
	return 0;
}
