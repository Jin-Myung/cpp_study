#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
 
template<class FIT>
void sel_sort(FIT b, FIT e) {
    for (FIT it = b; it != e; ++it) {
        iter_swap(it, min_element(it, e));
    }
}

int main() {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7};
    std::random_shuffle(v.begin(), v.end());
 
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    sel_sort(v.begin(), v.end());
 
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    return 0;
}
