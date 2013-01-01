
#ifndef FIND_URLS
#define FIND_URLS

#include<string>
#include<vector>
#include<algorithm>

bool not_url_char(char);
std::string::const_iterator
url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

#endif
