
#ifndef FILL
#define FILL

#include<string>
#include<time.h>
#include<stdlib.h>

#include "../Chap4/Student_info.h"

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

template<typename T>
void fill(T & container, const unsigned int & num_students){

    /* initialize random seed: */
    srand ( time(NULL) );
    for(int i = 0; i < num_students; ++i)
    {
        Student_info * temp = new Student_info();
        temp->name = rand_str(8);
        temp->midterm = rand() % 100;
        temp->final = rand() % 100;
        temp->homework.push_back(rand() % 100);
        temp->homework.push_back(rand() % 100);
        temp->homework.push_back(rand() % 100);
        container.push_back(*temp);
    }    
}

#endif

