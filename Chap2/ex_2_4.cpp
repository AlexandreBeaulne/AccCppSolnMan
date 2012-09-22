#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";

    const int pad = 1;

    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;

    std::cout << std::endl;

    std::cout << std::string(cols,'*') << std::endl;
    std::cout << "*" << std::string(cols-2,' ') << "*" << std::endl;
    std::cout << "*" << std::string(pad,' ') << greeting;
    std::cout << std::string(pad,' ') << "*" << std::endl;
    std::cout << "*" << std::string(cols-2,' ') << "*" << std::endl;
    std::cout << std::string(cols,'*') << std::endl;

    return 0;
}
