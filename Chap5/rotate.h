
#ifndef ROTATE
#define ROTATE

#include<vector>

template< typename T>
std::vector<T> rotate(const std::vector<T> & input, const int & offset){
    // rotate([1,2,3,4,5],2) => [4,5,1,2,3]
    int len = input.size();
    std::vector<T> output(len);
    copy(input.begin(),input.end()-offset,output.begin()+offset);
    copy(input.begin()+len-offset,input.end(),output.begin());
    return output;
}

#endif
