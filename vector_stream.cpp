
#include "vector_stream.h"

// Small function that allow the use of
// the stream operator << on vectors of
// TYPE (assuming TYPE objects themselves
// support the << operator)

template<typename T>
std::ostream & operator<<(std::ostream & stream, const std::vector<T> & vect)
{
    stream << "[";
    
    for(int i = 0; i!=vect.size-1; ++i)
    {
        stream << vect[i] << ",";
    }

    stream << vect[vect.size-1] << "]";

    return stream;
}

