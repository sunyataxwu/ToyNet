
#include <iostream>
#include <limits>
#include <ios>

#include "core.h"
#include "grade.h"

using namespace std;

double Core::Grade() const
{
    return ::Grade(midterm_, final_, homework_);
}

std::istream& Core::ReadCommon(std::istream &is)
{
    cout << "Please enter name, midterm and final (or 'exit' to finish): ";
    if (!(is >> name_) || name_ == "exit")
    {
        is.setstate(ios::failbit);  // 设置失败状态以终止循环
        return is;
    }

    if (!(is >> midterm_ >> final_))
    {
        cerr << "Error reading midterm/final scores\n";
        is.clear();  // 清除错误状态
        is.ignore(numeric_limits<streamsize>::max(), '\n');  // 跳过当前行(忽略输入流中最多 numeric_limits<streamsize>::max() 个字符，直到遇到换行符 \n（包括换行符本身）)
        is.setstate(ios::failbit);  // 主动标记为失败以终止循环
        return is;
    }

    ReadHw(is, homework_);

    // 检查是否有作业成绩
    if (homework_.empty()) cerr << "Warning: No homework scores entered\n";

    return is;
}

std::istream& Core::Read(std::istream &is)
{
    ReadCommon(is);
    return is;
}
