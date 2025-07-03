
#ifndef __ACCELERATED_CPP_GRAD_H__
#define __ACCELERATED_CPP_GRAD_H__

#include <iostream>

#include "core.h"

class Grad : public Core
{
public:
    Grad() : thesis_(0)     {}
    Grad(std::istream &in)  { Read(in); }
public:
    std::istream&   Read(std::istream &in);
    double          Grade() const;
    void            Regrade(double d, double d2);
protected:
    Grad*           Clone() { return new Grad(*this); }
private:
    double thesis_;
};


#endif //__ACCELERATED_CPP_Grad_H__
