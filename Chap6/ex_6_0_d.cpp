// exercise 6-0 d)

#include<vector>
#include<algorithm>

#include "../Chap4/Student_info.h"

bool pgrade(const Student_info& s) {
    return !fgrade(s);
}

//// Double pass version
//std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
//    std::vector<Student_info> fail;
//    remove_copy_if(students.begin(), students.end(),
//        back_inserter(fail), pgrade);
//    students.erase(remove_if(students.begin(), students.end(),
//        fgrade), students.end());
//    return fail;
//}

// Single pass version
std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
    std::vector<Student_info>::iterator iter =
        stable_partition(students.begin(), students.end(), pgrade);
    std::vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}
