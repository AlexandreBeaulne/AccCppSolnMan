
#include <iostream>
#include <vector>
#include <list>
#include <string>

template < class T >
std::ostream& stream(std::ostream& os, const T & container) 
{
    //std::ostream os;
    os << "[";

    typename T::const_iterator it = container.begin();
    while(it!=container.end())
    {
        //os << *it++ << (it!=container.end()-1 ? ", " : "");
        os << *it++ << (it!=&container.back() ? "," : "");
    }

    os << "]";
    return os;
}

int main()
{
    std::vector<int> v;
    std::list<double> l;

    v.push_back(1); v.push_back(2);
    l.push_back(1.1); l.push_back(2.2);

    stream(std::cout, v) << std::endl;
    stream(std::cout, l) << std::endl;

    return 0;
}

