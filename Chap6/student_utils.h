
#ifndef STUDENT_UTILS
#define STUDENT_UTILS

#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

#include "../Chap4/Student_info.h"
#include "../Chap4/grade.h"
#include "../Chap4/median.h"

bool did_all_hw(const Student_info&);
double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double average(const std::vector<double>&);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info&);
double optimistic_median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream& out, const std::string&,
        double analysis(const std::vector<Student_info>&),
        const std::vector<Student_info>&,
        const std::vector<Student_info>&);

#endif
