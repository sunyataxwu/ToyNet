
/**
 * ģ��
 */

#ifndef __CPP_CH_4_HPP__
#define __CPP_CH_4_HPP__

#include "chapter_04.h"

namespace chapter_04
{

void ch_4()
{
    /* ����ģ������ģ�� */
    {
        Vector<int>     ivec;
        Vector<float>   fvec;
        Vector<Test>    hvec;

        CallArray(ivec);
        CallArray(hvec);        // ���������ƶ�
        CallArray<float>(fvec); //
    }

    /* ��ģ��ƥ�� */
    {
        Vector<Test> ct;
        float *p = ct.Hello1<float>();
    }

    /* ��ģ���(��)�̳� */
    {
        Test1 t;                         // ��ͨ�̳�ģ��
        t.Hello();

        Test2<Test> it;                  // ģ��̳С���ͨ��
        it.Hello1<int>();

        Test3<float, int, double> ft;    // ģ��̳�ģ��
        ft.Hello2();

        Test6 t1;                        // ��̳�
        t1.Hello();

        Test7 t2;                        // ��Ԫ
        t2.Hello();
    }

    /* ��ģ��Ͷ�̬ */
    {
        hello1 a;
        hello<int> *p = &a;
        p->Init();

        p->Hello();
        p->Hello(1);

        hello1 *p2 = &a;
        p2->Hello(10);
        p2->Hello(0, 1024);
    }

    /* �߼��� */
    {

    }

    /*  */
    {
        int a1 = 1;
        int a2 = 2;
        int a3 = 4;
        int a5 = 6;
        int sum = FunValue<int>(a1, a2, a3, a5);
        printf("sum = %d\n", sum);
    }
}

}
#endif //__CPP_CH_4_HPP__
