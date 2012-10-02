
#include<iostream>

#include "Student_info.h"

int main(){
    int maxlen = 0;
    Student_info record;
    std::cout << "Please enter student record (e.g. Smith 87 84 88 89 81)" << std::endl;
    read(std::cin, record);
    
    // maxlen = std::max(maxlen,record.name.size());

    std::cout << "It doesn't work because int and std::string::size_type aren't the same type" << std::endl;
    return 0;
}
