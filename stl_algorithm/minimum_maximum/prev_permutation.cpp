#include <algorithm>
#include <string>
#include <iostream>

int main() {
    std::string str = "dcba";
    do {
        std::cout << str << std::endl;
    } while (prev_permutation(str.begin(), str.end()));
    return 0;
}
