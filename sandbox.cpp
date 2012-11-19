
#include<iostream>
#include<vector>
#include<string>
#include<cctype>

#include"vector_stream.h"
#include"Chap5/split.h"
#include"Chap5/rotate.h"
#include"Chap5/merge.h"

template<typename T>
T extract_girls(T & students)
{
    T girl;
    typename T::iterator iter = students.begin();
    while (iter != students.end()) {
        if (*iter=="Mary") {
            girl.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return girl;
}

int main()
{

    std::vector<std::string> students;
    students.push_back("John");
    students.push_back("Mary");
    students.push_back("Jack");

    std::vector<std::string> girls = extract_girls(students);

    std::cout << students << std::endl;
    std::cout << girls << std::endl;

    return 0;
}
