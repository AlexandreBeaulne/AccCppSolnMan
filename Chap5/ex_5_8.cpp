// Exercise 5-0 c

#include<iostream>
#include<string>
#include<vector>

#include "frame.h"

int main(){

    // 5-8. In the hcat function from §5.8.3/95, what would happen if we defined s outside
    // the scope of the while? Rewrite and execute the program to confirm your hypothesis.
    // 
    // I suspect nothing would happen.

    std::vector<std::string> pic1;
    pic1.push_back("Some tests with");
    pic1.push_back("this framing suite");
    pic1.push_back("we are building as");
    pic1.push_back("an exercise");
    pic1 = frame(pic1);

    std::vector<std::string> pic2;
    pic2.push_back("haha man I");
    pic2.push_back("enjoy coding");
    pic2.push_back("quite a lot!");
    pic2 = frame(pic2);

    std::cout << std::endl;
    std::cout << "Picture 1:" << std::endl;
    std::cout << std::endl;
    printPic(pic1);
    std::cout << std::endl;
    std::cout << "Picture 2:" << std::endl;
    std::cout << std::endl;
    printPic(pic2);
    std::cout << std::endl;
    std::cout << "Vertical concatenation:" << std::endl;
    std::cout << std::endl;
    printPic(vcat(pic1,pic2));
    std::cout << std::endl;
    std::cout << "Horizontal concatenation:" << std::endl;
    std::cout << std::endl;
    printPic(hcat(pic1,pic2));
    std::cout << std::endl;

    return 0;
}

