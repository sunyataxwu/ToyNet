

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

void Chapter_07();
void Practice_7_5_4();
void Practice_7_6();
void Practice_7();
void Homework_7_11();
void Homework_7_32();

/***************************7.3.4*********************************/
// ��Ԫ������������
struct GZX
{
    friend void f() {}
    //GZX() { f(); }

    void g();
    void h();
};

//void GZX::g() { return f(); }
void f();

/*****************************************************************/
/***************************7.32*********************************/
//������Ԫ����
class ZGWindowMgr
{
public:
    void clear();
};

class ZGScreen
{
    friend void ZGWindowMgr::clear();
private:
    std::string contents_;
};

typedef double Money;
class Acc
{
    typedef int Money;  //δ��ʹ�� ---> ��ȷ
public:
    Money balance() {return bal;}
private:
    /* 7-4-1 ���ֲ�������������� */
    //��ʹ�ò��������¶���
    //�������������,������
    //typedef int Money;
    Money bal;
};
/*****************************************************************/
/***************************7.5.1*********************************/
// 7.5.1 ���캯����ʼֵ�б�
// ���캯����ʼֵ��ʱ�ز�����
class ConstRef
{
public:
//    ConstRef(int i)
//    {
//        ci = i;
//        ri = i;
//    }
    ConstRef(int i) : ci(i), ri(i) {}
private:
    const int   ci;
    int         ri;
};

// ��Ա��ʼ��˳��
class xx
{
public:
    //xx(int val) : j(val), i(j) {}   //error
    xx(int val) : i(val), j(val) {}     //�������ò�����ʼ��
private:
    int i, j;
};

/*****************************************************************/
/***************************7.5.3*********************************/

// 7.5.3 Ĭ�Ϲ��캯��������
class NoDefault
{
public:
    NoDefault(int i){}
};

struct gza
{
    NoDefault my_mem;
};

//gza aaa;

class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){}
};

struct B
{
    //B(){}
    NoDefault no;
};

/*****************************************************************/
/***************************7.6*********************************/
//��̬��Ա����������ĳ�ֳ���,��ͨ��Ա����
class Bar
{
public:
    //Bar() {}
    static Bar mem1;
    Bar *mem2;
    //Bar mem3;
};

class Example
{
public:
    //Example() {}
    //static const double rate = 6.5;
    static constexpr double rate = 6.5;
    static const int vec_size = 20;
    static const std::vector<int> ivec;
};

void Homework_7_58();


#endif // __CPP_PRIMER_CHAPTER_07_H__
