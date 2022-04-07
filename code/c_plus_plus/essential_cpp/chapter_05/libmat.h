

#ifndef __ESSENTIAL_CPP_CHAPTER_04_LIBMAT_H__
#define __ESSENTIAL_CPP_CHAPTER_04_LIBMAT_H__

#include <iostream>

class LibMat
{
public:
    LibMat() { std::cout << "LibMat::LibMat() default constructor!\n"; }
    virtual ~LibMat() { std::cout << "LibMat::~LibMat() default destructor!\n"; }
public:
    virtual void Print() const { std::cout << "LibMat::Print() -- i am a LibMat object!\n"; }
};

void Print(const LibMat &mat);

#endif // __ESSENTIAL_CPP_CHAPTER_04_LIBMAT_H__
