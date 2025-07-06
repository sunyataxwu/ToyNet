#ifndef __ACCELERATED_CPP_PICTURE_DERIVED_H__
#define __ACCELERATED_CPP_PICTURE_DERIVED_H__

#include <algorithm>

#include "picture_base.h"
#include "handle.hpp"

class Picture;
class FramePicture : public PictureBase
{
    friend Picture Frame(const Picture &pic);

    FramePicture(const Ptr<PictureBase> &pic, 
                char tb = '*', char lr = '*', char c = '*') 
                : p_(pic), tb_(tb), lr_(lr), c_(c){}

    wd_sz   width() const override { return p_->width() + 4; }
    ht_sz   height() const override {return  p_->height() + 4;}
    void    display(std::ostream &, ht_sz, bool) const override;

    void    reframe(char tb, char lr, char c) override;

    Ptr<PictureBase>    p_;
    char tb_, lr_, c_;
};

class VcatPicture : public PictureBase
{
    friend Picture Vcat(const Picture &l, const Picture &r);

    VcatPicture(const Ptr<PictureBase> &t, const Ptr<PictureBase> &b)
            : top_(t), bottom_(b) {}

    wd_sz   width() const override { return std::max(top_->width(), bottom_->width()); }
    ht_sz   height() const override { return top_->height() + bottom_->height(); }
    void    display(std::ostream &, ht_sz, bool) const override;

    void    reframe(char tb, char lr, char c) override
    {
        top_->reframe(tb, lr, c);
        bottom_->reframe(tb, lr, c);
    }

    Ptr<PictureBase>    top_, bottom_;
};

class HcatPicture : public PictureBase
{
    friend Picture Hcat(const Picture &l, const Picture &r);

    HcatPicture(const Ptr<PictureBase> &l, const Ptr<PictureBase> &f)
            : left_(l), right_(f) {}

    wd_sz   width() const override { return left_->width() + right_->width(); }
    ht_sz   height() const override { return std::max(left_->height(), right_->height()); }
    void    display(std::ostream &, ht_sz, bool) const override;

    void    reframe(char tb, char lr, char c) override
    {
        left_->reframe(tb, lr, c);
        right_->reframe(tb, lr, c);
    }

    Ptr<PictureBase>    left_, right_;
};

#include <string>
#include <vector>

class StringPicture : public PictureBase
{
    friend class Picture;

    StringPicture(const std::vector<std::string> &v) : data_(v) {}

    wd_sz   width() const override;
    ht_sz   height() const override { return data_.size(); }
    void    display(std::ostream &, ht_sz, bool) const override;

    void    reframe(char, char, char) override {
    /* 没框可换，留空即可 */
    }
    std::vector<std::string>    data_;
};

#endif // __ACCELERATED_CPP_PICTURE_DERIVED_H__
