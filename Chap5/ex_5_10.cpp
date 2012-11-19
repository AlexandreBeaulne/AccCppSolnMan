
#include<iostream>
#include<string>
#include<vector>

#include "split.h"
#include "../vector_stream.h"

bool isPalindrome(const std::string & input){
    const unsigned int len = input.length();
    if(len<2)
        return true;
    else if(input[0]==input[len-1])
        return isPalindrome(input.substr(1,len-2));
    else return false;
}

std::vector<std::string> palindromes(const std::string & input){
    std::vector<std::string> byproduct = split(input);
    std::vector<std::string> output;
    for(std::vector<std::string>::iterator i = byproduct.begin(); i!=byproduct.end(); ++i){
        if(isPalindrome(*i)) output.push_back(*i);
    }
    return output;
}

std::string longest(const std::vector<std::string> & input){
    unsigned int max_len = 0;
    std::string output;
    for(std::vector<std::string>::const_iterator i = input.begin(); i!=input.end();++i){
        if((*i).length()>max_len){
            output = *i;
            max_len = (*i).length();
        }
    }
    return output;
}

int main(){

    const std::string dictionary = "Many people have wondered what would happen if we didn't read from left to right. Imagine if you read this sentence from right to left-this is what you would see-tfel ot ohgir morf ecnetnes... Not much to read there. But imagine a sentence that you can read from left to right or right to left and still come up with the same thing-that's a palindrome. Palindromes are all over the place and once you know what they are you will begin to realize that many of the words that we use on an everyday basis are considered palindrome words because of their ability to be read both forward and backwards with no change in the spelling. There are literally hundreds of palindromes in the English language. Maybe we actually could read from right to left if we worked really hard. There are even palindrome sentences that make some sense...and some that make very little sense but still work. When creating a palindrome sentence it is not important whether the actual syllables match both ways, only that the letters are correct. However, if you can make a palindrome sentence that actually has the same syllables and spaces both forward and backwards it is even more legible!: civic Dewed deified dad mom devoved Hannah peeweep repaper kayak minim radar murdrum Malayalam madam lemel level racecar radar redder bob pop tot refer reviver rotator rotavator stats solos tenet terret testset kinikinik wassamassaw";

    std::vector<std::string> p = palindromes(dictionary);

    std::cout << "\nDictionary:\n" << std::endl;
    std::cout << dictionary << std::endl;
    std::cout << "\nPalindromes:\n" << std::endl;
    std::cout << p << std::endl;
    std::cout << "\nLongest:\n" << std::endl;
    std::cout << longest(p) << std::endl << std::endl;

    return 0;
}

