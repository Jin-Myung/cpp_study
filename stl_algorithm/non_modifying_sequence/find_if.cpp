#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n1 = 3;
    int n2 = 0;
 
    std::vector<int> v{0, 1, 2, 3, 4};
    
    auto result1 = find_if(v.cbegin(), v.cend(), [n1](int a){ return a > n1; });
    auto result2 = find_if_not(v.cbegin(), v.cend(), [n2](int a) -> bool { return a >= n2; });
 
    if (result1 != std::end(v)) {
        std::cout << "v contains a number greater than " << n1 << '\n';
    } else {
        std::cout << "all v elements are less than or equal to " << n1 << '\n';
    }
 
    if (result2 != std::end(v)) {
        std::cout << "v contains a number less than " << n2 << '\n';
    } else {
        std::cout << "all v elements are grater than or equal to " << n2 << '\n';
    }
}