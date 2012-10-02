
#include<iostream>
#include<vector>

double average(const std::vector<double> & vect){

    double sum = 0;
    int i = 0;
    for(;i<vect.size();++i)
        sum += vect[i];

    return sum/i;
}

int main(){

    std::vector<double> vect;
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    
    std::cout << average(vect) << std::endl;

    return 0;
}
    
