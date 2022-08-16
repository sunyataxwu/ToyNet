

#ifndef __CPP_PRIMER_CHAPTER_13_STR_VEC_H__
#define __CPP_PRIMER_CHAPTER_13_STR_VEC_H__

#include <string>
#include <memory>

/* 13.5 ��̬�ڴ������ */
class StrVec
{
    // ����StrVec��
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &rhs);
    StrVec& operator=(const StrVec &rhs);
    ~StrVec();
public:
    void            PushBack(const std::string &s);
    size_t          Size()  const { return first_free - elements; }
    size_t          Capacity() const { return cap - elements; }
    std::string*    Begin() const { return elements; }
    std::string*    End() const { return first_free; }
private:
    static std::allocator<std::string> alloc;

    std::string *elements;
    std::string *first_free;
    std::string *cap;
private:
    void CheckAlloc() { if (Size() == Capacity()) Reallocate(); }

    std::pair<std::string*, std::string*>
    AllocCopy(const std::string *beg, const std::string *end);
    void Free();
    void Reallocate();
public:
    // homework 13.40
    StrVec(const std::initializer_list<std::string> &il);
public:
    /* 13.6 */
    StrVec(StrVec &&rhs) noexcept;
    // �ƶ���ֵ�����
    StrVec& operator=(StrVec &&rhs) noexcept;
public:
    /* 13.6.3 ��ֵ���úͳ�Ա���� */
    void PushBack(std::string &&);

    /* 14.4 */
    StrVec& operator=(const std::initializer_list<std::string> &il);

public:
    // homework14.26
    std::string& operator[](std::size_t n) { return elements[n]; }
    const std::string& operator[](std::size_t n) const { return elements[n]; }

public:
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec &lhs, const StrVec &rhs);



public:
    void Reserve(size_t n);
    void Resize(size_t n);
    void Resize(size_t n, const std::string &s);
private:

    void Reallocate(size_t n);
};

// homework14.16
bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);

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
