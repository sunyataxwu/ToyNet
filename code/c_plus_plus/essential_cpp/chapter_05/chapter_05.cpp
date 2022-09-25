
#include <iostream>

#include "chapter_05.h"
#include "../util/libmat.h"
#include "../util/book.h"
#include "../util/audio_book.h"
#include "../util/num_sequence_ver2.h"
#include "../util/fibonacci_ver2.h"
#include "../util/num_sequence_ver3.h"
#include "../util/fibonacci_ver3.h"

using namespace std;

void ch_5()
{
    //ch_5_2();
    //ch_5_5();
    //ch_5_6();
    //ch_5_9();
    ch_5_10();
}

void ch_5_2()
{
    {
        LibMat libmat;
        Print(libmat);
    }
    cout << "==================================" << endl;

    {
        Book book("a", "b");
        Print(book);
    }
    cout << "==================================" << endl;

    {
        AudioBook audio("1", "2", "3");
        audio.Print();
    }
}

void ch_5_5()
{
    FibonacciVer2 fib;
    cout << "fib: the begging at element 1 for 1 element: "
         << fib << endl;

    FibonacciVer2 fib2(16);
    cout << "fib: the begging at element 1 for 16 element: "
         << fib2 << endl;

    FibonacciVer2 fib3(8, 12);
    cout << "fib: the begging at element 12 for 8 element: "
         << fib3 << endl;
}

void ch_5_6()
{
    const int postion = 8;
    
    FibonacciVer2 fib;
    Display(cout, fib, postion);
    // TODO 需要修改一下print函数
}

void Print1(LibMat lib, const LibMat *p1, const LibMat &r1)
{
    lib.Print();    //基类切割
    cout << endl;

    p1->Print();
    cout << endl;

    r1.Print();
}

void ch_5_9()
{
    // AudioBook a("1", "2", "3");
    // Print1(a, &a, a);

    FibonacciVer3 b;
    cout << b.WhatAmI() << endl;

    FibonacciVer3 *ptr = b.Clone();
    cout << ptr->WhatAmI() << endl;
    // TODO 完善其他类型接着测试一下

}

//RTII
void ch_5_10()
{
    FibonacciVer3 fib;
    NumSequenceVer3 *ps = &fib;

    if (typeid(*ps) == typeid(FibonacciVer3))
    {
        //cout << ps->WhatAmI() << endl;
        //ps->GenElems(64);
        //ps->FibonacciVer3::GenElems(64);   //error
    }
    
    if (FibonacciVer3 *pf = dynamic_cast<FibonacciVer3 *>(ps))
        cout << pf->WhatAmI() << endl;
}
