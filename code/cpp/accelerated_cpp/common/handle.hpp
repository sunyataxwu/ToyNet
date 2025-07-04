
#ifndef __ACCELERATED_CPP_HANDLE_H__
#define __ACCELERATED_CPP_HANDLE_H__

#include <stdexcept>

/*值版本*/
template <typename T>
class Handle
{
public:
    Handle() : p_(0)        {}
    Handle(T *p) : p_(p)    {}

    Handle(const Handle &rhs)
            : p_(0)         { if (rhs.p_) p_ = rhs.p_->Clone(); }
    Handle& operator=(const Handle &rhs);

    ~Handle()               { delete p_; }
public:
    operator    bool() const { return p_; }
    T&          operator*() const;
    T*          operator->() const;
private:
    T* p_;
};

template<typename T>
Handle<T>& Handle<T>::operator=(const Handle &rhs)
{
    if (&rhs != this)
    {
        delete p_;
        p_ = rhs.p_ ? rhs.p_->Clone() : 0;
    }

    return *this;
}

template<typename T>
T& Handle<T>::operator*() const
{
    if (p_)
        return *p_;

    throw std::runtime_error("unbound Handle.");
}

template<typename T>
T* Handle<T>::operator->() const
{
    if (p_)
        return p_;

    throw std::runtime_error("unbound Handle.");

}

/*引用计数版*/
template <typename T>
class RefHandle
{
public:
    RefHandle() : ref_ptr_(new size_t(1)), p_(0) {}
    RefHandle(const RefHandle &rhs) : ref_ptr_(rhs.ref_ptr_), p_(rhs.p_)
    {
        ++*ref_ptr_;
    }
    RefHandle& operator=(const RefHandle &rhs);
    RefHandle(T *p) : ref_ptr_(new size_t(1)), p_(p) {}
    ~RefHandle();
public:
    operator bool() const { return p_; }
    T& operator*() const;
    T* operator->() const;
private:
    size_t      *ref_ptr_;
    T           *p_;
};

template <typename T>
RefHandle<T>& RefHandle<T>::operator=(const RefHandle& rhs)
{
    if (this != &rhs) 
    {                                       // 先挡住自赋值
        ++*rhs.ref_ptr_;                    // ① 右侧计数 +1
        if (--*ref_ptr_ == 0)
        {                                   // ② 左侧旧计数 -1
            delete p_;
            delete ref_ptr_;
        }
        ref_ptr_ = rhs.ref_ptr_;            // ③ 共享同一计数器
        p_       = rhs.p_;
    }
    return *this;
}


template<typename T>
T& RefHandle<T>::operator*() const
{
    if (p_)
        return *p_;
    
    throw std::runtime_error("unbound RefHandle.");
}

template<typename T>
T* RefHandle<T>::operator->() const
{
    if (p_)
        return p_;
    
    throw std::runtime_error("unbound RefHandle.");

}

template<typename T>
RefHandle<T>::~RefHandle()
{
    if (--*ref_ptr_ == 0)
    {
        delete ref_ptr_;
        delete p_;
    }
}

#include "vec.hpp"

//plan C
template<typename T>
struct Cloner
{
    static T* call(T* p)
    {          // 唯一能摸到 protected Clone 的地方
        return p->Clone();
    }
};

template <class T>
T* Clone(T* tp)
{
    // return tp ? new T(*tp) : nullptr;        // plan A
    // return tp->Clone();                   // plab B
    return tp ? Cloner<T>::call(tp) : nullptr;    // plan C
}

/* 这里的plab B、C主要是应对Clone成员函数为protected权限，其实可以使用public权限就没有这么复杂
 * plan A是最友好的解决方案，B、C比较麻烦，需要在基类与派生类都添加友元声明（Core与Grad类）
 * 所以，最好的解决办法是成员函数Clone访问权限为public或者使用plan A
 * 使用plan A还有一种好处是相对plan B不用使用下方的特化函数
 */

/*tips: inline必须加否则会导致重定义，第二种解决办法是头文件声明，实现文件定义*/
template <>
inline Vec<char>* Clone(Vec<char>* vp)
{
    return new Vec<char>(*vp);
}

template <typename T>
class Ptr
{
public:
    Ptr() : ref_ptr_(new size_t(1)), p_(0) {}
    Ptr(T *p) : ref_ptr_(new size_t(1)), p_(p) {}
    Ptr(const Ptr &rhs) : ref_ptr_(rhs.ref_ptr_), p_(rhs.p_) { ++*ref_ptr_; }
    Ptr& operator=(const Ptr &rhs);
    ~Ptr();
public:
    operator    bool() const { return p_; }
    T&          operator*() const;
    T*          operator->() const;
public:
    void make_unique()
    {
        if (*ref_ptr_ != 1)
        {
            --*ref_ptr_;
            ref_ptr_ = new size_t(1);
            //p_ = p_ ? p_->Clone() : 0;
            p_ = p_ ? Clone(p_) : 0;
        }
    }
private:
    size_t      *ref_ptr_;
    T           *p_;
};

template<typename T>
Ptr<T>& Ptr<T>::operator=(const Ptr &rhs)
{
    if (this != &rhs) 
    {                                       // 先挡住自赋值
        ++*rhs.ref_ptr_;                    // ① 右侧计数 +1
        if (--*ref_ptr_ == 0)
        {                                   // ② 左侧旧计数 -1
            delete p_;
            delete ref_ptr_;
        }
        ref_ptr_ = rhs.ref_ptr_;            // ③ 共享同一计数器
        p_       = rhs.p_;
    }
    return *this;
}

template<typename T>
T& Ptr<T>::operator*() const
{
    if (p_) return *p_;
    throw std::runtime_error("unbound Ptr.");
}

template<typename T>
T* Ptr<T>::operator->() const
{
    if (p_) return p_;
    throw std::runtime_error("unbound Ptr.");
}

template<typename T>
Ptr<T>::~Ptr()
{
    if (--*ref_ptr_ == 0)
    {
        delete ref_ptr_;
        delete p_;
    }
}

#endif // __ACCELERATED_CPP_HANDLE_H__
