
// exercise 6-8

#include "../Chap4/Student_info.h"
#include "../Chap4/grade.h"
#include "../Chap4/median.h"
#include "student_utils.h"

template<typename T>
T separate(T & students, bool criteria(const Student_info &))
{
    T didnt_pass;
    std::remove_copy_if(students.begin(), students.end(), back_inserter(didnt_pass), criteria);
    return didnt_pass;
}

int main()
{
    // students who did and didn't do all their homework
    std::vector<Student_info> did, didnt;
    // read the student records and partition them
    
    Student_info student;

    std::cout << "Please enter each student's record on a line" << std::endl;
    std::cout << "<Name> <midterm> <final> <hw1> <hw2> ... " << std::endl;
    std::cout << "E.g. Smith 78 87 67 75 82" << std::endl;
    std::cout << "Enter end-of-file (ctrl+D) when done" << std::endl;

    while (read(std::cin, student)) {
        did.push_back(student);
    }

    didnt = separate(did, did_all_hw);

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

