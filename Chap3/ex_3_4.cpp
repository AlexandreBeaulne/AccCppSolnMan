

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

bool shorter(const std::string & string1, const std::string & string2){
    return string1.length() < string2.length();
}

int main(){

    std::cout << "Please enter text (press Ctrl+d when you're done): " << std::endl;

    std::vector<std::string> text;
    std::string word;
    while(std::cin >> word){
        text.push_back(word);
    }

    sort(text.begin(),text.end(), shorter);

    std::cout << "\nShortest: " << text[0] << ", longest: " << text[text.size()-1] << std::endl;

    return 0;
}
