#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> arr{0, 1, 2, 3, 3, 3, 4, 5, 6};
    auto ret = equal_range(arr.begin(), arr.end(), 3);
    copy(ret.first, ret.second, ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
