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
    
    struct DivisibleBy {
        const int d;
        DivisibleBy(int _d) : d(_d) { }
        bool operator()(int a) { return (a % d == 0); }
    };
    
    if (any_of(v.cbegin(), v.cend(), DivisibleBy(6))) {
        cout << "There is a number divisible by 6" << endl;
    }
    return 0;
}
