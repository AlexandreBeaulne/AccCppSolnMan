// Exercise 5-0 a

#include<iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>

#include "../Chap4/grade.h"
#include "../Chap4/Student_info.h"
#include "../vector_stream.h"

// predicate to determine whether a student failed
bool fgrade(const Student_info & s)
{
    return grade(s) < 60;
}

// separate passing and failing student records: first try
std::vector<Student_info> extract_fails(std::vector<Student_info> & students)
{
    std::vector<Student_info> pass, fail;

    for(std::vector<Student_info>::size_type i = 0;
            i != students.size(); ++i)
        if(fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);

    students = pass;
    return fail;
}

std::string rand_str(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    std::string output;

    for (int i = 0; i < len; ++i)
    {
        output.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
    }

    return output;
}

int main(){
    
    // Create a vector of random student_info structs to test on
    /* initialize random seed: */
    srand ( time(NULL) );
    std::vector<Student_info> students(10);
    for(std::vector<Student_info>::size_type i = 0;
            i != students.size(); ++i)
    {
        students[i].name = rand_str(8);
        students[i].midterm = rand() % 100;
        students[i].final = rand() % 100;
        students[i].homework.push_back(rand() % 100);
        students[i].homework.push_back(rand() % 100);
        students[i].homework.push_back(rand() % 100);
    }    

    std::cout << "\nAll students:" << std::endl;
    std::cout << students << std::endl;
    std::vector<Student_info> fail = extract_fails(students);
    std::cout << "\nPassing students:" << std::endl;
    std::cout << students << std::endl;
    std::cout << "\nFailing students:" << std::endl;
    std::cout << fail << std::endl;
}
