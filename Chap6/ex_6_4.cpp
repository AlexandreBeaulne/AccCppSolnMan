
// exercise 6-4

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

#include "../vector_stream.h"

int main(){

//    // First solution: Resize the vector v to have enough
//    // space to hold the elements of u. Strengh: Good control
//    // on the ending size of v, weakness: will crash if the
//    // number of elements inserted in v is bigger than expected,
//    // or there will be unallocated space if the number of
//    // inserted elements is smaller than expected.
//
//    std::vector<int> u(10, 100);
//    std::vector<int> v;
//
//    v.resize(10);   // allocate space for 10 elements
//
//    std::copy(u.begin(), u.end(), v.begin());

    // Second solution: use back_inserter instead of begin
    // Strengh: Will only allocate the precise space needed
    // by v, weakness: the final size of v is not known and
    // need to be queried if needed.

    std::vector<int> u(10, 100);
    std::vector<int> v;

    std::copy(u.begin(), u.end(), back_inserter(v));

    std::cout << "u: " << u << std::endl;
    std::cout << "v: " << v << std::endl;

    return 0;
}
