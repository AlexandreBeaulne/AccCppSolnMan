
#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>

#include "split.h"
#include "merge.h"

std::string sort(const std::string & input){
    std::vector<std::string> byproduct = split(input);
    std::vector<std::string>::iterator head = byproduct.begin();
    std::vector<std::string>::iterator tail = byproduct.begin();
    while(head!=byproduct.end()){
        if(islower((*head)[0])){
            std::string temp = *head;
            *head = *tail;
            *(tail++) = temp;
        } 
        ++head;
    }
    return merge(byproduct);
}


int main(){

    std::string input = "THIS is SOME arbitrary INPUT";

    std::cout << "\nInput:\n" << std::endl;
    std::cout << input << std::endl;
    std::cout << "\nResult:\n" << std::endl;
    std::cout << sort(input) << std::endl << std::endl;

    return 0;
}

