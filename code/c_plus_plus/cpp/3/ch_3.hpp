
/**
 * ��̬���������
 */

#ifndef __CPP_CH_3_HPP__
#define __CPP_CH_3_HPP__

#include <iostream>
#include "chapter_03.h"

using namespace std;

namespace chapter_03
{

void Fun(const int a,const HelloTest *Ptr,const HelloStruct &InHello)
{
    int ccc = Ptr->a;
    Ptr = new HelloTest();

    InHello.a;
}

void ch_3()
{
    /* �����ڼ̳��е����� */
    Test1();

    /* �麯������ͨ��������ִ������ */
    Test2();

    /* ���麯�� */
    Test3();

    /* ��ͨ������ʹ��lambda */
    Test4();

    /* ����ʹ��lambda */
    Test5();

    /* c/cpp���װ */
    //TODO...

    /* ǿ��ת�� */
    Test6();

    /* const */
    Test7();
}

}

#endif // __CPP_CH_3_HPP__
