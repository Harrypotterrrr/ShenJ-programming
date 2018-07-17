/* 1651574 1�� ����� */
#include <iostream>
#include <cmath>
using namespace std;

class point {
	private:
		int x;
		int y;
	public:
		int getx() {
			return x;
		}
		int gety() {
			return y;
		}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
		void set(int x, int y)
		{
			this->x = x;
			this->y = y;
		}


};

class triangle {
	private:
		point p1;
		point p2;
		point p3;
	public:
		double area() {
			double a, b, c;  //�ֱ��ʾ���������ߵĳ���
			double s;

			/* ������Ҫ������Ӧ����䣬��������һ������������ */
			a = sqrt(pow((p1.getx() - p2.getx()), 2) + pow((p1.gety() - p2.gety()), 2));
			b = sqrt(pow((p2.getx() - p3.getx()), 2) + pow((p2.gety() - p3.gety()), 2));
			c = sqrt(pow((p3.getx() - p1.getx()), 2) + pow((p3.gety() - p1.gety()),2));
			s = (a + b + c) / 2;

			return sqrt(s*(s-a)*(s-b)*(s-c));
			}

		triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y) {
			/* ��p1/p2/p3������ֱ�x,y����ֵ */
			p1.set(p1_x, p1_y);
			p2.set(p2_x, p2_y);
			p3.set(p3_x, p3_y);
			}
};

/* main������׼�� */
int main()
{
	if (1) {
		triangle tr(0,0,0,1,1,0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�"<< tr.area() << endl;
		}

	if (1) {
		triangle tr(0,2,-1,-1,1,-1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�"<< tr.area() << endl;
		}

	if (1) {
		triangle tr(5,5,-3,1,9,-2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�"<< tr.area() << endl;
		}
	
	return 0;
}
