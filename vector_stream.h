
#ifndef VECTOR_STREAM
#define VECTOR_STREAM

// Small function that allow the use of
// the stream operator << on vectors of
// TYPE (assuming TYPE objects themselves
// support the << operator)

#include<iostream>
#include<vector>

template<typename T>
std::ostream & operator<<(std::ostream &, const std::vector<T> &);

#endif
