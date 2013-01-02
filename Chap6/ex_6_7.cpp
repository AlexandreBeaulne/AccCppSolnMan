
// exercise 6-7

#include<algorithm>
#include<iterator>

#include "../Chap4/Student_info.h"

template<typename T>
T extract_fails(T & students)
{
    T fail;
    std::remove_copy_if(students.begin(), students.last(), back_inserter(fail), fgrade);
    return fail;
}
