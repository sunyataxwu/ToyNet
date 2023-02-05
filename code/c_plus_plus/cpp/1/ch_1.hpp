
#ifndef __CPP_CH_1_HPP__
#define __CPP_CH_1_HPP__

/**
 * C��CPP�Ĳ�ͬ��
 */

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

int ch_1()
{
    /* ��ӡ��ʽ��ͬ */
    {
        printf("Hello World \n");       // C
        cout << "Hello World" << endl;  // C++
    }

    /* bool������ͬ */
    {
        bool bok = false;
    }

    /* �β����� */
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
    }

    // ����ֵ��ʱ��,ʹ��ָ��(���ⴴ�����ɹ�)
    if (CreateObject())
    {
        //
    }

    return 0;
}

}


#endif //
