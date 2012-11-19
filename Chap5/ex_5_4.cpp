// Exercise 5-4

#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "../Chap4/Student_info.h"
#include "../container_stream.h"
#include "fill.h"
#include "extract_fails.h"

typedef std::vector<Student_info> school_t;
//typedef std::list<Student_info> school_t;

int main(){

    school_t students;
    fill(students, 10);

    school_t fail = extract_fails(students);
    print(fail);
    std::cout << std::endl;

    return 0;
}


