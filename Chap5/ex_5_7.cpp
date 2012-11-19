
#include<iostream>

#include "frame.h"

int main(){

    std::cout << "Expectation: an empty frame:\n" << std::endl;
    std::cout << "****" << std::endl;
    std::cout << "****" << std::endl;


    std::cout << "Observed:\n" << std::endl;
    std::vector<std::string> pic;
    printPic(frame(pic));
    std::cout << std::endl;

    return 0;
}
