/* 1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;

class matrix {
    private:
        int value[2][3];
	//除此之外不允许再添加数据成员
    public:
	matrix(const int(*p)[3] = NULL);	//构造函数，用数组初始化矩阵
	void display() const;		//输出该矩阵
    friend matrix operator+(const matrix &a, const matrix &b);

        /* ----根据需要添加其它成员函数的定义，数量不限---- */

};

/* ----给出类成员函数的体外实现及友元函数的实现---- */

matrix::matrix(const int(*p)[3])
{
	if (p) {
		for (int i = 0; i < sizeof(value) / sizeof(*value); i++)
			for (int j = 0; j < sizeof(*p) / sizeof(**p); j++)
				value[i][j] = p[i][j];
	}
}

void matrix::display() const
{
	for (int i = 0; i < sizeof(value) / sizeof(*value); i++) {
		for (int j = 0; j < sizeof(*value) / sizeof(**value); j++)
			cout << value[i][j] << ' ';
		cout << endl;
	}
}

matrix operator+(const matrix &a, const matrix &b)
{
	matrix tmp;
	for (int i = 0; i < sizeof(a.value) / sizeof(*(a.value)); i++)
		for (int j = 0; j < sizeof(*(a.value)) / sizeof(**(a.value)); j++)
			tmp.value[i][j] = a.value[i][j] + b.value[i][j];
	return tmp;
}
/* ----给出成员函数的体外实现---- */

/* ----main函数不准动---- */
int main()
{
	int a[2][3] = { { 1,2,3 },{ 4,5,6 } };
	int b[2][3] = { { 2,4,6 },{ 3,6,9 } };
	matrix m1(a), m2(b), m3;

	cout << "初始矩阵m1的值：" << endl;
	m1.display();
	cout << "初始矩阵m2的值：" << endl;
	m2.display();
	m3 = m1 + m2;
	cout << "相加后矩阵m3的值：" << endl;
	m3.display();

	return 0;
}
