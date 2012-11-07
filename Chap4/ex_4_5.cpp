// Exercise 4-5

#include<iostream>
#include<vector>
#include<map>

std::vector<std::string> read_text(){

    std::cout << "Enter text followed by end-of-file (ctrl-d)" << std::endl;

    std::vector<std::string> output;
    std::string word;
    while(std::cin >> word){
        output.push_back(word);
    }
    return output;
}

int num_word(std::vector<std::string> input){
    return input.size();
}

std::map<std::string,int> count_word(std::vector<std::string> input){
    std::map<std::string,int> output;
    for(int i=0;i<input.size();++i){
        if(output.find(input[i])==output.end()){
            output[input[i]] = 1;
        } else {
            output[input[i]] += 1;
        }
    }
    return output;
}

typedef std::map<std::string, int>::iterator it_type;

int main(){

    std::vector<std::string> input = read_text();

    std::cout << "\nthe text you entered has " << num_word(input) << " words. Their breakdown is: " <<std::endl;

    std::map<std::string,int> hashmap = count_word(input);

    for(it_type i = hashmap.begin();i !=hashmap.end();++i){
        std::cout << i->first << "     " << i->second << std::endl;
    }

    return 0;
}
