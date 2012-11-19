// Exercise 5-2

#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<sys/time.h>

#include "../Chap4/Student_info.h"
#include "../container_stream.h"
#include "extract_fails.h"
#include "fill.h"

static unsigned long long get_timestamp(){
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_usec + (unsigned long long) now.tv_sec * 1000000;
}

int main(){
    
    for(int i = 1; i<=4; ++i){
        int num_students = pow(10,i);
        std::vector<Student_info> students_vector;
        fill(students_vector, num_students);
        std::list<Student_info> students_list;
        fill(students_list, num_students);

        // vector
        unsigned long long t0 = get_timestamp();     
        extract_fails(students_vector);
        unsigned long long t1 = get_timestamp();     
        double perf = (t1-t0) / 1000000.0L;
        std::cout << "Benchmark: " << num_students;
        std::cout << " students, container: vector,";
        std::cout << " performance: " << perf;
        std::cout << " seconds" << std::endl;

        // list
        t0 = get_timestamp();     
        extract_fails(students_list);
        t1 = get_timestamp();     
        perf = (t1-t0) / 1000000.0L;
        std::cout << "Benchmark: " << num_students;
        std::cout << " students, container: list,";
        std::cout << " performance: " << perf;
        std::cout << " seconds" << std::endl;

    }
    /* output:
    Benchmark: 10 students, container: vector, performance: 0.000136 seconds
    Benchmark: 10 students, container: list, performance: 0.000124 seconds
    Benchmark: 100 students, container: vector, performance: 0.003802 seconds
    Benchmark: 100 students, container: list, performance: 0.000627 seconds
    Benchmark: 1000 students, container: vector, performance: 0.294511 seconds
    Benchmark: 1000 students, container: list, performance: 0.00501 seconds
    Benchmark: 10000 students, container: vector, performance: 34.1391 seconds
    Benchmark: 10000 students, container: list, performance: 0.053426 seconds
    */
    return 0;
}

