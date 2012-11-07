// Exercise 4-6

#include <iostream>
#include <string>
#include <vector>

#include "grade.h"

using std::istream;
using std::vector;

struct student_info{
    std::string name;
    double grade;
};

bool compare(const student_info& x, const student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, student_info& s)
{
    double midterm;
    double final;
    std::vector<double> homework;

    is >> s.name >> midterm >> final;
    read_hw(is, homework);
    s.grade = grade(midterm,final,homework);
    return is;
}

// read homework grades from an input stream into a `vector'
istream& read_hw(istream& in, vector<double>& hw)
{
    if(in){
        // get rid of previous contents
        hw.clear();
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

int main(){
    student_info student;
    std::cout << "enter a student's record";
    std::cout << "(E.g. Mat<Enter>87<Enter>85<Enter>78<Enter>87<Enter>77<Ctrl-D>)" << std::endl;
    read(std::cin,student);
    std::cout << student.grade << std::endl;
    return 0;
}
