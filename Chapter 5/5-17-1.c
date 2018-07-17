/*1班 贾昊霖 1651574*/
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
			printf("请输入第%d个人的姓名、学号、成绩\n", i + 1);
			if (!scanf("%s", name+i) || !scanf("%s", num+i)){
				rewind(stdin);		//指针指回文件开始
			  //fflush(stdin);	//清空缓冲区
				continue;
			}
			if (!scanf("%d", &grade[i])){
				rewind(stdin);
				continue;
			}
			break;
		}
	}
	printf("不及格名单\n");
	for (i = 0; i < N; i++) {
		if (grade[i] < 60) {
			printf("%s %s %d\n", name[i], num[i], grade[i]);
		}
	}
	return 0;
}
