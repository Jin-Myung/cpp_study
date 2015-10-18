#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>
#include <list>

using namespace std;

void tf(int n) {
    this_thread::sleep_for(chrono::seconds(n));
    cout << n << endl;
}

int main() {
    vector<thread> v;
    v.emplace_back(tf, 1);
    v.emplace_back(tf, 2);
    v.emplace_back(tf, 3);
    
    list<thread> w;
    move(v.begin(), v.end(), back_inserter(w));
    for (auto &t : w) {
        t.join();
    }
    return 0;
}
