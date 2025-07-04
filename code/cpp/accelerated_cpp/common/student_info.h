
#ifndef __ACCELERATED_CPP_STUDENT_INFO_H__
#define __ACCELERATED_CPP_STUDENT_INFO_H__

#include <iostream>
#include <string>
#include <vector>

namespace ver0
{

struct StudentInfo
{
    std::string     name;
    double          midterm, final;
    std::vector<double> homework;
};

extern bool Compare(const StudentInfo &, const StudentInfo &);
extern std::istream& Read(std::istream &in, StudentInfo &);

typedef double (*Analysis)(const std::vector<StudentInfo> &);

extern bool DidAllHW(const StudentInfo &s);
extern void WriteAnalysis(std::ostream &os, const std::string &name, Analysis,
                          std::vector<StudentInfo> &did, std::vector<StudentInfo> &didnt);
extern double MedianAnalysis(const std::vector<StudentInfo> &students);
extern double AverageAnalysis(const std::vector<StudentInfo> &students);
extern double OptimisticAnalysis(const std::vector<StudentInfo> &students);

extern std::vector<StudentInfo> ExtractFails(std::vector<StudentInfo> &students);

}

namespace ver1
{
class StudentInfo
{
public:
    StudentInfo()
        : midterm_(0.0), final_(0.0)    {}
    StudentInfo(std::istream &in)       { Read(in); }
public:
    std::string     Name()  const   { return name_; }
    bool            Valid() const   { return !homework_.empty(); }

    std::istream&   Read(std::istream &in);
    double          Grade() const;
private:
    std::string         name_;
    double              midterm_, final_;
    std::vector<double> homework_;
};

}

#include "core.h"

namespace ver2
{

class StudentInfo
{
public:
    StudentInfo() : cp_(0) {}
    StudentInfo(std::istream &in) : cp_(0) { Read(in); }
    StudentInfo(const StudentInfo &rhs);
    StudentInfo& operator=(const StudentInfo &rhs);
    ~StudentInfo() { delete cp_; }
public:
    std::istream& Read(std::istream &in);
    std::string Name() const
    {
        if (cp_)
            return cp_->Name();
        else
            throw std::domain_error("uninit student.");
    }

    double Grade() const
    {
        if (cp_)
            return cp_->Grade();
        else
            throw std::domain_error("uninit student.");
    }

    static bool Compare(const StudentInfo &lhs,
                        const StudentInfo &rhs)
    {
        return lhs.Name() < rhs.Name();
    }
private:
    Core* cp_;
};

}

#include "handle.hpp"

namespace ver3 
{

class StudentInfo
{
public:
    StudentInfo() {}
    StudentInfo(std::istream &in) { Read(in); }
public:
    std::istream&   Read(std::istream &in);
    std::string     Name() const
    {
        if (cp_)
            return cp_->Name();
        else
            throw std::domain_error("uninit student.");
    }

    double grade() const
    {
        if (cp_)
            return cp_->Grade();
        else
            throw std::domain_error("uninit student.");
    }

    static bool compare(const StudentInfo &lhs,
                        const StudentInfo &rhs)
    {
        return lhs.Name() < rhs.Name();
    }

    void ReGrade(double final, double thesis);
private:
    Ptr<Core> cp_;
};

}

#endif //__ACCELERATED_CPP_STUDENT_INFO_H__
