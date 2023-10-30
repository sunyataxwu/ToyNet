

#ifndef __ESSENTIAL_CPP_FIBONACCI_VER2_H__
#define __ESSENTIAL_CPP_FIBONACCI_VER2_H__

#include <vector>

#include "num_sequence_ver2.h"

namespace chapter_05
{
namespace ver2
{

class Fibonacci : public NumSequence
{
public:
    Fibonacci(int len = 1, int beg = 1);
    Fibonacci(const Fibonacci &rhs);
    Fibonacci& operator=(const Fibonacci &rhs);
public:
    Fibonacci* Clone() { return new Fibonacci(*this); } // ���ÿ�������
    // const char* WhatAmI() const { return "fibonacci"; }
protected:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
};

}
}
#endif // __ESSENTIAL_CPP_FIBONACCI_VER2_H__
