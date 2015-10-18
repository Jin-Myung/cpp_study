#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;

int main() {
    vector<int> arr{0, 1, 4, 5, 8, 9, 2, 3, 6, 7};
    replace_copy_if(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "), bind(less<int>(), placeholders::_1, 5), 10);
    cout << endl;
    return 0;
}
