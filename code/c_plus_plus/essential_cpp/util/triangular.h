

#ifndef __ESSENTIAL_CPP_UTIL_TRIANGULAR_H__
#define __ESSENTIAL_CPP_UTIL_TRIANGULAR_H__

#include <string>
#include <vector>
#include <iostream>
//#include "triangular_iterator.h"

class TriangularIterator;
class Triangular
{
private:
    int             beg_pos_;
    int             length_;
    mutable int     next_;
public:
    Triangular(int len, int bp);
    Triangular(int len);
    Triangular(const Triangular &rhs);

public:
    int Length() const { return length_; }
    int BegPos() const { return beg_pos_; }
    int Elem(int pos) const { return elems_[pos - 1]; }

    void NextReset() const { next_ = beg_pos_ - 1; }
    bool Next(int &val) const;
public:
    friend std::ostream &operator<<(std::ostream &os, const Triangular &rhs);
    friend class TriangularIterator;
    typedef  TriangularIterator Iterator;

    Triangular& operator=(const Triangular &rhs);
public:


    void Length(int len) { length_ = len; }
    void BegPos(int pos) { beg_pos_ = pos; }


    Iterator Begin() const;// { return Iterator(beg_pos_); }
    Iterator End() const;// { return  Iterator(beg_pos_ + length_); }
public:
    static bool IsElem(int val);
    static void GenElements(int length);
    static void GenElemsToValue(int value);
    static void Display(int len, int bp, std::ostream &os = std::cout);

    /* 可以避免友元 */
    //static int max_size() { return max_size; }
    static int elem_size() { return elems_.size(); }
private:
    //static const int max_size = 1024;
    enum { max_size = 1024 };
    static std::vector<int>    elems_;
};

std::ostream &operator<<( std::ostream &os, const Triangular &rhs );
int Sum(const Triangular &item);

#endif // __ESSENTIAL_CPP_UTIL_TRIANGULAR_H__
