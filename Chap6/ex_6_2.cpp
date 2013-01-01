// exercise 6-2

#include<vector>
#include<string>
#include<iostream>

#include "find_urls.h"
#include "../vector_stream.h"

int main(){

    const std::string test = "Here's one url: http://www.google.com and"
        "another one: ftp://alex.com but this is not a url ://notaurl.com"
        "nor this is one notaurl:// ok";

    std::vector<std::string> urls = find_urls(test);
    
    std::cout << "String: " << test << std::endl;
    std::cout << "URLs: " << urls << std::endl;

    return 0;
}

