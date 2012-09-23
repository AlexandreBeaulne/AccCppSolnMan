
#include<iostream>
#include<algorithm>
#include<vector>

std::ostream & operator<<(std::ostream &lhs, const std::vector<double> & rhs){
    lhs << '[';
    for(int i=0;i<rhs.size();++i){
        lhs << rhs[i];
        if(i<rhs.size()-1){
            lhs << ',';
        }
    }
    lhs << ']';
    return lhs;
}
    


const std::vector<double> augment(std::vector<double> input, const double & tgt_median)
{
    // takes a vector of doubles in and return a 
    // new vector whose median is tgt_median and
    // which comprise all values of the input vector
    // plus additional (completely) arbitrary values.
    // This function has no other value than show
    // that the median, unlike the moments, requires
    // the whole sample to be computed.

    std::sort(input.begin(),input.end());
    int smaller = int(std::lower_bound(input.begin(),input.end(),tgt_median)-input.begin());
    int bigger = input.size()-smaller-1;

    int sign = (bigger>smaller?-1:1);
    int diff = -sign*(bigger-smaller);
    for(int i=0;i<diff;++i){
        input.push_back(tgt_median + sign);
    }
    return input;
}

int main(){

    std::vector<double> arb(6);
    for(int i=0;i<6;++i){
        arb[i] = 10*i;
    }

    std::cout << arb << std::endl;
    double tgt_median;
    std::cout << "Please pick any value in the above vector: ";
    std::cin >> tgt_median;

    std::cout << "new vector: " << augment(arb,tgt_median);
    std::cout << ", median: " << tgt_median << std::endl;

    return 0;
}
