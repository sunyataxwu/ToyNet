
#include "gz_window_mgr.h"

using namespace std;

/***************************7.3.4*********************************/
void GZWindowMgr::Clear(ScreenIndex i)
{
    GZScreen &s = screens_[i];
    s.contents_ = string(s.height_ * s.width_, ' ');
}

/*****************************************************************/
/***************************7.4*********************************/

GZWindowMgr::ScreenIndex GZWindowMgr::AddScreen(const GZScreen &s)
{
    screens_.push_back(s);
    return screens_.size() - 1;
}
