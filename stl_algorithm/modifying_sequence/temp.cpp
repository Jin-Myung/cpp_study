#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>

int main() {
    std::vector<int> from(10);
    std::iota(from.begin(), from.end(), 0);
    std::deque<int> to;
    std::copy(from.begin(), from.end(), std::front_inserter(to));
    std::copy_if(to.begin(), to.end(), std::ostream_iterator<int>(std::cout, " "), [](int a){ return a%2; });
    std::cout << "\n";
    return 0;
}