// Exercise 3-2

#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    std::vector<double> vect;
    std::cout << "Please enter number to populate the vector, enter eof when done" << std::endl;

    double x;
    while(std::cin >> x)
        vect.push_back(x);
    
    sort(vect.begin(),vect.end());

    int lenght = vect.size();
    
    std::cout << "\nmin: " << vect[0] << std::endl;
    std::cout << "1st quartile: " << vect[lenght/4] << std::endl;
    std::cout << "2nd quartile: " << vect[lenght/2] << std::endl;
    std::cout << "3rd quartile: " << vect[lenght-lenght/4] << std::endl;
    std::cout << "4th quartile: " << vect[lenght-1] << std::endl;

    return 0;
}
