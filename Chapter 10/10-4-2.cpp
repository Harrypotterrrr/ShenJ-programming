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
    friend matrix operator+(const matrix &a, const matrix &b);

        /* ----������Ҫ���������Ա�����Ķ��壬��������---- */

};

/* ----�������Ա����������ʵ�ּ���Ԫ������ʵ��---- */

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
/* ----������Ա����������ʵ��---- */

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
