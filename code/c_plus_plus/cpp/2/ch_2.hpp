
/**
 * �̳кͲ���������
 */

#ifndef __CPP_CH_2_HPP__
#define __CPP_CH_2_HPP__

#include "chapter_02.h"

using namespace std;

namespace chapter_02
{

void ch_2()
{
    /* �ṹ���ԱȨ�� */
    {
        Hello t;
        t.a = 0;            // ʹ�ó�Ա
        int k = t.a;
        //t.m = 10;
        t.hello();
    }

    /* ���Ա���� */
    {
        Hello::SHello();    // ���þ�̬��Ա

        Monster monster;

        Monster::SHello();
        monster.SHello();
        monster.Hello();

        monster.GetP();     // ����
    }

    /* ��ļ̳����Ա���� */
    {
        ComponentWorkers workers;
        workers.Work();
//        workers.Work1();
//        workers.Work2();

        SpliceWorkers workers2;
        workers2.Hello();
//        workers2.Work();
//        workers2.Work1();
//        workers2.Work2();
    }

    /* ��Ķ�̳���ܹ� */
    {
        Attackor attackor;
        attackor.Start();
        attackor.Simulate();        // ��̳зֿ�

        Attackor attackor1;
        attackor.AttackTarget(&attackor1);

        Physics *p = &attackor;
        Attack *a = &attackor;

        IsSimulate(&attackor);      // ֻ���ĵײ�(����)�ͺ�
        IsSimulate(&attackor1);
    }

    /* �����̳� */
    {
        HelloD d;
        d.Hello();
    }

    /* ��Ԫ�� */
    {
        HelloTest2 t;
        t.Init();
    }

    /* ��Ԫ���� */
    {
        Test t;
        Test::Print2(t);

        Print(t);
    }

    /* ���캯������������ */
    {
        TestA t;
        cout << t.a << endl;

        TestA t1(0);
        cout << t1.a << endl;
    }

    /* ǳ����,��� */
    {
        TestA t1;
        TestA t2(t1);
    }

    /* �����ռ� */
    {
        ch_02::Hello o = ch_02::Hello_A;
        ch_02::Hello o2 = ch_02::Hello::Hello_B;

        ch_02::Interface *p = new ch_02::Interface();

        ch_02::GetHello();
    }

    /* ����<< >> */
    {
        Operator::GZstream << "HELLO" << Operator::GZendl;
        Operator::GZstream << "HELLO" << "123" << Operator::GZendl;
        Operator::GZstream << 1.024f << Operator::GZendl;
        Operator::GZstream << 1.00000123 << Operator::GZendl;
    }

    /* ���ز������������ǳ���� */
    {
        (Operator::GZstream = "GZ").Print() << Operator::GZendl;

        Operator::Stream a, b;
        a.ptr = (char *)malloc(20);
        strcpy(a.ptr, "nihao");
        b = a;
        b.Print();
    }
}

}

#endif //
