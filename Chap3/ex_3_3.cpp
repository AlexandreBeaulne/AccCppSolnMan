// Exercise 3-3

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

template<class TYPE>
std::ostream & operator<<(std::ostream &lhs, const std::vector<TYPE> & rhs){
    lhs << '[';
    for(int i=0;i<rhs.size();++i){
        lhs << rhs[i];
        if(i<rhs.size()-1){
            lhs << ',';
        }
    }
    lhs << ']';
    return lhs;
}

int main(){

    std::cout << "Please enter text (press Ctrl+d when you're done): " << std::endl;

    std::vector<std::string> text;
    std::string word;
    while(std::cin >> word){
        text.push_back(word);
    }

    sort(text.begin(),text.end());

    int idx = 0;
    int count = 1;
    std::vector<int> counts;
    std::vector<std::string> glossary;
    while(idx<text.size()){
        if(idx+count>=text.size()||text[idx].compare(text[idx+count])){
            glossary.push_back(text[idx]);
            counts.push_back(count);
            idx += count;
            count=1;
        }
        else{
            ++count;
        }
    }
    
    std::cout << std::endl;

    for(int i=0;i<glossary.size();++i){
        std::cout << "word: " << glossary[i];
        std::cout << ", occurences: " << counts[i] << std::endl;
    }

    return 0;
}
