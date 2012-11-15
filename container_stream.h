
#ifndef CONTAINER_STREAM
#define CONTAINER_STREAM

// Small function that allow the use of
// the stream operator << on CONTAINERS of
// TYPE (assuming TYPE objects themselves
// support the << operator)

#include<iostream>

//template < typename C, typename T >
template < template <class> class C, class T >
std::ostream& operator << (std::ostream& os, const typename C<T>& v) 
{
    os << "[";
    for(C<T>::iterator it = v.begin(); it != v.end(); ++it)
    {
        os << *it << (it!=v.end()-1 ? ", " : "");
    }
    os << "]";
    return os;
}

#endif
