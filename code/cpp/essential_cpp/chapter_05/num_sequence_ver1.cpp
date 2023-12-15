
#include <iostream>

#include "num_sequence_ver1.h"

using namespace std;

namespace chapter_05
{

namespace ver1
{

std::ostream& operator<<(std::ostream &os, const NumSequence &ns)
{
    cout << " ( " << ns.Length() << ", " << ns.BegPos() << " ) ";
    return  ns.Print(os);
}

bool NumSequence::CheckIntegrity(int pos, int size) const
{
    if (pos <=0 || pos >= max_elems_)
    {
        cerr << "invalid position: " << pos << endl;
        return false;
    }

    if (pos > size)
        GenElems(pos);  //

    return true;
}

}

}
