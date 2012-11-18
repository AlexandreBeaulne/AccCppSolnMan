// Exercise 5-0 a

//#define CONTAINER std::vector
#define CONTAINER std::list

#include<iostream>
#include<vector>
#include<list>

#include "../Chap4/Student_info.h"
#include "../container_stream.h"
#include "extract_fails.h"
#include "fill.h"

int main(){

    CONTAINER<Student_info> students;
    fill(students,10);

    std::cout << "\nAll students:" << std::endl;
    print(students);
    std::cout << std::endl;

    CONTAINER<Student_info> fail = extract_fails(students);
    std::cout << "\nPassing students:" << std::endl;
    print(students);
    std::cout << std::endl;

    std::cout << "\nFailing students:" << std::endl;
    print(fail);
    std::cout << std::endl;

    return 0;
}

