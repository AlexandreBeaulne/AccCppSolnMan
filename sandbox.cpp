
#include<iostream>
#include<vector>

#include"vector_stream.h"

int main()
{
    std::vector<double> vect;
    vect.push_back(21.65);
    vect.push_back(1);
    vect.push_back(-1.23);

    std::cout << vect << std::endl;
}
