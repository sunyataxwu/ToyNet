
#include <stdexcept>
#include <vector>
#include <iostream>
#include <vector>
#include <limits>
#include <ios>

#include "grade.h"
#include "median.h"

using namespace std;

double Grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double Grade(double midterm, double final, const vector<double> &hw)
{
    if (hw.empty())
    {
        throw domain_error("student has done no homework.");
    }

    return Grade(midterm, final, Median(hw));
}

double Grade(const ver0::StudentInfo &s)
{
    return Grade(s.midterm, s.final, s.homework);
}

#define SCORE   60

bool FGrade(const ver0::StudentInfo &s)
{
    return Grade(s) < SCORE;
}

bool PGrade(const ver0::StudentInfo &s)
{
    return !FGrade(s);
}

istream& ReadHw(istream &in, vector<double> &hw)
{
    cout << "Please enter homeworks (enter any non-number to finish): ";

    hw.clear();
    double x;
    while (in >> x)  // 当输入非数字时自动停止
        hw.push_back(x);

    // 清除错误状态并忽略错误输入
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    return in;
}