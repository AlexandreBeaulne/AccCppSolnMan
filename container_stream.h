
#ifndef VECTOR_STREAM
#define VECTOR_STREAM

// Small function that allow the use of
// the stream operator << on vectors of
// TYPE (assuming TYPE objects themselves
// support the << operator)

#include<iostream>
#include<vector>

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << *ii << (ii!=v.end()-1 ? ", " : "");
    }
    os << "]";
    return os;
}

#endif
