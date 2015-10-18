#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> arr{0, 1, 2, 3, 4};
    vector<int> out;
    rotate_copy(arr.begin(), arr.begin()+2, arr.end(), back_inserter(out));
    copy(out.begin(), out.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
