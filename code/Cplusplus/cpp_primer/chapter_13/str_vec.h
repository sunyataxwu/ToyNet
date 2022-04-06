

#ifndef __CPP_PRIMER_CHAPTER_13_STR_VEC_H__
#define __CPP_PRIMER_CHAPTER_13_STR_VEC_H__

#include <string>
#include <memory>

class StrVec
{
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<std::string> &il);
    StrVec(const StrVec &rhs);
    StrVec(StrVec &&rhs) noexcept;
    StrVec& operator=(const StrVec &rhs);
    StrVec& operator=(const std::initializer_list<std::string> &il);
    StrVec& operator=(StrVec &&rhs) noexcept;
    ~StrVec();
public:
    std::string& operator[](std::size_t n) { return elements[n]; }
    const std::string& operator[](std::size_t n) const { return elements[n]; }
public:
    void PushBack(const std::string &s);
    size_t Size() const { return first_free - elements; }
    size_t Capacity() const { return cap - elements; }
    std::string* Begin() const { return elements; }
    std::string* End() const { return first_free; }

    void Reserve(size_t n);
    void Resize(size_t n);
    void Resize(size_t n, const std::string &s);
private:
    void Reallocate();
    void Reallocate(size_t n);
    void CheckAlloc() {if (Size() == Capacity()) Reallocate(); }
    void Free();
    std::pair<std::string*, std::string*> AllocCopy(const std::string *beg, const std::string *end);
private:
    static std::allocator<std::string> alloc;

    std::string *elements;
    std::string *first_free;
    std::string *cap;
};


// bool operator==(const StrVec &lhs, const StrVec &rhs)
// {
//     if (lhs.Size() != rhs.Size())
//         return false;

//     for (auto iter1 = lhs.Begin(), iter2 = rhs.Begin();
//          iter1 != lhs.End() && iter2 != rhs.End(); iter1++, iter2)
//     {
//         if (*iter1 != *iter2)
//             return false;
//     }
    
//     return true;
// }

// bool operator!=(const StrVec &lhs, const StrVec &rhs)
// {
//     return !(lhs == rhs);
// }

// bool operator<(const StrVec &lhs, const StrVec &rhs)
// {
//     auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
//     for (;
//          ps1 != lhs.End() && ps2 != rhs.End();
//         ps1++, ps2++)
//     {
//         if (*ps1 < *ps2)
//             return true;
//         else
//             return false;
//     }

//     if (ps1 == lhs.End()) 
//         return true;

//     return false; 
// }

// bool operator<=(const StrVec &lhs, const StrVec &rhs)
// {
//     auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
//     for (;
//          ps1 != lhs.End() && ps2 != rhs.End();
//         ps1++, ps2++)
//     {
//         if (*ps1 < *ps2)
//             return true;
//         else
//             return false;
//     }

//     if (ps1 == lhs.End()) 
//         return true;

//     return false; 
// }

// bool operator>(const StrVec &lhs, const StrVec &rhs)
// {
//     auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
//     for (;
//          ps1 != lhs.End() && ps2 != rhs.End();
//         ps1++, ps2++)
//     {
//         if (*ps1 > *ps2)
//             return true;
//         else
//             return false;
//     }

//     if (ps1 != lhs.End() || ps2 == rhs.End()) 
//         return true;

//     return false; 
// }

// bool operator>=(const StrVec &lhs, const StrVec &rhs)
// {
//     auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
//     for (;
//          ps1 != lhs.End() && ps2 != rhs.End();
//         ps1++, ps2++)
//     {
//         if (*ps1 > *ps2)
//             return true;
//         else
//             return false;
//     }

//     if (ps2 == rhs.End()) 
//         return true;

//     return false; 
// }

#endif // __CPP_PRIMER_CHAPTER_13_STR_VEC_H__
