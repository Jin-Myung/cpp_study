#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> arr{0, 1, 2, 3, 4, 5, 6};
    vector<int> even;
    vector<int> odd;
    partition_copy(arr.cbegin(), arr.cend(), back_inserter(even), back_inserter(odd), [](const int a) { return a % 2 == 0; });
    copy(even.cbegin(), even.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(odd.cbegin(), odd.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;    
}
