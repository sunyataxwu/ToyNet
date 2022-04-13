

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

void Chapter_07();
void Practice_7_5_4();
void Practice_7_6();

void Homework_7_11();

/* 7-3-4 ��Ԫ������������ */
struct Xxx
{
    Xxx();
    friend void f() { }     //��Ԫ���Զ���������
    //X() { f(); }            //error: δ����
    void g();
    void k();
};

//void Xxx::g() {f();}        //error: δ����
void f();
//k()ʵ����Դ�ļ�...

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

class ConstRef
{
public:
    /* 7-5-1 ���캯����ʼֵ�б� */
    //���캯����ʼֵ��ʱ��ز�����
    //const,����,δ�ṩĬ�Ϲ��캯��...
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

class xx
{
public:
    /* 7-5-1 ��Ա��ʼ��˳�� */
    //����ʹ��ͬһ�������������Ա��ʼ��
    //xx(int val) : j(val), i(j) {}   //error
    xx(int val) : i(val), j(val) {}
private:
    int i, j;
};

/* 7-5-3 Ĭ�Ϲ��캯�������� */
class NoDefault
{
public:
    NoDefault(int i){}
};

class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){}
};

//TODO: �����ʱ����ԣ�����
struct B
{
    NoDefault no;
};

/* 7-6 ��̬��Ա����������ĳ�ֳ���,��ͨ��Ա���� */
//Ĭ�ϲ���...
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
