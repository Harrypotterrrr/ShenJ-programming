/* 1651574 贾昊霖 1班 */
#pragma once
#define ELEMTYPE_IS_INT		//不定义也行
//#define ELEMTYPE_IS_DOUBLE1
//#define ELEMTYPE_IS_CHAR_P
//#define ELEMTYPE_IS_STRUCT_STUDENT

/* P.10 的预定义常量和类型 */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2

typedef int Status;

//typedef int ElemType;	//可根据需要修改元素的类型

template <class ElemType> class DuLinkList;//声明模板，虚类型 ElemType
//class DuLinkList;	//提前声明，因为定义友元要用到


template <class ElemType>//声明模板，虚类型 ElemType
class LNode {
protected:
	ElemType data;	//数据域
	LNode    *prior; //前驱指针域
	LNode    *next;	//后继指针域
public:
	friend class DuLinkList <ElemType>;
	//不定义任何函数，相当于struct LNode
};

template <class ElemType>//声明模板，虚类型 ElemType
class DuLinkList {
protected:
	LNode <ElemType> *head;	//头指针
public:
	/* P.19-20的抽象数据类型定义转换为实际的C++语言 */
	DuLinkList();	//构造函数，替代InitList
	~DuLinkList();	//析构函数，替代DestroyList
	Status	ClearList();
	Status	ListEmpty();
	int	ListLength();
	Status	GetElem(int i, ElemType &e);
	int	LocateElem(ElemType e, Status(*compare)(ElemType e1, ElemType e2));
	Status	PriorElem(ElemType cur_e, ElemType &pre_e);
	Status	NextElem(ElemType cur_e, ElemType &next_e);
	Status	ListInsert(int i, ElemType e);
	Status	ListDelete(int i, ElemType &e);
	Status	ListTraverse(Status(*visit)(ElemType e));
};