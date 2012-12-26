
#include<string>
#include<algorithm>

bool is_palindrome(const std::string& s){
    return std::equal(s.begin(), s.end(), s.rbegin());
}
