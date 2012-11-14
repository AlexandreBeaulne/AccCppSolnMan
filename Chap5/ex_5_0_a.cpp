// Exercise 5-0 a
//#define CONTAINER vector
#define CONTAINER list

#include<iostream>
#include<vector>
#include<list>
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

// version 3: iterators but no indexing; still potentially slow
std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
{
    std::vector<Student_info> fail;
    std::vector<Student_info>::iterator iter = students.begin();
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

// version 4: use list instead of vector
std::list<Student_info> extract_fails(std::list<Student_info>& students)
{
    std::list<Student_info> fail;
    std::list<Student_info>::iterator iter = students.begin();
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
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
    int NUM_STUDENTS = 10;
    std::CONTAINER<Student_info> students;
    for(int i = 0; i < NUM_STUDENTS; ++i)
    {
        Student_info * temp = new Student_info();
        temp->name = rand_str(8);
        temp->midterm = rand() % 100;
        temp->final = rand() % 100;
        temp->homework.push_back(rand() % 100);
        temp->homework.push_back(rand() % 100);
        temp->homework.push_back(rand() % 100);
        students.push_back(*temp);
    }    

    std::cout << "\nAll students:" << std::endl;
    std::cout << students << std::endl;
    std::CONTAINER<Student_info> fail = extract_fails(students);
    std::cout << "\nPassing students:" << std::endl;
    std::cout << students << std::endl;
    std::cout << "\nFailing students:" << std::endl;
    std::cout << fail << std::endl;
}

