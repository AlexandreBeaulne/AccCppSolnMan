
#include<iostream>

void rectangle(const int &y, const int &x){
    std::cout << std::endl;
    std::cout << std::string(x,'*') << std::endl;

    for(int i=0;i<y-2;++i){
        std::cout << "*" << std::string(x-2,' ') << "*" << std::endl;
    }

    std::cout << std::string(x,'*') << std::endl;
    std::cout << std::endl;
}

void square(const int & size){
    rectangle(size,size);
}

int main(){
    square(5);
    rectangle(4,6);
    return 0;
}


