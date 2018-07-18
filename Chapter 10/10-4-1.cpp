/* 1651574 1�� �����*/
#include <iostream>
using namespace std;

class matrix {
    private:
        int value[2][3];
	//����֮�ⲻ������������ݳ�Ա
    public:
	matrix(const int(*p)[3] = NULL);	//���캯�����������ʼ������
	void display() const;		//����þ���
	matrix operator+(const matrix &b);
	/* ----������Ҫ���������Ա�����Ķ��壬��������---- */

};

/* ----������Ա����������ʵ��---- */
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
			cout << value[i][j] <<' ';
		cout << endl;
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

/* ----main������׼��---- */
int main()
{
	int a[2][3] = { { 1,2,3 },{ 4,5,6 } };
	int b[2][3] = { { 2,4,6 },{ 3,6,9 } };
	matrix m1(a), m2(b), m3;

	cout << "��ʼ����m1��ֵ��" << endl;
	m1.display();
	cout << "��ʼ����m2��ֵ��" << endl;
	m2.display();
	m3 = m1 + m2;
	cout << "��Ӻ����m3��ֵ��" << endl;
	m3.display();

	return 0;
}
