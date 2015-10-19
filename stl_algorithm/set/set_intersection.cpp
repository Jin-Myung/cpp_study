#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector<int> a(10);
    vector<int> b(10);
    generate(a.begin(), a.end(), []{ return rand()%10; });
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    generate(b.begin(), b.end(), []{ return rand()%10; });
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> c;
//    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    vector<int>::const_iterator ia = a.begin();
    vector<int>::const_iterator ib = b.begin();
    while (1) {
        if (ia == a.end() || ib == b.end()) {
            break;
        }
        if (*ia == *ib) {
            c.push_back(*ia);
            ++ia; ++ib;
        } else if (*ia < *ib) {
            ++ia;
        } else {
            ++ib;
        }
    }
    copy(c.begin(), c.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    c.erase(unique(c.begin(), c.end()), c.end());
    copy(c.begin(), c.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}