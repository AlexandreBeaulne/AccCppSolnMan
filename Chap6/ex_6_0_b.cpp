// exercise 6-0 b)

#include<vector>
#include<string>
#include<iostream>

#include "find_urls.h"
#include "../vector_stream.h"

int main(){

    const std::string test = "Here's one url: http://www.google.com and another one: ftp://alex.com ok";

    std::vector<std::string> urls = find_urls(test);
    
    std::cout << "Result: " << urls << std::endl;

    return 0;
}

