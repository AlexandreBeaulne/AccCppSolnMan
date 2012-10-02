
#include<iostream>
#include<iomanip>

int main(){
    std::cout << std::setw(4) << "i" << std::setw(6) << "i^2" << std::endl;
    std::cout << std::setw(4) << "---" << std::setw(6) << "-----" << std::endl;
    for(int i = 1; i<=100; ++i){
        std::cout << std::setw(4) << i << std::setw(6) << i*i << std::endl;
    }    
    return 0;
}
