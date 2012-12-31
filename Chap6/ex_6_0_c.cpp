
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

#include "../Chap4/Student_info.h"
#include "../Chap4/grade.h"
#include "../Chap4/median.h"

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


int main()
{
    // students who did and didn't do all their homework
    std::vector<Student_info> did, didnt;
    // read the student records and partition them
    Student_info student;

    while (read(std::cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // verify that the analyses will show us something
    if (did.empty()) {
        std::cout << "No student did all the homework!" << std::endl;
        return 1;
    }

    if (didnt.empty()) {
        std::cout << "Every student did all the homework!" << std::endl;
        return 1;
    }

    // do the analyses
    write_analysis(std::cout, "median", median_analysis, did, didnt);
    write_analysis(std::cout, "average", average_analysis, did, didnt);
    write_analysis(std::cout, "median of homework turned in",
        optimistic_median_analysis, did, didnt);
    return 0;
}

