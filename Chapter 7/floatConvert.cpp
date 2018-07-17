#include <stdio.h>  

#define print_float(a) print_bitxx(a, 4)  
#define print_int(a) print_bitxx(a, 4)  

#define print_double(a) print_bitxx(a, 8)  

int is_little_endian()
{
	short int x = 0x0001;
	return ((char*)&x)[0];
}

void print_bitxx(const void *a, int bytes)
{
	const unsigned char *pos = (const unsigned char *)a;
	int i, j;
	int max_i = bytes - 1;
	if (is_little_endian()) {
		for (i = max_i; i >= 0; i--) {
			for (j = 7; j >= 0; j--) {
				printf("%d", ((pos[i] & (1 << j)) ? 1 : 0));
				if (j == 4 || j == 0)
					printf(" ");
			}
			printf(" ");
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	float a = 123.45;
	double b = 123.45;
	print_float(&a);
	print_double(&b);
	printf("%d\n", a == (float)b);
	printf("%d\n", (double)a == (double)b);
	return 0;
}