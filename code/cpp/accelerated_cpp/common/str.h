
#ifndef __ACCELERATED_CPP_STR_H__
#define __ACCELERATED_CPP_STR_H__

#include "str_util.h"
#include "vec.hpp"

#include <cctype>
#include <cstddef>
#include <ios>
#include <iostream>
#include <algorithm>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>
#include <string.h>
#include <vector>

namespace ver1 
{

class Str
{
    friend std::ostream& operator<<(std::ostream &, const Str&);
    friend std::istream& operator>>(std::istream &, Str &);
public:
    typedef Vec<char>::size_type size_type;

    Str(){}
    Str(size_type n, char c) : data_(n, c){}
    Str(const char *cp) { std::copy(cp, cp + strlen(cp), std::back_inserter(data_)); }

    template<typename In>
    Str(In b, In e) { std::copy(b, e, std::back_inserter(data_)); }
public:
    char& operator[](size_type i) { return data_[i]; }
    const char& operator[](size_type i) const { return data_[i]; }

    size_type Size() const { return data_.Size(); }
public:
    char* c_str();
    char* data() { return data_.Begin(); }
public:
    Str& operator+=(const Str &s)
    {
        std::copy(s.data_.Begin(), s.data_.End(), std::back_inserter(data_));
        return *this;
    }

    operator void*()
    {
        return data_.Begin();
    }
private:
    Vec<char>   data_;
};

std::ostream& operator<<(std::ostream &, const Str&);
std::istream& operator>>(std::istream &, Str &);
Str operator+(const Str &lhs, const Str &rhs);

}

namespace ver2
{

class Str
{
public:
    using size_type         = std::size_t;
    using iterator          = char*;
    using const_iterator    = const char*;
public:
    Str()                       { Create(0, '\0'); }
    Str(size_type n, char c)    { Create(n, c); }
    template<typename In>
    Str(In beg, In end)         { Create(beg, end); }
    Str(const char *cp)         { Create(cp, cp + strlen(cp)); }
    Str(const Str &s)           { Create(s.Begin(), s.End()); }
    ~Str()                      { Uncreate(); }

    Str& operator=(const Str &rhs)
    {
        if (this != &rhs)
        {
            Uncreate();
            Create(rhs.Begin(), rhs.End());
        }
        return *this;
    }

    Str& operator+=(const Str &rhs)
    {
        size_type new_size = Size() + rhs.Size();
        char* new_ch_ptr = alloc.allocate(new_size);
        std::uninitialized_copy(Begin(), End(), new_ch_ptr);
        std::uninitialized_copy(rhs.Begin(), rhs.End(), new_ch_ptr + Size());
        alloc.construct(new_ch_ptr + new_size, '\0');

        Uncreate();
        length_ = new_size + 1;
        ch_ptr = new_ch_ptr;
        return *this;
    }

    Str& operator+=(const char *s) { return *this += Str(s); }

    explicit operator bool() const { return Size() != 0; }
public:
    iterator        Begin()         { return ch_ptr; }
    const_iterator  Begin() const   { return ch_ptr; }
    iterator        End()           { return ch_ptr + length_; }
    const_iterator  End() const     { return ch_ptr + length_; }

    size_type       Size() const    { return length_ ? length_ - 1 : 0;}
public:
    char&       operator[](size_type i)         { return ch_ptr[i]; }
    const char& operator[](size_type i) const   { return ch_ptr[i]; }
public:
    const char* c_str() const { return ch_ptr; }
    const char* data()  const { return ch_ptr; }
public:
    size_type Copy(char *s, size_type n, size_type pos = 0);
public:
    Str& assgin(const Str &s) { if (this != &s) { Uncreate(); Create(s.Begin(), s.End()); } return *this; }
    Str& assgin(const char *s) { return assgin(Str(s)); }
    Str& assgin(size_type n, char c) { return  assgin(Str(n ,c)); }
public:
    Str& insert(size_type pos, const Str& s);
    Str& insert(size_type pos, const char* s) { return insert(pos, Str(s)); }
public:
    void Create(size_type n, char c);
    template<typename In>
    void Create(In beg, In end)
    {
        length_ = static_cast<size_type>(std::distance(beg, end) + 1);
        ch_ptr = alloc.allocate(length_);
        std::uninitialized_copy(beg, end, ch_ptr);
        alloc.construct(ch_ptr + length_ - 1, '\0');
    }
    void Uncreate();
private:
    size_type               length_ = 0;
    char                    *ch_ptr = nullptr;
    std::allocator<char>    alloc;
};

inline Str operator+(Str &lhs, const Str &rhs) { return lhs += rhs; }
inline Str operator+(Str &lhs, const char *rhs) { return lhs += Str(rhs); }
inline Str operator+(const char *s, const Str &rhs) { return Str(s) += rhs; }
inline bool operator<(const Str &lhs, const Str &rhs){ return strcmp(lhs.c_str(), rhs.c_str()) < 0; }
inline bool operator>(const Str &lhs, const Str &rhs){ return lhs < rhs; }
inline bool operator==(const Str &lhs, const Str &rhs) { return strcmp(lhs.c_str(), rhs.c_str()) == 0; }
inline bool operator!=(const Str &lhs, const Str &rhs) { return !(lhs == rhs); }
inline bool operator>=(const Str &lhs, const Str &rhs){ return !(lhs < rhs); }
inline bool operator<=(const Str &lhs, const Str &rhs){ return !(lhs > rhs); }

inline std::istream& operator>>(std::istream &is, Str &s)
{
    s.Uncreate();

    char c;
    while (is.get(c) && std::isspace(c));

    if (is)
    {
        std::vector<char> buf;
        do{
            buf.push_back(c);
        } while(is.get(c) && !std::isspace(c));

        if (is) is.unget();
        s.Create(buf.begin(), buf.end());
    }
    return is;
}

#include <iterator>

inline std::ostream& operator<<(std::ostream &os, const Str &s)
{
    // return os.write(s.data(), static_cast<std::streamsize>(s.Size()));
    std::copy(s.Begin(), s.End(), std::ostream_iterator<char>(os));
    return os;
}

inline std::istream& getline(std::istream &is, Str &s)
{
    s.Uncreate();

    std::vector<char> buf;
    char c;
    while (is.get(c))
    {
        if (c == '\n') break;
        buf.push_back(c);
    }

    if (!is && buf.empty()) return is;
    s.Create(buf.begin(), buf.end());
    return is;
}

}


#include "handle.hpp"

namespace ver3
{

class Str
{
    friend std::ostream& operator<<(std::ostream &, const Str&);
    friend std::istream& operator>>(std::istream &, Str &);
public:
    typedef Vec<char>::size_type size_type;

    Str() : data(new Vec<char>){}
    Str(size_type n, char c) : data(new Vec<char>(n, c)){}
    Str(const char *cp) : data(new Vec<char>) { std::copy(cp, cp + strlen(cp), std::back_inserter(*data)); }
    template<typename In>
    Str(In b, In e) : data(new Vec<char>) { std::copy(b, e, std::back_inserter(*data)); }
    Str& operator=(const Str &rhs)
    {
        data.make_unique();
        std::copy(rhs.data->Begin(), rhs.data->End(), std::back_inserter(*data));
        return *this;
    }
public:
    char& operator[](size_type i)
    {
        data.make_unique();
        return (*data)[i];
    }
    const char& operator[](size_type i) const { return (*data)[i]; }

    size_type Size() const { return data->Size(); }

    operator void*()
    {
        return (*data).Begin();
    }
private:
    Ptr<Vec<char>>   data;
};

}

#endif //__ACCELERATED_CPP_STR_H__
