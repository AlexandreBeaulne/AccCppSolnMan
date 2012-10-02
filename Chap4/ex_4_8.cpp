
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

std::vector<double> f(){
    std::vector<double> output;
    srand(time(NULL));
    for(int i=0; i<10;++i){
        output.push_back(double(rand()%10000)/100);
    }
    return output;
}

int main(){
    int n = 5;
    double d = f()[n];

    std::cout << "f() has to return a vector or an array of double, or any type castable to double" << std::endl;

    return 0;
}
