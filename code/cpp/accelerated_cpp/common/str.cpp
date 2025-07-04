
#include "str.h"
#include <algorithm>
#include <memory>
#include <stdexcept>

namespace ver1 
{

std::ostream& operator<<(std::ostream &os, const Str &item)
{
    for (Str::size_type i = 0; i != item.Size(); ++i)
        os << item[i];

    return os;
}

std::istream& operator>>(std::istream &in, Str &item)
{
    item.data_.Clear();

    char c;
    while(in.get(c) && isspace(c));

    if (in)
    {
        do
        {
            item.data_.push_back(c);
        } while (in.get(c) && !isspace(c));

        if (in)
            in.unget();//
    }

    return in;
}

Str operator+(const Str &lhs, const Str &rhs)
{
    Str s = lhs;
    s += rhs;
    return s;
}

char* Str::c_str()
{
    *(data_.End()) = '\0';
    return data_.Begin();
}

}

namespace ver2
{

void Str::Create(size_type n, char c)
{
    length_ = n + 1;
    ch_ptr = alloc.allocate(length_);
    std::uninitialized_fill_n(ch_ptr, n, c);
    alloc.construct(ch_ptr + n, '\0');
}

void Str::Uncreate()
{
    if (ch_ptr)
    {
        iterator it = ch_ptr + length_;
        while (it != ch_ptr)
            alloc.destroy(it);

        alloc.deallocate(ch_ptr, length_);
    }

    ch_ptr = nullptr;
    length_ = 0;
}

Str::size_type Str::Copy(char *s, size_type n, size_type pos)
{
    if (pos > Size())
        throw std::out_of_range("Str::Copy: pos > Size()");

    size_type cnt = std::min(n, Size() - pos);
    std::copy(ch_ptr + pos, ch_ptr + pos + cnt, s);
    return cnt;
}

Str& Str::insert(size_type pos, const Str& s)
{
    if (pos > Size()) throw std::out_of_range("Str::insert pos > size!");
    if (s.Size() == 0) return *this;

    size_type new_len = Size() + s.Size();
    char *new_chars = alloc.allocate(new_len);
    std::uninitialized_copy(Begin(), Begin() + pos, new_chars);
    std::uninitialized_copy(s.Begin(), s.End(), new_chars + pos);
    std::uninitialized_copy(Begin() + pos, End(), new_chars + pos + s.Size());
    alloc.construct(new_chars + new_len, '\0');

    Uncreate();
    ch_ptr = new_chars;
    length_ = new_len + 1;
    return *this;
}

}