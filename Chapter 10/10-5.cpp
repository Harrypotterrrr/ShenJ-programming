/* 1651574 1�� �����*/
#include <iostream>
using namespace std;

class matrix {
    private:
        int value[2][3];
	//����֮�ⲻ������������ݳ�Ա
    public:
        matrix operator+(const matrix &b);
		matrix(const int(*p)[3] = NULL);	//���캯�����������ʼ������
		friend istream& operator>> (istream &in, matrix &);
		friend ostream& operator<< (ostream &out, const matrix &);
        /* ----������Ҫ��ӳ����ݳ�Ա����Ķ��壬��������---- */

    };

/* ----�������Ա����������ʵ��---- */
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

/* ----main������׼��---- */
int main()
{
    matrix m1, m2, m3;

    cout << "���������m1��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m1;
    cout << "���������m2��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m2;
	
    cout << "��ʼ����m1��ֵ��" << endl;
    cout << m1 << endl;
    cout << "��ʼ����m2��ֵ��" << endl;
    cout << m2 << endl;
    cout << "��Ӻ����m3��ֵ��" << endl;
    cout << (m3=m1+m2) << endl;

    return 0;
}
