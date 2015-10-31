#include <string>
#include <iostream>
#include <memory>

using namespace std;

int main() {
    allocator<string> alc;
    allocator<string>::pointer p = alc.allocate(10);
    auto q = p + 10;
    uninitialized_fill(p, q, "abc");
    do {
        q--;
        cout << *q << endl;
        alc.destroy(q);
    } while (q != p);
    alc.deallocate(p, 10);
    return 0;
}

