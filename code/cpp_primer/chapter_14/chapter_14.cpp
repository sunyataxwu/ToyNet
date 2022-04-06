
#include "chapter_14.h"

#include <vector>
#include <algorithm>
#include <time.h>
#include <functional>
#include <map>

using namespace std;

void Chapter_14()
{

    //Homework_14_35();
    //Homework_14_37();
    //Homework_14_38();
    //Homework_14_39();

    //Partice_14_8_2();
    //Partice_14_8_3();
    Partice_14_9_1();
}

void Homework_14_35()
{
    ReadString read;
    cout << "read: " << read() << endl;
}

void Homework_14_37()
{
    srand(time(nullptr));
    vector<int> vec;

    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(rand() % 100);
    }
    
    const int old_val = 10;
    const int new_val = 20;
    
    IntCompare icmp(old_val);
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " ";});
    cout << endl;

    replace_if(vec.begin(), vec.end(), icmp, new_val);
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " ";});
    cout << endl;    
}

void ReadStr(istream &is, vector<string> &vec)
{
    string word;
    while (is >> word)
        vec.push_back(word);
}


void Homework_14_38()
{
    vector<string> words;
    ReadStr(cin, words);

    for (size_t i = 0; i < 10; i++)
    {
        StrLenIs str_len(i);
        cout << "length: " << i  << ", cnt: "
            << count_if(words.begin(), words.end(), str_len) 
            << endl;
    }
    
    return ;
}

void Homework_14_39()
{
    vector<string> words;
    ReadStr(cin, words);

    StrLenBetween len_between(1, 9);
    cout << "len 1~9: " << count_if(words.begin(), words.end(), len_between)
         << endl;

    StrLongerThan len_long(10);
    cout << "len longer 10: " << count_if(words.begin(), words.end(), len_long)
         << endl;
}


void Partice_14_8_2()
{
    plus<int>   int_add;
    negate<int> int_negate;

    cout << "sum: " << int_add(1, 2) 
         << ", negate: " << int_negate(int_add(1, 2))
         << endl;

    // char *p1 = "ni hao", *p2 = "hello", *p3 = "hi";
    // vector<char *> vec;
    // vec.push_back(p1);
    // vec.push_back(p2);
    // vec.push_back(p3);
    // //error
    // //sort(vec.begin(), vec.end(), [](char *a, char *b) { return a < b; });

    // sort(vec.begin(), vec.end(), less<char *>());
}

int Add(int i, int j) { return i + j; }
auto Mod = [](int i, int j) { return i % j; };
struct Divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

void Partice_14_8_3()
{
    function<int(int, int)> f1 = Add;
    function<int(int, int)> f2 = Mod;
    function<int(int, int)> f3 = [](int i ,int j) { return i * j; };

    int (*p)(int, int) = Add;   //
    map<string, function<int(int, int)>> binops = {
        {"+", p},
        {"-", minus<int>()},
        {"*", [](int i, int j) { return i*j; }},
        {"/", Divide()},
        {"%", Mod}
    };

    int left, right;
    string options;
    cin >> left >> options >> right;
    cout << "ret: " << binops[options](left, right) << endl;
}


void Partice_14_9_1()
{
    SmallInt i(100);
    //cout << "sum: " << i + 43 << endl;
    cout << "sum: " << static_cast<int>(i) + 43 << endl;
    // if (!i)
    //     cout << "equal ..." << endl;
}