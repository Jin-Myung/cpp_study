#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main() {
    vector<int> arr{0, 1, 4, 5, 8, 9, 2, 3, 6, 7};
    replace_if(arr.begin(), arr.end(), bind(less<int>(), placeholders::_1, 5), 10);
    for_each(arr.begin(), arr.end(), [](const int &a) { cout << a << " "; });
    cout << endl;
    return 0;
}
