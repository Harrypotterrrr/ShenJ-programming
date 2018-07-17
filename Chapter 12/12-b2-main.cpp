/* 1651574 贾昊霖 1班 */
#include <iostream>
#include <iomanip>
#include "12-b2-linear_list_DL.h"
#include"12-b2-linear_list_DL.cpp"
#include"12-b2-double1.h"
#include"12-b2-student.h"

using namespace std;

#define INSERT_NUM		115		//初始插入表中的元素数量
#define MAX_NUM_PER_LINE 	10		//每行最多输出的元素个数

int line_count = 0;   //打印链表时的计数器

					  /* 用于比较两个值是否相等的具体函数，与LocateElem中的函数指针定义相同，调用时代入
					  int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
template <class ElemType>//声明模板，虚类型 ElemType
Status MyCompare(ElemType e1, ElemType e2)
{
	if (e1 == e2)
		return TRUE;
	else
		return FALSE;
}

/* 用于访问某个元素的值的具体函数，与ListTraverse中的函数指针定义相同，调用时代入
Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
template <class ElemType>//声明模板，虚类型 ElemType
Status MyVisit(ElemType e)
{
	cout << e << "->";

	/* 每输出MAX_NUM_PER_LINE个，打印一个换行 */
	if ((++line_count) % MAX_NUM_PER_LINE == 0)
		cout << endl;

	return OK;
}









int main()
{
#if defined (ELEMTYPE_IS_STRUCT_STUDENT)
	/* 这两种数据类型需要预置数据 */
	student e[] = { { 1001, "张三", 'M', 76.5, "上海市杨浦区" },
	{ 1002, "李四", 'F', 87, "上海市普陀区" },
	{ 1003, "王五", 'M', 80, "浙江省杭州市" },
	{ 1004, "赵六", 'M', 54, "浙江省绍兴市" },
	{ 1005, "牛七", 'F', 85, "江苏省南京市" },
	{ 1006, "马八", 'M', 60, "江苏省苏州市" } };
#endif


	DuLinkList<student> L;
	student      e1, e2;
	/* 以下没有任何改变 */
	int          i, pos;

	cout << "空表=" << ((L.ListEmpty() == TRUE) ? "TRUE" : "FALSE") << endl;
	cout << "表长=" << L.ListLength() << endl;



#ifdef ELEMTYPE_IS_DOUBLE1
	cout << "插入" << INSERT_NUM << "个元素：" << endl;
	for (i = INSERT_NUM * 2; i>0; i -= 2)
		L.ListInsert(1, (double1)i);	//i是整型，严格来说需要转换为double
#elif defined (ELEMTYPE_IS_CHAR_P)
	cout << "插入" << INSERT_NUM << "个元素：" << endl;
	e1 = "test000";
	//e1 = (ElemType)malloc(80 * sizeof(char));	//e1实际是指针，必须先申请相应的空间
	//e2 = (ElemType)malloc(80 * sizeof(char));	//e2实际是指针，必须先申请相应的空间
	for (i = INSERT_NUM * 2; i>0; i -= 2) {
	//	sprintf(e1, "test%03d", i);
		
		e1[4] = i / 100 + '0';
		e1[5] = i % 100 / 10 + '0';
		e1[6] = i % 100 % 10 + '0';
		L.ListInsert(1, e1);
	}
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	cout << "插入" << 6 << "个元素：" << endl;
	for (i = 0; i<6; i++)
		L.ListInsert(L.ListLength() + 1, *(e + i));
#else	//缺省当做int处理
	cout << "插入" << INSERT_NUM << "个元素：" << endl;
	for (i = INSERT_NUM * 2; i>0; i -= 2)
		L.ListInsert(1, i);
#endif


	/*cout << "插入" << INSERT_NUM << "个元素：" << endl;
	for (i = INSERT_NUM * 2; i>0; i -= 2)
		L.ListInsert(1, i);*/
	L.ListTraverse(MyVisit);//此处传入MyVisit函数名

	cout << "空表=" << ((L.ListEmpty() == TRUE) ? "TRUE" : "FALSE") << endl;
	cout << "表长=" << L.ListLength() << endl;

	/* 分别取第1、最后、以及小于第1、大于最后的4种情况下的的元素值、前驱值、后继值
	最后再加一个任意输入值 */
	for (i = 0; i<5; i++) {
		int pos;
		switch (i) {
		case 0:
			pos = 1;
			break;
		case 1:
			pos = L.ListLength();
			break;
		case 2:
			pos = -1;
			break;
		case 3:
			pos = L.ListLength() + 1;
			break;
		case 4:
			cout << "请输入要取元素的位序[1.." << L.ListLength() << "]：" << endl;
			cin >> pos;
			break;
		}

		if (L.GetElem(pos, e1) == OK) {
			cout << "第" << pos << "个元素=" << e1 << endl;

			/* 只有取得了某个元素，才能取前驱和后继 */
			if (L.PriorElem(e1, e2) == OK)
				cout << "第" << pos << "个元素(" << e1 << ")的前驱=" << e2 << endl;
			else
				cout << "无法取得第" << pos << "个元素(" << e1 << ")的前驱" << endl;

			if (L.NextElem(e1, e2) == OK)
				cout << "第" << pos << "个元素(" << e1 << ")的后继=" << e2 << endl << endl;
			else
				cout << "无法取得第" << pos << "个元素(" << e1 << ")的后继" << endl << endl;
		}
		else
			cout << "无法取得第" << pos << "个元素" << endl << endl;
	} // end of for

	cout << "请输入要查找的元素：" << endl;
	cin >> e1;
	if ((pos = L.LocateElem(e1, MyCompare))>0)
		cout << "元素" << e1 << "的位序=" << pos << endl;
	else
		cout << "找不到元素" << e1 << endl;

	cout << endl << "请输入要插入元素的值：" << endl;
	cin >> e1;
	cout << "请输入要插入元素的位序：" << endl;
	cin >> pos;
	if (L.ListInsert(pos, e1) == OK) {
		cout << "在" << pos << "前插入元素" << e1 << "成功" << endl;
		cout << "新表为：" << endl;
		L.ListTraverse(MyVisit);
	}
	else
		cout << "在" << pos << "前插入元素" << e1 << "失败" << endl;

	cout << endl << "请输入要删除元素的位序：" << endl;
	cin >> pos;
	if (L.ListDelete(pos, e1) == OK) {
		cout << "删除第" << pos << "元素=" << e1 << "成功" << endl;
		cout << "新表为：" << endl;
		L.ListTraverse(MyVisit);
	}
	else
		cout << "删除第" << pos << "元素=" << e1 << "失败" << endl;

	cout << endl << "清空表：" << endl;
	L.ClearList();
	cout << "空表=" << ((L.ListEmpty() == TRUE) ? "TRUE" : "FALSE") << endl;
	cout << "表长=" << L.ListLength() << endl;

	return 0;
}