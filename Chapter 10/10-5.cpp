/* 1651574 1班 贾昊霖*/
#include <iostream>
using namespace std;

class matrix {
    private:
        int value[2][3];
	//除此之外不允许再添加数据成员
    public:
        matrix operator+(const matrix &b);
		matrix(const int(*p)[3] = NULL);	//构造函数，用数组初始化矩阵
		friend istream& operator>> (istream &in, matrix &);
		friend ostream& operator<< (ostream &out, const matrix &);
        /* ----根据需要添加除数据成员以外的定义，数量不限---- */

    };

/* ----给出类成员函数的体外实现---- */
matrix::matrix(const int(*p)[3])
{
	if (p) {
		for (int i = 0; i < sizeof(value) / sizeof(*value); i++)
			for (int j = 0; j < sizeof(*p) / sizeof(**p); j++)
				value[i][j] = p[i][j];
	}
}

matrix matrix::operator+(const matrix &b)
{
	matrix tmp;
	for (int i = 0; i < sizeof(value) / sizeof(*(this->value)); i++)
		for (int j = 0; j < sizeof(*(this->value)) / sizeof(**(this->value)); j++)
			tmp.value[i][j] = value[i][j] + b.value[i][j];
	return tmp;
}

istream& operator>>(istream &in, matrix &m)
{
	for (int i = 0; i < sizeof(m.value) / sizeof(*(m.value)); i++)
		for (int j = 0; j < sizeof(*(m.value)) / sizeof(**(m.value)); j++)
			in >> m.value[i][j];
	return in;
}

ostream& operator<< (ostream &out, const matrix &m)
{
	for (int i = 0; i < sizeof(m.value) / sizeof(*(m.value)); i++) {
		for (int j = 0; j < sizeof(*(m.value)) / sizeof(**(m.value)); j++)
			out << m.value[i][j] << ' ';
		out << endl;
	}
	return out;
}

/* ----main函数不准动---- */
int main()
{
    matrix m1, m2, m3;

    cout << "请输入矩阵m1的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m1;
    cout << "请输入矩阵m2的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m2;
	
    cout << "初始矩阵m1的值：" << endl;
    cout << m1 << endl;
    cout << "初始矩阵m2的值：" << endl;
    cout << m2 << endl;
    cout << "相加后矩阵m3的值：" << endl;
    cout << (m3=m1+m2) << endl;

    return 0;
}
