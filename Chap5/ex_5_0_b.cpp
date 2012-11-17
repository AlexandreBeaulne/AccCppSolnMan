// Exercise 5-0 b

#include<string>
#include<vector>
#include<cctype>

#include "../container_stream.h"
#include "split.h"

int main() {
    std::string s;
    // read and split each line of input
    while (getline(std::cin, s)) {
        std::vector<std::string> v = split(s);
        // write each word in v
        print(v);
        std::cout << std::endl;
    }
    return 0;
}

