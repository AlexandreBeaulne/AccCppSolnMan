
// exercise 6-6

#include<vector>
#include<algorithm>

#include "../Chap4/Student_info.h"
#include "../Chap4/median.h"

double analysis(const std::vector<Student_info>& students, double grade(const Student_info&))
{
    std::vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), grade);
    return median(grades);
}
