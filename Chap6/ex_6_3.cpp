
#include<iostream>
#include<vector>
#include<algorithm>

#include "../vector_stream.h"

int main(){
    std::cout << "This code snippet is supposed to create a"
        " vector of size ten filled with the integers"
        " one hundred:" << std::endl;

    std::vector<int> u(10, 100);
    std::vector<int> v;

    std::cout << "u: " << u << std::endl;
    std::cout << "and copies its contents into vector v,"
        " but crashes because there is no space allocated to"
        " v to receive the elements. Once v is resized, the" 
        " code works:" << std::endl;

    v.resize(10);   // allocate space for 10 elements

    std::copy(u.begin(), u.end(), v.begin());

    std::cout << v << std::endl;

    return 0;
}
