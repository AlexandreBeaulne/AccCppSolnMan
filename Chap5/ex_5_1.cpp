// Exercise 5-1

#include<cctype>
#include<vector>
#include<string>
#include<algorithm>

#include "../container_stream.h"
#include "split.h"
#include "rotate.h"

struct word {
    std::string word;
    int index;
};

bool compare(const std::string & a, const std::string & b){

    for(int i=0; i<std::min(a.length(),b.length());++i){
        if(tolower(a[i])<tolower(b[i]))
            return 1;
        else if(tolower(a[i])>tolower(b[i]))
            return 0;
    }

    return (a.length()<b.length());    
}

int main(){

    std::string s = "The quick brown fox\njumped over the fence";

    std::vector<std::string> input = split(s,'\n');
    std::vector<std::string> output;
    
    std::vector<std::string> splitted;
    for(int i = 0; i<input.size(); ++i){
        splitted = split(input[i]);
        for(int j = 0;j<splitted.size();++j){
            output.push_back(merge(rotate(splitted,j)));
        }
    }

    std::sort(output.begin(), output.end(), compare);
    print(output);
    std::cout << std::endl;

    return 0;
}

