#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str = "this is a box";
    str.erase(
            remove_if(str.begin(), str.end(), [](char c){ return isspace(c); }),
            str.end()
            );
    cout << str << endl;
    return 0;
}
