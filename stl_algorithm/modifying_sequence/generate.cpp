#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    vector<int> arr(5);
    generate(arr.begin(), arr.end(), std::rand);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    int n = 0;
    generate(arr.begin(), arr.end(), [&n]{ return n++; });
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    
    return 0;
}