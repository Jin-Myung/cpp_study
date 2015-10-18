#include <memory>
#include <iostream>

using namespace std;

int main() {
    allocator<string> alc;
    auto const p = alc.allocate(10);
    auto q = p;
    alc.construct(q++);
    alc.construct(q++, 10, 'd');
    alc.construct(q++, "hello");
    
    while (p != q) {
        --q;
        cout << *q << endl;
        alc.destroy(q);
    }
    alc.deallocate(p, 10);
    return 0;
}
