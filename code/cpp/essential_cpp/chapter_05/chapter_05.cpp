
#include <iostream>

#include "chapter_05.h"
#include "libmat.h"
#include "book.h"
#include "audio_book.h"
#include "num_sequence_ver2.h"
#include "num_sequence_ver1.h"
#include "fibonacci_ver2.h"
#include "fibonacci_ver1.h"
#include "lifo_stack.h"

using namespace std;


namespace chapter_05
{

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
    using namespace ver1;

    Fibonacci fib;
    cout << "fib: the begging at element 1 for 1 element: \n"
        << fib << endl;

    Fibonacci fib2(16);
    cout << "fib: the begging at element 1 for 16 element: \n"
        << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << "fib: the begging at element 12 for 8 element: \n"
        << fib3 << endl;
}

void ch_5_6()
{
    using namespace ver1;
    const int postion = 8;
    
    Fibonacci fib;
    Display(cout, fib, postion);

    Fibonacci fib2(8);
    cout << fib2 << endl;
}

void Print1(LibMat lib, const LibMat *p1, const LibMat &r1)
{
    lib.Print();    //基类切割
    cout << endl;

    p1->Print();
    cout << endl;

    r1.Print();
}

void ch_5_8()
{
    using namespace ver2;

    Fibonacci a;
    Fibonacci b;
    a = b;

    Fibonacci c = b;
}

void ch_5_9()
{
    using namespace ver2;

    {
        Fibonacci b;
        Fibonacci *ptr = b.Clone();
        cout << ptr->WhatAmI() << endl;

        NumSequence *p = b.Clone();
        p->WhatAmI();

    }

    /* 虚函数静态解析 */
    {
//         AudioBook a("1", "2", "3");
//         Print1(a, &a, a);
    }

    {
//        NumSequence *ptr = new Fibonacci();
    }
}

//RTII
void ch_5_10()
{
    using namespace ver2;

    Fibonacci fib;
    NumSequence *ps = &fib;
//    cout << ps->WhatAmI() << endl;
//    ps->GenElems(64);
//    ps->Fibonacci::GenElems(64);   //error
#if 0
    if (typeid(*ps) == typeid(Fibonacci))
    {
        Fibonacci *p = static_cast<Fibonacci *>(ps);
        ps->WhatAmI();
    }
#endif

    if (Fibonacci *pf = dynamic_cast<Fibonacci *>(ps))
        cout << pf->WhatAmI() << endl;
}

extern void hw_5_2()
{
    using namespace ver1;

    LifoStack ls;
    string str;
    while (cin >> str && !ls.full())
    {
        ls.push(str);
    }

    cout << ls << endl;
    cout << ls.top() << endl;

    string s;
    ls.pop(s);
    cout << s << endl;
    ls.peek(ls.top() - 1, s);
    cout << s << endl;
}

}
