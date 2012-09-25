
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
    while(idx+count<text.size()){
        if(text[idx].compare(text[idx+count])){
            ++count;
        }
        else{
            counts.push_back(count);
            idx += count;
            count=1;
        }
    }

    std::vector<std::string> text2 = unique(text.begin(),text.end(),std::string.compare);

    std::cout << "\n\ntext: " << text << std::endl;

//    std::string text;
//    getline(std::cin, text, '\n');
//    std::cout << text << std::endl;

    return 0;
}
