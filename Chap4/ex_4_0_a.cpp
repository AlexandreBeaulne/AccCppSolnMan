// Exercise 4-0 a

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include<stdlib.h>
#include<time.h>

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(std::vector<double> vec)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

int main(){
    std::vector<double> test;
    srand(time(NULL));
    std::cout << "The median of vector\n[";
    for(int i = 0; i<12; ++i){
        double value = 0.1*(rand()%1000);
        test.push_back(value);
        std::cout << value << ",";
    }
    std::cout << "] is " << median(test) << std::endl;

    return 0;
}
