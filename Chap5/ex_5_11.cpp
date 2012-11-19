
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "split.h"

bool hasCenders(const std::string & input){
    const std::string CENDERS = "bdfhkltgjpqy";
    for(std::string::const_iterator i=++input.begin(); i!=input.end(); ++i){
        if(CENDERS.find(*i)<CENDERS.length())
            return true;
    }

    return false;
}

std::string longestCendersless(const std::string & input){
    std::string output;
    unsigned int max_len = 0;
    const std::vector<std::string> byproduct = split(input);
    for(std::vector<std::string>::const_iterator i=byproduct.begin(); i!=byproduct.end();++i){
        if(!hasCenders(*i) && (*i).length()>max_len){
            output = *i;
            max_len = (*i).length();
        }
    }
    return output;
}

int main(){

    const std::string dictionary = "Many people have wondered what would happen if we didn't read from left to right. Imagine if you read this sentence from right to left-this is what you would see-tfel ot ohgir morf ecnetnes... Not much to read there. But imagine a sentence that you can read from left to right or right to left and still come up with the same thing-that's a palindrome. Palindromes are all over the place and once you know what they are you will begin to realize that many of the words that we use on an everyday basis are considered palindrome words because of their ability to be read both forward and backwards with no change in the spelling. There are literally hundreds of palindromes in the English language. Maybe we actually could read from right to left if we worked really hard. There are even palindrome sentences that make some sense...and some that make very little sense but still work. When creating a palindrome sentence it is not important whether the actual syllables match both ways, only that the letters are correct. However, if you can make a palindrome sentence that actually has the same syllables and spaces both forward and backwards it is even more legible!: civic Dewed deified dad mom devoved Hannah peeweep repaper kayak minim radar murdrum Malayalam madam lemel level racecar radar redder bob pop tot refer reviver rotator rotavator stats solos tenet terret testset linikinik wassamassaw";

    std::cout << "\nDictionary:\n" << std::endl;
    std::cout << dictionary << std::endl;
    std::cout << "\nLongest word without ascenders or descenders: ";
    std::cout << longestCendersless(dictionary) << std::endl << std::endl;

    return 0;
}
