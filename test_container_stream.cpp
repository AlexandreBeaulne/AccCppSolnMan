#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T, typename U>
void foo(T a, U b)
{
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

//template<typename T, typename U>
template<typename U>
void print(U<int> container)
{
    U<int>::iterator it = container.begin();
    while(it!=container.end())
    {
        std::cout << *it++ << std::endl;
    }
}

int main()
{
//    const int a = 2;
//    const char b = 'h';
//
//    foo(a,b);
    vector<int> v;
    list<double> l;

    v.push_back(1); v.push_back(2);
    l.push_back(1.1); l.push_back(2.2);

    print(v) << endl;
//    print(l) << endl;
//
//    cin.get();
    return 0;
}

//// test the << operator container_stream.h for vectors and lists
//
//#include<iostream>
//#include<vector>
//#include<list>
//#include<time.h>
//#include <stdlib.h>
//
//#include "container_stream.h"
//
//int main(){
//
//    const int SIZE = 5;
//
//    static const char alphanum[] =
//        "0123456789"
//        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//        "abcdefghijklmnopqrstuvwxyz";
//
//    std::vector<double> a_vect(SIZE);
//    std::list<char> b_vect(SIZE);
//
//    srand ( time(NULL) );
//
//    for(int i=0; i<SIZE; ++i){
//        a_vect.push_back( double(rand()%100)/10 );
//        b_vect.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
//    }
//
//    std::cout << a_vect << std::endl;
//    std::cout << b_vect << std::endl;
//
//    return 0;
//}
