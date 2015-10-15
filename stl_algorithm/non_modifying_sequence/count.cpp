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

    cout << count(v.cbegin(), v.cend(), 2) << endl;
    cout << count_if(v.cbegin(), v.cend(), [](int a){ return (a < 8); }) << endl;
    
    return 0;
}
