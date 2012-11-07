// Exercise 2-5

#include<iostream>
#include<string>

void rectangle(const int &y, const int &x){
    std::cout << std::endl;
    std::cout << std::string(x,'*') << std::endl;

    for(int i=0;i<y-2;++i){
        std::cout << "*" << std::string(x-2,' ') << "*" << std::endl;
    }

    std::cout << std::string(x,'*') << std::endl;
    std::cout << std::endl;
}

void isotriangle(const int &sidesize){

    std::cout << std::endl;

    std::string line(sidesize,' ');

    for(int i=0;i<sidesize-1;++i){
        line[0] = '*';
        line[i] = '*';
        std::cout << line << std::endl;
        line[i] = ' ';
    }

    std::cout << std::string(sidesize,'*') << std::endl;

    std::cout << std::endl;
}

void square(const int & size){
    rectangle(size,size);
}

int main(){
    square(5);
    rectangle(4,6);
    isotriangle(5);
    return 0;
}

