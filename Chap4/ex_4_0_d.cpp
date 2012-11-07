// Exercise 4-0 d

#include<algorithm>
#include<iomanip>
#include<ios>
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>

#include "grade.h"
#include "Student_info.h"

int main()
{
    std::vector<Student_info> students;
    Student_info record;
    std::string::size_type maxlen = 0;

    std::cout << "Please enter each student's record on a line" << std::endl;
    std::cout << "<Name> <midterm> <final> <hw1> <hw2> ... " << std::endl;
    std::cout << "E.g. Smith 78 87 67 75 82" << std::endl;
    std::cout << "Enter end-of-file (ctrl+D) when done" << std::endl;

    while (read(std::cin, record)) {
        // find length of longest name
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    // write the names and grades
    for(std::vector<Student_info>::size_type i = 0;i != students.size(); ++i){
        // write the name, padded on the right to maxlen + 1 characters
        std::cout << students[i].name << std::string(maxlen + 1 - students[i].name.size(), ' ');
        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade << std::setprecision(prec);
        } catch (std::domain_error e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    }
    return 0;
}
