/*1651574 1�� �����*/
#include <stdio.h>
#include <math.h>
#define pai 2*asin(1)

int main()
{
	double r = 1.5, h = 3;
	double roundCircum, roundSquare, sphereSquare, \
		sphereVolume,cylinVolume;
	roundCircum = 2 * pai*r;
	roundSquare = pai * r * r;
	sphereSquare = 4 * pai*r*r;
	sphereVolume = 4. / 3.*pai*r*r*r;
	cylinVolume = roundCircum*h;
	printf("Բ�ܳ�Ϊ��%.2f\n", roundCircum);
	printf("Բ���Ϊ��%.2f\n", roundSquare);
	printf("Բ������Ϊ��%.2f\n", sphereSquare);
	printf("Բ�����Ϊ��%.2f\n", sphereVolume);
	printf("Բ�������Ϊ��%.2f\n", cylinVolume);
	return 0;
}
