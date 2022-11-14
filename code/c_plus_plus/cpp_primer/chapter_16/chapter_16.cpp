

#include "chapter_16.h"
#include "../common/gz_ch_16.hpp"
#include "../common/blob.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void ch_16()
{
    /* ����ģ�� */
    ch_16_1();
}

void ch_16_1()
{
    /* ����ģ�� */
    //ch_16_1_1();
    //hw_16_4();
    hw_16_7();
}

void ch_16_1_1()
{
    /* ʵ��������ģ�� */
    {
        cout << Compare(1, 0) << endl;

        vector<int> vec1{1,2,3}, vec2{4,5,6};
        cout << Compare(vec1, vec2) << endl;
    }
}


void hw_16_4()
{
    vector<int> vec = {1, 23 ,43 ,3, 45,6,11};

    auto iter = Find(vec.begin(), vec.end(), 6);
    if (iter == vec.end())
        cout << "not find value." << endl;
    else
        cout << "find value position: " 
             << iter - vec.begin() << endl;

    list<string> lst = {"hello", "hi", "nihao"};
    auto iter1 = Find(lst.begin(), lst.end(), "!");
    if (iter1 == lst.end())
        cout << "can not find value." << endl;
    else
        cout << "find value position: " 
             << iter - vec.begin() << endl;
}

void hw_16_7()
{
    int iarray[5] = {1, 3 ,5 ,23, 6};
    Print(iarray);

    string sarray[4] = {"nihao", "hi", "hello"};
    Print(sarray);
}

void ch_16_1_2()
{
    /* ʵ������ģ�� */
    {
        Blob<string>    sa = {"hello", "hi", "nihao"};
    }

    /* ��ģ���Ա����ʵ���� */
    {
        Blob<int>       ia = {1,2,3,4,5,6,7,8,9};

        for (size_t i = 0; i != ia.Size(); i++)
            ia[i] = i * i;

        for (size_t i = 0; i < ia.Size(); i++)
            cout << ia[i] << " ";
        cout << endl;
    }

    

    typedef Blob<string> StrBlob;
    StrBlob sb;

    BLOB<string>    sbb;

    TFoo<int> tf1, tf2;
    cout << TFoo<int>::Count() << ", " << tf1.Count() << ", " << tf2.Count() << endl;
}

template <typename T>
void PrintV(const T &v)
{
    // for (typename T::size_type i = 0; i != v.size(); ++i)
    //     cout << v[i] << " ";

    for (auto i = v.begin(); i != v.end(); i++)
        cout << v[i] << " ";
    
    cout << endl;
}
