
// exercise 6-5

// Copied Pasted from ex_6_0_c.cpp

#include<vector>
#include<algorithm>

#include "../Chap4/Student_info.h"
#include "../Chap4/grade.h"
#include "../Chap4/median.h"
  
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
    std::vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
        back_inserter(nonzero), 0);
    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), optimistic_median);
    return median(grades);
}
