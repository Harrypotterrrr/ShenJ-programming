/* 1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/* �˴�������ӱ���Ķ����������������ȫ�ֱ����� */
class Teacher;

/* Student ��Ķ�����ʵ��(Student���в�����������κ����ݳ�Ա����Ա��������Ԫ) */
class Student {
private:
	int num;		//ѧ��
	char name[16];	//����
	char sex;		//�Ա�ֻ���� F/M ���֣���Сд������
	char addr[64];	//��ͥסַ
public:
	Student();
	Student(const int num1, const char *name1, const char sex1, const char *addr1);
	friend ostream &operator<<(ostream &out, const Student &stu);
	Student(Teacher &te);
	operator Teacher();
	//������ӳ�Ա����������ʵ��
};


/* Teacher ��Ķ�����ʵ��(Teacher���в�����������κ����ݳ�Ա����Ա��������Ԫ) */
class Teacher {
private:
	int num;		//����
	char name[16];	//����
	char sex;		//�Ա�ֻ���� F/M ���֣���Сд������
	char addr[64];	//��ͥסַ
public:
	Teacher();
	Teacher(const int num1, const char *name1, const char sex1, const char *addr1);
	friend ostream &operator<<(ostream &out, const Teacher &te);
	friend Student;
};

/* ----����Student���Ա��������Ԫ����������ʵ��---- */
Student::Student()
{
	num = 1750000;
	strcpy(name, "<ѧ��S>");
	sex = 'M';
	strcpy(addr, "��ƽ·1239��");
}

Student::Student(const int num1, const char*name1, const char sex1, const char*addr1)
{
	num = num1;
	strcpy(name, name1);
	sex = sex1;
	strcpy(addr, addr1);
}

ostream& operator<<(ostream &out, const Student &stu)
{
	out << stu.num << ' ';
	out << stu.name << ' ';
	out << stu.sex << ' ';
	out << stu.addr << endl;
	return out;
}

Student::operator Teacher()
{
	Teacher tmp;
	tmp.num = this->num;
	strcpy(tmp.name, this->name);
	tmp.sex = this->sex;
	strcpy(tmp.addr, this->addr);
	return tmp;
}

Student::Student(Teacher &te)
{
	num = te.num;
	strcpy(name, te.name);
	sex = te.sex;
	strcpy(addr, te.addr);
}


/* ----����Teacher���Ա��������Ԫ����������ʵ��---- */
Teacher::Teacher()
{
	num = 18000;
	strcpy(name, "<��ʦT>");
	sex = 'M';
	strcpy(addr, "��ƽ·1239���Ժ�¥");
}

Teacher::Teacher(const int num1, const char*name1, const char sex1, const char*addr1)
{
	num = num1;
	strcpy(name, name1);
	sex = sex1;
	strcpy(addr, addr1);
}


ostream& operator<<(ostream &out, const Teacher &te)
{
	out << te.num << ' ';
	out << te.name << ' ';
	out << te.sex << ' ';
	out << te.addr << endl;
	return out;
}

/* ----main������׼��---- */
int main()
{
	Student s1;	//ȱʡֵ - ѧ�ţ�1750000 ������<ѧ��S> �Ա�M ��ַ����ƽ·1239��
	Student s2 = Student(1751234, "ѧ����", 'M', "�ܰ���·4800��");
	Teacher t1;	//ȱʡֵ - ���ţ�18000 ������<��ʦT> �Ա�M ��ַ����ƽ·1239���Ժ�¥
	Teacher t2 = Teacher(18123, "��ʦ��", 'F', "�ܰ���·4800�����Ź�");

	/* ��ӡԭʼѧ����Ϣ */
	cout << "ѧ����Ϣ��" << s1 << endl;				//���������"ѧ����Ϣ��1750000 <ѧ��S> M ��ƽ·1239��"
	cout << "ѧ����Ϣ��" << s2 << endl;				//���������"ѧ����Ϣ��1751234 ѧ���� M �ܰ���·4800��"
	cout << endl;

	/* ��ӡԭʼ��ʦ��Ϣ */
	cout << "��ʦ��Ϣ��" << t1 << endl;				//���������"��ʦ��Ϣ��18000 <��ʦT> M ��ƽ·1239���Ժ�¥"
	cout << "��ʦ��Ϣ��" << t2 << endl;				//���������"��ʦ��Ϣ��18123 ��ʦ�� F �ܰ���·4800�����Ź�"
	cout << endl;

	/* ѧ��ת��ʦ���ԣ�
	   ѧ��ת���Ź��򣺹��� = 18 + ѧ�ź���λ
	   ����ת������ԭ��ת��
	   �Ա�ת������ԭ��ת��
	   ��ַת������ԭ��ַ���"**ѧԺ"(�������ַ���Խ��)    */
	t1 = s2;
	cout << "ѧ����Ϣ��" << s2 << endl;				//���������"ѧ����Ϣ��1751234 ѧ���� M �ܰ���·4800��"
	cout << "ת��Ϊ��ʦ����Ϣ��" << t1 << endl;		//���������"ת��Ϊ��ʦ����Ϣ��18234 ѧ���� M �ܰ���·4800��**ѧԺ"
	cout << endl;

	/* ��ʦתѧ�����ԣ�
	   ����תѧ�Ź���ѧ�� = 1750 + ���ź���λ
	   ����ת������ԭ��ת��
	   �Ա�ת������ԭ��ת��
	   ��ַת������ԭ��ַ���"**��"(�������ַ���Խ��)    */
	s1 = t2;
	cout << "��ʦ��Ϣ��" << t2 << endl;				//���������"��ʦ��Ϣ��18123 ��ʦ�� F �ܰ���·4800�����Ź�"
	cout << "ת��Ϊѧ������Ϣ��" << s1 << endl;		//���������"ת��Ϊѧ������Ϣ��1750123 ��ʦ�� F �ܰ���·4800�����Ź�**��"
	cout << endl;

	return 0;
}
