#include <string>

class has_ptr_t {
    friend void swap(has_ptr_t&, has_ptr_t&);
public:
    has_ptr_t(const std::string &s = std::string())
            : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    has_ptr_t(const has_ptr_t &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    has_ptr_t &operator=(const has_ptr_t rhs);
    ~has_ptr_t() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

inline void swap(has_ptr_t &lhs, has_ptr_t &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

has_ptr_t &has_ptr_t::operator=(has_ptr_t rhs) {
    swap(*this, rhs);
    return *this;
}

int main() {
    return 0;
}
