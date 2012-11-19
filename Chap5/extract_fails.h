
#ifndef EXTRACT_FAILS
#define EXTRACT_FAILS

#include "../Chap4/Student_info.h"

//// separate passing and failing student records: first try
//std::vector<Student_info> extract_fails(std::vector<Student_info> & students)
//{
//    std::vector<Student_info> pass, fail;
//
//    for(std::vector<Student_info>::size_type i = 0;
//            i != students.size(); ++i)
//        if(fgrade(students[i]))
//            fail.push_back(students[i]);
//        else
//            pass.push_back(students[i]);
//
//    students = pass;
//    return fail;
//}

//// second try: correct but potentially slow
//std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
//{
//    std::vector<Student_info> fail;
//    std::vector<Student_info>::size_type i = 0;
//    // invariant:elements [0, i) of students represent passing grades
//    while (i != students.size()) {
//        if (fgrade(students[i])) {
//            fail.push_back(students[i]);
//            students.erase(students.begin() + i);
//        } else
//            ++i;
//    }
//    return fail;
//}

// version 3 & 4
template<typename T>
T extract_fails(T & students)
{
    T fail;
    typename T::iterator iter = students.begin();
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

#endif

