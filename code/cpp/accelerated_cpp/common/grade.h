

#ifndef __ACCELERATED_CPP_GRADE_H__
#define __ACCELERATED_CPP_GRADE_H__

#include <vector>
#include "student_info.h"

extern double Grade(double, double, double);
extern double Grade(double, double, const std::vector<double>&);
extern double Grade(const ver0::StudentInfo &);

extern bool FGrade(const ver0::StudentInfo &);
extern bool PGrade(const ver0::StudentInfo &);

extern std::istream& ReadHw(std::istream &in,  std::vector<double> &);

#endif //__ACCELERATED_CPP_GRADE_H__
