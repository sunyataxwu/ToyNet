
#ifndef __ACCELERATED_CPP_GRAD_H__
#define __ACCELERATED_CPP_GRAD_H__

#include <iostream>

#include "core.h"

// plan B
// template<typename T>
// T* Clone(T*);

// plan C
template<typename T>
struct Cloner;

class Grad : public Core
{
    // plan B
    // friend Grad* ::Clone<>(Grad*);

    // plan C
    friend struct Cloner<Grad>;
public:
    Grad() : thesis_(0)     {}
    Grad(std::istream &in)  { Read(in); }
public:
    std::istream&   Read(std::istream &in);
    double          Grade() const;
    void            Regrade(double d, double d2);
    virtual bool    Less(const Core& rhs) const
    {
        const Grad* p = dynamic_cast<const Grad*>(&rhs);
        if (p)
            return Grade() < p->Grade();
        else
            return Core::Less(rhs);
    }
protected:
    Grad*           Clone() { return new Grad(*this); }
private:
    double thesis_;
};


#endif //__ACCELERATED_CPP_Grad_H__
