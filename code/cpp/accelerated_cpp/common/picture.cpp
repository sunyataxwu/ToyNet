#include "picture.h"
#include "picture_base.h"

using namespace std;

ostream& operator<<(ostream &os, const Picture &pic)
{
    const PictureBase::ht_sz ht = pic.p_->height();
    for (PictureBase::ht_sz i = 0; i != ht; ++i) 
    {
        pic.p_->display(os, i, false);
        os << endl;
    }

    return os;
}