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
    
    if (all_of(v.cbegin(), v.cend(), [](int i){ return i%2 == 0; })) {
        cout << "All numbers are even" << endl;
    }
    return 0;
}
