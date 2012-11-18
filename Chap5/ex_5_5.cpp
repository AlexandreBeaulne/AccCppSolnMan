// Exercise 5-5

#include<iostream>
#include<string>
#include<vector>

#include "split.h"
#include "merge.h"

std::string strip(const std::string & str, const char & c){
    // strip both sides of a string of the character c

    unsigned int start = 0;
    while(str[start]==c) ++start;

    unsigned int end = str.length() -1;
    while(str[end]==c) --end;

    return std::string(str, start, end-start+1);
}

std::string lPad(const std::string & str, const char & c, const unsigned int & buffer){
    return std::string(buffer,c) + str;
}

std::string rPad(const std::string & str, const char & c, const unsigned int & buffer){
    return str + std::string(buffer,c);
}

std::string pad(const std::string & str, const char & c, const unsigned int & buffer){
    return std::string(buffer,c) + str + std::string(buffer,c);
}

std::vector<std::string> center(const std::vector<std::string> & input){

    unsigned int width = input[0].length();
    std::vector<std::string> output;
    output.push_back(std::string(width,'*'));
    for(std::vector<std::string>::const_iterator i = input.begin()+1; i!=input.end()-1; ++i){
        std::string content = strip(strip(*i,'*'),' ');
        if(content.length()%2==0){
            output.push_back("*" + pad(content, ' ', (width-content.length()-2)/2) + "*");
        } else {
            unsigned int lpad = (width - content.length() - 2)/2;
            unsigned int rpad = lpad + 1;
            output.push_back("*" + lPad(rPad(content, ' ', rpad),' ', lpad) + "*");
        }
    }
    output.push_back(std::string(width,'*'));
    return output;
}

std::string center(const std::string & input){
    std::vector<std::string> temp = center(split(input,'\n'));
    return merge(temp,'\n');
}

int main(){
    const std::string picture =
        "****************\n"
        "* Early        *\n"
        "* optimisation *\n"
        "* is           *\n"
        "* the          *\n"
        "* root         *\n"
        "* of           *\n"
        "* all          *\n"
        "* evil         *\n"
        "****************\n";

    std::cout << picture << std::endl;

    std::string centered = center(picture);

    std::cout << centered << std::endl;

    return 0;
}
