
#include "item_07.h"
#include <iostream>

using namespace std;
using namespace effective_item_07;

void Item07()
{
    cout << "**********item 07**********" << endl;
#if 1
    //TimeKeeper *tk = new TimeKeeper();
    //delete tk;

    TimeKeeper *tk2 = new AtomicClock();
    delete tk2;
#endif
#if 0
    // ��������������������Ϊ�麯��--->����
    cout << "Point size: " << sizeof (Point) << endl;
#endif
    cout << "***************************" << endl;
}

namespace effective_item_07 {

TimeKeeper* GetTimeKeeper()
{
    static TimeKeeper stk;
    return &stk;
}

}

