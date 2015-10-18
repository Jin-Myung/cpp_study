#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> a{0, 1, 2, 3, 4};
    vector<int> b{5, 6, 7, 8, 9};
    swap_ranges(a.begin(), a.begin()+3, b.begin());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
