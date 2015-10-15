#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector<int> v(5, 3);
    partial_sum(v.cbegin(), v.cend(), v.begin(), [](int i, int j){ return i + j + 1; });
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}

