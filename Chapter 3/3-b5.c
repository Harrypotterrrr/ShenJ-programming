/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define eps 1e-8
int main()
{
	double x, y;
	int h;
	printf("������һ���������(x,y):\n");
	scanf("%lf%lf",&x,&y);
	if (x > eps && y > eps && y + x - 3 <= 0)
		h = 1;
	else if (x < -eps && y >  eps && y - x - 3 <= 0)
		h = 2;
	else if (x < -eps && y < -eps && y + x + 3 >= 0)
		h = 3;	
	else if (x >  eps && y < -eps && y - x + 3 >= 0)
		h = 4;
	else
		h = 0;
	printf("�����꺣��Ϊ��\n%d\n",h);
	return 0;
}
