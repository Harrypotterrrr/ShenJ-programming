/* 1651574 贾昊霖 1班 */
#include <iostream>
#include<stdlib.h>
#include"12-b2-linear_list_DL.h"
using namespace std;

/* 构造函数，初始化双向链表 */
template <class ElemType>//声明模板，虚类型 ElemType
DuLinkList<ElemType>::DuLinkList()
{
	head = new(nothrow) LNode<ElemType>;//申请头结点
	if (head == NULL)
		exit(LOVERFLOW);

    /* 头结点 前 后指针，均为 NULL*/
	head->prior = NULL;
	head->next = NULL;
}


/* 析构函数，删除双向链表 */
template <class ElemType>//声明模板，虚类型 ElemType
DuLinkList<ElemType>::~DuLinkList()
{
	LNode<ElemType> *q, *p = head;

	/* 从头结点开始，依次释放（含头结点）*/
	while (p)
	{
		q = p->next;//抓住下一个结点
		delete p;
		p = q;
	}

	head = NULL;//头指针置NULL
}

/* 清除双向链表，保留头结点 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::ClearList()
{
	LNode<ElemType> *q, *p = head->next;

	/* 从首元结点开始释放 */
	while (p)
	{
		q = p->next;//抓住下一个结点
		delete p;
		p = q;
	}

	head->next = NULL;//头结点的next置NULL

	return OK;
}

/* 判断链表是否为空 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::ListEmpty()
{
	/* 直接判断头结点即可 */
	if (head->next == NULL)
		return TRUE;
	else
		return FALSE;
}


/* 求链表的长度 */
template <class ElemType>//声明模板，虚类型 ElemType
int DuLinkList<ElemType>::ListLength()
{
	LNode<ElemType> *p = head->next;//p指向首元结点
	int    len = 0;

	/* 循环整个链表 ，计数 */
	while (p)
	{
		p = p->next;
		len++;
	}

	return len;//返回长度
}


/* 取链表元素 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::GetElem(int i, ElemType &e)
{
	LNode<ElemType> *p = head->next;//指向首元结点
	int    pos = 1;//初始位置为1

	/* 链表不为NULL，且 没有到第 i 个元素 */
	while (p != NULL&&pos < i)
	{
		p = p->next;
		pos++;
	}
	if (!p || pos > i)
		return ERROR;

	e = p->data;

	return OK;
}


/* 查找符合指定条件的元素 */
template <class ElemType>//声明模板，虚类型 ElemType
int DuLinkList<ElemType>::LocateElem(ElemType e, Status(*compare)(ElemType e1, ElemType e2))
{
	LNode<ElemType> *p = head->next;//首元结点
	int    pos = 1;//初始位置为1

	/* 循环链表 */
	while (p && (*compare)(e, p->data) == FALSE)
	{
		p = p->next;
		pos++;
	}

	return p ? pos : 0;
}

/* 查找符合指定条件的元素的前驱元素 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::PriorElem(ElemType cur_e, ElemType &pre_e)
{
	LNode<ElemType> *p = head->next;	//指向首元结点

	if (p == NULL)	//空表直接返回
		return ERROR;

	/* 从第2个结点开始循环整个链表(如果比较相等，保证有前驱) */
	while (p->next && p->next->data != cur_e)
		p = p->next;

	if (p->next == NULL) //未找到
		return ERROR;

	pre_e = p->data;
	return OK;
}


/* 查找符合指定条件的元素的后继元素 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::NextElem(ElemType cur_e, ElemType &next_e)
{
	LNode<ElemType> *p = head->next;  //首元结点

	if (p == NULL)	//空表直接返回
		return ERROR;

	/* 有后继结点且当前结点值不等时继续 */
	while (p->next && p->data != cur_e)
		p = p->next;

	if (p->next == NULL)
		return ERROR;

	next_e = p->next->data;
	return OK;
}


/* 在指定位置前插入一个新元素 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::ListInsert(int i, ElemType e)
{
	LNode<ElemType> *s, *p = head;	//p指向头结点
	int   pos = 0;

	/* 寻找第i-1个结点 */
	while (p && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //i值非法则返回
		return ERROR;

	//执行到此表示找到指定位置，p指向第i-1个结点

	s = new LNode<ElemType>;
	if (s == NULL)
		return LOVERFLOW;

	s->data = e; 	//新结点数据域赋值
	s->next = p->next;	//新结点的next是第i个
	if(p->next)
		p->next->prior = s;
	p->next = s;	//第i-1个的next是新结点
	s->prior = p;

	return OK;
}


/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::ListDelete(int i, ElemType &e)
{
	LNode<ElemType> *q, *p = head;	//p指向头结点
	int   pos = 0;

	/* 寻找第i个结点（p->next是第i个结点） */
	while (p->next && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p->next == NULL || pos>i - 1)	//i值非法则返回
		return ERROR;

	//执行到此表示找到了第i个结点，此时p指向第i-1个结点

	q = p->next;       //q指向第i个结点
	p->next = q->next; //第i-1个结点的next域指向第i+1个
	if(q->next)
		q->next->prior = p;

	e = q->data;      //取第i个结点的值
	delete q;           //释放第i个结点

	return OK;
}


/* 遍历线性表 */
template <class ElemType>//声明模板，虚类型 ElemType
Status DuLinkList<ElemType>::ListTraverse(Status(*visit)(ElemType e))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	LNode<ElemType> *p = head->next;

	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	cout << endl;	//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
