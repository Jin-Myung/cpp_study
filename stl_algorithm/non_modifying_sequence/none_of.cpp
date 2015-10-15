#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <functional>

using namespace std;

int main() {
    vector<int> v(5, 2);
    partial_sum(v.cbegin(), v.cend(), v.begin());
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    
    if (none_of(v.cbegin(), v.cend(), bind(modulus<int>(), placeholders::_1, 2))) {
        cout << "All numbers are even" << endl;
    }
    return 0;
}
