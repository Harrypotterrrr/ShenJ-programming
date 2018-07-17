/* 1651574 ����� 1�� */
#include <iostream>
#include<stdlib.h>
#include"12-b2-linear_list_DL.h"
using namespace std;

/* ���캯������ʼ��˫������ */
template <class ElemType>//����ģ�壬������ ElemType
DuLinkList<ElemType>::DuLinkList()
{
	head = new(nothrow) LNode<ElemType>;//����ͷ���
	if (head == NULL)
		exit(LOVERFLOW);

    /* ͷ��� ǰ ��ָ�룬��Ϊ NULL*/
	head->prior = NULL;
	head->next = NULL;
}


/* ����������ɾ��˫������ */
template <class ElemType>//����ģ�壬������ ElemType
DuLinkList<ElemType>::~DuLinkList()
{
	LNode<ElemType> *q, *p = head;

	/* ��ͷ��㿪ʼ�������ͷţ���ͷ��㣩*/
	while (p)
	{
		q = p->next;//ץס��һ�����
		delete p;
		p = q;
	}

	head = NULL;//ͷָ����NULL
}

/* ���˫����������ͷ��� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::ClearList()
{
	LNode<ElemType> *q, *p = head->next;

	/* ����Ԫ��㿪ʼ�ͷ� */
	while (p)
	{
		q = p->next;//ץס��һ�����
		delete p;
		p = q;
	}

	head->next = NULL;//ͷ����next��NULL

	return OK;
}

/* �ж������Ƿ�Ϊ�� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::ListEmpty()
{
	/* ֱ���ж�ͷ��㼴�� */
	if (head->next == NULL)
		return TRUE;
	else
		return FALSE;
}


/* ������ĳ��� */
template <class ElemType>//����ģ�壬������ ElemType
int DuLinkList<ElemType>::ListLength()
{
	LNode<ElemType> *p = head->next;//pָ����Ԫ���
	int    len = 0;

	/* ѭ���������� ������ */
	while (p)
	{
		p = p->next;
		len++;
	}

	return len;//���س���
}


/* ȡ����Ԫ�� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::GetElem(int i, ElemType &e)
{
	LNode<ElemType> *p = head->next;//ָ����Ԫ���
	int    pos = 1;//��ʼλ��Ϊ1

	/* ����ΪNULL���� û�е��� i ��Ԫ�� */
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


/* ���ҷ���ָ��������Ԫ�� */
template <class ElemType>//����ģ�壬������ ElemType
int DuLinkList<ElemType>::LocateElem(ElemType e, Status(*compare)(ElemType e1, ElemType e2))
{
	LNode<ElemType> *p = head->next;//��Ԫ���
	int    pos = 1;//��ʼλ��Ϊ1

	/* ѭ������ */
	while (p && (*compare)(e, p->data) == FALSE)
	{
		p = p->next;
		pos++;
	}

	return p ? pos : 0;
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::PriorElem(ElemType cur_e, ElemType &pre_e)
{
	LNode<ElemType> *p = head->next;	//ָ����Ԫ���

	if (p == NULL)	//�ձ�ֱ�ӷ���
		return ERROR;

	/* �ӵ�2����㿪ʼѭ����������(����Ƚ���ȣ���֤��ǰ��) */
	while (p->next && p->next->data != cur_e)
		p = p->next;

	if (p->next == NULL) //δ�ҵ�
		return ERROR;

	pre_e = p->data;
	return OK;
}


/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::NextElem(ElemType cur_e, ElemType &next_e)
{
	LNode<ElemType> *p = head->next;  //��Ԫ���

	if (p == NULL)	//�ձ�ֱ�ӷ���
		return ERROR;

	/* �к�̽���ҵ�ǰ���ֵ����ʱ���� */
	while (p->next && p->data != cur_e)
		p = p->next;

	if (p->next == NULL)
		return ERROR;

	next_e = p->next->data;
	return OK;
}


/* ��ָ��λ��ǰ����һ����Ԫ�� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::ListInsert(int i, ElemType e)
{
	LNode<ElemType> *s, *p = head;	//pָ��ͷ���
	int   pos = 0;

	/* Ѱ�ҵ�i-1����� */
	while (p && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //iֵ�Ƿ��򷵻�
		return ERROR;

	//ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����

	s = new LNode<ElemType>;
	if (s == NULL)
		return LOVERFLOW;

	s->data = e; 	//�½��������ֵ
	s->next = p->next;	//�½���next�ǵ�i��
	if(p->next)
		p->next->prior = s;
	p->next = s;	//��i-1����next���½��
	s->prior = p;

	return OK;
}


/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::ListDelete(int i, ElemType &e)
{
	LNode<ElemType> *q, *p = head;	//pָ��ͷ���
	int   pos = 0;

	/* Ѱ�ҵ�i����㣨p->next�ǵ�i����㣩 */
	while (p->next && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p->next == NULL || pos>i - 1)	//iֵ�Ƿ��򷵻�
		return ERROR;

	//ִ�е��˱�ʾ�ҵ��˵�i����㣬��ʱpָ���i-1�����

	q = p->next;       //qָ���i�����
	p->next = q->next; //��i-1������next��ָ���i+1��
	if(q->next)
		q->next->prior = p;

	e = q->data;      //ȡ��i������ֵ
	delete q;           //�ͷŵ�i�����

	return OK;
}


/* �������Ա� */
template <class ElemType>//����ģ�壬������ ElemType
Status DuLinkList<ElemType>::ListTraverse(Status(*visit)(ElemType e))
{
	extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
	LNode<ElemType> *p = head->next;

	line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	cout << endl;	//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
	return OK;
}
