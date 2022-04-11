

#include "chapter_04.h"
//#include "../sales_data/sales_data.h"

#include <iostream>
#include <vector>

using std::vector;
using namespace std;

void Chapter_04()
{
    //Practice_4_2();
    //Practice_4_5();
    //Practice_4_7();
    //Practice_4_9();
    Practice_4_8();
    //Practice_4_11_2();
}

//溢出
//TODO...
void Practice_4_2()
{
    short short_value = 32767;
    short_value += 1;
    cout << "short value: " << short_value << endl;
}

/*���������*/
void Practice_4_5()
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

/*������������ȼ��ǳ���*/
void Practice_4_7()
{
    int grade = 75;
    cout << ((grade < 60) ?  "fail" : "pass");
    cout << endl;

    cout << (grade < 60) ?  "fail" : "pass";
    cout << endl;

    //cout << grade < 60 ?  "fail" : "pass";
}

void Practice_4_8()
{
    unsigned long quiz = 0;
    quiz |= 1UL << 2;
    quiz &= ~(1UL << 2);
    cout << quiz;
}

/*数组与指针的关系*/
void Practice_4_9()
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


void Practice_4_11_2()
{
    int array[5] = {0};
    cout << array << endl;
    cout << &array << endl;
    cout << &array[0] << endl;
    
    cout << &array[1] << endl;
    cout << &array[0] + 1 << endl;
    cout << &array + 1 << endl;
    cout << (&array + 1) - &array << endl;
    cout << sizeof(*array) << endl; 
}
