#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    string str = "this is a box";
    remove_copy_if(str.begin(), str.end(), ostream_iterator<char>(cout), [](char c){ return isspace(c); });
    cout << "\n";
    return 0;
}
