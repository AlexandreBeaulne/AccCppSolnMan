// Exercise 5-3

#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<sys/time.h>

#include "../Chap4/Student_info.h"
#include "../container_stream.h"

//typedef std::vector<Student_info> school_t;
typedef std::list<Student_info> school_t;

school_t extract_fails(school_t & students)
{
    school_t fail;
    school_t::iterator iter = students.begin();
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
    
    /* initialize random seed: */
    srand ( time(NULL) );

    int num_students = 10;
    school_t students;
    for(int i = 0; i < num_students; ++i)
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

    school_t fail = extract_fails(students);
    print(fail);
    std::cout << std::endl;

    return 0;
}

