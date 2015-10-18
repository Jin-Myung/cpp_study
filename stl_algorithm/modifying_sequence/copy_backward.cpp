#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> from(10);
    iota(from.begin(), from.end(), 0);
    vector<int> to(15);
    copy_backward(from.begin(), from.end(), to.end());
    copy(to.begin(), to.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
