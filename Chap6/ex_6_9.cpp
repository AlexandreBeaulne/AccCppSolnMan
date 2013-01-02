
// exercise 6-9

#include<string>
#include<iostream>
#include<vector>
#include<numeric>

std::string concat(std::vector<std::string> input){
    return accumulate(input.begin(), input.end(), std::string());
}

int main(){

    std::vector<std::string> vect;
    vect.push_back("Here");
    vect.push_back("is");
    vect.push_back("a");
    vect.push_back("bunch");
    vect.push_back("of");
    vect.push_back("words");
    vect.push_back("in");
    vect.push_back("a");
    vect.push_back("vector");

    std::cout << concat(vect) << std::endl;

    return 0;
}
