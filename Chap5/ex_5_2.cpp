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

static unsigned long long get_timestamp(){
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_usec + (unsigned long long) now.tv_sec * 1000000;
}

int main(){
    
    /* initialize random seed: */
    srand ( time(NULL) );

    for(int i = 1; i<=4; ++i){
        int num_students = pow(10,i);
        std::vector<Student_info> students_vector;
        std::list<Student_info> students_list;
        for(int i = 0; i < num_students; ++i)
        {
            Student_info * temp = new Student_info();
            temp->name = rand_str(8);
            temp->midterm = rand() % 100;
            temp->final = rand() % 100;
            temp->homework.push_back(rand() % 100);
            temp->homework.push_back(rand() % 100);
            temp->homework.push_back(rand() % 100);
            students_vector.push_back(*temp);
            students_list.push_back(*temp);
        }    

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

