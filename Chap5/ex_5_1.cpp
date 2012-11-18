// Exercise 5-1

#include<cctype>
#include<vector>
#include<string>
#include<algorithm>

#include "../container_stream.h"
#include "split.h"
#include "merge.h"
#include "rotate.h"

template <typename T, typename U>
struct pair{
    // Haskell-inspired pair
    // (Yes I know it's now
    // part of the standard
    // lib in C++11)
    T fst;
    U snd;
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

bool operator<(const pair<std::string,int> & a, const pair<std::string,int> & b){
    return compare(a.fst,b.fst);
}

std::string lBuffer(std::string str, const int & buffer){
    return std::string(buffer,' ') + str;
}

std::string prettyPrint(const std::vector<pair<std::string,int> > & input){
    
    int max_length = 0;
    for(std::vector<pair<std::string,int> >::const_iterator i=input.begin(); i!=input.end();++i){
        max_length = (max_length > (*i).fst.length() ? max_length : (*i).fst.length());
    }

    std::string output;

    for(std::vector<pair<std::string,int> >::const_iterator i=input.begin(); i!=input.end();++i){
        std::string lhs, rhs;
        std::vector<std::string> temp = split((*i).fst);
        for(int j = (*i).snd; j<temp.size();++j) lhs += temp[j] + " ";
        for(int j = 0; j<(*i).snd;++j) rhs += temp[j] + " ";
        output += lBuffer(lhs,max_length-lhs.length()) + "    " + rhs + "\n";
    }

    return output;
}

std::string permutedIndex(const std::string & input){

    std::vector<std::string> lines = split(input,'\n');
    std::vector<pair<std::string,int> > rLines;
    
    std::vector<std::string> splitted;
    for(int i = 0; i<lines.size(); ++i){
        splitted = split(lines[i]);
        for(int j = 0;j<splitted.size();++j){
            pair<std::string,int> temp;
            temp.fst = merge(rotate(splitted,j));
            temp.snd = (j!=0 ? j : splitted.size());
            rLines.push_back(temp);
        }
    }

    std::sort(rLines.begin(), rLines.end());

    std::string output = prettyPrint(rLines);
    return output;
}

int main(){

    std::string s = "The quick brown fox\njumped over the fence";
    std::cout << std::endl << "Input:" << std::endl;
    std::cout << s << std::endl;
    std::cout << std::endl << "Permuted Index:" << std::endl;
    std::string output = permutedIndex(s);
    std::cout << output;

    return 0;
}

