
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(){

    std::cout << "Please enter text: " << std::endl;

    std::string text;
    getline(std::cin, text, '\n');
    std::cout << text << std::endl;

    return 0;
}
