
#ifndef CONTAINER_STREAM
#define CONTAINER_STREAM

// Small function that allow the use of
// the stream operator << on CONTAINERS of
// TYPE (assuming TYPE objects themselves
// support the << operator)

#include<iostream>

template < class T >
void print(const T & container) 
{
    std::cout << "[";

    typename T::const_iterator next = container.begin();
    typename T::const_iterator tail;
    while(next!=container.end())
    {
        tail = next++;
        std::cout << *tail;
        std::cout << (next!=container.end() ? "," : "");
    }

    std::cout << "]";
}

#endif
