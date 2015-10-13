#include <memory>
#include <iostream>

using namespace std;

int main() {
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");
    
    while (p != q) {
        --q;
        cout << *q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, 10);
    return 0;
}
