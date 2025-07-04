
#include <iostream>
#include "str.h"

using namespace std;

int main()
{
    ver2::Str s1(2, 'a');
    cout << s1 << endl;

    ver2::Str s2 = "hello";
    cout << s2 << endl;
    char aa[] = "Hello world";

    ver2::Str s3(begin(aa), end(aa));
    cout << s3 << endl;

    cin >> s3;
    cout << s3 << endl;
    cout << s3[0] << endl;

    ver2::Str s4 = s2 + s3;
    cout << s4 << endl;

    return 0;
}