// Exercise 5-6

#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<sys/time.h>

#include "../Chap4/Student_info.h"
#include "../container_stream.h"
#include "fill.h"
#include "extract_fails.h"

static unsigned long long get_timestamp(){
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_usec + (unsigned long long) now.tv_sec * 1000000;
}

std::vector<Student_info> extract_fails_resize(std::vector<Student_info> & students){
    std::vector<Student_info>::iterator tail = students.begin();
    std::vector<Student_info>::iterator head = students.begin();
    while(head!=students.end()){
        if(fgrade(*head)){
            ++head;
        } else {
            Student_info temp = *head;
            *head = *tail;
            *tail = temp;
            ++head;
            ++tail;
        }
    }
    int num_pass = std::distance(students.begin(), tail);
    int num_fail = students.size() - num_pass;
    std::vector<Student_info> fails(num_fail);
    copy(tail, students.end(), fails.begin());
    students.resize(num_pass);
    return fails;
}

int main(){

    for(int i = 1; i<=4; ++i){
        int num_students = pow(10,i);
        std::vector<Student_info> students1;
        std::vector<Student_info> students2;
        fill(students1, num_students);
        fill(students2, num_students);

        unsigned long long t0 = get_timestamp();     
        extract_fails(students1);
        unsigned long long t1 = get_timestamp();     
        double perf = (t1-t0) / 1000000.0L;
        std::cout << "Benchmark: " << num_students;
        std::cout << " students, container: vector,";
        std::cout << " method: erase,";
        std::cout << " performance: " << perf;
        std::cout << " seconds" << std::endl;

        t0 = get_timestamp();     
        extract_fails_resize(students2);
        t1 = get_timestamp();     
        perf = (t1-t0) / 1000000.0L;
        std::cout << "Benchmark: " << num_students;
        std::cout << " students, container: vector,";
        std::cout << " method: resize,";
        std::cout << " performance: " << perf;
        std::cout << " seconds" << std::endl;

    }
//    /* output:
//    Benchmark: 10 students, container: vector, performance: 0.000136 seconds
//    Benchmark: 10 students, container: list, performance: 0.000124 seconds
//    Benchmark: 100 students, container: vector, performance: 0.003802 seconds
//    Benchmark: 100 students, container: list, performance: 0.000627 seconds
//    Benchmark: 1000 students, container: vector, performance: 0.294511 seconds
//    Benchmark: 1000 students, container: list, performance: 0.00501 seconds
//    Benchmark: 10000 students, container: vector, performance: 34.1391 seconds
//    Benchmark: 10000 students, container: list, performance: 0.053426 seconds
//    */
    return 0;
}

