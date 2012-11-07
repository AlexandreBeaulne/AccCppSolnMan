// Exercise 2-10 

int main() {
    int n = 10;
    int k = 0;
    while (k != n) {
        using std::cout; 
        // this std indicate we will be using
        // the cout function from the std namespace.
        // It only apply to this code block.
        cout << "*";
        ++k;
    }
    std::cout << std::endl;
    // these std's indicate from which namespace
    // cout and endl come from.
    return 0;
}
