

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

extern void ch_07();

extern void ch_7_3();
extern void ch_7_3_1();
extern void ch_7_3_2();
extern void ch_7_5_4();
extern void ch_7_6();
void Practice_7();
void Homework_7_11();
void Homework_7_32();

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
