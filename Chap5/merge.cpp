
#include "merge.h"

std::string merge(const std::vector<std::string> & input, const char & delim){
    std::string output;
    for(std::vector<std::string>::const_iterator i = input.begin(); i!=input.end(); ++i){
        output += *i;
        if(i!=input.end()-1) output += delim;
    }
    return output;
}

std::string merge(const std::vector<std::string> & input){
    return merge(input,' ');
}
