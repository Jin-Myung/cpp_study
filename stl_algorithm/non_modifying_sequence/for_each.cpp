#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector<int> v(5, 2);
    partial_sum(v.cbegin(), v.cend(), v.begin());
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    for_each(v.begin(), v.end(), [](int &ii){ ++ii; } );
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    struct Sum {
        int sum = 0;
        Sum() = default;
        int operator()(int a) { sum += a; return sum; }
    };
    Sum s = for_each(v.begin(), v.end(), Sum());
    cout << s.sum << endl;
    
    return 0;
}
