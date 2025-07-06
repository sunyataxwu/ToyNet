
#ifndef __ACCELERATED_CPP_PICTURE_H__
#define __ACCELERATED_CPP_PICTURE_H__

#include <vector>
#include <string>

#include "picture_derived.h"
#include "handle.hpp"
#include "picture_base.h"

class Picture
{
    friend Picture Frame(const Picture &pic);
    friend Picture Hcat(const Picture &l, const Picture &r);
    friend Picture Vcat(const Picture &l, const Picture &r);

    friend std::ostream& operator<<(std::ostream &os, const Picture &pic);
public:
    Picture(const std::vector<std::string> &vs = std::vector<std::string>())
            : p_(new StringPicture(vs)){}
    Picture(PictureBase *ptr) : p_(ptr) {}

    void reframe(char tb = '*', char lr = '*', char c = '*')
    { p_->reframe(tb, lr, c); }
private:
    Ptr<PictureBase> p_;
};

inline Picture Frame(const Picture &pic)
{
    return new FramePicture(pic.p_);
}

inline Picture Hcat(const Picture &l, const Picture &r)
{
    return new HcatPicture(l.p_, r.p_);
}

inline Picture Vcat(const Picture &l, const Picture &r)
{
    return new VcatPicture(l.p_, r.p_);
}

#include <ostream>

std::ostream& operator<<(std::ostream &os, const Picture &pic);

#endif // __ACCELERATED_CPP_PICTURE_H__
