
#include<iostream>

int main(){
    double first;
    double second;

    std::cout << "Please enter a number: ";
    std::cin >> first;

    std::cout << "and another number: ";
    std::cin >> second;

    if(first>second){
        std::cout << first << " is larger than " << second << std::endl;
    }
    else if(second>first){
        std::cout << second << " is larger than " << first << std::endl;
    }
    else{
        std::cout << second << " is equal to " << first << std::endl;
    }

    return 0;
}
