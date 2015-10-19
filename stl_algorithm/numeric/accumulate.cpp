#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<int> v{0, 1, 2, 3, 4};
    string str = accumulate(v.begin(), v.end(), string{},
            [](const string &s, int a){ return s + "-" + to_string(a); }
            );
    cout << str << endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
    return 0;
}
