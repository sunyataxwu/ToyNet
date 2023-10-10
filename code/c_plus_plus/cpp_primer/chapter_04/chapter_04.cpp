

#include "chapter_04.h"

#include <iostream>
#include <vector>

using namespace std;

void ch_04()
{
    //ch_4_2();
    //ch_4_5();
    //ch_4_7();
    //ch_4_9();
    //ch_4_8();
    ch_4_11();
}

void ch_4_1()
{
    /*
     * 4.1.1 （运算符）
     * 1、组合运算符对象
     * 2、运算对象转换
     * 3、重载运算符 ---> 可改变与不可改变
     * 4、左值、右值
     *      ---> 赋值运算符、取地址运算符、解引用、下标、内置递增（减）、decltype
     */

    /*
     * 4.1.2 优先级与结合律
     * 1、括号无视优先级和结合律
     * 2、优先级与结合律有何影响 ---> 通过指针访问数组、标准输入连续输入多个变量
     */

    /*
     * 4.1.3 求值顺序
     * && || ?： ,
     * 1、求值顺序、优先级、结合律
     *      ---> 改变了一个对象的值其他地方就不要在使用这个值(这个对象是子对象除外*++iter)
     */
}
void ch_4_2()
{
    int i = 1;
    cout << -i << ", " << +i << ", " << i << endl;    //-返回的是副本
    //cout << +i << ", " << i << endl;

    short short_value = 32767;
    short_value += 1;
    cout << "short value: " << short_value << endl;
}

int get_val() { return 0; }
void ch_4_4()
{
    {
        int k = 0;
        //k = {3.14};
        k = {1024};

        vector<int> ivec;
        ivec = {0,1,2,3,4};
    }

    /* 赋值运算符优先级比较低 */
    {
        int i;
        while ((i = get_val()) != 1024)
        {
            /* code */
        }
    }
}

/*后置运算符*/
void ch_4_5()
{
    vector<int> ivec;
    int cnt = 10;
    while (cnt > 0)
        ivec.push_back(cnt--);

    auto iter = ivec.begin();
    while(iter != ivec.end())
        cout << *iter++ << endl;

    vector<int> vec(10, 0);
    cnt = vec.size();
    for (vector<int>::size_type i = 0; i != vec.size(); ++i, cnt--)
        vec[i] = cnt;
    
    auto it = vec.begin();
    while(it != vec.end())
        cout << *it++ << endl;
}

void ch_4_6()
{
    string s1 = "a string", *p = &s1;
    auto n = s1.size();
    n = (*p).size();
    //n = *p.size();
    n = p->size();
}

/*条件运算符优先级非常低*/
void ch_4_7()
{
    int grade = 75;
    cout << ((grade < 60) ?  "fail" : "pass");
    cout << endl;

//    cout << (grade < 60) ?  "fail" : "pass";
//    cout << endl;

//    cout << grade < 60 ?  "fail" : "pass";
}

void ch_4_8()
{
    unsigned long quiz = 0;
    quiz |= 1UL << 2;
    quiz &= ~(1UL << 2);
    cout << quiz;
}

/* sizeof */
void ch_4_9()
{
    int x[10];
    int *ptr = x;

    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(ptr) / sizeof(*ptr) << endl;
    cout << sizeof(ptr) << endl;

    cout << "int: " << sizeof(int) << "\n"
         << "int[3]: " << sizeof(int[3]) << "\n"
         << "int*: " << sizeof(int*) << "\n"
         << "int&: " << sizeof(int&) << endl;

    cout << "short: " << sizeof(short) << "\n"
         << "short[3]: " << sizeof(short[3]) << "\n"
         << "short*: " << sizeof(short*) << "\n"
         << "short&: " << sizeof(short&) << endl;
    /*
    cout << "SalesData: " << sizeof(SalesData) << "\n"
         << "SalesData[3]: " << sizeof(SalesData[3]) << "\n"
         << "SalesData*: " << sizeof(SalesData*) << "\n"
         << "SalesData&: " << sizeof(SalesData&) << endl;
    */
}

void ch_4_11()
{
    ch_4_11_2();

    //ch_4_11_3();
}

void ch_4_11_2()
{
    int array[5] = {0};

    {
        cout << array << endl;
        cout << &array << endl;
        cout << &array[0] << endl;
        cout << endl;
    }

    {
        cout << &array[1] << endl;
        cout << &array[0] + 1 << endl;
        cout << &array + 1 << endl;
        cout << endl;
    }

    {
        auto v1 = &array + 1;
        auto v2 = &array;
        cout << v1 - v2 << endl;
        cout << sizeof(*array) << endl;
        cout << sizeof (int) << endl;
        cout << endl;
    }

    {
        int array[2][3] = {0};
        cout << array << endl;
        cout << &array << endl;
        cout << &array[0] << endl;
        cout << &array[1] << endl;
        cout << array + 1 << endl;
        cout << &array + 1 << endl;
        cout << endl;
        cout << sizeof(**array) << endl;
        cout << sizeof(*array) << endl;
        cout << sizeof(array) << endl;
        cout << endl;
    }
}

void ch_4_11_3()
{
    /* 保证转换后指向类型与原类型相同 */
    double d = 3.14;
    void    *vpd = &d;
    //double  *dpd = static_cast<int *>(vpd);
    double  *dpd = static_cast<double *>(vpd);

    const char  *pc = "hello";
    char        *p = const_cast<char *>(pc);
    //*p = "world";     //通过p写值是未定义行为

    //string tmp = const_cast<string>(pc);
    string s = static_cast<string>(pc);
    cout << s << endl;

    int i = 1;
    int *pi = &i;
    char *ppc = reinterpret_cast<char *>(pi);
//    string tmp(ppc);
//    cout << *ppc << ", " << tmp << endl;
}
