
#include "ch_13.hpp"
#include "chapter_13.h"
#include "employee.h"
#include "has_ptr.h"
#include "str_vec.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

void ch_13()
{
    /* 拷贝、赋值与销毁 */
    ch_13_1();
}

void ch_13_1()
{
    /* 拷贝构造函数 */
    //ch_13_1_1();
    //hw_13_4();

    hw_13_17();
}

void ch_13_1_1()
{
    /* 编译器可以绕过拷贝构造函数 */
    {
        //string null_book = "9-99-999-9999";
        string null_book("9-99-999-9999");

//        string tmp = "9-99-999-9999";
//        string null_book = tmp;
    }
}

Point foo_bar(Point arg)
{
    Point *head = new Point(arg);
    Point pa[4] = {arg, *head};
    return *head;
}

void hw_13_4()
{
    Point arg;
    foo_bar(arg);
}

void F1(X x){}
void F2(X &x){}

void hw_13_13()
{
    X object;
    cout << endl;

    {
        cout << "call func by pass value" << endl;
        F1(object);
        cout << endl;
    }

    {
        cout << "call func by pass refrence" << endl;
        F2(object);
        cout << endl;
    }

    {
        cout << "malloc " << endl;
        X *p = new X;
        delete p;
        cout << endl;
    }

    {
        cout << "vector push back val" << endl;
        vector<X> vec;                  //vec析构的时候,会析构里边的对象
        vec.push_back(object);
        cout << endl;
    }

    {
        cout << "create new object by copy construct func" << endl;
        X y = object;
        cout << endl;
    }

    {
        cout << "assign value" << endl;
        X new_val;
        new_val = object;
        cout << endl;
    }

    cout << "end" << endl;
}

void f1(Numbered s){cout << s.my_sn_ << endl;}
void f2(const Numbered &s){cout << s.my_sn_ << endl;}

void hw_13_17()
{
    Numbered a, b = a, c = b;   // 0 1 2
    f1(a);
    f1(b);
    f1(c);
    cout << endl;
    f2(a);
    f2(b);
    f2(c);
}

/* 13.1.6 阻止拷贝*/
void ch_13_1_2()
{
    GZNoCopy no_object;
    //GZNoCopy no_object2 = no_object;
    GZNoCopy no_object3;
    //no_object3 = no_object;

    //GZNoDtor no_dtor;
    //GZNoDtor *no_dtor_ptr = new GZNoDtor;
    //delete no_dtor_ptr;

    GZPrivateCopy pri_object;
    //GZPrivateCopy pri_object2 = pri_object;

    //GZPrivateCopy pri_object3;
    //pri_object3 = pri_object;
}

void hw_13_18()
{
    GZEmployee a("a"), b = a, c;
    c = b;

    PrintGZEmployee(a);
    PrintGZEmployee(b);
    PrintGZEmployee(c);
}

/***************************************************************/
/***************************13.2********************************/

void hw_13_22()
{
    HasPtr h1("hi");
    HasPtr h2(h1);
    HasPtr h3 = h1;

    *h2 = "nihao";
    *h3 = "hello";

    cout << "h1: " << *h1 << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    cout << endl;

    swap(h2, h3);
    cout << "h1: " << *h1 << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
}

/***************************************************************/
/***************************13.3********************************/

class GZFoo
{
    friend void swap(GZFoo &lhs, GZFoo &rhs);
public:
    explicit GZFoo(const string &s) : s_(s), hp_(s) {}
    string PrintVal() const { return s_; }
private:
    string s_;
    HasPtr hp_;
};

// swap调用的应该是swap，而不是std::swap
void swap(GZFoo &lhs, GZFoo &rhs)
{
    using std::swap;
    cout << "swap GZFoo object: " << lhs.PrintVal() <<
            " and " << rhs.PrintVal() << endl;
    swap(lhs.hp_, rhs.hp_);
}

void ch_13_3()
{
//    GZFoo foo1("foo1"), foo2("foo2");
//    swap(foo1, foo2);

    HasPtr h1("h1"), h2("h2");
    h1 = h2;
}

void hw_13_31()
{
    srand(time(NULL));
    vector<HasPtr> vec;

    for (int i = 0; i != 10; ++i)
        vec.push_back(to_string(rand() % 1000));

    for (auto &it : vec)
        cout << *it << " ";
    cout << endl;

    sort(vec.begin(), vec.end());
    for (auto &it : vec)
        cout << *it << " ";

}

/***************************************************************/
/***************************13.6********************************/

// 编译器会为GZX和GZhasX合成移动构造函数
struct GZX
{
    int     i;
    string  s;
};

struct GZhasX
{
    GZX mem;
};

struct GZY
{
    int     i;
    string  s;
    GZY(const GZY&){}
};

struct GZhasY
{
    GZhasY() = default;
    GZhasY(GZhasY &&) = default;

    GZY mem;
};

StrVec GetVec(istream &is)
{

}

class Foo
{
public:
    Foo() {cout << "construct func." << endl;}
    Foo(const Foo &rhs) { cout << "copy construct func." << endl; }

    /* 13.6.3 */
    // 右值和左值成员函数
    Foo& operator=(const Foo &) &;

    // 重载和引用函数
     Foo Sorted() &&;
     Foo Sorted() const &;
    ~Foo(){}
private:
    vector<int> data;
};

Foo& Foo::operator=(const Foo &rhs) &
{
    //
    return *this;
}

Foo Foo::Sorted() &&
{
     sort(data.begin(), data.end());
     return *this;
}

Foo Foo::Sorted() const &
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}

void ch_13_6_2()
{
    //
//    StrVec sv1;
//    //StrVec sv2(sv1);
//    StrVec sv3;
//    sv3 = std::move(sv1);

    // 合成移动操作
//    GZX x, x2 = std::move(x);
//    GZhasX hx, hx2 = std::move(hx);

    //GZhasY hy, hy2 = std::move(hy);

    // 移动右值,拷贝左值...
    StrVec v1, v2;
    //v1 = v2;
    //v2 = GetVec(cin);

    // 没有移动构造函数，右值被拷贝
    Foo x;
    Foo y(x);
    Foo z(std::move(x));    //Foo&& --> const Foo&
}

Foo& RetFoo()
{

}

Foo RetVal()
{

}

void ch_13_6_3()
{
    StrVec sv;
    string s = "some thing";
    sv.PushBack(s);
    sv.PushBack("other thing");

    RetFoo().Sorted();
    RetVal().Sorted();
}
