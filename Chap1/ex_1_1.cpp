// Exercise 1-1

#include <iostream>
#include <string>

int main()
{
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";
    std::cout << message << std::endl;
    std::cout << "Yes it works" << std::endl;
}
