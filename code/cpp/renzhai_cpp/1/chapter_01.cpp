

#include <stdio.h>
#include <iostream>
//#include "stdbool.h"            // C������Ҫ��������
#include "chapter_01.h"

using namespace std;

namespace chapter_01
{

void Func(Hello &ref)           // C++֧�ִ�����,C���Բ�֧�ִ�����
{
    ref.a = 0;
}

void Func(Hello *ptr)           // C++ ֧�ִ�ָ��(Ҳ����copy)
{
    ptr->a = 0;
}

Hello* CreateObject()
{
    return NULL;
}

void Test1()
{
    printf("Hello World \n");       // C
    cout << "Hello World" << endl;  // C++
}

void Test2()
{
    bool bok = false;
}

void Test3()
{
    Hello o;
    Func(o);

    Hello &o1 = o;      // ���ñ����ʼ��; Ψһ��
    Hello &o2 = o;      // �������������
//        Hello &o3 = NULL;

    cout << "o1 size : " << sizeof(o1) << endl;

    Hello o3;
    o2 = o3;            // ���õ�ָ�򲻱�

    // ָ������޸�ָ��
    Hello *optr = &o;
    optr = &o3;

    // ����ֵ��ʱ��,ʹ��ָ��(���ⴴ�����ɹ�)
    if (CreateObject())
    {
        //
    }
}

}

// C���Բ�֧�ֽṹ�ڶ��庯��,֧��ָ��

/*

void Hello(int a, int b)
{

}

struct Test
{
    void (*FuncPtr)(int, int);

    int a;
    int b;

} test;

void main()
{
    test.FuncPtr = Hello;
}

*/
