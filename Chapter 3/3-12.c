/* 1651574 1�� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("�����һ����������λ����������\n");
	int num, num_1, num_2, num_3, num_4, num_5;
	scanf("%d",&num);
	num_1 = num / 1 % 10;
	num_2 = num / 10 % 10;
	num_3 = num / 100 % 10;
	num_4 = num / 1000 % 10;
	num_5 = num / 10000 % 10;
	if (num_5)
		printf("5λ��\n��������Ϊ��\n%d %d %d %d %d\n��������Ϊ��%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else if (num_4)
		printf("4λ��\n��������Ϊ��\n%d %d %d %d %d\n��������Ϊ��%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else if (num_3)
		printf("3λ��\n��������Ϊ��\n%d %d %d %d %d\n��������Ϊ��%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else if (num_2)
		printf("2λ��\n��������Ϊ��\n%d %d %d %d %d\n��������Ϊ��%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	else
		printf("1λ��\n��������Ϊ��\n%d %d %d %d %d\n��������Ϊ��%d %d %d %d %d\n",num_5,num_4,num_3,num_2,num_1,num_1,num_2,num_3,num_4,num_5);
	//�Եúܴ�..����Ϊ�˸�ʱ�䰡����������[��][��][��]
	return 0;
}
