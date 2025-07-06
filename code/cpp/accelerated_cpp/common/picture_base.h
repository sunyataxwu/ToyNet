
#ifndef __ACCELERATED_CPP_PICTURE_BASE_H__
#define __ACCELERATED_CPP_PICTURE_BASE_H__

#include <ostream>
#include <vector>
#include <string>
#include <iostream>

class Picture;

class PictureBase
{
    friend std::ostream& operator<<(std::ostream &os, const Picture &);
    friend class FramePicture;
    friend class VcatPicture;
    friend class HcatPicture;
    friend class StringPicture;


    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type              wd_sz;

    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream &, ht_sz, bool) const = 0;
public:
    virtual void reframe(char tb, char lr, char c) = 0;
public:
    virtual ~PictureBase() = default;
protected:
    static void Pad(std::ostream &os, wd_sz beg, wd_sz end)
    {
        while (beg != end)
        {
            os << " ";
            ++beg;
        }
    }
};

#endif // __ACCELERATED_CPP_PICTURE_BASE_H__
