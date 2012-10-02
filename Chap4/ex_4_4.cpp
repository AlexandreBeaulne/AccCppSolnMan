
#include<iostream>
#include<iomanip>

int main(){
    std::cout << std::setw(16) << "i" << std::setw(16) << "i^2" << std::endl;
    std::cout << std::setw(16) << "---" << std::setw(16) << "-----" << std::endl;
    for(double i = 0.0; i<=10000.0; i += 542.73264){
        std::cout << std::setw(16) << std::setprecision(12) << i << std::setw(16) << std::setprecision(12) << i*i << std::endl;
    }    
    return 0;
}
