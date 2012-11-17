
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

#include "../vector_stream.h"

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
bool fgrade(const Student_info & s);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::ostream& operator<<(std::ostream &, const Student_info &);

#endif
