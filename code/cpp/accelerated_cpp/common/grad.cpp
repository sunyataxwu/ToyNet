
#include <algorithm>

#include "grad.h"

std::istream& Grad::Read(std::istream &in)
{
    ReadCommon(in);
    // ReadHw(in, homework_);

    if (in) in >> thesis_;

    return in;
}

double Grad::Grade() const
{
    return std::min(Core::Grade(), thesis_);
}

void Grad::Regrade(double d, double d2)
{
    Core::Regrade(d);
    thesis_ = d2;
}