
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
    {
        B b;
        b.Func1();
//        b.Func1(1);
//        b.Func1(1, 2);
    }

    /* �麯������ͨ��������ִ������ */
    {
        B b;
        A *ptr_a = &b;
        ptr_a->Func1();
//        ptr_a->Func1(1,2,3,4);

        ptr_a->Func();

        B *ptr_b = &b;
        //ptr_b->Func();
//        ptr_b->Func1(1, 2);
        ptr_b->Func1(1,2,3,4);
    }

    /* ���麯�� */
    {
        NewObject1 obj;
        Interface *ptr = &obj;
        ptr->Init();
        ptr->Destroy();

        obj.Init();
        NewObject1 *p = &obj;
        p->Init();
    }

    /* ��ͨ������ʹ��lambda */
    char buff1[1024] = "hello world��";
    {
        char buff[1024] = "hello world";
        auto hello = [&](char *buf)
        {
            auto hello1 = [](char *buf1)
            {
                printf("%s\n", buf1);
            };

            hello1(buf);
            hello1(buff);
            hello1(buff1);
        };

        hello(buff);
    }

    /* ����ʹ��lambda */
    {
        HelloTest test;
        test.Init();
    }

    /* c/cpp���װ */
    {
        // todo...
    }

    /* ǿ��ת�� */
    {
        // const_cast
        const HelloTest *ptr = new HelloTest();
        //ptr->Init();
        HelloTest *p = const_cast<HelloTest *>(ptr);  // ת��ʧ�ܷ���null
        p->Init();

        // C������ײ���Ұָ��
        HelloTest *p1 = (HelloTest *)ptr;
        p1->Init();

        // reinterpret_cast
        int *a = reinterpret_cast<int *>(p);
        cout << "*a = " << *a << endl;
        HelloTest *p2 = reinterpret_cast<HelloTest *>(a);
        p2->Init();

        delete ptr;

        // dynamic_cast(�麯��)
        Hello *ph = new Hello();

        Hello1 *ph1 = dynamic_cast<Hello1 *>(ph);  // ����ת��
        ph1->Hello();

        Hello *ph2 = dynamic_cast<Hello *>(ph1);   // ����ת��
        //ph2->Init();

        Hello *ph3 = ph1;    // ��ʽת��

        Hello2 *ph4 = dynamic_cast<Hello2 *>(ph);
        if (!ph4)
        {
            cout << "ph convert ph4 failed." << endl;
        }

        // static_cast(û���麯��)
        Hello2 *ph5 = static_cast<Hello2 *>(ph);

        HelloA *pa = new HelloA();
        HelloB *pb = static_cast<HelloB *>(pa);

        delete pa;
        delete p;
    }

    /* const */
    {
        Const *pc = new Const();
        pc->m_ptr = new HelloTest();
        delete pc;

        const TestConst *ptc = new TestConst();
        ptc->Init();
        //ptc->Init2();

        TestConst c[10];
        for (int i = 0; i < 10; ++i)
        {
            const TestConst *p = &c[1];
            p->Init();
        }
    }
}

}

#endif // __CPP_CH_3_HPP__
