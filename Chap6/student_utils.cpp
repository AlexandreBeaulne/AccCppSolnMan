
#include "student_utils.h"

bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0))
        == s.homework.end());
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (std::domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double median_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const std::vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    transform(students.begin(), students.end(),
        back_inserter(grades), average_grade);
    return median(grades);
}


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

void write_analysis(std::ostream& out, const std::string& name,
        double analysis(const std::vector<Student_info>&),
        const std::vector<Student_info>& did,
        const std::vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
        ", median(didnt) = " << analysis(didnt) << std::endl;
}

