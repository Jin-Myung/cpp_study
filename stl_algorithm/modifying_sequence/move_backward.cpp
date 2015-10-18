#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

void print(const vector<string> &str_arr) {
    copy(str_arr.begin(), str_arr.end(), ostream_iterator<string>(cout, " "));
    cout << "\n";
}

int main() {
    vector<string> src{"foo", "bar", "baz"};
    vector<string> dst(3);
    
    print(src);
    print(dst);

    move_backward(src.begin(), src.end(), dst.end());

    print(src);
    print(dst);
    
    return 0;
}
