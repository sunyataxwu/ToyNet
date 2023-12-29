
#ifndef __EFFECTIVE_CPP_ITEM_03_H__
#define __EFFECTIVE_CPP_ITEM_03_H__

#include <string.h>
#include <iostream>

class Rational{};
const Rational operator*(const Rational &lhs, const Rational &rhs);

#include <string>
class TextBook
{
private:
    std::string text_;
public:
    TextBook(const std::string &s) : text_(s) {}
    ~TextBook(){}
public:
    const char& operator[](std::size_t position) const
    {
        return text_[position];
    }

    char& operator[](std::size_t position)
    {
        //return text_[position];
        return const_cast<char &>(static_cast<const TextBook &>(*this)[position]);
    }
};

void Print(const TextBook &ctb);

class CTextBook
{
public:
    char                *ptext_;
    mutable std::size_t text_length_;
    mutable bool        length_is_valid_;
public:
    CTextBook(const char *s) : ptext_(new char[strlen(s) + 1]) 
    {
        strcpy(ptext_, s); 
        ptext_[strlen(s)] = '\0';
    } 
    ~CTextBook()
    {
        if (ptext_ != nullptr)
        {
            delete [] ptext_;
            ptext_ = nullptr;
        }
    }

    void TestPtr() const
    {
        *ptext_ = '\0';
        //++ptext_;
    }
public:
    char& operator[](std::size_t position) const
    {
        return ptext_[position];
    }
public:
    std::size_t Length() const
    {
        if (!length_is_valid_)
        {
            text_length_ = strlen(ptext_);
            length_is_valid_ = true;
        }

        return text_length_;
    }
};

#endif // __EFFECTIVE_CPP_ITEM_03_H__
