/*1∞‡ 1651574 º÷Íª¡ÿ*/
#include <stdio.h>
int main()
{
	int sum, flag;
	for (int i = 6; i <= 1000; i++) {
		sum = 0;
		flag = 1;
		for (int j = 1; j <= i / 2;j++)
			if (!(i%j))
				if (sum < i)
					sum += j;
				else {
					flag = 0;
					break;
				}
				if (sum == i && flag) {
					for (int j = i; j >= 2; j--)
						if (!(i%j)) {
							if (j == i)
								printf("%d,its factors are %d", i, i / j);
							else
								printf(",%d", i / j);
						}
					putchar('\n');
				}
	}
	return 0;
}