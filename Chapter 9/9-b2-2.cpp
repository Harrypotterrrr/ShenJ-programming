/*1651574 1班 贾昊霖 */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //类的提前声明，思考一下，放在这里的目的是为什么
class point {
	private:
		int x;
		int y;
	public:
	/* 仅允许在此添加一个成员函数【仅限1个】 */
	friend triangle;
	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	/* 除上面允许的那个成员函数外，不再允许添加任何的数据成员和成员函数，但可以根据需要添加其它内容 */
};

class triangle {
	private:
		point p1;
		point p2;
		point p3;
	public:
		double area() {
			double a, b, c;  //分别表示三角形三边的长度
			double s;

			/* 根据需要补充相应的语句，假设三边一定构成三角形 */
			a = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
			b = sqrt(pow((p2.x - p3.x), 2) + pow((p2.y - p3.y), 2));
			c = sqrt(pow((p3.x - p1.x), 2) + pow((p3.y - p1.y), 2));
			s = (a + b + c) / 2;

			return sqrt(s*(s-a)*(s-b)*(s-c));
			}
		triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y) {
			/* 给p1/p2/p3三个点分别赋x,y坐标值 */
			p1.set(p1_x, p1_y);
			p2.set(p2_x, p2_y);
			p3.set(p3_x, p3_y);
			}
};

/* main函数不准动 */
int main()
{
	if (1) {
		triangle tr(0,0,0,1,1,0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是："<< tr.area() << endl;
		}

	if (1) {
		triangle tr(0,2,-1,-1,1,-1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是："<< tr.area() << endl;
		}

	if (1) {
		triangle tr(5,5,-3,1,9,-2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是："<< tr.area() << endl;
		}
	
	return 0;
}
