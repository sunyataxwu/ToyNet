
/**
 * CPP���IO
 */

#ifndef __CPP_CH_6_HPP__
#define __CPP_CH_6_HPP__

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string.h>

#include "chapter_06.h"

using namespace std;

namespace chapter_06
{

void ch_6()
{
    char    buffer[1024] = {0};

    /* �������������� */
    Test1();

    /* CPP����ļ���д */
    Test2();

    /* �ļ����� */
    Test3();
}

}

#endif // __CPP_CH_6_HPP__
