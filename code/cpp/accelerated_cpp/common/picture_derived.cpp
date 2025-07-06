
#include <algorithm>
#include <string>

#include "picture_derived.h"
#include "picture_base.h"

using namespace std;

void FramePicture::display(std::ostream& os,
                           ht_sz row, bool do_pad) const
{
    if (row >= height()) {
        if (do_pad) Pad(os, 0, width());
        return;
    }

    if (row == 0 || row == height() - 1) {                 // 顶 / 底 边
        os << c_ << std::string(width() - 2, tb_) << c_;
    } else if (row == 1 || row == height() - 2) {          // 第二 / 倒数第二行
        os << lr_;
        Pad(os, 1, width() - 1);
        os << lr_;
    } else {                                               // 正文
        os << lr_ << ' ';
        p_->display(os, row - 2, true);
        os << ' ' << lr_;
    }
}


void FramePicture::reframe(char tb, char lr, char c)
{
    // ① 自己换装
    tb_ = tb;
    lr_ = lr;
    c_  = c;

    // ② 继续向内层传播
    p_->reframe(tb, lr, c);
}

void VcatPicture::display(std::ostream &os, ht_sz row, bool do_pad) const
{
    // wd_sz w = 0;
    // if (row < top_->height())
    // {
    //     top_->display(os, row, da_pad);
    //     w = top_->width();
    // }
    // else
    // {
    //     bottom_->display(os, row - top_->height(), da_pad);
    //     w = bottom_->width();
    // }

    // if (da_pad) Pad(os, w, width());

    wd_sz top_w = top_->width();
    wd_sz bot_w = bottom_->width();
    wd_sz total_w = std::max(top_w, bot_w);

    if (row < top_->height()) {
        // top 区域
        wd_sz pad = (total_w - top_w) / 2;
        Pad(os, 0, pad);
        top_->display(os, row, do_pad);
        if (do_pad)
            Pad(os, pad + top_w, total_w); // 补右边空格
    } else {
        // bottom 区域
        ht_sz bottom_row = row - top_->height();
        if (bottom_row < bottom_->height()) {
            wd_sz pad = (total_w - bot_w) / 2;
            Pad(os, 0, pad);
            bottom_->display(os, bottom_row, do_pad);
            if (do_pad)
                Pad(os, pad + bot_w, total_w);
        } else if (do_pad) {
            Pad(os, 0, total_w); // 超出高度的行，整行空格
        }
    }
}

void HcatPicture::display(std::ostream &os, ht_sz row, bool do_pad) const 
{
    // left_->display(os, row, do_pad || row < right_->height());
    // right_->display(os, row, do_pad);
    // 找出较高图和较矮图
    // ① 高度
    ht_sz lh = left_->height();
    ht_sz rh = right_->height();

    // ② 判定哪幅矮
    bool left_shorter = lh < rh;
    ht_sz  tall_h  = left_shorter ? rh : lh;
    ht_sz  short_h = left_shorter ? lh : rh;
    ht_sz  pad_top = (tall_h - short_h) / 2;

    // --- 左边输出 ---
    if (left_shorter) {                   // 左图是矮的
        if (row < pad_top || row >= pad_top + lh) {
            if (do_pad) Pad(os, 0, left_->width());
        } else {
            left_->display(os, row - pad_top, do_pad);
        }
    } else {                              // 左图是高的
        if (row < lh)
            left_->display(os, row, do_pad);
        else if (do_pad)
            Pad(os, 0, left_->width());
    }

    // --- 右边输出 ---
    if (!left_shorter) {                  // 右图是矮的
        if (row < pad_top || row >= pad_top + rh) {
            if (do_pad) Pad(os, 0, right_->width());
        } else {
            right_->display(os, row - pad_top, do_pad);
        }
    } else {                              // 右图是高的
        if (row < rh)
            right_->display(os, row, do_pad);
        else if (do_pad)
            Pad(os, 0, right_->width());
    }
}

StringPicture::ht_sz StringPicture::width() const
{
    PictureBase::wd_sz n = 0;
    for (PictureBase::ht_sz i = 0; i != data_.size(); ++i) 
    {
        n = max(n, data_[i].size());
    }

    return n;
}

void StringPicture::display(ostream &os, ht_sz row, bool do_pad) const
{
    wd_sz start = 0;
    if (row < height())
    {
        os << data_[row];
        start = data_[row].size();
    }

    if (do_pad) Pad(os, start, width());
}