// exercise 6-0 a)

#include<iostream>
#include<vector>

#include "is_palindrome.h"
#include "split.h"

int main(){

    std::string sentence = "The words civic eye and level are palindromes";
    std::vector<std::string> words = split(sentence); 

    for(std::vector<std::string>::const_iterator i = words.begin(); i!= words.end(); ++i) {
        if(is_palindrome(*i))
            std::cout << *i << " is a palindrome" << std::endl;
    }

    return 0;
}

