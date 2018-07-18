/* 1651574 ����� 1�� */
#pragma once
#define ELEMTYPE_IS_INT		//������Ҳ��
//#define ELEMTYPE_IS_DOUBLE1
//#define ELEMTYPE_IS_CHAR_P
//#define ELEMTYPE_IS_STRUCT_STUDENT

/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2

typedef int Status;

//typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

template <class ElemType> class DuLinkList;//����ģ�壬������ ElemType
//class DuLinkList;	//��ǰ��������Ϊ������ԪҪ�õ�


template <class ElemType>//����ģ�壬������ ElemType
class LNode {
protected:
	ElemType data;	//������
	LNode    *prior; //ǰ��ָ����
	LNode    *next;	//���ָ����
public:
	friend class DuLinkList <ElemType>;
	//�������κκ������൱��struct LNode
};

template <class ElemType>//����ģ�壬������ ElemType
class DuLinkList {
protected:
	LNode <ElemType> *head;	//ͷָ��
public:
	/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C++���� */
	DuLinkList();	//���캯�������InitList
	~DuLinkList();	//�������������DestroyList
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