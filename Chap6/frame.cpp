
#include "frame.h"

std::string::size_type width(const std::vector<std::string>& v)
{
    std::string::size_type maxlen = 0;

    for(std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    
    return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string>& v) {
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');
    // write the top border
    ret.push_back(border);
    // write each interior row, bordered by an asterisk and a space
    for (std::vector<std::string>::const_iterator iter = v.begin();
            iter != v.end();
            ++iter) {
        ret.push_back( "* " + *iter + std::string(maxlen - (*iter).size(), ' ') + " *");
    }
    // write the bottom border
    ret.push_back(border);
    return ret;
}

std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom)
{
    // copy the top picture
    std::vector<std::string> ret = top;
    // copy entire bottom picture
    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}


std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right)
{
    std::vector<std::string> ret;
    // add 1 to leave a space between pictures
    std::string::size_type width1 = width(left) + 1;
    // indices to look at elements from left and right respectively
    std::vector<std::string>::const_iterator i = left.begin();
    std::vector<std::string>::const_iterator j = right.begin();
    // continue until we've seen all rows from both pictures
    // construct new string to hold characters from both pictures
    std::string s;
    while (i != left.end() || j != right.end()) {
        // copy a row from the left-hand side, if there is one
        if (i != left.end())
            s = *i++;
        // pad to full width
        s += std::string(width1 - s.size(), ' ');
        // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += *j++;
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}

void printPic(const std::vector<std::string> & pic){
    for(std::vector<std::string>::const_iterator i = pic.begin(); i!=pic.end(); ++i){
        std::cout << *i << std::endl;
    }
}
