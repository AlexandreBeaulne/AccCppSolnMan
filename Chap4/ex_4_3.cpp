// Exercise 4-3

#include<iostream>
#include<iomanip>

int main(){
    std::cout << std::setw(16) << "i" << std::setw(16) << "i^2" << std::endl;
    std::cout << std::setw(16) << "---" << std::setw(16) << "-----" << std::endl;
    for(int i = 0; i<=10000; i += 1000){
        std::cout << std::setw(16) << i << std::setw(16) << i*i << std::endl;
    }    
    return 0;
}
